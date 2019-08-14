#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>

typedef struct {
  char color;
  char placeR;					//struct for each square on the board
  char placeC;
  char piece;
}block;
void findtheking(unsigned char a[],block b[][8]);
void findthekingblack(unsigned char a[],block b[][8]);
int checkblack(block b[][8],unsigned char a[],unsigned char *x,unsigned char *y,int fixingpoint);
int check(block b[][8],unsigned char a[],unsigned char *x,unsigned char *y,int fixingpoint);

int checkresult(block b[][8],char x[]){ //checks if the path of movement is clear so that no pieces can jump
char i,max,min; int z = 1;
if(x[0]==x[2] && x[1]!=x[3]){
if(x[3]<x[1]){
max = x[1]; min = x[3];
} else {
max = x[3]; min = x[1];
}
for(i = min+1; i < max; i++){
if(b[i-49][x[0]-97].piece !='\0'){ z= 0;
return z;
}}}
else if(x[1]==x[3] && x[0]!=x[2]){
if(x[2]<x[0]){
max = x[0]; min = x[2];
} else {
max = x[2]; min = x[0];
}
for(i = min+1; i < max; i++){
if(b[x[1]-49][i-97].piece !='\0'){
z= 0;
return z;
}}}
else {
  char a,e,c;
    if (x[0]<x[2]){ a=x[0]; e=x[2]; }
  else { a=x[2]; e=x[0]; }
  if (x[1]<x[3]){ c=x[1]; }
  else {c=x[3];}
  int i=1;
  if (x[0]<x[2]&&x[1]>x[3]){
     for (i=1;i<(e-a);i++){
  if (b[x[1]-49-i][a-97+i].piece!='\0'){
  			z=0;
    return z;
  }
}
  }
  else   if (x[2]<x[0]&&x[3]>x[1]){
     for (i=1;i<(e-a);i++){
  if (b[x[3]-49-i][a-97+i].piece!='\0'){
  			z=0;
    return z;
  }
}
  }
  else {
  for (i=1;i<(e-a);i++){
  if (b[c-49+i][a-97+i].piece!='\0'){ z=0;
    return z;
  }
}
}}
return z;
}

block ReadingBlock(int i , int  j ){// fills the block with color & place values
block block1;
char initplace(int i , int j);

if(abs(i - j) %  2 == 0){
		block1.color = '-';

} else {
block1.color = '.';

}
	block1.placeC = i + 96;
    block1.placeR = j + 48;
    block1.piece = initplace(i,j);

return block1;
}
char initplace(int i , int j){	// fills the board with pieces at their initial places


    char block1piece;
if(i ==2 ){
block1piece = 'p';
}

else if(i==7){block1piece='P';}
else if (i==8){
if (j==1||j==8){block1piece='R';}
else if (j==2||j==7){block1piece='N';}
else if (j==3||j==6){block1piece='B';}
else if (j==4){block1piece='Q';}
else if (j==5){block1piece='K';}
}
else if(i == 1 ){
if(j == 1|| j == 8){
block1piece = 'r';
} else if ( j == 2 || j == 7){
block1piece = 'n';
} else if (j == 3|| j == 6){
block1piece = 'b';
} else if (j == 4) {
block1piece = 'q';
} else if (j == 5){
block1piece = 'k';}
else { block1piece='\0';}

}
else { block1piece='\0';}
return block1piece;
}

