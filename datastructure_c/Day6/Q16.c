/*
        逆波兰表达式求值
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evalRPN(char** tokens, int tokensSize);

int main() {
    char* tokens[] = {"2", "1", "+", "3", "*"};
    int tokensSize = sizeof(tokens)/sizeof(tokens[0]);
    int result = evalRPN(tokens, tokensSize);
    printf("%d\n", result);
    return 0;
}

//思路
// 1. 遍历tokens数组，如果token是数字，则压栈；如果token是运算符，则弹出栈顶两个元素，进行运算，并将结果压栈
// 2. 最后栈顶元素即为结果。
int evalRPN(char** tokens, int tokensSize) {
    int stack[tokensSize],top=-1;
    for(int i=0;i<tokensSize;i++){
        char* s = tokens[i];
        if(strlen(s)==1&&(s[0]<'0'||s[0]>'9')){
            int a = stack[top--];
            int b = stack[top--];
            switch(s[0]){
                case '+' : stack[++top]=b+a; break;
                case '-' : stack[++top]=b-a; break;
                case '*' : stack[++top]=b*a; break;
                case '/' : stack[++top]=b/a; break;
                default: break; // error-handling
            }
        }else{
            stack[++top]=atoi(s);
        }
    }    
    return stack[top];
}