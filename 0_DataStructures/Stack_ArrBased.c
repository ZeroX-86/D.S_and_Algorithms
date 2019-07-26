#include "Stack_ArrBased.h"


SAB_return_t SAB_stack_create(Stack_ArrBased *ptr_stack)
{
    if(ptr_stack != NULL)
    {
        ptr_stack->Stack_ArrBased_top=0;    //the top is the first empty location to use
        return SAB_NO_ERRORS;
    }
    return SAB_ERROR_FOUND;
}

SAB_return_t SAB_stack_empty(Stack_ArrBased *ptr_stack)
{
    if(ptr_stack != NULL)
    {
        if( ptr_stack->Stack_ArrBased_top == 0)
        {
            return SAB_STACK_EMPTY;
        }
        else
        {
            return SAB_STACK_NOT_EMPTY;
        }
    }
    return SAB_INVALID_ARG;
}

SAB_return_t SAB_stack_full(Stack_ArrBased *ptr_stack)
{
    if(ptr_stack != NULL)
    {
        if( ptr_stack->Stack_ArrBased_top == MAX_STACK_LENGTH)
        {
            return SAB_STACK_FULL;
        }
        else
        {
            return SAB_STACK_NOT_FULL;
        }
    }
    return SAB_INVALID_ARG;
}

uint32_t SAB_stack_size(Stack_ArrBased *ptr_stack)
{
    if(ptr_stack != NULL)
    {
        return ptr_stack->Stack_ArrBased_top;
    }
    return SAB_INVALID_ARG;
}
SAB_return_t SAB_stack_push(Stack_ArrBased *ptr_stack,STACK_ENTRY *ptr_entry)
{
    if((ptr_stack != NULL)&&(ptr_entry != NULL))
    {
        ptr_stack->entry_arr[ptr_stack->Stack_ArrBased_top]=*ptr_entry;
        ptr_stack->Stack_ArrBased_top++;
        return SAB_NO_ERRORS;
    }
    return SAB_INVALID_ARG;
}
SAB_return_t SAB_stack_pop(Stack_ArrBased *ptr_stack,STACK_ENTRY *ptr_entry)
{
    if((ptr_stack != NULL)&&(ptr_entry != NULL))
    {
        ptr_stack->Stack_ArrBased_top--;
        *ptr_entry=ptr_stack->entry_arr[ptr_stack->Stack_ArrBased_top];
        return SAB_NO_ERRORS;
    }
    return SAB_INVALID_ARG;
}

SAB_return_t SAB_stack_retrive(Stack_ArrBased *ptr_stack,STACK_ENTRY *ptr_entry)
{
    if((ptr_stack != NULL)&&(ptr_entry != NULL))
    {
        *ptr_entry=ptr_stack->entry_arr[ptr_stack->Stack_ArrBased_top-1];
        return SAB_NO_ERRORS;
    }
    return SAB_INVALID_ARG;
}
SAB_return_t SAB_stack_clear(Stack_ArrBased *ptr_stack)
{
    if(ptr_stack != NULL)
    {
        ptr_stack->Stack_ArrBased_top=0;
        return SAB_NO_ERRORS;
    }
    return SAB_INVALID_ARG;
}
SAB_return_t SAB_stack_traverse(Stack_ArrBased *ptr_stack,void(*ptr_func)(STACK_ENTRY))
{
    if((ptr_stack != NULL)&&(ptr_func != NULL))
    {
        uint32_t i=0;
        for(i=0;i<ptr_stack->Stack_ArrBased_top;i++)
        {
            (*ptr_func)(ptr_stack->entry_arr[i]);
        }
        return SAB_NO_ERRORS;
    }
    return SAB_INVALID_ARG;
}