int checkmove(char x[],block b[][8],int y){// checks if the input in the right form of movement(normal move or promotion or castling)
int z=0;
	if ((x[0]<=104)&&(x[0]>=97)){
  	if ((x[2]<=104)&&(x[2]>=97)){
  		if ((x[1]<=56)&&(x[1]>=49)){
      	if ((x[3]<=56)&&(x[3]>=49)){
        	if (x[5]=='\0'||x[5]=='\n'){
            if (y==1){
if (b[x[1]-49][x[0]-97].piece=='P'||b[x[1]-49][x[0]-97].piece=='R'||b[x[1]-49][x[0]-97].piece=='B'||b[x[1]-49][x[0]-97].piece=='N'||b[x[1]-49][x[0]-97].piece=='Q'||b[x[1]-49][x[0]-97].piece=='K'){
    z=0;
}
else if (b[x[3]-49][x[2]-97].piece=='p'||b[x[3]-49][x[2]-97].piece=='r'||b[x[3]-49][x[2]-97].piece=='b'||b[x[3]-49][x[2]-97].piece=='n'||b[x[3]-49][x[2]-97].piece=='q'||b[x[3]-49][x[2]-97].piece=='k'){
    z=0;
}else {z=1;}
            }
            else if (y==-1){
if (b[x[1]-49][x[0]-97].piece=='p'||b[x[1]-49][x[0]-97].piece=='r'||b[x[1]-49][x[0]-97].piece=='b'||b[x[1]-49][x[0]-97].piece=='n'||b[x[1]-49][x[0]-97].piece=='q'||b[x[1]-49][x[0]-97].piece=='k'){
    z=0;
}
else if (b[x[3]-49][x[2]-97].piece=='P'||b[x[3]-49][x[2]-97].piece=='R'||b[x[3]-49][x[2]-97].piece=='B'||b[x[3]-49][x[2]-97].piece=='N'||b[x[3]-49][x[2]-97].piece=='Q'||b[x[3]-49][x[2]-97].piece=='K'){
    z=0;
}else {z=1;}
            }

          }

          if (z==1){
                if (b[x[1]-49][x[0]-97].piece=='p'&&(x[0]==x[2]||abs(x[2]-x[0])==1)&&x[1]=='7'&&x[3]=='8'){
                if (x[4]=='b'||x[4]=='r'||x[4]=='q'||x[4]=='n'){}
                else {z=0;} }

                else if (b[x[1]-49][x[0]-97].piece=='P'&&(x[0]==x[2]||abs(x[2]-x[0])==1)&&x[1]=='2'&&x[3]=='1'){
                     if (x[4]=='B'||x[4]=='R'||x[4]=='Q'||x[4]=='N'){}
                else {z=0;}
                }
                else if (x[4]!='\n'){
                    z=0;
                }




          }
        }
      }
  }
  }
  return z;
}
void Moving(char *oldblock , char *newblock,block b[][8],int *flag,char q[],char n[][7], int h){
char temp;
unsigned char g1,g2;
unsigned char x[3];
int z;
if((n[h][1]=='1'&&n[h][3]=='1'&&((n[h][0]=='e'&&n[h][2]=='g')||(n[h][0]=='e'&&n[h][2]=='c')))&& *oldblock=='k' ){
if(n[h][2]-n[h][0]>0){
    b[n[h][3]-49][n[h][2]-97].piece ='\0';
    b[n[h][1]-49][n[h][0]-97].piece = 'k';
    b[n[h][1]-49][n[h][0]-97+3].piece='r';
    b[n[h][3]-49][n[h][2]-97-1].piece = '\0';
 }else{
      b[n[h][3]-49][n[h][2]-97].piece = '\0';
    b[n[h][1]-49][n[h][0]-97].piece = 'k';
    b[n[h][1]-49][n[h][0]-97-4].piece = 'r';
    b[n[h][3]-49][n[h][2]-97+1].piece= '\0';
 }
}
if((n[h][1]=='8'&&n[h][3]=='8'&&((n[h][0]=='e'&&n[h][2]=='g')||(n[h][0]=='e'&&n[h][2]=='c')))&& *oldblock=='K' ){
if(n[h][2]-n[h][0]>0){
    b[n[h][3]-49][n[h][2]-97].piece ='\0';
    b[n[h][1]-49][n[h][0]-97].piece = 'K';
    b[n[h][1]-49][n[h][0]-97+3].piece='R';
    b[n[h][3]-49][n[h][2]-97-1].piece = '\0';
 }else{
      b[n[h][3]-49][n[h][2]-97].piece = '\0';
    b[n[h][1]-49][n[h][0]-97].piece = 'K';
    b[n[h][1]-49][n[h][0]-97-4].piece = 'R';
    b[n[h][3]-49][n[h][2]-97+1].piece= '\0';
 }
}
else if (q[4]=='q'||q[4]=='b'||q[4]=='r'||q[4]=='n'||q[4]=='Q'||q[4]=='B'||q[4]=='R'||q[4]=='N'){
        if (*newblock=='\0'&&(*oldblock=='q'||*oldblock=='r'||*oldblock=='b'||*oldblock=='n')){
            temp = *newblock;
        *newblock = 'p';
        *oldblock = '\0';
        }
        else if (*newblock=='\0'&&(*oldblock=='Q'||*oldblock=='R'||*oldblock=='B'||*oldblock=='N')){
            temp = *newblock;
        *newblock = 'P';
        *oldblock = '\0';
        }
        else {
            temp = *newblock;
        *newblock = q[4];
        *oldblock = '\0';
        }


}
else {
temp = *newblock;
*newblock = *oldblock;					//moves the pieces
*oldblock = '\0';}
if(*flag > 0){
        findtheking(x,b);
    z=check(b,x,&g1,&g2,1);
} else if(*flag < 0){
    findthekingblack(x,b);
z=checkblack(b,x,&g1,&g2,1);}
if(z==0){
    *oldblock = *newblock;
    *newblock = temp;
    *flag *=-1;
}
}
int virtualmoving(unsigned char x[], block b[][8], int flag){
unsigned char g1,g2;
int z;
if(flag > 0){
 	z=check(b,x,&g1,&g2,1);
} else if(flag < 0){
	z=checkblack(b,x,&g1,&g2,1);}
return z;
}
int checkp(block b[][8],char x[]){  //checks if the input is a valid move for pawn
  int z=0;
  if ((x[1]=='2')||(x[1]=='7')){
    if (abs(x[1]-x[3])==1||abs(x[1]-x[3])==2){
      if (x[0]==x[2]){
        	if (abs(x[1]-x[3])==1){
            if (b[x[3]-49][x[2]-97].piece=='\0'){
              z=1;
            }
          }
        	else {
      		z=checkresult(b,x);
      		}
    }
  }
  }
  else if (abs(x[3]-x[1])==1){
    if (x[0]==x[2]){
       if (b[x[3]-49][x[2]-97].piece=='\0'){
              z=1;
            }
    }}
  if (abs(x[2]-x[0])==1&&abs(x[3]-x[1])==1){

      if (b[x[3]-49][x[2]-97].piece!='\0'){
        z=1;
      }
    }
    if (z==1){
    if ((x[3]<x[1])&&(b[x[1]-49][x[0]-97].piece!='P')){
      z=0;
    }
    else if ((x[1]<x[3])&&(b[x[1]-49][x[0]-97].piece!='p')){
      z=0;
    }
  }
  return z;
}
int checkb(block b[][8],char x[]){//checks if the input is a valid move for bishop
	int z=0;
	if (abs(x[1]-x[3])==abs(x[0]-x[2])){
  	if (x[0]-x[2]!=0){
    z=1;
    }}
  if (z==1){
  z = checkresult(b,x);}
  return z;
  }
int checkq (block b[][8],char x[]){//checks if the input is a valid move for queen
	int z=0;
  if (abs(x[1]-x[3])==abs(x[0]-x[2])){
  	if (x[0]-x[2]!=0){
    z=1;
    }}
  else if(x[0]==x[2] && abs(x[1]-x[3])!=0 ){
z=1;
} else if(x[1]==x[3] && abs(x[0]-x[2])!=0){
z=1;
}
  if (z==1){
  z = checkresult(b,x);}
return z;
}
int checkr(block b[][8],char x[]){//checks if the input is a valid move for rooks
int z=0;
if(x[0]==x[2] && abs(x[1]-x[3])!=0 ){
z=1;
} else if(x[1]==x[3] && abs(x[0]-x[2])!=0){
z=1;
}
    if (z==1){
  z = checkresult(b,x);}
  return z;
}
int checkk(block b[][8],char x[]){//checks if the input is a valid move for king
int z = 0;
if((abs(x[0]-x[2])==1 && abs(x[1]-x[3])==1)||(abs(x[0]-x[2])==1 && abs(x[1]-x[3])==0)||(abs(x[0]-x[2])==0 && abs(x[1]-x[3])==1)){
z = 1;
}
  if (z==1){
  z = checkresult(b,x);}
return z;
}
int checkn(char x[]){//checks if the input is a valid move for knights
int z = 0;
if(abs(x[0]-x[2])==2 && abs(x[1]-x[3])==1){
z = 1;

} else if(abs(x[1]-x[3])==2 && abs(x[0]-x[2])==1){
z = 1;
}
return z;
}
 void eatingpieces(int a[],char c){// adds eaten pieces to the array of eaten pieces for white & black :D
if(c == 'p' || c == 'P'){ a[0]++;}
  else if (c == 'n' || c == 'N'){a[2]++;}
	else if (c == 'b' || c == 'B'){a[4]++;}
  else if (c == 'r' || c == 'R'){a[6]++;}
  else if (c == 'q' || c == 'Q'){a[8]++;}

 }
 void undoeatingpieces(int a[],char c){ // resets the eaten piece if user entered undo
if(c == 'p' || c == 'P'){ a[0]--;}
  else if (c == 'n' || c == 'N'){a[2]--;}
	else if (c == 'b' || c == 'B'){a[4]--;}
  else if (c == 'r' || c == 'R'){a[6]--;}
  else if (c == 'q' || c == 'Q'){a[8]--;}
 }
