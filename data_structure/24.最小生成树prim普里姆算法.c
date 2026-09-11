#include <stdio.h>
#include <stdlib.h>

#define MAX 32727

/**
 * 顶点之前不通，那么邻接矩阵的值为MAX
 * 如果顶点是自己本身，那么值为0
 */

typedef struct Graph
{
    char *vexs; // 顶点
    int **arcs; // 边
    int vexNum; // 顶点数
    int arcNum; // 边数
} Graph;

typedef struct Edge
{
    char vex;   // 记录U集合到最小边的起始节点
    int weight; // 记录最小边
} Edge;

/**
 * 当edge.weight =0,
 * 代表顶点加入到U集合当中
 */

Edge *initEdge(Graph *G, int index)
{
    Edge *edge = (Edge *)malloc(sizeof(Edge) * G->vexNum);
    for (int i = 0; i < G->vexNum; i++)
    {
        edge[i].vex = G->vexs[index];
        edge[i].weight = G->arcs[index][i];
    }
    return edge;
}

int getMinEdge(Edge *edge, Graph *G)
{
    int index;
    int min = MAX;
    for (int i = 0; i < G->vexNum; i++)
    {
        if (edge[i].weight != 0 && min > edge[i].weight)//排除不是本身节点还有无法直接到达的点
        {
            min = edge[i].weight;
            index = i;
        }
    }
    return index;//在所有未加入生成树的顶点中，哪个顶点通过最小权边与已选顶点集（U集合）相连
}


void prim(Graph *G, int index)
{
    int min;
    Edge *edge = initEdge(G, index);
    for (int i = 0; i < G->vexNum; i++)
    {
        min = getMinEdge(edge, G);
        printf("v%c --> v%c, weight = %d\n", edge[min].vex, G->vexs[min], edge[min].weight);
        edge[min].weight = 0;
        for (int j = 0; j < G->vexNum; j++)
        {
            if (G->arcs[min][j] < edge[j].weight)//更新，其实就是现在换成下一个顶点的，这一步是更新成新顶点的边
            {
                edge[j].weight = G->arcs[min][j];
                edge[j].vex = G->vexs[min];
            }
        }
    }
}

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

void createGraph(Graph *G, char *vexs, int *arcs)
{
    for (int i = 0; i < G->vexNum; i++)
    {
        G->vexs[i] = vexs[i];
        for (int j = 0; j < G->vexNum; j++)
        {
            G->arcs[i][j] = *(arcs + i * G->vexNum + j);
            if (G->arcs[i][j] != 0 && G->arcs[i][j] != MAX)
            {
                G->arcNum++;
            }
        }
    }
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

int main()
{
    Graph *G = initGraph(5);
    int *visited = (int *)malloc(sizeof(int) * G->vexNum);
    for (int i = 0; i < G->vexNum; i++)
    {
        visited[i] = 0;
    }
    int arcs[6][6] = {
        0, 6, 1, 5, MAX, MAX,
        6, 0, 5, MAX, 3, MAX,
        1, 5, 0, 5, 6, 4,
        5, MAX, 5, 0, MAX, 2,
        MAX, 3, 6, MAX, 0, 6,
        MAX, MAX, 4, 2, 6, 0};
    createGraph(G, "123456", (int *)arcs);
    prim(G,0);
    printf("\n");
    return 0;
}