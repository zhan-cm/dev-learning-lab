
//花了好久才学会，woc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GetNext(const char* pattern, int* next) {
    int j = 0;
    next[0] = 0;  // 第一个位置永远是0
    for (int i = 1; pattern[i] != '\0'; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1];  // 回退
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        next[i] = j;
    }
}

int KMP(const char* text, const char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    if (m == 0) return 0;  // 空模式串

    int next[m];
    GetNext(pattern, next);

    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = next[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) {
            return i - m + 1;  // 返回匹配起始位置
        }
    }
    return -1;  // 未匹配到
}

//test
int main() {
    const char *text = "ABABDABACDABABCABAB";
    const char *pattern = "ABABCABAB";
    
    int pos = kmpSearch(text, pattern);
    
    if (pos != -1) {
        printf("Pattern found at index: %d\n", pos);
        printf("Matched substring: %.*s\n", (int)strlen(pattern), text + pos);
    } else {
        printf("Pattern not found.\n");
    }
    
    return 0;
}
