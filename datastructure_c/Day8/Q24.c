/*
        无重复字符的最长子串
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//核心思路
//用两个指针left和right，left指向当前子串的左边界，right指向当前子串的右边界
//如果当前字符s[right]不在当前子串中，则right右移，并更新max
//如果当前字符s[right]在当前子串中，则left右移，直到s[left]不再等于s[right]，然后right右移
//直到right到达字符串末尾，此时max即为最长无重复子串的长度

int lengthOfLongestSubstring(char* s) {
    int left=0,right=0,max=0;
    int len = strlen(s);
    for(int i=0;i<len;i++){
        if(left<=right){
            for(int j=left;j<right;j++){
                if(s[j]==s[right]){
                    left=j+1;
                    break;
                }
            }
        }
        max=max<(right-left+1)?(right-left+1):max;
        right++;
    }
    
    return max;
}



int main(){
    char s[]="abcabcbb";
    printf("%d\n",lengthOfLongestSubstring(s));
    return 0;
}