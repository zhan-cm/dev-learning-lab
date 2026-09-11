#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// 哈希表节点
typedef struct HashNode {
    char *key;
    int value;
    struct HashNode *next;
} HashNode;

// 哈希表
typedef struct {
    HashNode **buckets;
    int size;
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
    ht->buckets = (HashNode**)calloc(size, sizeof(HashNode*));
    return ht;
}

// 创建节点
HashNode* create_node(const char *key, int value) {
    HashNode *node = (HashNode*)malloc(sizeof(HashNode));
    node->key = strdup(key);
    node->value = value;
    node->next = NULL;
    return node;
}

// 插入键值对
void hashtable_insert(HashTable *ht, const char *key, int value) {
    unsigned int bucket = hash(key, ht->size);
    HashNode *node = ht->buckets[bucket];
    
    // 检查键是否已存在
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            node->value = value; // 更新值
            return;
        }
        node = node->next;
    }
    
    // 插入新节点到链表头部
    HashNode *new_node = create_node(key, value);
    new_node->next = ht->buckets[bucket];
    ht->buckets[bucket] = new_node;
}

// 查找键
int hashtable_search(HashTable *ht, const char *key) {
    unsigned int bucket = hash(key, ht->size);
    HashNode *node = ht->buckets[bucket];
    
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    
    return -1; // 未找到
}

// 删除键
void hashtable_delete(HashTable *ht, const char *key) {
    unsigned int bucket = hash(key, ht->size);
    HashNode *node = ht->buckets[bucket];
    HashNode *prev = NULL;
    
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            if (prev == NULL) {
                ht->buckets[bucket] = node->next;
            } else {
                prev->next = node->next;
            }
            free(node->key);
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}

// 打印哈希表
void print_hashtable(HashTable *ht) {
    for (int i = 0; i < ht->size; i++) {
        printf("Bucket %d: ", i);
        HashNode *node = ht->buckets[i];
        while (node != NULL) {
            printf("(%s, %d) ", node->key, node->value);
            node = node->next;
        }
        printf("\n");
    }
}

// 释放哈希表
void free_hashtable(HashTable *ht) {
    for (int i = 0; i < ht->size; i++) {
        HashNode *node = ht->buckets[i];
        while (node != NULL) {
            HashNode *temp = node;
            node = node->next;
            free(temp->key);
            free(temp);
        }
    }
    free(ht->buckets);
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