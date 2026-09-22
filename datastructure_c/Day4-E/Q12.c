/*
        多数元素
        给定一个大小为 n 的数组 nums ，返回其中的多数元素。
        多数元素是指在数组中出现次数 大于 ? n/2 ? 的元素。
*/

#include <stdio.h>
#include <stdlib.h>

//核心思路
// 1. 先设置一个flag变量，初始值为数组的第一个元素
// 2. 遍历数组，如果当前元素与flag相同，则flagnum加1，否则flagnum减1
// 3. 如果flagnum为0，则flag设置为当前元素，flagnum加1
// 4. 遍历完成后，flag即为多数元素

int majorityElement(int* nums, int numsSize) {
    int flag=nums[0];
    int flagnum=0;
    int i =0;
    while(i<numsSize){
        if(nums[i]==flag){
            flagnum++;
            i++;
        }else{
            if(flagnum==0){
                flag=nums[i];
                flagnum++;
                i++;
            }else{
                flagnum--;
                i++;
            }
        }
    }
    return flag;
}



//测试代码
int main() {
    int nums[] = {3, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = majorityElement(nums, numsSize);
    printf("The majority element is: %d\n", result);    
    return 0;
}