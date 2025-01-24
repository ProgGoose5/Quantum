#include "librariesreq.h"
#include "appereance.c"

int main()
{
    //Define inmutable variables.
    definitions();  
    
    clear();
    
     while(1){

    //Calling resizing for measure the terminal.
        Resizing(); 
    //Defining properties of the boxes
        boxesdef();
    //Refresh important variables...
        alwaysrefresh();
    //Callin' a read of the keyboard.
        KeyCommands();
    //Call a blackout to clean the screen 
        blackout(); 
    //Redifine the boxes (Just in case...)
        boxesdef();         
    //Call the box printing(where the boxes print vertically)
        Boxrep();
    //Call the General Printing (For the appeareance.)
        genprint();        
    //Ask the system to get the directories 
        callsystem(); 
    //Repeat in loop.
    } 
   return 0;
}
