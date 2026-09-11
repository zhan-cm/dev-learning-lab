#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void GetNext(char* pattern,char* next){
    int j=0;
    next[0]=0;
    for(int i =1;pattern[i]!='\0';i++){
        while(j>0||pattern[i]!=pattern[j])
            j=next[j-1];
        if(pattern[i]==pattern[j])j++;

        next[i]=j;
    }
}

int kmp(char* text,char* pattern){
    int n = strlen(text);
    int m = strlen(pattern);

    int next[m];
    GetNext(pattern,next);

    int j=0;
    for(int i=1;i<n;i++){
        while(j>0&&text[i]!=pattern[j])
            j=next[j-1];

        if(text[i]==pattern[j])
            j++;
        
        if(j==m){
            return i-m+1;
        }
    }
    return -1;
}