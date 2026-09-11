#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define DELETED_NODE (HashNode*)(-1)

typedef struct {
    char *key;
    int value;
} HashNode;

typedef struct {
    HashNode **nodes;
    int size;
    int count;
} HashTable;

// 哈希函数
unsigned int hash(const char *key, int size) {
    unsigned int hashval = 0;
    for (; *key != '\0'; key++) {
        hashval = *key + 31 * hashval;
    }
    return hashval % size;
}

// 创建哈希表
HashTable* create_hashtable(int size) {
    HashTable *ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = size;
    ht->count = 0;
    ht->nodes = (HashNode**)calloc(size, sizeof(HashNode*));
    return ht;
}

// 创建节点
HashNode* create_node(const char *key, int value) {
    HashNode *node = (HashNode*)malloc(sizeof(HashNode));
    node->key = strdup(key);
    node->value = value;
    return node;
}

// 插入键值对
void hashtable_insert(HashTable *ht, const char *key, int value) {
    if (ht->count >= ht->size) {
        printf("Hash table is full!\n");
        return;
    }
    
    unsigned int index = hash(key, ht->size);
    HashNode *node = ht->nodes[index];
    
    // 线性探测
    int i = 1;
    while (node != NULL && node != DELETED_NODE) {
        if (strcmp(node->key, key) == 0) {
            node->value = value; // 更新值
            return;
        }
        index = (index + i) % ht->size;
        node = ht->nodes[index];
        i++;
    }
    
    // 插入新节点
    ht->nodes[index] = create_node(key, value);
    ht->count++;
}

// 查找键
int hashtable_search(HashTable *ht, const char *key) {
    unsigned int index = hash(key, ht->size);
    HashNode *node = ht->nodes[index];
    
    int i = 1;
    while (node != NULL) {
        if (node != DELETED_NODE && strcmp(node->key, key) == 0) {
            return node->value;
        }
        index = (index + i) % ht->size;
        node = ht->nodes[index];
        i++;
    }
    
    return -1; // 未找到
}

// 删除键
void hashtable_delete(HashTable *ht, const char *key) {
    unsigned int index = hash(key, ht->size);
    HashNode *node = ht->nodes[index];
    
    int i = 1;
    while (node != NULL) {
        if (node != DELETED_NODE && strcmp(node->key, key) == 0) {
            free(node->key);
            free(node);
            ht->nodes[index] = DELETED_NODE;
            ht->count--;
            return;
        }
        index = (index + i) % ht->size;
        node = ht->nodes[index];
        i++;
    }
}

// 打印哈希表
void print_hashtable(HashTable *ht) {
    for (int i = 0; i < ht->size; i++) {
        printf("Slot %d: ", i);
        if (ht->nodes[i] == NULL) {
            printf("NULL");
        } else if (ht->nodes[i] == DELETED_NODE) {
            printf("DELETED");
        } else {
            printf("(%s, %d)", ht->nodes[i]->key, ht->nodes[i]->value);
        }
        printf("\n");
    }
}

// 释放哈希表
void free_hashtable(HashTable *ht) {
    for (int i = 0; i < ht->size; i++) {
        if (ht->nodes[i] != NULL && ht->nodes[i] != DELETED_NODE) {
            free(ht->nodes[i]->key);
            free(ht->nodes[i]);
        }
    }
    free(ht->nodes);
    free(ht);
}

int main() {
    HashTable *ht = create_hashtable(TABLE_SIZE);
    
    // 插入测试
    hashtable_insert(ht, "apple", 10);
    hashtable_insert(ht, "banana", 20);
    hashtable_insert(ht, "orange", 30);
    hashtable_insert(ht, "pear", 40);
    hashtable_insert(ht, "grape", 50);
    
    printf("Hash table contents:\n");
    print_hashtable(ht);
    
    // 查找测试
    printf("\nSearch results:\n");
    printf("apple: %d\n", hashtable_search(ht, "apple"));
    printf("banana: %d\n", hashtable_search(ht, "banana"));
    printf("watermelon: %d\n", hashtable_search(ht, "watermelon")); // 不存在
    
    // 删除测试
    printf("\nDeleting 'banana'...\n");
    hashtable_delete(ht, "banana");
    print_hashtable(ht);
    
    // 更新测试
    printf("\nUpdating 'apple' to 100...\n");
    hashtable_insert(ht, "apple", 100);
    print_hashtable(ht);
    
    free_hashtable(ht);
    return 0;
}