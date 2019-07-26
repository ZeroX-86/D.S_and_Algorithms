#include "includes.h"
//revisiting the data-structures course
int main()
{
    uint8_t temp1=50,temp2=0;
    Stack_ArrBased MStack;
    SAB_stack_create(&MStack);
    printf("empty is %d\n",SAB_stack_empty(&MStack) == SAB_STACK_EMPTY);
    printf("full is %d\n",SAB_stack_full(&MStack) == SAB_STACK_NOT_FULL);
    SAB_stack_push(&MStack,&temp1);
    SAB_stack_pop(&MStack,&temp2);
    printf("temp2 now = %d\n",temp2);
    return 0;
}
