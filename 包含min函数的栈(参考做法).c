#include<stdio.h>
#include<stdlib.h>

//有问题，该方案是传值，S里面的参数无法改变
typedef struct MSE{
    int data;
    int min;
}MinStackElement;

typedef struct MStack{
    MinStackElement* data;
    int size;
    int top;
}MinStack;

MinStack MinStackInit(int maxSize)
{
    MinStack s;
    s.size = maxSize;
    s.data = (MinStackElement*)malloc(sizeof(MinStackElement)*maxSize);
    s.top = 0;
    return s;
}

void MinStackFree(MinStack S)
{
    free(S.data);
}

int MinStackPush(MinStack S, int d)
{
    if(S.top == S.size)
        return 1;            //out of stack space
    MinStackElement* p = &S.data[S.top];
    p->data = d;
    p->min = (S.top == 0? d : S.data[S.top-1].min);
    if(p->min > d) p->min = d;
    S.top++;
    return 0;
}

int MinStackPop(MinStack S)
{
    return S.data[--S.top].data;
}

int MinStackMin(MinStack S)
{

    return S.data[S.top-1].min;
}

main()
{
    MinStack S = MinStackInit(20);
    MinStackPush(S,10);
    printf("%d\n",S.top);
    return 0;
}
