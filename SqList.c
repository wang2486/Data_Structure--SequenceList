/******************************************************************************
 * 
 *  file name: SqList.c
 *  author   : w6661888@google.com
 *  date     : 2025/4/6
 *  function : SqList
 *  note     : null
 * 
 * 
 *  Copyright (C) 2025  w6661888@google.com  ALL rights reserved.
 * 
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef int Elemtype_t;//Custom data types

typedef struct SqList
{
    unsigned int size;
    Elemtype_t *start;
    int end;
}SqList_t;

SqList_t *SqList_Creat(int size){
    //控表
    SqList_t *List=(SqList_t *)calloc(1,sizeof(List));
    if(NULL==List)
    {
        perror("calloc false");
        exit(-1);
    }

    //为所有元素申请堆内存
    List->start = (Elemtype_t *)calloc(size,sizeof(Elemtype_t));
    if(List->start == NULL)
    {
        printf("calloc false");
        free(List);
        exit(-1);
    }
    //init
    List->end = -1;
    List->size=size;

    return  List;
}

bool SqList_In(SqList_t *List, Elemtype_t value){
    // Full judgment
    if (List->end == List->size - 1) // Correct condition for full list
    {
        printf("Sequential full\n");
        return false;
    }
    #define HEAD 1
    #define TAIL 2
    int mod;
    printf("Choose head (1) or tail (2) insert: ");
    if (scanf("%d", &mod) != 1) // Correct format specifier and input validation
    {
        printf("Invalid input\n");
        return false;
    }
    switch (mod)
    {
    case HEAD: // Head insert
        for (int i = List->end; i >= 0; i--) // Correct loop condition for shifting elements
        {
            List->start[i + 1] = List->start[i];
        }
        // Add new element to the head and update end index
        List->start[0] = value;
        List->end++;
        break;
    case TAIL: // Tail insert
        List->start[++List->end] = value;
        break;
    default:
        printf("Invalid choice\n");
        return false;
    }

    return true;
}

bool SqList_Del(SqList_t *List,Elemtype_t value){
    int temp=-1;
    //Empty judgment
    if(-1==List->end)
    {
        printf("Sequential empty");
        return false;
    }
    for(int i=0;i<=List->end;i++)
    {
        if(value==List->start[i])
        {
            temp=i;
            break;
        }
    }
    if(-1==temp)
    {
        printf("no found");
        return false;
    }
    for(int i=temp;i<List->end;i++)
    {
        List->start[i]=List->start[i+1];
    }
    //由于删除了一个元素，则需要让顺序表的有效元素下标-1
	List->end--;
    return true;
}

void SqList_traversal(SqList_t *List){
    for(int i=0;i<=List->end;i++)
    {
        printf("%d ",List->start[i]);
    }
}


SqList_t *rank(SqList_t *List){
    //每次循环都把一个最大的数放在最终位置（冒泡排序）
    for(int i=0;i<=List->end;i++)
    {
        for(int j=0;j<(List->end - i);j++)
        {
            if(List->start[j]>List->start[j+1])
            {
                List->start[j]=List->start[j]+List->start[j+1];
                List->start[j+1]=List->start[j]-List->start[j+1];
                List->start[j]=List->start[j]-List->start[j+1];
            }
        }
    }
    return List;
}

SqList_t *bishiti1(SqList_t *List,int x){
    SqList_In(List,x);
    rank(List);
}

int bishiti2(SqList_t *List,int p){
    if(p>List->end)
    {
        printf("out of range");
        return 0;
    }
    int e=List->start[p];
    for(int i=p;i<List->end;i++)
    {
        List->start[i]=List->start[i+1];
    }
    List->end--;
    return 1;
}


int main(int argc, char const *argv[])
{
    SqList_t *List=SqList_Creat(10);
    SqList_In(List,0);
    SqList_In(List,1);
    SqList_In(List,2);
    SqList_In(List,3);
    SqList_In(List,5);
    SqList_traversal(List);
    printf("\n");

    rank(List);
    SqList_traversal(List);
    bishiti1(List,4);
    SqList_traversal(List);

    //bishiti2(List,0);
    //SqList_traversal(List);

	//SqList_Del(List,5);
    //printf("\n");
	//SqList_Del(List,0);
    //SqList_traversal(List);    
}