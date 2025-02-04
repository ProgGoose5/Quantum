#include "librariesreq.h"

#ifndef GLOBALFUNC_C

//constants
#define PAIR1 1
#define PAIR2 2
#define PAIR3 3
//Int Variables
int x, y; //Screen position variables
int i, f=1, t=1, Q=0; //Used to operate with fors and other things
int quantity, page, actualpage=0, dbfilesperpage=0, filesperpage;
int dirbar=2; //The space that occupies the directory bar
int txright, filedivision=5,  filelayout=5; //Useful for the Boxes
int cou=0; 
int ygaps, gap;
int selectedfile=0,invertedcordinates= 0, actualfile=0; //All for the selection of files
int NumDir=2;
int verification=0;
int actualaction=0;
 
int borderx, bordery, borderval, boxesdivisions, initboxes, realxubication, realyubication=0;
//CharStrings 
char* directory[300]={"","/"};
char* options[1000] = {" "};
char *allowedcharacters="_. :,*+ñ()-";
//Char Variables
char cdcom[4000];
char *boxChar = " ";
char combinedDir[4000];
//boolens
bool g=FALSE;
bool inactions= FALSE; 
bool commandcall=FALSE;
bool isfile;
bool filingarray[4960];

struct Fileubs
{
  int xposition, yposition, xlength, ylength, actualy;
}Fileubs1,Fileubs2,Fileubs3,Fileubs4,Fileubs5;

//First definitions.
void definitions()
{
  setlocale(LC_ALL, "");
  initscr();
  start_color();
  keypad(stdscr,TRUE);
  noecho();


  init_pair(PAIR1, COLOR_WHITE, COLOR_BLACK);
  init_pair(PAIR2, COLOR_BLACK, COLOR_WHITE);
  init_pair(PAIR3, COLOR_CYAN, COLOR_BLACK);

  
}



//Calls the system and reads the size of the terminal
void Resizing(){
  //BASH COMMANDS
  char lines[12]= "tput lines"; 
  char columns[12]="tput cols"; 
  //Defining variables to copy the result of the commands
  int lns = 0, cols = 0;

//Fopen wanst required!!!

// Get the number of lines and columns
if(lns != LINES || cols != COLS){
  lns = LINES;
  cols = COLS;
  x = cols-2;
  y = lns-1;
}

}

//The definitions of various boxes
void boxesdef() {

txright= (x/4)*3;
boxesdivisions= 18;
initboxes= (x/4)+1;
ygaps= (int)round((y/5));

if((round(txright/filedivision))<20 && filedivision>1){
  filedivision--;
}
else if((txright/filedivision)>=28 && filedivision<5){
  filedivision++;
}

if((round(y/(filelayout+1)))<7 && filelayout>1){
  filelayout--;

if((round(y/(filelayout+1)))>=9 && filelayout<5){
  filelayout++;
}}

//definition of Fileubs1
Fileubs1.xposition= initboxes;
Fileubs1.yposition= 1+dirbar;
Fileubs1.ylength= 10;
Fileubs1.actualy= 0;
Fileubs1.xlength= boxesdivisions+initboxes;

//definition of Fileubs2
Fileubs2.xposition= Fileubs1.xlength+2;
Fileubs2.yposition= Fileubs1.ylength;
Fileubs2.actualy= 0;
Fileubs2.xlength= boxesdivisions+Fileubs2.xposition;
//definition of Fileubs3
Fileubs3.xposition= Fileubs2.xlength+2;
Fileubs3.yposition= Fileubs2.yposition*2;
Fileubs3.actualy= 0;
Fileubs3.xlength= boxesdivisions+Fileubs3.xposition;

//definition of Fileubs4
Fileubs4.xposition= Fileubs3.xlength + 2;
Fileubs4.yposition= Fileubs2.yposition*3;
Fileubs4.actualy= 0;
Fileubs4.xlength= boxesdivisions+Fileubs4.xposition;

//definition of Fileubs5
Fileubs5.xposition= Fileubs4.xlength + 2;
Fileubs5.yposition= Fileubs2.yposition*4;
Fileubs5.actualy= 0;
Fileubs5.xlength= boxesdivisions+Fileubs5.xposition;


}

