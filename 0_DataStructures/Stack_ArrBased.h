#ifndef __STACK_ARRBASED__
#define __STACK_ARRBASED__
#include "includes.h"
/*
*   SAB_ >> Stack Array Based
*
*/
#define MAX_STACK_LENGTH 20
typedef uint8_t STACK_ENTRY;
typedef enum
{
    SAB_ERROR_FOUND,
    SAB_NO_ERRORS,
    SAB_INVALID_ARG,
    SAB_STACK_EMPTY,
    SAB_STACK_NOT_EMPTY,
    SAB_STACK_FULL,
    SAB_STACK_NOT_FULL,

}SAB_return_t;

typedef struct{
    STACK_ENTRY entry_arr[MAX_STACK_LENGTH];
    uint32_t    Stack_ArrBased_top;
    //may add an extra variable to define whither initialized or not
}Stack_ArrBased;


SAB_return_t SAB_stack_create(Stack_ArrBased *ptr_stack);
SAB_return_t SAB_stack_empty(Stack_ArrBased *ptr_stack);
SAB_return_t SAB_stack_full(Stack_ArrBased *ptr_stack);
uint32_t SAB_stack_size(Stack_ArrBased *ptr_stack);
SAB_return_t SAB_stack_push(Stack_ArrBased *ptr_stack,STACK_ENTRY *ptr_entry);
SAB_return_t SAB_stack_pop(Stack_ArrBased *ptr_stack,STACK_ENTRY *ptr_entry);
SAB_return_t SAB_stack_retrive(Stack_ArrBased *ptr_stack,STACK_ENTRY *ptr_entry);
SAB_return_t SAB_stack_clear(Stack_ArrBased *ptr_stack);
SAB_return_t SAB_stack_traverse(Stack_ArrBased *ptr_stack,void(*ptr_func)(STACK_ENTRY));
#endif //__STACK_ARRBASED__
