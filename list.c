#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define ElementType int

typedef struct 
{
    ElementType data[MAXSIZE];
    int last;
} List;


List * MakeEmpty()
{
    List* ptrL = (List *)malloc(sizeof(List));
    ptrL->last = -1;
    return ptrL;
}

int Find(List* ptrL, ElementType x)
{
    int i = 0;

    while(i <= ptrL->last && ptrL->data[i] != x)
        i++;
    
    if (i > ptrL->last)
        return -1;
    else
        return i;
    
}

int Insert(List * ptrL, int i, ElementType x)
{
    //判断是否表满
    
    if (ptrL->last == MAXSIZE - 1) {
        printf("表满\n");
        return -1;
    }
    //判断位置是否合法
    if (i < 1 || i > ptrL->last + 2) {
        printf("位置不合法\n");
        return -1;
    }

    
    for(int j = ptrL->last; j >= i-1; j--)
        ptrL->data[j+1] = ptrL->data[j];
    
    ptrL->data[i-1] = x;
    ptrL->last++;
    return i;
}

int Delete(List * ptrL, int i)
{
    if (i < 1 || i > ptrL->last + 1) {
        printf("不存在位置为%d的元素\n", i);
        return -1;
    }

    for(int j = i -1; j < ptrL->last;j++)
        ptrL->data[j] = ptrL->data[j+1];

    ptrL->last--;
    return i;
}

int main()
{
    List * ptrL = MakeEmpty();

    int rs1 = Insert(ptrL, 1000, 10);

    int rs2 = Insert(ptrL, 1, 20);

    printf("rs1=%d, rs2=%d, list->last=%d\n", rs1, rs2, ptrL->last);

    Delete(ptrL, 10);

    Delete(ptrL, 1);

    printf("list->last=%d\n", ptrL->last);

    return 0;
}