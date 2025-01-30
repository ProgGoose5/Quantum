#include "librariesreq.h"
#ifndef APPEREANCE_C
#include "actions.c"


void genprint(){

    char* decoration1= "━";
    char* decoration2= "│";
    char* decoration3= "┯";
    char* decoration4= "┷";
    char* corner1= "┍";
    char* corner2= "┑";
    char* corner3= "┕";
    char* corner4= "┙";

    definitions();
    attron(COLOR_PAIR(PAIR1));
    //Corners

        refresh();
    for(int a= 0; a<x; a++){
        mvprintw(0,a,"%s", decoration1);
        mvprintw(y,a,"%s",decoration1);

    }
    for( int a= 0; a<y; a++){
        mvprintw(a,0,"%s", decoration2);
        mvprintw(a,x/4,"%s", decoration2);
        mvprintw(a, x, "%s", decoration2);
    }
    mvprintw(0, x/4, "%s", decoration3);
    mvprintw(y, x/4, "%s", decoration4);

    mvprintw(0,0, "%s", corner1);
    mvprintw(0,x, "%s", corner2);
    mvprintw(y,0, "%s", corner3);
    mvprintw(y,x, "%s", corner4);
    refresh();
}

void FolderIcon(){

/*
┍━━━━┑
│    ╘═══════╕
│            │
│            │
┕━━━━━━━━━━━━┙
123456789abcdefghi 
▆▆▆▆▆ ◣
███████▍
███████▍
███████▍
███████▍
*/

int positionX, positionY;
char* fileicons[13]={"━", "│", "═", "╕", "┑", "┍", "┕", "┙", "╘"};
char* fileicons2[2]={"▆▆▆▆▆ ◣", "███████▎"};
int C=1;
int D=1;

for(int H= (0+filesperpage); H < dbfilesperpage; H++){

switch(C){
    case 1:
    positionX=(Fileubs1.xposition)+2;
    break;   
    case 2:
    positionX=(Fileubs2.xposition)+2;
    break;
    case 3:
    positionX=(Fileubs3.xposition)+2;
    break;
    case 4:
    positionX=(Fileubs4.xposition)+2;
    break;
    case 5:
    positionX=(Fileubs5.xposition)+2;
    break;
    }


switch(D){
    case 1:
    positionY=Fileubs1.yposition;
    break;   
    case 2:
    positionY=13;
    break;
    case 3:
    positionY=23;
    break;
    case 4:
    positionY=33;
    break;
    case 5:
    positionY=43;
    break;
    }

C++;


  if(selectedfile==0){invertedcordinates=0;}
 if (H == (invertedcordinates+filesperpage))
    { attron(COLOR_PAIR(PAIR2));}
  else
    { attron(COLOR_PAIR(PAIR1));}
if(filingarray[H]==FALSE){
mvprintw(positionY, positionX, "%s", fileicons[5]);//corner
mvprintw(positionY+1, positionX+13, "%s", fileicons[3]);//corner
for(int xb=1; xb<6; xb++){//horizontal
mvprintw(positionY, positionX+xb, "%s", fileicons[2]);
}

for(int xb=1; xb<13; xb++){//horizontal
mvprintw(positionY+4, positionX+xb, "%s", fileicons[0]);
}

for(int yb=1; yb<4; yb++){ //Vertical
mvprintw(positionY+yb, positionX, "%s", fileicons[1]);
}

mvprintw(positionY, positionX+5, "%s", fileicons[4]);//corner
mvprintw(positionY+1, positionX+5, "%s", fileicons[8]);//corner

for (int xb=2; xb<9; xb++){//Horizontal
mvprintw(positionY+1, positionX+xb+4, "%s", fileicons[2]);
}


mvprintw(positionY+4, positionX, "%s", fileicons[6]);//corner
for(int vb=1; vb<3; vb++){//Vertical
mvprintw(positionY+vb+1, positionX+13, "%s", fileicons[1]);
}
mvprintw(positionY+4, positionX+13, "%s", fileicons[7]);

if (C==filedivision+1){C=1; D++;}
}
else if(filingarray[H]==TRUE){

mvprintw(positionY, positionX+3, "%s", fileicons2[0]);

for(int vd=1; vd<5; vd++){
mvprintw(positionY+vd, positionX+3, "%s", fileicons2[1]);
if (C==filedivision+1){C=1; D++;}
}


}

}

}

void Leftside(){
    char *commandsnames[20]= {"New Directory", "New File", "Copy", "Cut", "Paste", "Rename", "Execute Locally", "Execute Wined", "CMake!", "Make!"};
    for (int l=0; l< 8; l++){
        if (l==actualaction){
            attron(COLOR_PAIR(PAIR2));
        }
        else{
            attron(COLOR_PAIR(PAIR1));
        }
        mvprintw(3+l, 2, "%s", commandsnames[l]);
        attron(COLOR_PAIR(PAIR3));
        mvprintw(2,2, "Commands");
    }
    
}

void directorybar(){
    attron(COLOR_PAIR(PAIR3));
    mvprintw(1, (x/4+1), "%s", combinedDir);
    refresh();
}


#endif 
