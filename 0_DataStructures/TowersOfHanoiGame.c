#include "TowersOfHanoiGame.h"
int move_disks(uint32_t count_h,uint32_t start, uint32_t finish, uint32_t temp)
{
    static uint32_t counter=0;
    if(count_h >0)
    {
        move_disks(count_h-1,start,temp,finish);
        printf("%-10d=Move Disk %d from %d to %d\n",counter++,count_h,start,finish);
        move_disks(count_h-1,temp,finish,start);
    }
   return true;
}
