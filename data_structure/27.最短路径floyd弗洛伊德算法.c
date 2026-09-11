#include <stdio.h>
#include <stdlib.h>
#define MAX 32767
/**
 * d数组：保存了两点的最短路径长度
 * p数组：保存了两点之前最短路径的前驱
 */

// 核心：试探法。通过加入不同的点进行中转，选择出最优解

typedef struct Graph
{
    int *vexs;
    int **arcs;
    int vexNum;
    int acrNum;
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
    G->acrNum = 0;
    return G;
}

void createGraph(Graph *G, char *vexs, int *arcs)
{
    for (int i = 0; i < G->vexNum; i++)
    {
        G->vexs[i] = vexs[i];
        for (int j = 0; j < G->vexNum; j++)
        {
            G->arcs[i][j] = *(arcs + i * G->vexNum + j);
            if (G->arcs[i][j] > 0 && G->arcs[i][j] != MAX)
            {
                G->acrNum++;
            }
        }
    }
    G->acrNum /= 2;
}

void DFS(Graph *G, int *visited, int index)
{
    printf("%c\t", G->vexs[index]);
    visited[index] = 1;
    for (int i = 0; i < G->vexNum; i++)
    {
        if (G->arcs[index][i] > 0 && G->arcs[index][i] != MAX && !visited[i])
        {
            DFS(G, visited, i);
        }
    }
}

void floyd(Graph *G)
{
    int d[G->vexNum][G->vexNum];
    int p[G->vexNum][G->vexNum];
    for (int i = 0; i < G->vexNum; i++)
    {
        for (int j = 0; j < G->vexNum; j++)
        {
            d[i][j] = G->arcs[i][j];
            if (G->arcs[i][j] > 0 && G->arcs[i][j] != MAX)
            {
                p[i][j] = i; // 初始化前驱
            }
            else
            {
                p[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < G->vexNum; i++)
    { // 中间点 i
        for (int j = 0; j < G->vexNum; j++)
        { // 起点 j
            for (int k = 0; k < G->vexNum; k++)
            { // 终点 k
                if (d[j][i] + d[i][k] < d[j][k])
                {
                    d[j][k] = d[j][i] + d[i][k]; // 更新最短距离
                    p[j][k] = p[i][k];           // 更新前驱节点
                }
            }
        }
    }

    for (int i = 0; i < G->vexNum; i++)
    {
        for (int j = 0; j < G->vexNum; j++)
        {
            printf("%d", d[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < G->vexNum; i++)
    {
        for (int j = 0; j < G->vexNum; j++)
        {
            printf("%d", p[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    Graph *G = initGraph(4);
    int *visited = (int *)malloc(sizeof(int) * G->vexNum);
    for (int i = 0; i < G->vexNum; i++)
    {
        visited[i] = 0;
    }
    int arcs[4][4] = {
        0, 1, MAX, 3,
        1, 0, 2, 2,
        MAX, 2, 0, 8,
        3, 2, 8, 0};
    createGraph(G, "1234", (int *)arcs);
    DFS(G, visited, 0);
    printf("\n");
    floyd(G);
    return 0;
}