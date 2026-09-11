#include <stdio.h>
/**
 * 前提：完全二叉树
 * 
 * 大根堆：任一节点>=其左右孩子
 * 小根堆：任一节点<=其左右孩子
 * 
 * 最好从下标1开始
 * i号节点：
 * 左孩子：2i  右孩子：2i+1  父亲：|i/2|
 */

// 交换两个元素的值
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 调整堆，使其满足堆的性质
// n: 堆的大小
// i: 当前需要调整的节点下标
void heapify(int arr[], int n, int i) {
    int largest = i;        // 初始化最大元素为当前节点
    int left = 2 * i + 1;   // 左子节点
    int right = 2 * i + 2;  // 右子节点

    // 如果左子节点比当前最大节点大，则更新最大节点
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点比当前最大节点大，则更新最大节点
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大节点不是当前节点，则交换并递归调整
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// 堆排序函数
void heapSort(int arr[], int n) {
    // 构建最大堆（从最后一个非叶子节点开始）
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 逐个提取堆顶元素（最大值），放到数组末尾
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);  // 将当前最大值移到数组末尾
        heapify(arr, i, 0);       // 调整剩余元素为最大堆
    }
}

// 打印数组
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// 测试代码
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组: \n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("排序后的数组: \n");
    printArray(arr, n);

    return 0;
}