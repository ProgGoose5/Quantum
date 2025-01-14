#include "librariesreq.h"
#include "appereance.c"

int main()
{
    definitions();   
    blackout();
    clear();
    
     while(1){
        
        Resizing();        
        genprint();
        callsystem(); 
        KeyCommands();
        
        

    } 
   return 0;
}
