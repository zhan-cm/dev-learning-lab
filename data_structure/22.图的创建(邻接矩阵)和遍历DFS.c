#include <stdio.h>
#include <stdlib.h>

typedef struct Graph
{
    char *vexs; //顶点
    int **arcs; // 边
    int vexNum; // 顶点数
    int arcNum; // 边数
} Graph;

Graph *initGraph(int vexNum)
{
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->vexs = (char *)malloc(sizeof(char) * vexNum);
    G->arcs = (int **)malloc(sizeof(int *) * vexNum);
    for (int i = 0; i < vexNum; i++)
    {
        G->arcs[i] = (int *)malloc(sizeof(int) * vexNum);
    }
    G->vexNum = vexNum;
    G->arcNum = 0;
    return G;
}

void createGraph(Graph *G,char *vexs,int *arcs){
    for(int i =0;i<G->vexNum;i++){
        G->vexs[i] = vexs[i];
        for(int j = 0;j<G->vexNum;j++){
            G->arcs[i][j] = *(arcs+i*G->vexNum+j);
            if(G->arcs[i][j]!=0){
                G->arcNum++;
            }
        }
    }
    G->arcNum/=2;
}

void DFS (Graph* G,int* visited,int index){
    printf("%c\t",G->vexs[index]);
    visited[index]=1;
    for(int i  =0;i<G->vexNum;i++){
        if(G->arcs[index][i]==1&&!visited[i]){
            DFS(G,visited,i);
        }
    }
}

int main()
{
    Graph *G = initGraph(5);
    int* visited = (int*)malloc(sizeof(int)*G->vexNum);
    for(int i =0;i<G->vexNum;i++){
        visited[i]=0;
    }
    int arcs[5][5]={
        0,1,1,1,0,
        1,0,1,1,1,
        1,1,0,0,0,
        1,1,0,0,1,
        0,1,0,1,0
    };
    createGraph(G,"ABCDE",(int*)arcs);
    DFS(G,visited,0);
    printf("\n");
    return 0;
}