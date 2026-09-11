#include<stdio.h>
void printArray(int array[],int length){
    for(int i=0;i<length;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

int partition(int array[], int i, int j) {
    int x = array[i];  // 选择第一个元素作为基准(pivot)
    while(i < j) {
        // 从右向左找第一个小于x的元素
        while(i < j && array[j] >= x) {
            j--;
        }
        if(i < j) {
            array[i] = array[j];  // 将小于x的元素放到左边
            i++;
        }
        
        // 从左向右找第一个大于等于x的元素
        while(i < j && array[i] < x) {
            i++;
        }
        if(i < j) {
            array[j] = array[i];  // 将大于等于x的元素放到右边
            j--;
        }
    }
    array[i] = x;  // 将基准值放入正确位置
    return i;      // 返回基准值的位置
}

void quickSort(int array[], int i, int j) {
    if(i < j) {  // 递归终止条件：子数组长度大于1
        int index = partition(array, i, j);  // 分区并获取基准位置
        quickSort(array, i, index-1);       // 递归排序左半部分
        quickSort(array, index+1, j);       // 递归排序右半部分
    }
}

int main(){
    int array[8] = {27,38,13,49,76,97,65,49};
    quickSort(array,0,7);
    printArray(array,8);
    return 0;
}