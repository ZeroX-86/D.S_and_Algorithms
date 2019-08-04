#include "Stack_LinkBased.h"

SLB_return_t SLB_stack_create(Stack_LinkBased *ptr_stack)
{
    if(ptr_stack != NULL)
    {
        ptr_stack->SLB_top=NULL;
        ptr_stack->SLB_InitStatus=true;
        ptr_stack->SLB_size=0;
        return SLB_NO_ERRORS;
    }
    return SLB_INVALID_ARG;
}
SLB_return_t SLB_stack_empty(Stack_LinkBased *ptr_stack)
{
    if(ptr_stack != NULL)
    {
        if(ptr_stack->SLB_InitStatus == true)
        {
            if((ptr_stack->SLB_top == NULL) || (ptr_stack->SLB_size == 0))
            {
                return SLB_STACK_EMPTY;
            }
            else
            {
                return SLB_STACK_NOT_EMPTY;
            }
        }
        else
        {
            return SLB_STACK_NOT_INITIALIZED;
        }
    }
    return SLB_INVALID_ARG;
}
SLB_return_t SLB_stack_full(Stack_LinkBased *ptr_stack)
{
    if(ptr_stack != NULL)
    {
        if(ptr_stack->SLB_InitStatus == true)
        {
            return SLB_STACK_NOT_FULL;
        }
        else
        {
            return SLB_STACK_NOT_INITIALIZED;
        }
    }
    return SLB_INVALID_ARG;
}
uint32_t SLB_stack_size(Stack_LinkBased *ptr_stack)
{
    if(ptr_stack != NULL)
    {
        if(ptr_stack->SLB_InitStatus == true)
        {
            return ptr_stack->SLB_size;
        }
        else
        {
            return SLB_STACK_NOT_INITIALIZED;
        }
    }
    return SLB_INVALID_ARG;
}
SLB_return_t SLB_stack_push(Stack_LinkBased *ptr_stack,STACK_ENTRY *ptr_entry)
{
    if((ptr_stack != NULL)&&(ptr_entry != NULL))
    {
        if(ptr_stack->SLB_InitStatus == true)
        {
            SLB_node *ptr_node=(SLB_node *)malloc(sizeof(SLB_node));
            if(ptr_node != NULL)
            {
                ptr_node->node_entry=*ptr_entry;
                ptr_node->node_next=ptr_stack->SLB_top;
                ptr_stack->SLB_top=ptr_node;
                ptr_stack->SLB_size++;
                return SLB_NO_ERRORS;
            }
            return SLB_ERROR_CNT_MALLOC;
        }
        else
        {
            return SLB_STACK_NOT_INITIALIZED;
        }
    }
    return SLB_INVALID_ARG;
}
SLB_return_t SLB_stack_pop(Stack_LinkBased *ptr_stack,STACK_ENTRY *ptr_entry)
{
    if((ptr_stack != NULL)&&(ptr_entry != NULL))
    {
        if(ptr_stack->SLB_InitStatus == true)
        {
            SLB_node*ptr_temp=ptr_stack->SLB_top;
            *ptr_entry=ptr_stack->SLB_top->node_entry;
            ptr_stack->SLB_top=ptr_stack->SLB_top->node_next;
            free(ptr_temp);
            ptr_stack->SLB_size--;
        }
        else
        {
            return SLB_STACK_NOT_INITIALIZED;
        }
    }
    return SLB_INVALID_ARG;
}
SLB_return_t SLB_stack_retrive(Stack_LinkBased *ptr_stack,STACK_ENTRY *ptr_entry)
{
    if((ptr_stack != NULL)&&(ptr_entry != NULL))
    {
        if(ptr_stack->SLB_InitStatus == true)
        {
            *ptr_entry=ptr_stack->SLB_top->node_entry;
        }
        else
        {
            return SLB_STACK_NOT_INITIALIZED;
        }
    }
    return SLB_INVALID_ARG;
}
SLB_return_t SLB_stack_clear(Stack_LinkBased *ptr_stack)
{
    if(ptr_stack != NULL)
    {
        if(ptr_stack->SLB_InitStatus == true)
        {
            SLB_node*ptr_temp;
            while((ptr_temp != NULL) && (ptr_stack->SLB_top != NULL))
            {
                ptr_temp=ptr_stack->SLB_top;
                ptr_stack->SLB_top=ptr_temp->node_next;
                free(ptr_temp);
            }
            ptr_stack->SLB_size=0;
            return SLB_NO_ERRORS;
        }
        else
        {
            return SLB_STACK_NOT_INITIALIZED;
        }
    }
    return SLB_INVALID_ARG;
}
SLB_return_t SLB_stack_traverse(Stack_LinkBased *ptr_stack,void(*ptr_func)(STACK_ENTRY))
{
    if(ptr_stack != NULL)
    {
        if(ptr_stack->SLB_InitStatus == true)
        {
            SLB_node*ptr_temp=ptr_stack->SLB_top;
            while(ptr_temp != NULL)
            {
                (*ptr_func)(ptr_temp->node_entry);
                ptr_temp=ptr_temp->node_next;
            }
        }
        else
        {
            return SLB_STACK_NOT_INITIALIZED;
        }
    }
    return SLB_INVALID_ARG;
}
/////////////////////////////////////////////////////done