//The functionality of the boxes (Not mistake with rep)
//Also, DONT TOUCH. It works as it is.
void boxesfunction(){

  int auxiliarstrlen= (int)strlen(options[i]);
  borderval=1;
    if(auxiliarstrlen<8){
      borderx=((boxesdivisions-(borderval*2))-(auxiliarstrlen));
    }
    else{borderx=((boxesdivisions-(borderval*2))-8);}
  int files= i+1;

  switch (f)
  {
    case 1:
      realxubication= Fileubs1.xposition+(borderx/2);
      break;
  
    case 2:
      realxubication= Fileubs2.xposition+(borderx/2);
      break;

    case 3: 
      realxubication= Fileubs3.xposition+(borderx/2);
      break;

    case 4:
      realxubication= Fileubs4.xposition+(borderx/2);
      break;

    case 5:
      realxubication= Fileubs5.xposition+(borderx/2);
      break;
  }

  switch(t){

    case 5:
      realyubication= 47+cou; //5
      break;

    case 1:
      realyubication= 7+cou; //1
      break;

    case 2:
      realyubication= 17+cou; //2
      break;

    case 3:
      realyubication= 27+cou; //3
      break;

    case 4:
      realyubication= 37+cou; //4
      break;

    default: 
    g=true;

  }
  if((files%filedivision)==0){
  f=1; t++;
}

else{f++;}



}

//Made for executing upon every box printed, Dummy me made boxes print one space each one instead of
// printing themselves completly.
void verify(){

if(verification==selectedfile){
  attron(COLOR_PAIR(PAIR2));
  verification++;
}
else{
  attron(COLOR_PAIR(PAIR1));
  verification++;
}

}

//The printing of each box.
//I hate this function with my heart. Its an Horrible function, but it does what it is intended to.
void Boxrep(){
  
  for(int G= 1; G<=5; G++){
    for(int L=Fileubs1.yposition; L<=Fileubs1.ylength; L++){
      for(int O=(Fileubs1.xposition); O<(Fileubs1.xlength); O++)
      { verification=0;
        verify();
        mvprintw(L, O, "%s", boxChar);
        if(filelayout>=2){
          verify();
          mvprintw(L+(Fileubs2.yposition),O, "%s", boxChar); }
        if(filelayout>=3){
          verify();
          mvprintw(L+(Fileubs3.yposition),O, "%s", boxChar); }
        if(filelayout>=4){
          verify();
          mvprintw(L+(Fileubs4.yposition),O, "%s", boxChar); }
        if(filelayout>=5){
          verify();
          mvprintw(L+(Fileubs5.yposition),O, "%s", boxChar); }
      } 
    if(filedivision>=2){
      for(int O=(Fileubs2.xposition); O<(Fileubs2.xlength); O++)
      { verification=filelayout;
        verify();
        mvprintw(L, O, "%s", boxChar);
        if(filelayout>=2 ){
          verify();
        mvprintw(L+(Fileubs2.yposition),O, "%s", boxChar); }
        if(filelayout>=3){
          verify();
          mvprintw(L+(Fileubs3.yposition),O, "%s", boxChar); }
        if(filelayout>=4 ){
          verify();
          mvprintw(L+(Fileubs4.yposition),O, "%s", boxChar); }
        if(filelayout>=5 ){
          verify();
          mvprintw(L+(Fileubs5.yposition),O, "%s", boxChar); }
      } }

    if(filedivision>=3){
      for(int O=(Fileubs3.xposition); O<(Fileubs3.xlength); O++)
      { verification=filelayout*2;
        verify();
        mvprintw(L, O, "%s", boxChar);
        if(filelayout>=2){
        verify();
        mvprintw(L+(Fileubs2.yposition),O, "%s", boxChar); }
        if(filelayout>=3 ){
        verify();
        mvprintw(L+(Fileubs3.yposition),O, "%s", boxChar); }
        if(filelayout>=4 ){
        verify();
        mvprintw(L+(Fileubs4.yposition),O, "%s", boxChar); }
        if(filelayout>=5 ){
        verify();
        mvprintw(L+(Fileubs5.yposition),O, "%s", boxChar); }
      } }

    if(filedivision>=4 ){
      for(int O=(Fileubs4.xposition); O<(Fileubs4.xlength); O++)
      { verification=filelayout*3;
        verify();
        mvprintw(L, O, "%s", boxChar);
        if(filelayout>=2){
        verify();
        mvprintw(L+(Fileubs2.yposition),O, "%s", boxChar); }
        if(filelayout>=3 ){
        verify();
        mvprintw(L+(Fileubs3.yposition),O, "%s", boxChar); }
        if(filelayout>=4 ){
        verify();
        mvprintw(L+(Fileubs4.yposition),O, "%s", boxChar); }
        if(filelayout>=5 ){
        verify();
        mvprintw(L+(Fileubs5.yposition),O, "%s", boxChar); }
      } }

  if(filedivision>=5){
      for(int O=(Fileubs5.xposition); O<(Fileubs5.xlength); O++)
      { verification=20;
        verify();
        mvprintw(L, O, "%s", boxChar);
        if(filelayout>=2){
        verify();
        mvprintw(L+(Fileubs2.yposition),O, "%s", boxChar); }
        if(filelayout>=3 ){
        verify();
        mvprintw(L+(Fileubs3.yposition),O, "%s", boxChar); }
        if(filelayout>=4 ){
        verify();
        mvprintw(L+(Fileubs4.yposition),O, "%s", boxChar); }
        if(filelayout>=5 ){
        verify();
        mvprintw(L+(Fileubs5.yposition),O, "%s", boxChar); }
      } }
      //When there's more fors... i must add an IF to
      //call the verification of filedivision
      
    }
  


} }

