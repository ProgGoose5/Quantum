#include "librariesreq.h"
#include "globalfunc.c"
#include "appereance.c"

int main()
{
    definitions();    
    while(1){
        Resizing();
        blackout();
        normalappeareance();
        refresh();
    }
}