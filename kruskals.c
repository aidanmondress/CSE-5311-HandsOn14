#include <stdio.h>
#include <stdlib.h>

typedef struct edge 
{
    int u;
    int v;
    int w;
} edge;

typedef struct edgeList 
{
    edge data[20];
    int size;
} edgeList;

edgeList el;
int size = 9;
int parent[size];
char vertices[size] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
int cost_mat[size][size] = 
{
    //a  b  c  d  e  f  g  h  i
     {0, 4, 0, 0, 0, 0, 0, 8, 0},
     {4, 0, 8, 0, 0, 0, 0, 11, 0},
     {0, 8, 0, 7, 0, 4, 0, 0, 2},
     {0, 0, 7, 0, 9, 14, 0, 0, 0},
     {0, 0, 0, 9, 0, 10, 0, 0, 0},
     {0, 0, 4, 14, 10, 0, 2, 0, 0},
     {0, 0, 0, 0, 0, 2, 0, 1, 6},
     {8, 0, 0, 0, 0, 0, 1, 0, 7},
     {0, 0, 2, 0, 0, 0, 6, 7, 0}
};

int find(int x) 
{
    while(parent[x] != x)
        x = parent[x];
    return x;
}

void kruskal() {
    int i, j, u, v;
    el.size = 0;
    for(i = 0; i < size; i++) 
    {
        for(j = 0; j < size; j++) 
        {
            if(cost_mat[i][j] != 0) 
            {
                el.data[el.size].u = i;
                el.data[el.size].v = j;
                el.data[el.size].w = cost_mat[i][j];
                el.size = el.size + 1;
            }
        }
    }
    int x, y;
    edge temp;
    for(x = 1; x < el.size; x++)
    {
        for(y = 0; y < el.size - 1; y++) 
        {
            if(el.data[y].w > el.data[y + 1].w) 
            {
                temp = el.data[y];
                el.data[y] = el.data[y + 1];
                el.data[y + 1] = temp;
            }
        }
    }
    for (i = 0; i < size; i++)
        parent[i] = i;
  
    printf("\nMinimum Cost Spanning Tree:\n");
    for (i = 0; i < el.size; i++) 
    {
        u = find(el.data[i].u);
        v = find(el.data[i].v);
        if (u != v) 
        {
            parent[u] = v;
            printf("\n%c -> %c = %d", vertices[el.data[i].u], vertices[el.data[i].v], el.data[i].w);
        }
    }
}

void main()
{
  kruskal();
}
