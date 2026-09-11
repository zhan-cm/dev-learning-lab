#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int weight;
    int parent;
    int lchild;
    int rchild;
}TreeNode;

typedef struct HFTree{
    TreeNode* data;
    int length;
}HFTree;

HFTree* initTree(int* weight,int length){
    HFTree* T = (HFTree*)malloc(sizeof(HFTree));
    T->data=(TreeNode*)malloc(sizeof(TreeNode)*(2*length-1));
    T->length=length;
    for(int i=0;i<length;i++){
        T->data[i].weight=weight[i];
        T->data[i].parent=0;
        T->data[i].lchild=-1;
        T->data[i].rchild=-1;
    }
    return T;
}

int* selectMin(HFTree* T){
    int min1,min2=10000;
    int index1,index2;
    for(int i =0;i<T->length;i++){
        if(T->data[i].parent==0){
            if(T->data[i].weight<min1){
                min1= T->data[i].weight;
                index1 = i;
            }
        }
    }
    for(int i =0;i<T->length;i++){
        if(T->data[i].parent==0&&i!=index1){
            if(T->data[i].weight<min2){
                min2= T->data[i].weight;
                index2 = i;
            }
        }
    }
    int* res = (int*)malloc(sizeof(int)*2);
    res[0]=index1,res[1]=index2;
    return res;
}

void createHFTree(HFTree* T){
    int* res;
    int min1,min2;
    int length = T->length*2-1;
    for(int i = T->length;i<length;i++){
        res = selectMin(T);
        min1 = res[0];
        min2 = res[1];
        T->data[i].weight = T->data[min1].weight+T->data[min2].weight;
        T->data[i].lchild = min1;
        T->data[i].rchild = min2;
        T->data[min1].parent = i;
        T->data[min2].parent = i;
        T->length++;
    }
}

void preOrder(HFTree* T,int index){
    if(index!=-1){
        printf("%d ",T->data[index].weight);
        preOrder(T,T->data[index].lchild);
        preOrder(T,T->data[index].rchild);
    }
}

int main(){
    int weight[4] = {1,2,3,4};
    HFTree* T = initTree(weight,4);
    createHFTree(T);
    preOrder(T,T->length-1);
    printf("\n");
    return 0;
}