//System and apps representation function.
void callsystem(){
  char lscom[5000];
 
  memset(combinedDir, 0, sizeof(combinedDir));
    for(int sk= 1; sk<NumDir; sk++){
      if(directory[sk]!= NULL){
      strncat(combinedDir, directory[sk], sizeof(combinedDir) - strlen(directory[sk])-1);
      }
    }
    snprintf(lscom, sizeof(lscom), "ls %s", combinedDir);

    //CD command
    
    snprintf(cdcom, sizeof(combinedDir), "cd %s", combinedDir);
  
  system(cdcom);
  FILE* Readings = popen(lscom, "r");
  if (Readings == NULL) {
    mvprintw(4, 7, "Failed to run command");
    return;
  }

  char buffer[256];
  int index = 0;
  while (fgets(buffer, sizeof(buffer), Readings) != NULL && index < 1000) {
    options[index] = strdup(buffer);
    index++;
    quantity=index;
  }
  pclose(Readings);

  filesperpage= (filedivision*filelayout)*actualpage;
  dbfilesperpage= (filedivision*filelayout)*(actualpage+1);
  if((dbfilesperpage-quantity)>0){dbfilesperpage-=(dbfilesperpage-quantity);}
    for(page=0; page<((index/(filedivision*filelayout))); page++){
  }

  actualfile=0;
  cou=1; 
      t=1;
      f=1; 
  for(i=(0+filesperpage); i < dbfilesperpage; i++){  
    quantity=index;   
    
    mvprintw(y-1, x-12, "Pages %d/%d",actualpage, page);

    char filesinthispage[4096];

    memset(filesinthispage, 0, sizeof(filesinthispage));
    
    char *newline = strchr(options[i], '\n');
    if (newline) *newline = '\0';
    strcat(filesinthispage, combinedDir);
    strcat(filesinthispage, "/");
    strcat(filesinthispage, options[i]);
  
  DIR* directorycomprobation= opendir(filesinthispage);
  if (directorycomprobation!=NULL){
    isfile=FALSE;
  } else {
    isfile=TRUE;
  }
  closedir(directorycomprobation);

  filingarray[i]= isfile;

  if(selectedfile==0){invertedcordinates=0;}
 if (i == (invertedcordinates+filesperpage))
    { attron(COLOR_PAIR(PAIR2));}
  else
    { attron(COLOR_PAIR(PAIR1));}

    char* Printyan= options[i];
    char Printylonger[128];

       strcpy(Printylonger, Printyan);



 int Nah= (int)strlen(Printylonger);

 boxesfunction();
  
  if (Nah>10){
    
  int q=0;
    for(int p = 0; Printylonger[p] != '\0'; p++) {
      
      if((isalpha(Printylonger[p]) || isalnum(Printylonger[p]) || strchr(allowedcharacters, Printylonger[p])!= NULL) && q < 3){
        mvprintw(realyubication, realxubication + (p % 10), "%c", Printylonger[p]);
      if ((p + 1) % 10 == 0) {
        realyubication++; 
        q++;
      }
      if(q==3){break;}
      }}
  }

  else{
    char Printy[16];
    snprintf(Printy, sizeof(Printy), "%s", options[i]);
    for (int j = 0; Printy[j] != '\0'; j++) {
        if (isalpha(Printy[j] || isalnum(Printy[j]))) {
            mvprintw(realyubication, realxubication + j, "%c", Printy[j]);
            }
        else if(isalnum(Printy[j])){
          mvprintw(realyubication, realxubication + j, "%c", Printy[j]);
        }

    }
    
  
  }

  
  

  attron(COLOR_PAIR(PAIR1));
  refresh();
  
  }}

