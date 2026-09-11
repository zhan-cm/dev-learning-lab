#include <stdio.h>
#include <stdlib.h>

// 合并两个已排序的子数组 arr[l..m] 和 arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;  // 左子数组的大小
    int n2 = r - m;      // 右子数组的大小

    // 创建临时数组
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // 拷贝数据到临时数组 L[] 和 R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // 合并临时数组回 arr[l..r]
    i = 0;    // 初始化左子数组的索引
    j = 0;    // 初始化右子数组的索引
    k = l;    // 初始化合并子数组的索引
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 拷贝 L[] 的剩余元素（如果有）
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 拷贝 R[] 的剩余元素（如果有）
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // 释放临时数组
    free(L);
    free(R);
}

// 归并排序主函数
// l: 左边界索引
// r: 右边界索引
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // 计算中间位置，避免溢出
        int m = l + (r - l) / 2;

        // 递归排序左半部分
        mergeSort(arr, l, m);
        // 递归排序右半部分
        mergeSort(arr, m + 1, r);

        // 合并已排序的两部分
        merge(arr, l, m, r);
    }
}

// 打印数组
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// 测试代码
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组: \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("排序后的数组: \n");
    printArray(arr, arr_size);

    return 0;
}