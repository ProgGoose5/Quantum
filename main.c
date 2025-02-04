#include "librariesreq.h"
#include "appereance.c"

int main()
{
    //Define inmutable variables.
    definitions();  
    
    clear();
    
     while(1){

    for(int jk= 0; jk< 2; jk++){
    //Clearing the screen
        clear();
    //Calling resizing for measure the terminal.
        Resizing(); 
    //Defining properties of the boxes
        boxesdef();
    //Refresh important variables...
        alwaysrefresh();
    //Call a blackout to clean the screen 

    //Redifine the boxes (Just in case...)
        boxesdef();         
    //Call the box printing(where the boxes print vertically)
        Boxrep();
        FolderIcon();
    //Call the General Printing (For the appeareance.)
        genprint();        
    //Ask the system to get the directories 
        callsystem(); 
    //Calling the Leftside appeareance to Execute.
        Leftside();
    //If a command is called, Actioncall will execute it
        Actioncall();
    //Shows the actual directory bar.
        directorybar();
     }
     //Redifining boxes variables
     boxesdef();  
     //Callin' a read of the keyboard.
     KeyCommands();
        
    //Repeat in loop.
    } 
   return 0;
}
