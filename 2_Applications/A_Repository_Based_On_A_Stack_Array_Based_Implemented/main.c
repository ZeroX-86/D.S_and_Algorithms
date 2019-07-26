#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 10
//typedef int StackEntry;
#define StackEntry int
typedef struct stac
{
    int Top;
    StackEntry entry[MAXSTACK];
}Stack;

void CreateStack(Stack *ps);
void ClearStack(Stack *ps);
int StackSize(Stack *ps);
void StackTop(Stack *ps,StackEntry *pe);
void PushToStack(Stack *ps,StackEntry *pe);
void TraverseStack(Stack *ps,void (*pf)(StackEntry));
void Display(StackEntry e);
void Pop4mStack(Stack *ps,StackEntry *pe);
int StackFull(Stack *ps);
int StackEmpty(Stack *ps);
int StackAvailable(Stack *ps);
int main(void)
{
    int q1=0;
    Stack s;
    CreateStack(&s);
    StackEntry e;
    int temp;
    while(1)
        {
        printf(">>wanna status(press 0),store(press 1) or retrieve(press 2)??\n>>");
        scanf("%d",&q1);
                while((q1 != 0) && (q1 != 1) && (q1 != 2)) //the user have only two options,to exit or to proceed :D :P
                    scanf("%d",&q1);

        if(q1 == 0)
            {
                printf("\n**********************\n");
                printf(">>ok here is the status of our stack :D\n");
                printf(">>in the stack we have>> %d elements \n",StackSize(&s));
                if(StackEmpty(&s))
                    printf(">>the latest element stored is NULL,We Have No Data yet D:\n");
                else
                {
                    StackTop(&s,&e);
                    printf(">>the latest element stored is %d\n",e);

                }
                printf(">>thank you :D\n**********************\n");
            }
        else if(q1 == 1)
        {
            printf("\n**********************\n");
push :      printf(">>ok u wanna add data :D\n>>please notice that there are only %d places available to store in\n",StackAvailable(&s));


            if(!StackFull(&s))
               {
PushNow :       printf(">>put data u wanna save\n>>");
                fflush(stdin);
                scanf("%d",&e);
                PushToStack(&s,&e);
               }
            else
            {
                printf("\n**********************\n");
                printf(">>ooops!!!sorry,stack is full!!!\n>>so,u have to pop at least one element!.\n>>so proceed to pop then push(press 1) or exit(press 0)?\n>>");
                scanf("%d",&temp);
                while((temp != 0) && (temp != 1)) //the user have only two options,to exit or to proceed :D :P
                    scanf("%d",&temp);
                if(temp == 0)
                {
                    continue;
                }
                else if(temp == 1)
                {   static int ee=0;
PopMore :           Pop4mStack(&s,&ee);
                    printf(">>here u are %d\n",ee);
                    printf(">>pop more(press 0) or proceed to push(press 1)?\n>>");
                    scanf("%d",&temp);
                while((temp != 0) && (temp != 1)) //the user have only two options,to exit or to proceed :D :P
                    scanf("%d",&temp);
                if(temp == 0)
                {
                    goto PopMore;
                }
                else
                {
                    goto PushNow;
                }
                }
            }
            printf(">>add more(press 0) or enough(press 1) ?\n>>");
            scanf("%d",&temp);
                while((temp != 0) && (temp != 1)) //the user have only two options,to exit or to proceed :D :P
                    scanf("%d",&temp);
                if(temp == 0)
                {
                    goto push;
                }
                else
                {
                    goto thanku;
                }
                printf("\n**********************\n");
                }
        else if(q1==2)
            {
             printf(">>ok,welcome sir,u wanna take some data\n");
pop :        if(!StackEmpty(&s))
             {
                 static int ee;
                 Pop4mStack(&s,&ee);
                 printf(">>here u are %d \n",ee);
             }
             else
             {
                printf(">>sorry,stack is empty!!\n>>do u wanna store first?(yes=press 0,no&exit=press 1)\n>>");
                scanf("%d",&temp);
                while((temp != 0) && (temp != 1)) //the user have only two options,to exit or to proceed :D :P
                    scanf("%d",&temp);
                if(temp == 0)
                {
                    goto push;
                }
                else if(temp == 1)
                {
                    goto thanku;
                }
            }
             printf(">>take more(press 0) or enough(press 1) ?\n>>");
             scanf("%d",&temp);
                while((temp != 0) && (temp != 1)) //the user have only two options,to exit or to proceed :D :P
                    scanf("%d",&temp);
                if(temp == 0)
                {
                    goto pop;
                }
                else if(temp == 1)
                {
                    goto thanku;
                }
     thanku : printf(">>thank u :D \n*******************************\n");       }
    }

return 0;
}
int StackAvailable(Stack *ps)
{
    return(MAXSTACK - (ps->Top) );
}
void ClearStack(Stack *ps)
{
    ps->Top=0;
}
int StackSize(Stack *ps)
{
    return ps->Top;
}
void StackTop(Stack *ps,StackEntry *pe)
{
    *pe=ps->entry[ps->Top-1];
}
void PushToStack(Stack *ps,StackEntry *pe)
{
    ps->entry[(ps->Top)++]=*pe;
}
void TraverseStack(Stack *ps,void (*pf)(StackEntry)) //set to void & StackEntry for Returning type & the parameter as designed by the user not a general rule
{
    for(int i=ps->Top;i>0;i--)
    (*pf)(ps->entry[i-1]);
}
void Display(StackEntry e)
{
    printf("e is %d \n",e);
}
void Pop4mStack(Stack *ps,StackEntry *pe)
{
    *pe=ps->entry[--(ps->Top)];
}
int StackFull(Stack *ps)
{       //may say return ps->Top >= MAXSTACK;  //then checks the condition and returns 0 or 1
    if(ps->Top == MAXSTACK) return 1; //if empty returns one and exit
    else return 0;//if came here then it's not empty so returns zero
}
int StackEmpty(Stack *ps)
{       //return !(ps->Top);
    if(ps->Top == 0) return 1; //if empty returns one and exit
    else return 0;//if came here then it's not empty so returns zero
}
void CreateStack(Stack *ps)
{
    ps->Top=0;

}
