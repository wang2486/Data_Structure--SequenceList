/**
  * @file name:SqList.h
  * @brief    :Functional interface design
  * @author   :i33akq@163.com
  * @date     :2025/04/13
  * @version  :1.0
  * @note     :none
  * @CopyRight (C)   2024-2025   i33akq@163.com   ALL Right Reseverd
*/

#ifndef SQLIST_H
#define SQLIST_H

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

/**
  * @function name: SqList_Creat
  * @brief         : Create a sequential list and initialize its control structure
  * @param         : 
  *                  @size : The total capacity of the list
  * @retval        : Pointer to the created SqList_t structure
  * @version       : 1.0
  * @note          : Memory is dynamically allocated using calloc. The program exits if allocation fails.
*/
SqList_t *SqList_Creat(unsigned int size);

/**
  * @function name: SqList_In
  * @brief         : Insert a new element at the head or tail of the sequential list
  * @param         : 
  *                  @List  : Pointer to the sequential list
  *                  @value : Value to be inserted
  * @retval        : true if insertion is successful, false otherwise
  * @version       : 1.0
  * @note          : Supports both head and tail insertion. Prompts user input to choose mode.
*/
bool SqList_In(SqList_t *List, Elemtype_t value);

/**
  * @function name: SqList_Del
  * @brief         : Delete the first occurrence of a given value from the sequential list
  * @param         : 
  *                  @List  : Pointer to the sequential list
  *                  @value : Value to be deleted
  * @retval        : true if deletion is successful, false if value not found or list is empty
  * @version       : 1.0
  * @note          : Shifts subsequent elements after deletion to maintain continuity
*/
bool SqList_Del(SqList_t *List,Elemtype_t value);

/**
  * @function name: SqList_traversal
  * @brief         : Print all valid elements in the sequential list
  * @param         : 
  *                  @List : Pointer to the sequential list
  * @retval        : None
  * @version       : 1.0
  * @note          : Outputs elements from index 0 to current end index
*/
void SqList_traversal(SqList_t *List);

/**
  * @function name: rank
  * @brief         : Sort the sequential list in ascending order using bubble sort
  * @param         : 
  *                  @List : Pointer to the sequential list to be sorted
  * @retval        : Pointer to the sorted list
  * @version       : 1.0
  * @note          : Swaps elements using arithmetic operations instead of temporary variables
*/
SqList_t *rank(SqList_t *List);

#endif