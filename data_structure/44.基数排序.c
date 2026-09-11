#include <stdio.h>
#include <stdlib.h>

// 获取数组中的最大值（用于确定最大位数）
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// 使用计数排序对数组按某一位进行排序
void countingSort(int arr[], int n, int exp) {
    int *output = (int *)malloc(n * sizeof(int)); // 存储排序后的数组
    int count[10] = {0}; // 0~9的计数数组

    // 统计当前位（exp位）的数字出现次数
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // 计算累计计数（确定每个数字的最终位置）
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // 从后往前遍历，保证排序的稳定性
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // 将排序后的数据复制回原数组
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output); // 释放临时数组
}

// 基数排序主函数
void radixSort(int arr[], int n) {
    int max = getMax(arr, n); // 获取最大值

    // 从最低位（个位）到最高位依次排序
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// 打印数组
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 测试代码
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组: \n");
    printArray(arr, n);

    radixSort(arr, n);

    printf("排序后的数组: \n");
    printArray(arr, n);

    return 0;
}