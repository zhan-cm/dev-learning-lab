#include<stdio.h>
#include<stdlib.h>

void printArray(int array[],int length){
    for(int i=0;i<length;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

void insertSort(int array[],int length){
    //外层循环，从第二个元素开始比较，比较从0-他们前一个元素之间有没有合适的位置插入
    for(int i=1;i<length;i++){
        for(int j=0;j<i;j++){
            if(array[i]<array[j]){
                int temp = array[i];
                for(int k =i-1;k>=j;k--){
                    array[k+1] = array[k];
                }
                array[j] = temp;
            }
        }
        printArray(array ,length);
    }
}

int main(){
    int array[6] = {4,3,5,1,9,6};
    printArray(array,6);
    insertSort(array,6);
    return 0;
}

/**
 * 3 4 5 1 9 6
 * 
 */