//Keyboard reading.
void KeyCommands(){

  int cius= getch();

  switch(cius){
    case KEY_RIGHT:
    if(inactions==FALSE){
      if((invertedcordinates+1+filesperpage) < dbfilesperpage){
        if(selectedfile<((filelayout*filedivision)-filelayout))
        {
          
          selectedfile= selectedfile+filelayout; invertedcordinates++;}}
      else if (actualpage<page){actualpage++; selectedfile=0; invertedcordinates=0;}
    }
    
    break;

    case KEY_LEFT:
    if(inactions==FALSE){
      if(selectedfile>=filelayout)
        {selectedfile-=filelayout; invertedcordinates--;}
      else if(actualpage>0){actualpage--; selectedfile=0; invertedcordinates=0;} 
    }
    break;

    case KEY_UP:
    if(inactions==FALSE){
      if(((selectedfile)%(filelayout))!= 0 || selectedfile==0){
        if(selectedfile>0)
        {selectedfile--; invertedcordinates-=(filedivision);}}
      else if(actualpage>0){actualpage--; selectedfile=0; invertedcordinates=0;}
    }
    else if(inactions==TRUE && actualaction>0){actualaction--;}

      break;

    case KEY_DOWN:
    if(inactions==FALSE){
      if(((invertedcordinates+1)+filedivision+filesperpage) <= dbfilesperpage && (invertedcordinates+filesperpage+1) <= dbfilesperpage){
        if(((selectedfile+1)%(filelayout))!= 0 || selectedfile==0){
          if((selectedfile<(filelayout*filedivision)-1) && (selectedfile+1)%(filelayout)!= 0){
            selectedfile++; invertedcordinates+=(filedivision);
      } }  }
      else if(actualpage<page){actualpage++; selectedfile=0; invertedcordinates=0;}
    }
    else if(inactions==TRUE && actualaction<10){actualaction++;}
    break;

    case KEY_F(1):
    if(inactions==FALSE){
    directory[NumDir]= NULL;
    NumDir--;
    selectedfile=0;
    actualpage=0;
    }
    break;

    case KEY_F(3):
    
    if(inactions==FALSE && filingarray[invertedcordinates]==FALSE){
      char Directory[256];
      char *newline = strchr(options[invertedcordinates+filesperpage], '\n');
      if (newline) *newline = '\0';
        snprintf(Directory, sizeof(Directory), "/%s", options[invertedcordinates+filesperpage]);
        directory[NumDir]= strdup(Directory);
        NumDir++;
        selectedfile=0;
        actualpage=0;
        } 
    else if(inactions==TRUE){
      commandcall=TRUE;
    }
    break;

    case KEY_F(5):
    if(inactions==FALSE){inactions=TRUE;}
    else{inactions=FALSE;}
    break;
  }


}

//Refresher of variable values.
void alwaysrefresh(){
  filesperpage= (filedivision*filelayout)*actualpage;
  dbfilesperpage= (filedivision*filelayout)*(actualpage+1);
  page= (quantity/(filedivision*filelayout));

  if((dbfilesperpage-quantity)>0){dbfilesperpage-=(dbfilesperpage-quantity);}

    mvprintw(1,((x/4)+1),"%s", combinedDir);
    mvprintw(y-1, x-12, "Pages %d/%d",actualpage, page);

  if((dbfilesperpage-quantity)>0){dbfilesperpage-=(dbfilesperpage-quantity);}
    for(page=0; page<((quantity/(filedivision*filelayout))); page++){
  }

boxesdef();
}

#endif

 
