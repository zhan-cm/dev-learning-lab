#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef struct {
    int data;
}Node;

typedef struct 
{
    int length;
    Node node[MAXSIZE];
}SqList;

//初始化
void InitList(SqList *L)
{
    L->length = 0;
}

//取值
int GetElem(SqList *L, int i) {
    if (i < 1 || i > L->length) {
        printf("取值位置错误\n");
        return -1; // 返回一个错误码，表示取值失败
    }
    return L->node[i - 1].data;
}
//查找
int LocateElem(SqList *L, int e) {
    for (int i = 0; i < L->length; i++) {
        if (L->node[i].data == e) {
            return i + 1; // 返回元素的位置（从1开始）
        }
    }
    return 0; // 如果未找到，返回0
}
//插入
int ListInsert(SqList *L, int i, int e) {
    if (i < 1 || i > L->length + 1) {
        printf("插入位置错误\n");
        return 0; // 返回0，表示插入失败
    }
    if (L->length >= MAXSIZE) {
        printf("顺序表已满，无法插入\n");
        return 0; // 返回0，表示插入失败
    }
    for (int j = L->length - 1; j >= i - 1; j--) {
        L->node[j + 1] = L->node[j];
    }
    L->node[i - 1].data = e;
    L->length++;
    return 1; // 返回1，表示插入成功
}

//删除
int ListDelete(SqList *L, int i) {
    if (i < 1 || i > L->length) {
        printf("删除位置错误\n");
        return 0; // 返回0，表示删除失败
    }
    for (int j = i; j < L->length; j++) {
        L->node[j - 1] = L->node[j];
    }
    L->length--;
    return 1; // 返回1，表示删除成功
}
//输出
void PrintSqList(SqList *L) {
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->node[i].data);
    }
    printf("\n");
}


int main() {
    SqList L;
    InitSqList(&L); // 初始化顺序表

    ListInsert(&L, 1, 10); // 插入元素
    ListInsert(&L, 2, 20);
    ListInsert(&L, 3, 30);

    printf("顺序表中的元素：");
    PrintSqList(&L); // 输出顺序表

    int elem = GetElem(&L, 2); // 取值
    printf("第2个元素的值为：%d\n", elem);

    int pos = LocateElem(&L, 20); // 查找
    if (pos != 0) {
        printf("元素20的位置为：%d\n", pos);
    } else {
        printf("未找到元素20\n");
    }

    ListDelete(&L, 2); // 删除元素
    printf("删除第2个元素后，顺序表中的元素：");
    PrintSqList(&L);

    return 0;
}
