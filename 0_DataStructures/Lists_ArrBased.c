#include "Lists_ArrBased.h"


LAB_return_t LAB_create (List_ArrBased *ptr_list)
{
    if(ptr_list != NULL)
    {
        ptr_list->LAB_InitStatus=true;
        ptr_list->LAB_size=0;
        return LAB_NO_ERRORS;
    }
    return LAB_INVALID_ARG;
}
LAB_return_t LAB_empty (List_ArrBased *ptr_list)
{
    if(ptr_list != NULL)
    {
        if(ptr_list->LAB_InitStatus == true)
        {
            if(ptr_list->LAB_size == 0)
                return LAB_EMPTY;
            return LAB_NOT_EMPTY;
        }
        return LAB_NOT_INITIALIZED;
    }
    return LAB_INVALID_ARG;
}
LAB_return_t LAB_full (List_ArrBased *ptr_list)
{
    if(ptr_list != NULL)
    {
        if(ptr_list->LAB_InitStatus == true)
        {
            if(ptr_list->LAB_size >= MAX_LIST_LENGTH)
                return LAB_FULL;
            return LAB_NOT_FULL;
        }
        return LAB_NOT_INITIALIZED;
    }
    return LAB_INVALID_ARG;
}
uint32_t     LAB_size (List_ArrBased *ptr_list)
{
    if(ptr_list != NULL)
    {
        if(ptr_list->LAB_InitStatus == true)
        {
            return ptr_list->LAB_size;
        }
        return LAB_NOT_INITIALIZED;
    }
    return LAB_INVALID_ARG;
}
LAB_return_t LAB_destroy (List_ArrBased *ptr_list)
{
    if(ptr_list != NULL)
    {
        ptr_list->LAB_InitStatus=false;
        ptr_list->LAB_size=0;
        return LAB_NO_ERRORS;
    }
    return LAB_INVALID_ARG;
}
LAB_return_t LAB_insert (List_ArrBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position)
{
    if((ptr_list != NULL)||(position > ptr_list->LAB_size))
    {
        if(ptr_list->LAB_InitStatus == true)
        {
            uint32_t i;
            for(i=ptr_list->LAB_size;i >= position;i--)
            {
                ptr_list->LAB_entry_arr[i]=ptr_list->LAB_entry_arr[i-1];
            }
            ptr_list->LAB_entry_arr[position]=*ptr_entry;
            ptr_list->LAB_size++;
        }
        return LAB_NOT_INITIALIZED;
    }
    return LAB_INVALID_ARG;
}
LAB_return_t LAB_delete (List_ArrBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position)
{
    if((ptr_list != NULL)||(position > ptr_list->LAB_size-1))
    {
        if(ptr_list->LAB_InitStatus == true)
        {
            *ptr_entry=ptr_list->LAB_entry_arr[position];
            uint32_t i;
            for(i=position;i < ptr_list->LAB_size-1;i++)
            {
                ptr_list->LAB_entry_arr[i] = ptr_list->LAB_entry_arr[i+1];
            }
            ptr_list->LAB_size--;
        }
        return LAB_NOT_INITIALIZED;
    }
    return LAB_INVALID_ARG;
}
LAB_return_t LAB_replace (List_ArrBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position)
{
    if((ptr_list != NULL)||(position > ptr_list->LAB_size-1))
    {
        if(ptr_list->LAB_InitStatus == true)
        {
            ptr_list->LAB_entry_arr[position]=*ptr_entry;
        }
        return LAB_NOT_INITIALIZED;
    }
    return LAB_INVALID_ARG;
}
LAB_return_t LAB_retrieve (List_ArrBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position)
{
    if((ptr_list != NULL)||(position > ptr_list->LAB_size-1))
    {
        if(ptr_list->LAB_InitStatus == true)
        {
            *ptr_entry=ptr_list->LAB_entry_arr[position];
            return LAB_NO_ERRORS;
        }
        return LAB_NOT_INITIALIZED;
    }
    return LAB_INVALID_ARG;
}
LAB_return_t LAB_traverse (List_ArrBased *ptr_list,void(*ptr_func)(LIST_ENTRY))
{
    if((ptr_list != NULL)&&(ptr_func != NULL))
    {
        if(ptr_list->LAB_InitStatus == true)
        {
            uint32_t i;
            for(i=0;i < ptr_list->LAB_size;i++)
            {
                (*ptr_func)(ptr_list->LAB_entry_arr[i]);
            }
        }
        return LAB_NOT_INITIALIZED;
    }
    return LAB_INVALID_ARG;
}
