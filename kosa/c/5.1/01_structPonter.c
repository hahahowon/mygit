
#include <stdio.h>


struct point
{
    int xpos;
    int ypos;
};

int main(void)
{
    struct point pos1={1, 2};
    struct point pos2={100, 200};
    struct point *pptr=&pos1;

    (*pptr).xpos += 4;
    (*pptr).ypos += 5;
    printf("[%d, %d] \n", pptr->xpos, pptr->ypos);

    pptr=&pos2;
    pptr->xpos +=1;
    pptr->ypos +=1;
    printf("[%d, %d] \n", (*pptr).xpos,(*pptr).ypos);
    return 0;    
}
//포인터를처음에는 pos 1으로 했다 pos2로 바꿈