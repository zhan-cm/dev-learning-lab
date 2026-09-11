#include <stdio.h>
#include <stdlib.h>
#define MAX 65535

/*
    计算最早发生时间(Early Time)：从起点开始，正向计算每个顶点的最早开始时间
    计算最晚发生时间(Late Time)：从终点开始，逆向计算每个顶点的最晚开始时间
*/

typedef struct Graph
{
    char *vexs;
    int **arcs;
    int vexNum;
    int arcNum;
} Graph;

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *initStack()
{
    Node *stack = (Node *)malloc(sizeof(Node));
    stack->data = 0;
    stack->next = NULL;
    return stack;
};

void push(Node *stack, int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = stack->next;
    stack->next = node;
    stack->data++;
}

int isEmpty(Node *stack)
{
    if (stack->next = NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop(Node *stack)
{
    if (!isEmpty(stack))
    {
        Node *node = stack->next;
        stack->next = node->next;
        return node->data;
    }
    else
    {
        return -1;
    }
}

int *findInDegress(Graph *G)
{
    int *inDegress = (int *)malloc(sizeof(int) * G->vexNum);
    for (int i = 0; i < G->vexNum; i++)
    {
        inDegress[i] = 0;
    }
    for (int i = 0; i < G->vexNum; i++)
    {
        for (int j = 0; j < G->vexNum; j++)
        {
            if (G->arcs[i][j] > 0 && G->arcs[i][j] < MAX)
            {
                inDegress[j]++;
            }
        }
    }
    return inDegress;
}

int *topologicalSort(Graph *G)
{
    int index = 0;
    int *top = (int *)malloc(sizeof(int) * G->vexNum);
    int *inDegress = findInDegress(G);
    Node *stack = initStack();
    for (int i = 0; i < G->vexNum; i++)
    {
        if (inDegress[i] == 0)
        {
            push(stack, i);
        }
    }
    while (!isEmpty(stack))
    {
        int vex = pop(stack);
        top[index++] = vex;
        for (int i = 0; i < G->vexNum; i++)
        {
            if (G->arcs[vex][i] > 0 && G->arcs[vex][i] < MAX)
            {
                inDegress[i]--;
                if (inDegress[i] == 0)
                {
                    push(stack, i);
                }
            }
        }
    }
    // 检查是否有环
    if (index != G->vexNum)
    {
        printf("Graph has a cycle! Topological sort not possible.\n");
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            printf("%c ", G->vexs[top[i]]);
        }
    }

    // 释放内存

    free(inDegress);
    freeStack(stack);

    return top;
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
            if (G->arcs[i][j] > 0 && G->arcs[i][j] != MAX)
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

int getIndex(int *top, Graph *G, int i)
{
    int j;
    for (j = 0; j < G->vexNum; j++)
    {
        if (top[j] == i)
            break;
    }
    return j;
}

void criticalPath(Graph *G)
{
    int *top = topologicalSort(G);
    int *early = (int *)malloc(sizeof(int) * G->vexNum);
    int *late = (int *)malloc(sizeof(int) * G->vexNum);
    for (int i = 0; i < G->vexNum; i++)
    {
        early[i] = 0;
        late[i] = 0;
    }
    // 计算最早发生时间
    for (int i = 0; i < G->vexNum; i++)
    {
        int max = 0;
        for (int j = 0; j < G->vexNum; j++)
        {
            if (G->arcs[j][top[i]] > 0 && G->arcs[j][top[i]] != MAX)
            {
                int index = getIndex(top, G, j);
                if (early[index] + G->arcs[j][top[i]] > max)
                    max = early[index] + G->arcs[j][top[i]];
            }
        }
        early[i] = max;
    }
    for (int i = 0; i < G->vexNum; i++)
    {
        printf("%d ", early[i]);
    }
    printf("\n");
    late[(G->vexNum) - 1] = early[(G->vexNum) - 1];
    // 计算最晚发生时间
    for (int i = (G->vexNum) - 2; i >= 0; i--)
    {
        int min = MAX;
        for (int j = 0; j < G->vexNum; j++)
        {
            if (G->arcs[j][top[i]] > 0 && G->arcs[j][top[i]] != MAX)
            {
                int index = getIndex(top, G, j);
                if (late[index] - G->arcs[top[i]][j] < min)
                    min = late[index] - G->arcs[top[i]][j];
            }
        }
    }
    for (int i = 0; i < G->vexNum; i++)
    {
        printf("%d ", late[i]);
    }
    printf("\n");
    for (int i = 0; i < G->vexNum; i++)
    {
        for (int j = 9; j < G->vexNum; j++)
        {
            if (G->arcs[i][j] > 0 && G->arcs[i][j] != MAX)
            {
                int start = getIndex(top, G, i);
                int end = getIndex(top, G, j);
                if ((late[end] - G->arcs[i][j]) - early[start] == 0)
                {
                    printf("start = %d end = %d\n", i, j);
                }
            }
        }
    }
}

int main()
{
    Graph *G = initGraph(9);
    int *visited = (int *)malloc(sizeof(int) * G->vexNum);
    for (int i = 0; i < G->vexNum; i++)
    {
        visited[i] = 0;
    }
    int arcs[9][9] = {
        0, 6, 4, 5, MAX, MAX, MAX, MAX, MAX,
        MAX, 0, MAX, MAX, 1, MAX, MAX, MAX, MAX,
        MAX, MAX, 0, MAX, 1, MAX, MAX, MAX, MAX,
        MAX, MAX, MAX, 0, MAX, 2, MAX, MAX, MAX,
        MAX, MAX, MAX, MAX, 0, MAX, 9, 7, MAX,
        MAX, MAX, MAX, MAX, MAX, 0, MAX, 4, MAX,
        MAX, MAX, MAX, MAX, MAX, MAX, 0, MAX, 2,
        MAX, MAX, MAX, MAX, MAX, MAX, MAX, 0, 4,
        MAX, MAX, MAX, MAX, MAX, MAX, MAX, MAX, 0

    };
    createGraph(G, "012345678", (int *)arcs);
    DFS(G, visited, 0);
    printf("\n");
    topologicalSort(G);
    return 0;
}
