#include "librariesreq.h"
#include "appereance.c"

int main()
{
    definitions();   
    blackout(); 
    while(1){
        Resizing();
        genprint();
        refresh();
    }
}
