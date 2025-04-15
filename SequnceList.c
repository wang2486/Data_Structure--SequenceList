/**
  * @file name:SequnceList.h
  * @brief    :Function test
  * @author   :i33akq@163.com
  * @date     :2025/04/13
  * @version  :1.0
  * @note     :none
  * @CopyRight (C)   2024-2025   i33akq@163.com   ALL Right Reseverd
*/

#include "SqList.h"
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


	//SqList_Del(List,5);
    //printf("\n");
	//SqList_Del(List,0);
    //SqList_traversal(List);
    return 0;    
}