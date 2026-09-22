/*
        BF算法
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//BF算法
//p为主串，q为模式串
//BF(p,q)
//BF算法的基本思想是，从主串的起始位置开始，逐个与模式串的每个字符进行匹配，如果匹配成功，则继续匹配下一个字符，直到模式串的末尾。如果匹配失败，则主串的下一个位置开始继续匹配。
//BF算法的时间复杂度为O(nm)，n为主串的长度，m为模式串的长度。

void BF(char* p,char* q){
	int plen=strlen(p);
	int qlen=strlen(q);
	if(qlen>plen){
		printf("输入的字符串长度有误,请重新输入");
		return;
	}

	for(int i=0;i<plen-qlen;i++){
		int k=i;
		int count=0;
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
int main(){
	char* p="aabaabaaf";
	char* q="aabaaf";
	BF(p,q);
	return 0;
}