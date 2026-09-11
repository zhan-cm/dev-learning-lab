#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// B树的阶数 - 每个节点最多有2*t-1个键
#define t 3

typedef struct BTreeNode {
    int *keys;          // 键的数组
    struct BTreeNode **children; // 子节点指针数组
    int n;              // 当前键的数量
    bool leaf;          // 是否是叶子节点
} BTreeNode;

// 创建新节点
BTreeNode* createNode(bool leaf) {
    BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    newNode->keys = (int*)malloc(sizeof(int) * (2*t-1));
    newNode->children = (BTreeNode**)malloc(sizeof(BTreeNode*) * 2*t);
    newNode->n = 0;
    newNode->leaf = leaf;
    return newNode;
}

// 在B树中搜索键
BTreeNode* search(BTreeNode* root, int key, int* index) {
    int i = 0;
    while (i < root->n && key > root->keys[i])
        i++;
    
    if (i < root->n && key == root->keys[i]) {
        *index = i;
        return root;
    }
    
    if (root->leaf)
        return NULL;
    
    return search(root->children[i], key, index);
}

// 分裂子节点
void splitChild(BTreeNode* parent, int i, BTreeNode* child) {
    BTreeNode* newNode = createNode(child->leaf);
    newNode->n = t - 1;
    
    // 复制后t-1个键到新节点
    for (int j = 0; j < t-1; j++)
        newNode->keys[j] = child->keys[j+t];
    
    // 如果不是叶子节点，复制子节点
    if (!child->leaf) {
        for (int j = 0; j < t; j++)
            newNode->children[j] = child->children[j+t];
    }
    
    child->n = t - 1;
    
    // 为新的子节点腾出空间
    for (int j = parent->n; j >= i+1; j--)
        parent->children[j+1] = parent->children[j];
    
    parent->children[i+1] = newNode;
    
    // 移动父节点的键
    for (int j = parent->n-1; j >= i; j--)
        parent->keys[j+1] = parent->keys[j];
    
    parent->keys[i] = child->keys[t-1];
    parent->n++;
}

// 插入非满节点
void insertNonFull(BTreeNode* node, int key) {
    int i = node->n - 1;
    
    if (node->leaf) {
        // 如果是叶子节点，直接插入
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i+1] = node->keys[i];
            i--;
        }
        node->keys[i+1] = key;
        node->n++;
    } else {
        // 不是叶子节点，找到合适的子节点
        while (i >= 0 && key < node->keys[i])
            i--;
        i++;
        
        // 检查子节点是否已满
        if (node->children[i]->n == 2*t-1) {
            splitChild(node, i, node->children[i]);
            if (key > node->keys[i])
                i++;
        }
        insertNonFull(node->children[i], key);
    }
}

// 插入键
BTreeNode* insert(BTreeNode* root, int key) {
    if (root == NULL) {
        root = createNode(true);
        root->keys[0] = key;
        root->n = 1;
        return root;
    }
    
    // 如果根节点已满，需要分裂
    if (root->n == 2*t-1) {
        BTreeNode* newRoot = createNode(false);
        newRoot->children[0] = root;
        splitChild(newRoot, 0, root);
        
        // 决定新键插入哪个子节点
        int i = 0;
        if (newRoot->keys[0] < key)
            i++;
        insertNonFull(newRoot->children[i], key);
        return newRoot;
    } else {
        insertNonFull(root, key);
        return root;
    }
}

// 获取前驱键
int getPredecessor(BTreeNode* node) {
    while (!node->leaf)
        node = node->children[node->n];
    return node->keys[node->n-1];
}

// 获取后继键
int getSuccessor(BTreeNode* node) {
    while (!node->leaf)
        node = node->children[0];
    return node->keys[0];
}

// 从子节点借键
void borrowFromPrev(BTreeNode* node, int idx) {
    BTreeNode* child = node->children[idx];
    BTreeNode* sibling = node->children[idx-1];
    
    // 为child的第一个键腾出空间
    for (int i = child->n-1; i >= 0; i--)
        child->keys[i+1] = child->keys[i];
    
    // 如果不是叶子节点，移动子节点指针
    if (!child->leaf) {
        for (int i = child->n; i >= 0; i--)
            child->children[i+1] = child->children[i];
    }
    
    child->keys[0] = node->keys[idx-1];
    
    if (!child->leaf)
        child->children[0] = sibling->children[sibling->n];
    
    node->keys[idx-1] = sibling->keys[sibling->n-1];
    
    child->n++;
    sibling->n--;
}

// 从下一个子节点借键
void borrowFromNext(BTreeNode* node, int idx) {
    BTreeNode* child = node->children[idx];
    BTreeNode* sibling = node->children[idx+1];
    
    child->keys[child->n] = node->keys[idx];
    
    if (!child->leaf)
        child->children[child->n+1] = sibling->children[0];
    
    node->keys[idx] = sibling->keys[0];
    
    for (int i = 1; i < sibling->n; i++)
        sibling->keys[i-1] = sibling->keys[i];
    
    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->n; i++)
            sibling->children[i-1] = sibling->children[i];
    }
    
    child->n++;
    sibling->n--;
}

