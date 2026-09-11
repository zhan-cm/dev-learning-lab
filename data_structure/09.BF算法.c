#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void BF(char* p,char* q){
    int plen = strlen(p);
    int qlen = strlen(q);
    for(int i=0;i<plen-qlen;i++){
        int k=i;
        int count =0;
        for(int j=0;j<qlen;j++){
            if(*(q+j)==p[k++]){
                count++;
            }
            if(count==qlen){
                printf("匹配成功");
                return;
            }
        }
    }
}