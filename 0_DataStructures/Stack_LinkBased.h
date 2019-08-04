#ifndef __STACK_LINKBASED__
#define __STACK_LINKBASED__
#include "includes.h"
/*
*   SLB_ >> Stack Linked Based
*   Mahmoud Saad @ZeroX86
*/
#define MAX_STACK_LENGTH 20 //NOT IMPORTANT IN THE LINKED BASED
typedef uint8_t STACK_ENTRY;
typedef enum
{
    SLB_ERROR_FOUND,
    SLB_NO_ERRORS,
    SLB_INVALID_ARG,
    SLB_STACK_EMPTY,
    SLB_STACK_NOT_EMPTY,
    SLB_STACK_FULL,
    SLB_STACK_NOT_FULL,
    SLB_STACK_NOT_INITIALIZED,
    SLB_ERROR_CNT_MALLOC,
}SLB_return_t;

typedef struct slb_node
{
    STACK_ENTRY node_entry;
    struct slb_node *node_next;
}SLB_node;

typedef struct
{
    bool SLB_InitStatus;//may add an extra variable to define whither initialized or not
    uint32_t SLB_size;
    SLB_node *SLB_top;
}Stack_LinkBased;

SLB_return_t SLB_stack_create(Stack_LinkBased *ptr_stack);
SLB_return_t SLB_stack_empty(Stack_LinkBased *ptr_stack);
SLB_return_t SLB_stack_full(Stack_LinkBased *ptr_stack);
uint32_t     SLB_stack_size(Stack_LinkBased *ptr_stack);
SLB_return_t SLB_stack_push(Stack_LinkBased *ptr_stack,STACK_ENTRY *ptr_entry);
SLB_return_t SLB_stack_pop(Stack_LinkBased *ptr_stack,STACK_ENTRY *ptr_entry);
SLB_return_t SLB_stack_retrive(Stack_LinkBased *ptr_stack,STACK_ENTRY *ptr_entry);
SLB_return_t SLB_stack_clear(Stack_LinkBased *ptr_stack);
SLB_return_t SLB_stack_traverse(Stack_LinkBased *ptr_stack,void(*ptr_func)(STACK_ENTRY));
#endif //__STACK_LINKBASED__