// 合并子节点
void merge(BTreeNode* node, int idx) {
    BTreeNode* child = node->children[idx];
    BTreeNode* sibling = node->children[idx+1];
    
    child->keys[t-1] = node->keys[idx];
    
    for (int i = 0; i < sibling->n; i++)
        child->keys[i+t] = sibling->keys[i];
    
    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; i++)
            child->children[i+t] = sibling->children[i];
    }
    
    for (int i = idx+1; i < node->n; i++)
        node->keys[i-1] = node->keys[i];
    
    for (int i = idx+2; i <= node->n; i++)
        node->children[i-1] = node->children[i];
    
    child->n += sibling->n + 1;
    node->n--;
    
    free(sibling->keys);
    free(sibling->children);
    free(sibling);
}

// 填充不足的子节点
void fill(BTreeNode* node, int idx) {
    if (idx != 0 && node->children[idx-1]->n >= t)
        borrowFromPrev(node, idx);
    else if (idx != node->n && node->children[idx+1]->n >= t)
        borrowFromNext(node, idx);
    else {
        if (idx != node->n)
            merge(node, idx);
        else
            merge(node, idx-1);
    }
}

// 从子节点删除键
void removeKey(BTreeNode* node, int key) {
    int idx = 0;
    while (idx < node->n && node->keys[idx] < key)
        idx++;
    
    if (idx < node->n && node->keys[idx] == key) {
        if (node->leaf)
            removeFromLeaf(node, idx);
        else
            removeFromNonLeaf(node, idx);
    } else {
        if (node->leaf) {
            printf("Key %d not found in the tree\n", key);
            return;
        }
        
        bool flag = (idx == node->n);
        
        if (node->children[idx]->n < t)
            fill(node, idx);
        
        if (flag && idx > node->n)
            removeKey(node->children[idx-1], key);
        else
            removeKey(node->children[idx], key);
    }
}

// 从子树中删除键
int removeFromLeaf(BTreeNode* node, int idx) {
    int key = node->keys[idx];
    for (int i = idx+1; i < node->n; i++)
        node->keys[i-1] = node->keys[i];
    node->n--;
    return key;
}

// 从非叶子节点删除键
int removeFromNonLeaf(BTreeNode* node, int idx) {
    int key = node->keys[idx];
    
    if (node->children[idx]->n >= t) {
        int pred = getPredecessor(node->children[idx]);
        node->keys[idx] = pred;
        removeKey(node->children[idx], pred);
    } else if (node->children[idx+1]->n >= t) {
        int succ = getSuccessor(node->children[idx+1]);
        node->keys[idx] = succ;
        removeKey(node->children[idx+1], succ);
    } else {
        merge(node, idx);
        removeKey(node->children[idx], key);
    }
    return key;
}



// 删除键
BTreeNode* deleteKey(BTreeNode* root, int key) {
    if (!root) {
        printf("The tree is empty\n");
        return root;
    }
    
    removeKey(root, key);
    
    if (root->n == 0) {
        BTreeNode* temp = root;
        if (root->leaf)
            root = NULL;
        else
            root = root->children[0];
        
        free(temp->keys);
        free(temp->children);
        free(temp);
    }
    
    return root;
}

// 打印B树
void printBTree(BTreeNode* node, int level) {
    printf("Level %d: ", level);
    for (int i = 0; i < node->n; i++)
        printf("%d ", node->keys[i]);
    printf("\n");
    
    if (!node->leaf) {
        for (int i = 0; i <= node->n; i++)
            printBTree(node->children[i], level+1);
    }
}

// 释放B树内存
void freeBTree(BTreeNode* node) {
    if (node) {
        if (!node->leaf) {
            for (int i = 0; i <= node->n; i++)
                freeBTree(node->children[i]);
        }
        free(node->keys);
        free(node->children);
        free(node);
    }
}

int main() {
    BTreeNode* root = NULL;
    
    // 插入测试
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 12);
    root = insert(root, 30);
    root = insert(root, 7);
    root = insert(root, 17);
    
    printf("B树结构:\n");
    printBTree(root, 0);
    
    // 搜索测试
    int index;
    BTreeNode* result = search(root, 6, &index);
    if (result)
        printf("\n键6在节点中找到，位置: %d\n", index);
    else
        printf("\n键6未找到\n");
    
    // 删除测试
    printf("\n删除键6后:\n");
    root = deleteKey(root, 6);
    printBTree(root, 0);
    
    printf("\n删除键13后(不存在):\n");
    root = deleteKey(root, 13);
    printBTree(root, 0);
    
    // 释放内存
    freeBTree(root);
    
    return 0;
}