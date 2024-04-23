#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char name[50];
    int start;
    int end;
} item;

int difference(const void *item1, const void *item2) 
{
    item *first = (item *)item1;
    item *second = (item *)item2;
    return second->end - first->end;
}

int main() 
{
    item arr[] = 
    {
        {"undershorts", 11, 16},
        {"shirt", 1, 8},
        {"jacket", 3, 4},
        {"tie", 2, 5},
        {"belt", 6, 7},
        {"pants", 12, 15},
        {"socks", 17, 18},
        {"shoes", 13, 14},
        {"watch", 9, 10}
    };
  
    int size = sizeof(arr) / sizeof(item);
    qsort(arr, size, sizeof(item), difference);
    printf("Result - Topological Sort:\n");
    for(int i = 0; i < size; i++) 
        printf("%s\n", arr[i].name);
    return 0;
}
