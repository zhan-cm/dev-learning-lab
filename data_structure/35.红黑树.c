#include <stdio.h>
#include <stdlib.h>

// 定义红黑树的颜色
typedef enum { RED, BLACK } Color;

// 红黑树节点结构
typedef struct RBTreeNode {
    int key;
    Color color;
    struct RBTreeNode *left;
    struct RBTreeNode *right;
    struct RBTreeNode *parent;
} RBTreeNode;

// 红黑树结构
typedef struct {
    RBTreeNode *root;
    RBTreeNode *nil;  // 哨兵节点，代表NULL
} RBTree;

// 创建哨兵节点
RBTreeNode* create_nil_node() {
    RBTreeNode *node = (RBTreeNode*)malloc(sizeof(RBTreeNode));
    node->color = BLACK;
    node->left = node->right = node->parent = NULL;
    return node;
}

// 初始化红黑树
void init_rbtree(RBTree *tree) {
    tree->nil = create_nil_node();
    tree->root = tree->nil;
}

// 创建新节点
RBTreeNode* create_rbtree_node(int key) {
    RBTreeNode *node = (RBTreeNode*)malloc(sizeof(RBTreeNode));
    node->key = key;
    node->color = RED;  // 新节点默认为红色
    node->left = node->right = node->parent = NULL;
    return node;
}

// 左旋
void left_rotate(RBTree *tree, RBTreeNode *x) {
    RBTreeNode *y = x->right;
    x->right = y->left;
    
    if (y->left != tree->nil) {
        y->left->parent = x;
    }
    
    y->parent = x->parent;
    
    if (x->parent == tree->nil) {
        tree->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    
    y->left = x;
    x->parent = y;
}

// 右旋
void right_rotate(RBTree *tree, RBTreeNode *y) {
    RBTreeNode *x = y->left;
    y->left = x->right;
    
    if (x->right != tree->nil) {
        x->right->parent = y;
    }
    
    x->parent = y->parent;
    
    if (y->parent == tree->nil) {
        tree->root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    
    x->right = y;
    y->parent = x;
}

// 插入修复
void rb_insert_fixup(RBTree *tree, RBTreeNode *z) {
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            RBTreeNode *y = z->parent->parent->right;
            
            if (y->color == RED) {
                // 情况1：叔叔节点是红色
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    // 情况2：叔叔节点是黑色，且当前节点是右孩子
                    z = z->parent;
                    left_rotate(tree, z);
                }
                // 情况3：叔叔节点是黑色，且当前节点是左孩子
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                right_rotate(tree, z->parent->parent);
            }
        } else {
            // 对称的情况
            RBTreeNode *y = z->parent->parent->left;
            
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    right_rotate(tree, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                left_rotate(tree, z->parent->parent);
            }
        }
    }
    tree->root->color = BLACK;
}

// 插入节点
void rb_insert(RBTree *tree, int key) {
    RBTreeNode *z = create_rbtree_node(key);
    RBTreeNode *y = tree->nil;
    RBTreeNode *x = tree->root;
    
    while (x != tree->nil) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    
    z->parent = y;
    
    if (y == tree->nil) {
        tree->root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
    
    z->left = tree->nil;
    z->right = tree->nil;
    z->color = RED;
    
    rb_insert_fixup(tree, z);
}

// 查找最小节点
RBTreeNode* tree_minimum(RBTree *tree, RBTreeNode *x) {
    while (x->left != tree->nil) {
        x = x->left;
    }
    return x;
}

// 替换节点
void rb_transplant(RBTree *tree, RBTreeNode *u, RBTreeNode *v) {
    if (u->parent == tree->nil) {
        tree->root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

// 删除修复
void rb_delete_fixup(RBTree *tree, RBTreeNode *x) {
    while (x != tree->root && x->color == BLACK) {
        if (x == x->parent->left) {
            RBTreeNode *w = x->parent->right;
            
            if (w->color == RED) {
                // 情况1：兄弟节点是红色
                w->color = BLACK;
                x->parent->color = RED;
                left_rotate(tree, x->parent);
                w = x->parent->right;
            }
            
            if (w->left->color == BLACK && w->right->color == BLACK) {
                // 情况2：兄弟节点是黑色，且兄弟的两个孩子都是黑色
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right->color == BLACK) {
                    // 情况3：兄弟节点是黑色，兄弟的左孩子是红色，右孩子是黑色
                    w->left->color = BLACK;
                    w->color = RED;
                    right_rotate(tree, w);
                    w = x->parent->right;
                }
                // 情况4：兄弟节点是黑色，兄弟的右孩子是红色
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                left_rotate(tree, x->parent);
                x = tree->root;
            }
        } else {
            // 对称的情况
            RBTreeNode *w = x->parent->left;
            
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                right_rotate(tree, x->parent);
                w = x->parent->left;
            }
            
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    left_rotate(tree, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                right_rotate(tree, x->parent);
                x = tree->root;
            }
        }
    }
    x->color = BLACK;
}

// 删除节点
void rb_delete(RBTree *tree, RBTreeNode *z) {
    RBTreeNode *y = z;
    RBTreeNode *x;
    Color y_original_color = y->color;
    
    if (z->left == tree->nil) {
        x = z->right;
        rb_transplant(tree, z, z->right);
    } else if (z->right == tree->nil) {
        x = z->left;
        rb_transplant(tree, z, z->left);
    } else {
        y = tree_minimum(tree, z->right);
        y_original_color = y->color;
        x = y->right;
        
        if (y->parent == z) {
            x->parent = y;
        } else {
            rb_transplant(tree, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        
        rb_transplant(tree, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    
    if (y_original_color == BLACK) {
        rb_delete_fixup(tree, x);
    }
    
    free(z);
}

// 查找节点
RBTreeNode* rb_search(RBTree *tree, int key) {
    RBTreeNode *x = tree->root;
    
    while (x != tree->nil && key != x->key) {
        if (key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    
    return x;
}

// 中序遍历（用于验证）
void inorder_traversal(RBTree *tree, RBTreeNode *x) {
    if (x != tree->nil) {
        inorder_traversal(tree, x->left);
        printf("%d(%s) ", x->key, x->color == RED ? "RED" : "BLACK");
        inorder_traversal(tree, x->right);
    }
}

// 释放红黑树
void free_rbtree(RBTree *tree, RBTreeNode *x) {
    if (x != tree->nil) {
        free_rbtree(tree, x->left);
        free_rbtree(tree, x->right);
        free(x);
    }
}

int main() {
    RBTree tree;
    init_rbtree(&tree);
    
    // 插入测试
    rb_insert(&tree, 10);
    rb_insert(&tree, 20);
    rb_insert(&tree, 30);
    rb_insert(&tree, 15);
    rb_insert(&tree, 25);
    rb_insert(&tree, 5);
    
    printf("Inorder traversal after insertion:\n");
    inorder_traversal(&tree, tree.root);
    printf("\n");
    
    // 查找测试
    int key = 20;
    RBTreeNode *node = rb_search(&tree, key);
    if (node != tree.nil) {
        printf("Found %d in the tree\n", key);
    } else {
        printf("%d not found in the tree\n", key);
    }
    
    // 删除测试
    key = 20;
    node = rb_search(&tree, key);
    if (node != tree.nil) {
        rb_delete(&tree, node);
        printf("Deleted %d from the tree\n", key);
    }
    
    printf("Inorder traversal after deletion:\n");
    inorder_traversal(&tree, tree.root);
    printf("\n");
    
    // 释放内存
    free_rbtree(&tree, tree.root);
    free(tree.nil);
    
    return 0;
}