void intializearr(int weaten[], int beaten[]){//puts the pieces in eaten arrays
  weaten[1]=112; weaten[3]=110; weaten[5]=98; weaten[7]=114; weaten[9]=113; beaten[1]=112-32; beaten[3]=110-32;
	beaten[5]=98-32; beaten[7]=114-32; beaten[9]=113-32;
}
void zerosarr(int weaten[], int beaten[]){// at the beginning number of eaten pieces =0
  for(int i = 0 ; i < 10; i++){
    weaten[i]=0;
    beaten[i]=0;
  }
}
void zerosundoarr(char undo[][7]){//resets number of eaten pieces if user entered undo
  for(int i = 0 ; i < 1000; i++){
        for(int j = 0 ; j < 7 ; j ++)
    undo[i][j]='\0';
  }
}
void savingplays(char x[][7],int numberofplays, char userin[]){//saves valid moves in the array of plays
    for(int i = 0 ; i< 7 ; i++ ){
         x[numberofplays][i] = userin[i];
    }}

int  callfn(char c,char x[],block b[][8]){//calls the check(x) function based on the piece on the block
    if(c == 'p' || c == 'P'){return checkp(b,x);}
  else if (c == 'n' || c == 'N'){return checkn(x);}
	else if (c == 'b' || c == 'B'){return checkb(b,x);}
  else if (c == 'r' || c == 'R'){return checkr(b,x);}
  else if (c == 'q' || c == 'Q'){return checkq(b,x);}
  else if(c=='k' || c == 'K'){return checkk(b,x);}
  else {return 0;}
}
void findtheking(unsigned char a[],block b[][8]){// returns the address of the king (white)
for(int i  = 0 ; i < 8 ; i++){
    for(int j = 0; j < 8 ; j ++ ) {
        if(b[i][j].piece=='k'){
            a[0]= i;
            a[1]=j;
        }}}}
