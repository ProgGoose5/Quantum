#include "librariesreq.h"
#include "appereance.c"

int main()
{
    definitions();   
    blackout();
    
     while(1){
        callsystem(); 
       Resizing();
        genprint();
        rightpad(); 
        refresh();
    } 
   return 0;
}
