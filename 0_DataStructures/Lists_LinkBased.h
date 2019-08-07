
#ifndef __LISTS_LINKBASED__
#define __LISTS_LINKBASED__
#include "includes.h"
/*
*   LLB_ >> Lists Linked Based
*   Mahmoud Saad @ZeroX86
*/
#define MAX_LIST_LENGTH 20 //NOT IMPORTANT IN THE LINKED BASED

typedef uint8_t LIST_ENTRY;
typedef enum
{
    LLB_ERROR_FOUND,
    LLB_NO_ERRORS,
    LLB_INVALID_ARG,
    LLB_EMPTY,
    LLB_NOT_EMPTY,
    LLB_FULL,
    LLB_NOT_FULL,
    LLB_NOT_INITIALIZED,
    LLB_ERROR_CNT_MALLOC,

}LLB_return_t;

typedef struct llb_node
{
    LIST_ENTRY node_entry;
    struct llb_node *node_next;
}LLB_node;

typedef struct{
    LLB_node *LLB_head;
    uint32_t  LLB_size;
    bool      LLB_InitStatus;
}List_LinkBased;

LLB_return_t LLB_create     (List_LinkBased *ptr_list);
LLB_return_t LLB_empty      (List_LinkBased *ptr_list);
LLB_return_t LLB_full       (List_LinkBased *ptr_list);
uint32_t     LLB_size       (List_LinkBased *ptr_list);
LLB_return_t LLB_destroy    (List_LinkBased *ptr_list);
LLB_return_t LLB_insert     (List_LinkBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position);
LLB_return_t LLB_delete     (List_LinkBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position);
LLB_return_t LLB_replace    (List_LinkBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position);
LLB_return_t LLB_retrieve   (List_LinkBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position);
LLB_return_t LLB_traverse   (List_LinkBased *ptr_list,void(*ptr_func)(LIST_ENTRY));
#endif //__LISTS_LINKBASED__