int check(block b[][8],unsigned char a[],unsigned char *x,unsigned char *y, int fixingpoint){  //checks if the king is attacked (white)
int z = 1;
 int flagright = 1; int flagleft = 1;
 int flagrightup = 1; int flagrightdown = 1 ;
 int flagleftup=1; int flagleftdown =  1 ;
for(int i = 1 ; i < 8; i ++ ){
    if(i + a[1] < 8 && flagright){
        if(b[a[0]][i+a[1]].piece == 'Q' || b[a[0]][i+a[1]].piece == 'R'  ){
          *x=a[0];
           *y=i+a[1];
         z= 0 ;

         break;
        } else if(b[a[0]][i+a[1]].piece == 'k' ){continue;}
         else if (b[a[0]][i+a[1]].piece != '\0' ){
            z = 1; flagright = 0;
        }
    } if(a[1]-i >=0 && flagleft) {
        if(b[a[0]][a[1] - i].piece == 'Q' || b[a[0]][a[1]-i].piece == 'R'  ){
                *x=a[0];
           *y=a[1]-i;
         z= 0 ;

         break;
        }else if(b[a[0]][a[1]-i].piece == 'k' ){continue;}
        else if (b[a[0]][a[1]-i].piece != '\0' ){
            z = 1; flagleft = 0;}
    }}
if (z==1){
flagright=1; flagleft = 1 ;
for(int i = 1 ; i < 8; i ++ ){
    if(i + a[0] < 8 && flagright){
        if(b[a[0]+i][a[1]].piece == 'Q' || b[a[0]+i][a[1]].piece == 'R'  ){
                *x=a[0]+i;
                *y=a[1];
         z= 0 ; break;
        }else if(b[a[0]+i][a[1]].piece == 'k' ){continue;}
         else if (b[a[0]+i][a[1]].piece != '\0' ){
            z = 1; flagright = 0;
        }
    } if(flagleft && a[0] - i >= 0 ) {
        if(b[a[0]-i][a[1]].piece == 'Q' || b[a[0]-i][a[1]].piece == 'R'  ){
         *x=a[0]-i;
         *y=a[1];
         z= 0 ;
         break;
        }else if(b[a[0]-i][a[1]].piece == 'k' ){continue;}
        else if (b[a[0]-i][a[1]].piece != '\0' ){
            z = 1; flagleft = 0;
        }}}}
if (z==1){if(fixingpoint != 25){
      if(a[0]+1 < 8 && a[1] + 1 < 8 && b[a[0]+1][a[1]+1].piece=='P'){
            *x=a[0]+1;
                *y=a[1]+1;
        z = 0;
      } else if(a[0]+1 >=0 && a[1] -1 < 8 && b[a[0]+1][a[1]-1].piece=='P')
      {
          *x=a[0]+1;
                *y=a[1]-1;
          z = 0;
      }}else if (fixingpoint == 25){
   if(a[0]+1 < 8  && b[a[0]+1][a[1]].piece=='P'){
    *x = a[0]+1; *y=a[1];
        z = 0;
      }

}}if(z==1) {
      for(int i = 1 ; i < 8 ; i++){
            if(a[0]+i < 8 && a[1] + i < 8 && flagrightdown){
        if( b[a[0]+i][a[1]+i].piece=='B' || b[a[0]+i][a[1]+i].piece=='Q'){
            *x=a[0]+i;
                *y=a[1]+i;
            z = 0;
            break;
        }else if(b[a[0]+i][i+a[1]].piece == 'k' ){continue;}
        else if ( b[a[0]+i][a[1]+i].piece!='\0'){
        z = 1 ;
        flagrightdown = 0;}}
      if(a[0]+i < 8 && a[1] - i >=0 && flagleftdown){
         if( b[a[0]+i][a[1]-i].piece=='B' || b[a[0]+i][a[1]-i].piece=='Q'){
               *x=a[0]+i;
                *y=a[1]-i;
            z = 0;
            break;
        }else if(b[a[0]+i][-i+a[1]].piece == 'k' ){continue;}
        else if ( b[a[0]+i][a[1]-i].piece!='\0'){
        z = 1 ;
        flagleftdown = 0;}}
      if(a[0]-i >=0 && a[1] - i >=0 && flagleftup){
            if( b[a[0]-i][a[1]-i].piece=='B' || b[a[0]-i][a[1]-i].piece=='Q'){
                  *x=a[0]-i;
                *y=a[1]-i;
            z = 0; break;
        }else if(b[a[0]-i][-i+a[1]].piece == 'k' ){continue;}
        else if ( b[a[0]-i][a[1]-i].piece!='\0'){
        z = 1 ;
        flagleftup = 0;
        }

      } if(a[0]-i >=0 && a[1] + i < 8 && flagrightup){
          if( b[a[0]-i][a[1]+i].piece=='B' || b[a[0]-i][a[1]+i].piece=='Q'){
                  *x=a[0]-i;
                *y=a[1]+i;
            z = 0;
            break;
        }else if(b[a[0]-i][i+a[1]].piece == 'k' ){continue;}
        else if ( b[a[0]-i][a[1]+i].piece!='\0'){
        z = 1 ;
        flagrightup = 0;}}}}
      if(z == 1){
      if(a[0]+1 < 8 && ((a[1]+2< 8 && b[a[0]+1][a[1]+2].piece=='N')||(a[1]-2>=0 && b[a[0]+1][a[1]-2].piece == 'N'))){
              if( b[a[0]+1][a[1]+2].piece=='N'){*x = a[0]+1 ; *y = a[1]+2;}
              else if( b[a[0]+1][a[1]-2].piece == 'N'){*x = a[0]+1 ; *y = a[1]-2;}

        z = 0;
      } else if(a[0]-1 >=0 && ((a[1]+2< 8 && b[a[0]-1][a[1]+2].piece=='N')||(a[1]-2>=0 && b[a[0]-1][a[1]-2].piece == 'N'))){
           if(b[a[0]-1][a[1]+2].piece=='N'){*x = a[0]-1 ; *y = a[1]+2;}
            else if(  b[a[0]-1][a[1]-2].piece == 'N'){*x = a[0]-1 ; *y = a[1]-2;}

      z = 0 ;
      } else if(a[1]+1 < 8 && ((a[0]+2< 8 && b[a[0]+2][a[1]+1].piece=='N')||(a[0]-2>=0&& b[a[0]-2][a[1]+1].piece=='N'))){
         if(b[a[0]+2][a[1]+1].piece=='N'){*x = a[0]+2 ; *y = a[1]+1;}
            else if(  b[a[0]-2][a[1]+1].piece=='N'){*x = a[0]-2 ; *y = a[1]+1;}
      z = 0;}
      else if(a[1]-1>=0 && ((a[0]+2<8 && b[a[0]+2][a[1]-1].piece=='N')||(a[0]-2>=0&& b[a[0]-2][a[1]-1].piece=='N'))){
 if(b[a[0]+2][a[1]-1].piece=='N'){*x = a[0]+2 ; *y = a[1]-1;}
            else if(  b[a[0]-2][a[1]-1].piece=='N'){*x = a[0]-2 ; *y = a[1]-1;}
        z = 0 ;}}
return z;

}
void findthekingblack(unsigned char a[],block b[][8]){//returns the address of the black king
for(int i  = 0 ; i < 8 ; i++){
    for(int j = 0; j < 8 ; j ++ ) {
        if(b[i][j].piece=='K'){
            a[0]= i;
            a[1]=j;}}}}
