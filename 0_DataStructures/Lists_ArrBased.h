#ifndef __LISTS_ARRBASED__
#define __LISTS_ARRBASED__
#include "includes.h"
/*
*   LAB_ >> Lists Array Based
*   Mahmoud Saad @ZeroX86
*/
#define MAX_LIST_LENGTH 20
typedef uint8_t LIST_ENTRY;
typedef enum
{
    LAB_ERROR_FOUND,
    LAB_NO_ERRORS,
    LAB_INVALID_ARG,
    LAB_EMPTY,
    LAB_NOT_EMPTY,
    LAB_FULL,
    LAB_NOT_FULL,
    LAB_NOT_INITIALIZED,
}LAB_return_t;


typedef struct{
    LIST_ENTRY  LAB_entry_arr[MAX_LIST_LENGTH];
    uint32_t    LAB_size;
    bool        LAB_InitStatus;//may add an extra variable to define whither initialized or not
}List_ArrBased;

LAB_return_t LAB_create     (List_ArrBased *ptr_list);
LAB_return_t LAB_empty      (List_ArrBased *ptr_list);
LAB_return_t LAB_full       (List_ArrBased *ptr_list);
uint32_t     LAB_size       (List_ArrBased *ptr_list);
LAB_return_t LAB_destroy    (List_ArrBased *ptr_list);
LAB_return_t LAB_insert     (List_ArrBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position);
LAB_return_t LAB_delete     (List_ArrBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position);
LAB_return_t LAB_replace    (List_ArrBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position);
LAB_return_t LAB_retrieve   (List_ArrBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position);
LAB_return_t LAB_traverse   (List_ArrBased *ptr_list,void(*ptr_func)(LIST_ENTRY));
#endif //__LISTS_ARRBASED__
