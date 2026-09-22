/*
        验证回文串
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isPalindrome(char* s) {
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        if (!isalnum(s[i])) {
            i++;
        } else if (!isalnum(s[j])) {
            j--;
        } else if (tolower(s[i]) == tolower(s[j])) {
            i++;
            j--;
        } else {
            return false;
        }
    }
    return true;
}
int main() {
    char s[100];
    printf("Enter a string: ");
    fgets(s, 100, stdin);
    s[strcspn(s, "\n")] = '\0';
    if (isPalindrome(s)) {
        printf("%s is a palindrome.\n", s);
    } else {
        printf("%s is not a palindrome.\n", s);
    }
    return 0;
}