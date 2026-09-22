/*
    斐波那契数列递归实现
*/
#include <stdio.h>


//核心思路
//用数组存储斐波那契数列
//用循环计算斐波那契数列
//返回数组中第n个元素   

int fib(int n) {
    if(n==0){return 0;}
    else if(n==1){return 1;}
    int a[n+1];
    int i=2;
    a[0]=0,a[1]=1;
    while(i<=n){
        a[i]=a[i-1]+a[i-2];
        i++;
    }
    return a[n];
}

//测试代码
int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    printf("Fibonacci series: ");
    for(int i=0;i<n;i++){
        printf("%d ",fib(i));
    }
    return 0;
}