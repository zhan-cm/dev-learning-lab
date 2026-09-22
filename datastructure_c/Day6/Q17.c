/*
        移除无效括号
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

//思路：
// 1. 遍历字符串，遇到左括号入栈，遇到右括号出栈，如果栈为空，则说明无效括号
// 2. 遍历字符串，遇到左括号入栈，遇到右括号出栈，如果栈不为空，则说明有效括号
// 3. 遍历字符串，遇到有效括号，则跳过，遇到无效括号，则替换为空格  
// 4. 最后返回字符串

char *minRemoveToMakeValid(char * s)
{
    int stack_left = 0;
    int stack_right = 0;
    int right_count = 0;
    int s_len = 0;
    int size = 0;
    char *str = s;

    while (*str != '\0') {
        right_count += (*str == ')');
        s_len++;
        str++;
    }

    for (int i = 0; i < s_len; i++) {
		if (s[i] == '(') {
			if (stack_left + 1 > stack_right + right_count) {
                continue;
            }
            stack_left++;
        } else if (s[i] == ')') {
            right_count--;
            if (stack_left <= stack_right) {
                continue;
            } 
            stack_right++;
        }
        s[size++] = s[i];
    }
    s[size] = '\0';
    return s;
}



int main()
{
    char s[] = "())()((()";
    char *result = minRemoveToMakeValid(s);
    printf("%s\n", result);
    return 0;
}