int checkblack(block b[][8],unsigned char a[],unsigned char *x,unsigned char *y,int fixingpoint){//checks if the king is attacked (black)
    int z = 1;
 int flagright = 1; int flagleft = 1;
 int flagrightup = 1; int flagrightdown = 1 ;
 int flagleftup=1; int flagleftdown =  1 ;
for(int i = 1 ; i < 8; i ++ ){
    if(i + a[1] < 8 && flagright){
        if(b[a[0]][i+a[1]].piece == 'q' || b[a[0]][i+a[1]].piece == 'r'  ){
                *x=a[0];
                *y=a[1]+i;
         z= 0 ;

         break;
        }else if(b[a[0]][i+a[1]].piece == 'K'){continue;}
        else if (b[a[0]][i+a[1]].piece != '\0' ){
            z = 1; flagright = 0;
        }
    } if(a[1]-i >=0 && flagleft) {
        if(b[a[0]][a[1] - i].piece == 'q' || b[a[0]][a[1]-i].piece == 'r'  ){
                *x=a[0];
                *y=a[1]-i;
         z= 0 ;

         break;
        }else if(b[a[0]][a[1]-i].piece == 'K'){continue;}
        else if (b[a[0]][a[1]-i].piece != '\0' ){
            z = 1; flagleft = 0;}}}
if (z==1){
flagright=1; flagleft = 1 ;
for(int i = 1 ; i < 8; i ++ ){
    if(i + a[0] < 8 && flagright){
        if(b[a[0]+i][a[1]].piece == 'q' || b[a[0]+i][a[1]].piece == 'r'  ){
                *x=a[0]+i;
                *y=a[1];
         z= 0 ; break;
        }else if(b[a[0]+i][a[1]].piece == 'K'){continue;}
        else if (b[a[0]+i][a[1]].piece != '\0' ){
            z = 1; flagright = 0;
        }
    } if(flagleft && a[0] - i >= 0 ) {
        if(b[a[0]-i][a[1]].piece == 'q' || b[a[0]-i][a[1]].piece == 'r'  ){
                *x=a[0]-i;
                *y=a[1];
         z= 0 ;
         break;
        }else if(b[a[0]-i][a[1]].piece == 'K'){continue;}
        else if (b[a[0]-i][a[1]].piece != '\0' ){
            z = 1; flagleft = 0;}}}}
if (z==1){ if(fixingpoint != 25){
      if(a[0]-1 >=0 && a[1] - 1 >=0 && b[a[0]-1][a[1]-1].piece=='p'){
            *x=a[0]-1;
                *y=a[1]-1;
        z = 0;
      } else if(a[0]-1 >=0 && a[1]+1 < 8 && b[a[0]-1][a[1]+1].piece=='p')
      { *x=a[0]-1;
                *y=a[1]+1;
          z = 0;
      } } else if(fixingpoint ==25){ if(a[0]-1 < 8  && b[a[0]-1][a[1]].piece=='p'){
          *x=a[0]-1;
                *y=a[1];
        z = 0;}
} }if(z==1) {
      for(int i = 1 ; i < 8 ; i++){
            if(a[0]+i < 8 && a[1] + i < 8 && flagrightdown){
        if( b[a[0]+i][a[1]+i].piece=='b' || b[a[0]+i][a[1]+i].piece=='q'){
                *x=a[0]+i;
                *y=a[1]+i;
            z = 0;
            break;
        }else if(b[a[0]+i][i+a[1]].piece == 'K'){continue;}
        else if ( b[a[0]+i][a[1]+i].piece!='\0'){
        z = 1 ;
        flagrightdown = 0;}}
      if(a[0]+i < 8 && a[1] - i >=0 && flagleftdown){
         if( b[a[0]+i][a[1]-i].piece=='b' || b[a[0]+i][a[1]-i].piece=='q'){
                *x=a[0]+i;
                *y=a[1]-i;
            z = 0;
            break;
        }else if(b[a[0]+i][a[1]-i].piece == 'K'){continue;}
        else if ( b[a[0]+i][a[1]-i].piece!='\0'){
        z = 1 ;
        flagleftdown = 0;}}
      if(a[0]-i >=0 && a[1] - i >=0 && flagleftup){
            if( b[a[0]-i][a[1]-i].piece=='b' || b[a[0]-i][a[1]-i].piece=='q'){
                    *x=a[0]-i;
                *y=a[1]-i;
            z = 0;
            break;
        }else if(b[a[0]-i][a[1]-i].piece == 'K'){continue;}
        else if ( b[a[0]-i][a[1]-i].piece!='\0'){
        z = 1 ;
        flagleftup = 0;}
      } if(a[0]-i >=0 && a[1] + i < 8 && flagrightup){
          if( b[a[0]-i][a[1]+i].piece=='b' || b[a[0]-i][a[1]+i].piece=='q'){
                *x=a[0]-i;
                *y=a[1]+i;
            z = 0;
            break;
        }else if(b[a[0]-i][i+a[1]].piece == 'K'){continue;}
        else if ( b[a[0]-i][a[1]+i].piece!='\0'){
        z = 1 ;
        flagrightup = 0;}}}}
      if(z == 1){
      if(a[0]+1 < 8 && ((a[1]+2< 8 && b[a[0]+1][a[1]+2].piece=='n')||(a[1]-2>=0 && b[a[0]+1][a[1]-2].piece == 'n'))){
            if(b[a[0]+1][a[1]-2].piece == 'n'){*x=a[0]+1; *y=a[1]-2;}
            else if(b[a[0]+1][a[1]+2].piece=='n'){*x = a[0]+1; *y = a[1]+2;}
        z = 0;
      } else if(a[0]-1 >=0 && ((a[1]+2< 8 && b[a[0]-1][a[1]+2].piece=='n')||(a[1]-2>=0 && b[a[0]-1][a[1]-2].piece == 'n'))){
        if(b[a[0]-1][a[1]+2].piece == 'n'){*x=a[0]-1; *y=a[1]+2;}
            else if(b[a[0]-1][a[1]-2].piece=='n'){*x = a[0]-1 ; *y = a[1]-2;}
      z = 0 ;
      } else if(a[1]+1 < 8 && ((a[0]+2< 8 && b[a[0]+2][a[1]+1].piece=='n')||(a[0]-2>=0&& b[a[0]-2][a[1]+1].piece=='n'))){
         if(b[a[0]+2][a[1]+1].piece == 'n'){*x=a[0]+2; *y=a[1]+1;}
            else if(b[a[0]-2][a[1]+1].piece=='n'){*x = a[0]-2 ; *y = a[1]+1;}
      z = 0;}
      else if(a[1]-1>=0 && ((a[0]+2<8 && b[a[0]+2][a[1]-1].piece=='n')||(a[0]-2>=0&& b[a[0]-2][a[1]-1].piece=='n'))){
          if(b[a[0]+2][a[1]-1].piece == 'n'){*x=a[0]+2; *y=a[1]-1;}
            else if(b[a[0]-2][a[1]-1].piece=='n'){*x = a[0]-2 ; *y = a[1]-1;}
        z = 0 ;}}
        return z;
}
int checkmate(block b[][8],unsigned char a[],int turn){//checks if situation is checkmate
int c1=0,c2=1,c3=1,fixingpoint=25;
unsigned char piece[3],g1,g2;
check(b,a,&piece[0],&piece[1],1);
for (int i=-1;i<2;i++){
    for (int j=-1;j<2;j++){
        if (i==0&&j==0){
            continue;
        }
        else {
            if (a[0]+i>-1&&a[0]+i<8&&a[1]+j>-1&&a[1]+j<8){
                    if((turn ==1 && b[a[0]+i][a[1]+j].piece>=97&& b[a[0]+i][a[1]+j].piece<122)||(turn ==-1 && b[a[0]+i][a[1]+j].piece>=65&& b[a[0]+i][a[1]+j].piece<90)){
                        continue;
                    }
                    a[0]+=i;
                    a[1]+=j;
                    if(virtualmoving(a,b,turn)==1){
                        c1=1;
                        break;}
                    a[0]-=i;
                    a[1]-=j;
                    }}
            }if(c1==1){
                break;}}
if (turn ==1){c2=checkblack(b,piece,&g1,&g2,1);}
  else {c2=check(b,piece,&g1,&g2,1);}
if (c2==0){return 0;}
if (b[piece[0]][piece[1]].piece=='n'||b[piece[0]][piece[1]].piece=='p'||b[piece[0]][piece[1]].piece=='N'||b[piece[0]][piece[1]].piece=='P'){
}
else { int i;
  if (a[0]==piece[0]){
    if (a[1]<piece[1]){
      for ( i=1;i<(piece[1]-a[1]);i++){
        unsigned char w[3];
        w[0]=a[0];
        w[1]=a[1]+i;
        if (turn==1){
        c3=checkblack(b,w,&g1,&g2,fixingpoint);}
        else {c3=check(b,w,&g1,&g2,fixingpoint);}
        if (c3==0){return 0;}
      }
    }
    else {for (i=1;i<(a[1]-piece[1]);i++){
        unsigned char w[3];
        w[0]=a[0];
        w[1]=piece[1]+i;
        if (turn==1){
        c3=checkblack(b,w,&g1,&g2,fixingpoint);}
        else {c3=check(b,w,&g1,&g2,fixingpoint);}
    if (c3==0){return 0;}}}}
  else if (a[1]==piece[1]){
     if (a[0]<piece[0]){
      for (i=1;i<(piece[0]-a[0]);i++){
        unsigned char w[3];
        w[0]=a[0]+i;
        w[1]=a[1];
        if (turn==1){
        c3=checkblack(b,w,&g1,&g2,fixingpoint);}
        else {c3=check(b,w,&g1,&g2,fixingpoint);}
      if (c3==0){return 0;}}
    }
    else {for (i=1;i<(a[0]-piece[0]);i++){
        unsigned char w[3];
        w[0]=piece[0]+i;
        w[1]=a[1];
        if (turn==1){
        c3=checkblack(b,w,&g1,&g2,fixingpoint);}
        else {c3=check(b,w,&g1,&g2,fixingpoint);}
    if (c3==0){return 0;}}}}
  else if (a[0]>piece[0]){
    if (a[1]>piece[1]){
      for (i=1;i<(a[0]-piece[0]);i++){
        unsigned char w[3];;
        w[0]=piece[0]+i;
        w[1]=piece[1]+i;
        if (turn==1){
        c3=checkblack(b,w,&g1,&g2,fixingpoint);}
        else {c3=check(b,w,&g1,&g2,fixingpoint);}
    if (c3==0){return 0;}}}
    else {
       for (i=1;i<(a[0]-piece[0]);i++){
        unsigned char w[3];
        w[0]=piece[0]+i;
        w[1]=piece[1]-i;
        if (turn==1){
        c3=checkblack(b,w,&g1,&g2,fixingpoint);}
        else {c3=check(b,w,&g1,&g2,fixingpoint);}
    if (c3==0){return 0;}}}}
  else {
    if (a[1]>piece[1]){
      for (i=1;i<(piece[0]-a[0]);i++){
        unsigned char w[3];
        w[0]=piece[0]-i;
        w[1]=piece[1]+i;
        if (turn==1){
        c3=checkblack(b,w,&g1,&g2,fixingpoint);}
        else {c3=check(b,w,&g1,&g2,fixingpoint);}
    if (c3==0){return 0;}}}
    else {
       for (i=1;i<(piece[0]-a[0]);i++){
        unsigned char w[3];
        w[0]=piece[0]-i;
        w[1]=piece[1]-i;
        if (turn==1){
        c3=checkblack(b,w,&g1,&g2,fixingpoint);}
        else {c3=check(b,w,&g1,&g2,fixingpoint);}
    if (c3==0){return 0;}}
    }
  }
}
if ((c1==0)&&c2&&c3) {return 1;}
else {return 0;}
}
int stalematewhite(block b[][8], int flag ){//checks if situation is stalemate
    int z;
if(flag ==1){ z=0;
        unsigned char x[3]; unsigned char g1,g2; unsigned char piecee[3]; unsigned char king[3];
    for(int i = 0 ; i <8; i++ ){
            for(int j= 0 ; j < 8 ; j++){
        x[0] = i; x[1]=j;
        char temp;
        if(b[i][j].piece == '\0' && !checkblack(b,x,&piecee[0],&piecee[1],25) ){
            temp=b[i][j].piece;
          b[i][j].piece = b[piecee[0]][piecee[1]].piece;
          b[piecee[0]][piecee[1]].piece = '\0';
          findtheking(king,b);
          if(check(b,king,&g1,&g2,1) == 1){
                z = 1;
          }   b[piecee[0]][piecee[1]].piece =  b[i][j].piece;
                 b[i][j].piece = temp;
        }
    }}
}
return z;
}
int stalemateblack(block b[][8], int flag ){//checks if situation is stalemate
    int z;
if(flag == - 1){ z=0;
        unsigned char x[3]; unsigned char g1,g2,g3,g4; unsigned char king[3];
    for(int i = 0 ; i <8; i++ ){
            for(int j= 0 ; j < 8 ; j++){
        x[0] = i; x[1]=j;
        char temp;
        if(b[i][j].piece == '\0' && !check(b,x,&g1,&g2,25) ){
            temp=b[i][j].piece;


          b[i][j].piece = b[g1][g2].piece;
          b[g1][g2].piece = '\0';
          findthekingblack(king,b);
          if(checkblack(b,king,&g3,&g4,1) == 1){
                z = 1;

          }   b[g1][g2].piece =  b[i][j].piece;
                 b[i][j].piece = temp;
        }
    }}
}
return z;
}
void savingthegame(block b[][8],int a[],int d[],int *turn){
    FILE *fchess;
    fchess = fopen("C:\\Users\\chess.text","w+");
for(int i = 0 ; i < 8 ;i ++){
    for(int  j = 0 ; j < 8 ; j++){
        fprintf(fchess,"%c",b[i][j].piece);
    }
}
for(int i = 0 ; i < 10; i+=2){
    fprintf(fchess,"%c",(char)a[i]);
}
for(int i = 0 ; i < 10; i+=2){
    fprintf(fchess,"%c",(char)d[i]);
}fprintf(fchess,"%d",*turn);

fclose(fchess);
system("cls");
}
void loadingthegame(block b[][8],int a[],int d[],int *turn){
    FILE *fchess;
    fchess = fopen("C:\\Users\\3arrows\\Desktop\\lap7.prob2\\chess.text","r");
for(int i = 0 ; i < 8 ;i ++){
    for(int  j = 0 ; j < 8 ; j++){
        fscanf(fchess,"%c",&b[i][j].piece);
    }
}
for(int i = 0 ; i < 10; i+=2){
    fscanf(fchess,"%c",&a[i]);
}
for(int i = 0 ; i < 10; i+=2){
    fscanf(fchess,"%c",&d[i]);
}fscanf(fchess,"%d",&*turn);

fclose(fchess);
system("cls");
}
int castling(block b[0][8], char a[],unsigned char *x,unsigned char *y, int fixingpoint){
 int z = 0;
 if(fixingpoint == 1 && a[1]== 49 && a[0]== 101&& a[1]-a[3]==0 && abs(a[2]-a[0])==2 && (b[a[1]-49][a[0]-97+3].piece=='r' || b[a[1]-49][a[0]-97-4].piece=='r' )&& b[a[1]-49][a[0]-97].piece=='k' ){
  z = 1;
    if(a[2]-a[0]> 0 && b[a[1]-49][a[0]-97+3].piece=='r'){
        for(int i = 1; i < 3; i++){
            if(b[0][4+i].piece!='\0'){
                z= 0;}
        }}else if(a[2]-a[0]< 0 && b[a[1]-49][a[0]-97-4].piece=='r'){ for(int i = 1; i < 4; i++){
            if(b[0][4-i].piece!='\0'){
                z= 0;}}}
    if(z == 1){
            if(a[2]-a[0]> 0 && b[a[1]-49][a[0]-97+3].piece=='r'){
         for(int i = 0; i < 3; i++){
            unsigned char l[3]; l[0] = 0; l[1] = 4+i;
            if(!check(b,l,x,y,fixingpoint)){
                z= 0;}}}else if(a[2]-a[0]< 0 && b[a[1]-49][a[0]-97-4].piece=='r') {
              for(int i = 0; i < 3; i++){
            unsigned char l[3]; l[0] = 0; l[1] = 4-i;
            if(!check(b,l,x,y,fixingpoint)){
                z= 0;}}}}}
 if(z == 0){

 } else if ( z == 1){
 if(a[2]-a[0]>0){
    b[a[3]-49][a[2]-97].piece ='k';
    b[a[1]-49][a[0]-97].piece = '\0';
    b[a[1]-49][a[0]-97+3].piece='\0';
    b[a[3]-49][a[2]-97-1].piece = 'r';
 }else{
      b[a[3]-49][a[2]-97].piece = 'k';
    b[a[1]-49][a[0]-97].piece = '\0';
    b[a[1]-49][a[0]-97-4].piece = '\0';
    b[a[3]-49][a[2]-97+1].piece= 'r';
 }
 }
 return z;
}
int castlingblack(block b[0][8], char a[],unsigned char *x,unsigned char *y, int fixingpoint){
 int z = 0;
 if(fixingpoint == -1 && a[1]== 49+7 && a[0]== 101&& a[1]-a[3]==0 && abs(a[2]-a[0])==2 && (b[a[1]-(49)][a[0]-97+3].piece=='R' || b[a[1]-(49)][a[0]-97-4].piece=='R' )&& b[a[1]-(49)][a[0]-97].piece=='K' ){
  z = 1;
    if(a[2]-a[0]> 0 && b[a[1]-(49)][a[0]-97+3].piece=='R'){
        for(int i = 1; i < 3; i++){
            if(b[7][4+i].piece!='\0'){
                z= 0;}
        }}else if(a[2]-a[0]< 0 && b[a[1]-(49)][a[0]-97-4].piece=='R'){ for(int i = 1; i < 4; i++){
            if(b[7][4-i].piece!='\0'){
                z= 0;}}}
    if(z == 1){
            if(a[2]-a[0]> 0 && b[a[1]-(49)][a[0]-97+3].piece=='R'){
         for(int i = 0; i < 3; i++){
            unsigned char l[3]; l[0] = 7; l[1] = 4+i;
            if(!checkblack(b,l,x,y,fixingpoint)){
                z= 0;}}}else if(a[2]-a[0]< 0 && b[a[1]-(49)][a[0]-97-4].piece=='R') {
              for(int i = 0; i < 3; i++){
            unsigned char l[3]; l[0] = 7; l[1] = 4-i;
            if(!checkblack(b,l,x,y,fixingpoint)){
                z= 0;}}}}}
 if(z == 0){

 } else if ( z == 1){
 if(a[2]-a[0]>0){
    b[a[3]-49][a[2]-97].piece ='K';
    b[a[1]-49][a[0]-97].piece = '\0';
    b[a[1]-49][a[0]-97+3].piece='\0';
    b[a[3]-49][a[2]-97-1].piece = 'R';
 }else{
      b[a[3]-49][a[2]-97].piece = 'K';
    b[a[1]-49][a[0]-97].piece = '\0';
    b[a[1]-49][a[0]-97-4].piece = '\0';
    b[a[3]-49][a[2]-97+1].piece= 'R';
 }
 }
 return z;
}
int draw(int a [], int b[]){
    int z= 0;
    if(a[0]==8 && a[2]==1 &&a[4] == 2 && a[6] == 2 && a[8]==1){
        if(b[0]==8 && b[2]==2 &&b[4] == 2 && b[6] == 2 && b[8]==1){
             z = 1;
        }
    }

    return z;
}
int main()
{	int draw50moveWhite = 0;
    int draw50moveblack = 0;
    char undoarray[1000][7]; int numberofplays=0; int checkmateee = 0;
    zerosundoarr(undoarray);
    int i,j,z1,z2,flag,turn=1;
    char userinput[7];
    unsigned char kingposition[3],blackingposition[3],g1,g2;
    int weaten[10];
    int beaten[10];
 zerosarr(weaten,beaten);
 intializearr(weaten,beaten);
    block a[8][8];
	for (i=1;i<=8;i++){
  			for (j=1;j<=8;j++){
        a[i-1][j-1]=ReadingBlock(i,j);
        }}
    while (1){
            printf("\n\n\n\n\n\n\n\t\t\t      a       b       c       d       e       f       g       h\n");

        for (i=1;i<=8;i++){printf("\t\t\t    *****   *****   *****   *****   *****   *****   *****   *****   \n");
                printf("\t\t\t%d",i);
  			for (j=1;j<=8;j++){
                printf("    ");
                if (a[i-1][j-1].color=='.'){
                printf("\b%c %c %c",178,a[i-1][j-1].piece,178);}
                else {printf("\b%c %c %c",176,a[i-1][j-1].piece,176);}
                }
                printf("  %d",i);
                printf("\n");}
        printf("\t\t\t    *****   *****   *****   *****   *****   *****   *****   *****   \n");
               printf("\t\t\t      a       b       c       d       e       f       g       h\n");
               if (turn==1){
if (z1==0 && checkmate(a,kingposition,turn)){
    printf("Checkmaaaate!!!");
    checkmateee = 1;
}}
  else {
    if (z2==0 && checkmate(a,blackingposition,turn)){
    printf("Checkmaaaate!!!\n");
    checkmateee = 1;
}

}
if( turn == 1&&z1 == 1 && !stalematewhite(a,turn) ){
    printf("STALEMATE BROOO\n");
    checkmateee = 1;
}
if( turn == -1&&z2 == 1 && !stalemateblack(a,turn) ){
    printf("STALEMATE BROOO\n");
    checkmateee = 1;
}
if(draw50moveblack == 50 || draw50moveWhite == 50){
    printf("it can be a 50-Draw !!");
}
if(draw(weaten,beaten)||draw(beaten,weaten)){
  printf("it can be a draw !!");
}
               if (z1==0||z2==0){printf("Check \n");}
               printf("WHITE PIECES:\n");
               for(int i = 1 ; i < 10; i+=2){
                if(weaten[i] !=0 && weaten [i-1] != 0 && i%2!=0){
                    printf(" %d  %c ,",weaten[i-1],weaten[i]);
                }
               } printf("\n");
               printf("BLACK PIECES:\n");
               for(int i = 1 ; i < 10; i+=2){
                if(beaten[i] !=0 && beaten [i-1] != 0 && i%2!=0){
                    printf(" %d  %c ,",beaten[i-1],beaten[i]);
                }
               }printf("\n");
               if (turn==1){printf("White's turn : ");}
               if (turn==-1){printf("Black's turn : ");}
fgets(userinput,7,stdin);
fflush(stdin);
flag = checkmove(userinput,a,turn);
if(castling(a,userinput,&g1,&g2,turn) || castlingblack(a,userinput,&g1,&g2,turn)){
    savingplays(undoarray,numberofplays,userinput);
    numberofplays++;
    turn=-turn;
    system("cls");
}
if (userinput[0]=='-'&&userinput[1]=='1'&&userinput[2]=='\n'){
  break;
}
else if(userinput[0]=='l'&&userinput[1]=='\n'){
     loadingthegame(a,weaten,beaten,&turn);
}
else if(userinput[0] == 's'&&userinput[1]=='\n'){
        savingthegame(a,weaten,beaten,&turn);
}else {
if(userinput[0]!='u' && userinput[0]!='r' && checkmateee == 0 && (flag||castling(a,userinput,&g1,&g2,turn) )){
    savingplays(undoarray,numberofplays,userinput);
    undoarray[numberofplays][6]=a[userinput[3]-49][userinput[2]-97].piece;
    if((a[userinput[1]-49][userinput[0]-97].piece != 'p' && turn == 1) || a[userinput[1]-49][userinput[0]-97].piece == '\0' ){
        draw50moveWhite++;
    }else if((a[userinput[1]-49][userinput[0]-97].piece == 'p' && turn == 1 )|| a[userinput[1]-49][userinput[0]-97].piece != '\0' )
   {draw50moveWhite = 0;}
if(a[userinput[1]-49][userinput[0]-97].piece != 'P' && turn == -1 && a[userinput[1]-49][userinput[0]-97].piece == '\0' ){
    draw50moveblack++;
   }else if((a[userinput[1]-49][userinput[0]-97].piece == 'P' && turn == -1 )|| a[userinput[1]-49][userinput[0]-97].piece == '\0' )
   {draw50moveWhite = 0;}
}
    else if (userinput[0]=='u'&&userinput[1]=='\n' ){
      	if (numberofplays>0){
            numberofplays--;
        Moving(&a[undoarray[numberofplays][3]-49][undoarray[numberofplays][2]-97].piece,&a[undoarray[numberofplays][1]-49][undoarray[numberofplays][0]-97].piece,a,&turn,userinput,undoarray,numberofplays);
        if(undoarray[numberofplays][6]!='\0'){
            a[undoarray[numberofplays][3]-49][undoarray[numberofplays][2]-97].piece=undoarray[numberofplays][6];
            if(turn == 1 ){undoeatingpieces(weaten,undoarray[numberofplays][6]);}
            else if(turn == -1){undoeatingpieces(beaten,undoarray[numberofplays][6]);}
        }
        turn*=-1;
        system("cls");
        if(checkmateee == 1){
            checkmateee = 0;
        }
        }
    } else if(userinput[0]=='r'&&userinput[1]=='\n' && checkmateee ==0){if(undoarray[numberofplays][0]!='\0'){
         if(turn == 1 ){eatingpieces(beaten,a[undoarray[numberofplays][3]-49][undoarray[numberofplays][2]-97].piece);}
    else if(turn == -1){eatingpieces(weaten,a[undoarray[numberofplays][3]-49][undoarray[numberofplays][2]-97].piece);}
    char del[7];
    del[0]=undoarray[numberofplays][0];
    del[1]=undoarray[numberofplays][1];
    del[2]=undoarray[numberofplays][2];
    del[3]=undoarray[numberofplays][3];
    if(!castling(a,del,&g1,&g2,turn) && !castlingblack(a,del,&g1,&g2,turn)){
    Moving(&a[undoarray[numberofplays][1]-49][undoarray[numberofplays][0]-97].piece,&a[undoarray[numberofplays][3]-49][undoarray[numberofplays][2]-97].piece,a,&turn,userinput,undoarray,numberofplays);}
    numberofplays++;
     turn*=-1;
        system("cls");}}
if(flag == 1){
z1=callfn(a[userinput[1]-49][userinput[0]-97].piece,userinput,a);}
if(flag == 0||z1==0){

   system("cls"); }
else{if(turn == 1 && checkmateee == 0){
        eatingpieces(beaten,a[userinput[3]-49][userinput[2]-97].piece);
    } else if(turn == -1 && checkmateee == 0){
    eatingpieces(weaten,a[userinput[3]-49][userinput[2]-97].piece);}
    Moving(&a[userinput[1]-49][userinput[0]-97].piece,&a[userinput[3]-49][userinput[2]-97].piece,a,&turn,userinput,undoarray,numberofplays);
    if(checkmateee==0){
    numberofplays++;}
    system("cls");
   turn=-turn;}
findtheking(kingposition,a);
z1=check(a,kingposition,&g1,&g2,1);
findthekingblack(blackingposition,a);
z2=checkblack(a,blackingposition,&g1,&g2,1);

}
}

return 0;}



