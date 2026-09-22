/*
        2的幂
*/
#include <stdio.h>
#include <stdbool.h>

//核心思路：
// 1. 先判断n是否小于等于0，如果小于等于0，则返回false
// 2. 如果n等于1，则返回true
// 3. 如果n是奇数，则返回false
// 4. 如果n是偶数，则递归调用isPowerOfTwo(n/2)，即判断n除以2的商是否为2的幂
// 5. 如果n除以2的商是2的幂，则返回true，否则返回false
bool isPowerOfTwo(int n) {
    if(n<=0){
        return false;
    }else if(n==1){
        return true;
    }else if(n%2==1){
        return false;
    }else{
        return isPowerOfTwo(n/2);
    }
}



//测试代码
int main() 
{
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    if(isPowerOfTwo(n)){
        printf("%d is a power of 2\n",n);
    }else{
        printf("%d is not a power of 2\n",n);
    }
    return 0;
}