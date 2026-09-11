void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // 每次遍历后，最大的元素会"冒泡"到最后
        for (int j = 0; j < n - i - 1; j++) {
            // 如果前一个元素比后一个大，则交换它们
            if (arr[j] > arr[j + 1]) {
                // 交换元素
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}