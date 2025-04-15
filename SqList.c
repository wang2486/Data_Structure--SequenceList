/**
  * @file name:SqList.c
  * @brief    :Sequence table basic function realization
  * @author   :i33akq@163.com
  * @date     :2025/04/13
  * @version  :1.0
  * @note     :none
  * @CopyRight (C)   2024-2025   i33akq@163.com   ALL Right Reseverd
*/

#include "SqList.h"

SqList_t *SqList_Creat(unsigned int size){
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
