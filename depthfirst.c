#include <stdio.h>
#include <stdlib.h>

void depthfirst(int i, int adj_mat[][9], int checked[], char *names[]) 
{
    int j;
    checked[i] = 1;
    for(j = 0; j < 9; j++) 
    {
        if(checked[j] == 0 && adj_mat[i][j] == 1) 
            depthfirst(j, adj, checked, names);
    }
}

int main() 
{
    char *names[9] = {"undershorts", "shirt", "jacket", "tie", "belt", "pants", "socks", "shoes", "watch"};
    int checked[9] = {0};
    int i;
    int adj_mat[9][9] = 
    {
        {0, 0, 0, 0, 1, 0, 0, 1, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
  
    printf("DFS search result: ");
    for(i = 0; i < 9; i++) 
    {
        if(checked[i] == 0) 
            depthfirst(i, adj_mat, checked, names);
    }
    return 0;
}
