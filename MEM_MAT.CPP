#include <fstream.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <time.h>



int m[6][6];

void page_home();
void page_index();
void gdisplay();
void ydisplay();
void matcalc();
void howtoplay_1();
void howtoplay_2();
void controls();


void matcalc()
{
 clearviewport();

 int i, j, index1=0, index2=0, temp=0;

 for(i=0; i<6; i++)
 {
  for(j=0; j<6; j++)
  {
   if(i%3==0)
   {
    m[i][j]=j;
   }
   else if(i%3==1)
   {
    m[i][j]=j+6;
   }
   else if(i%3==2)
   {
    m[i][j]=j+12;
   }
  }
 }

 randomize();

 for(i=0;i<6;i++)
 {
  for(j=0;j<6;j++)
  {
   index1=random(6);
   index2=random(6);
   temp=m[i][j];
   m[i][j]=m[index1][index2];
   m[index1][index2]=temp;
  }
 }

 /*for(i=0;i<6;i++)
 {
  for(j=0; j<6; j++)
  {
   printf("%d\t", m[i][j]);
  }
  printf("\n");
 }

 getch(); */

 clearviewport();

 ydisplay();
}

void gdisplay()
{

 floodfill(2,2,2);

 for(int i=100;i<=400;i++)
 {
  for(int j=100;j<=400; j=j+50)
  {
   putpixel(i,j,2);
  }
 }


 for(int j=100;j<=400;j++)
 {
  for(int i=100;i<=400; i=i+50)
  {
   putpixel(i,j,2);
  }
 }

}

void ydisplay()
{
 gdisplay();
 floodfill(2,2,2);

 int a, i1, i2, j1, j2, ti2, tj2, xc, yc;
 int chkctr=0, lctr=0, scrctr=200, endctr=0;;
 int temp1, temp2, temp3;
 int chk_arr[2];
 char buf[1];

 i2=j2=100;
 xc=yc=0;

 char ch;

 settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);

 for(i1=i2;i1<=i2+50;i1++)
 {
  for(j1=j2;j1<=j2+50;j1=j1+50)
  {
   putpixel(i1, j1, 14);
  }
 }

 for(i1=i2;i1<=i2+50;i1=i1+50)
 {
  for(j1=j2;j1<=j2+50;j1++)
  {
   putpixel(i1, j1, 14);
  }
 }

 while(lctr<=0)
 {

  for(int i=0; i<6; i++)
  {
   for(int j=0; j<6; j++)
   {
    if(m[i][j]==-1)
     endctr++;
   }
  }

  if(endctr==36)
  {
   ifstream fin;
   ofstream fout;

   fin.open("highscores.txt");
   int s1;
   fin>>s1;

   if(scrctr>s1)
   {
    fin.close();
    fout.open("highscores.txt");
    fout<<scrctr;
    fout.close();
   }
   else
    fin.close();

   settextstyle(SMALL_FONT, HORIZ_DIR, 6);
   outtextxy(430, 220, "congratulations");
   outtextxy(430, 250, "You score is");
   sprintf(buf, "%d", scrctr);
   outtextxy(560, 250, buf);
   outtextxy(430, 325, "press enter...");
   break;
  }
  else
   endctr=0;

  ch=getch();
  switch(ch)
  {
   case 'w' : if(j2>100)
	      {
	       gdisplay();
	       j2=j2-50;
	       for(i1=i2;i1<=i2+50;i1++)
	       {
		for(j1=j2;j1<=j2+50;j1=j1+50)
		{
		 putpixel(i1, j1, 14);
		}
	       }

	       for(i1=i2;i1<=i2+50;i1=i1+50)
	       {
		for(j1=j2;j1<=j2+50;j1++)
		{
		 putpixel(i1, j1, 14);
		}
	       }
	      }
	      break;

   case 's' : if(j2<350)
	      {
	       gdisplay();
	       j2=j2+50;
	       for(i1=i2;i1<=i2+50;i1++)
	       {
		for(j1=j2;j1<=j2+50;j1=j1+50)
		{
		 putpixel(i1, j1, 14);
		}
	       }

	       for(i1=i2;i1<=i2+50;i1=i1+50)
	       {
		for(j1=j2;j1<=j2+50;j1++)
		{
		 putpixel(i1, j1, 14);
		}
	       }
	      }
	      break;

   case 'a' : if(i2>100)
	      {
	       gdisplay();
	       i2=i2-50;
	       for(i1=i2;i1<=i2+50;i1++)
	       {
		for(j1=j2;j1<=j2+50;j1=j1+50)
		{
		 putpixel(i1, j1, 14);
		}
	       }

	       for(i1=i2;i1<=i2+50;i1=i1+50)
	       {
		for(j1=j2;j1<=j2+50;j1++)
		{
		 putpixel(i1, j1, 14);
		}
	       }
	      }
	      break;

   case 'd' : if(i2<350)
	      {
	       gdisplay();
	       i2=i2+50;
	       for(i1=i2;i1<=i2+50;i1++)
	       {
		for(j1=j2;j1<=j2+50;j1=j1+50)
		{
		 putpixel(i1, j1, 14);
		}
	       }

	       for(i1=i2;i1<=i2+50;i1=i1+50)
	       {
		for(j1=j2;j1<=j2+50;j1++)
		{
		 putpixel(i1, j1, 14);
		}
	       }
	      }
	      break;

   case 'e' : scrctr--;
	      xc=(j2/50)-2;
	      yc=(i2/50)-2;
	      if(chkctr==0 && m[xc][yc]!=-1)
	      {
	       temp1=m[xc][yc];

	       ti2=i2;
	       tj2=j2;
	       chkctr=1;
	       sprintf(buf, "%d", m[xc][yc]);
	       outtextxy((i2+i2+50)/2, (j2+j2+50)/2, buf);
	      }
	      else if(chkctr==1 && m[xc][yc]!=-1)
	      {
	       temp2=m[xc][yc];
	       sprintf(buf, "%d" , m[xc][yc]);
	       outtextxy((i2+i2+50)/2, (j2+j2+50)/2, buf);
	       temp3=temp2;
	       if(temp1!=temp3)
	       {
		for(a=0;a<50;a++)
		 delay(20);

		for(i1=ti2+3;i1<=ti2+47;i1++)
		{
		 for(j1=tj2+3;j1<=tj2+47;j1++)
		 {
		  putpixel(i1, j1, 1);
		 }
		}

		for(i1=i2+3;i1<=i2+47;i1++)
		{
		 for(j1=j2+3;j1<=j2+47;j1++)
		 {
		  putpixel(i1, j1, 1);
		 }
		}

	       }
	       else
	       {

		for(i1=0; i1<6; i1++)
		{
		 for(j1=0; j1<6; j1++)
		 {
		  if(m[i1][j1]==temp1)
		   m[i1][j1]=-1;
		 }
		}

	       }
	       chkctr=0;
	      }

	      break;

   case 'q' : page_home();

  };

 }

 getch();
 page_home();
}


void howtoplay_1()
{
 clearviewport();

 floodfill(2,2,2);

 setcolor(WHITE);
 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
 outtextxy(95, 20, "WELCOME TO MEMORY MATRIX:");

 setcolor(WHITE);

 char ch;
 int i,j;
 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);

 outtextxy(50, 100, "This is a memory based 2D game");
 outtextxy(50, 140, "When you start the game you will see a 6X6 matrix");
 outtextxy(50, 180, "Each box in the matrix is hiding a number");
 outtextxy(50, 220, "When you select the box, you will see the number");
 outtextxy(50, 245,  "hidden inside that box");

 for(i=200; i<=380; i++)
 {
  for(j=290; j<=470; j=j+30)
   putpixel(i,j,2);
 }

 for(i=200; i<=380; i=i+30)
 {
  for(j=290; j<=470; j++)
   putpixel(i,j,2);
 }

 settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
 outtextxy(274, 364, "8");

 setcolor(3);
 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
 outtextxy(395, 440, "b - back   n - next page");

 setcolor(14);
 rectangle(260, 350, 290, 380);


 ch=getch();
 if(ch=='b')
  page_home();
 else if(ch=='n')
  howtoplay_2();
 else
  howtoplay_1();

}

void howtoplay_2()
{
 clearviewport();

 floodfill(2,2,2);

 setcolor(WHITE);

 char ch;
 int i,j;
 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);

 outtextxy(50, 50, "Select 2 numbers consecutively");
 outtextxy(50, 90, "If the 2 numbers are same, they will remain in the box, ");
 outtextxy(50, 115, "and the box will get unlocked");
 outtextxy(50, 340, "If the 2 numbers are not same, they will automatically");
 outtextxy(50, 365,  "disappear after some time");
 outtextxy(50, 405, "Unlock the entire matrix TO WIN!");

 for(i=200; i<=380; i++)
 {
  for(j=150; j<=330; j=j+30)
   putpixel(i,j,2);
 }

 for(i=200; i<=380; i=i+30)
 {
  for(j=150; j<=330; j++)
   putpixel(i,j,2);
 }

 settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
 outtextxy(244, 284, "8");
 outtextxy(364, 164, "8");

 setcolor(3);
 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
 outtextxy(370, 440, "b - back    q - main menu");

 setcolor(14);
 rectangle(350, 150, 380, 180);


 ch=getch();
 if(ch=='b')
 howtoplay_1();
 else if(ch=='q')
 page_home();
 else
 howtoplay_2();

}

void controls()
{
 clearviewport();

 floodfill(2,2,2);

 char ch='\0';

 setcolor(WHITE);
 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
 outtextxy(220, 50, "CONTROLS:");

 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);

 setcolor(WHITE);
 outtextxy(220, 130, "w - Move up");
 outtextxy(220, 160, "a - Move left");
 outtextxy(220, 190, "s - Move down");
 outtextxy(220, 220, "d - Move right");
 outtextxy(220, 250, "e - Select the box");
 outtextxy(220, 280, "q - Quit");

 setcolor(3);
 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
 outtextxy(470, 440, "b - back");

 ch=getch();
 if(ch=='b')
  page_home();
 else
  controls();

}

void page_first()
{
 int i;

 clearviewport();

 setfillstyle(SOLID_FILL, 1);
 floodfill(14, 14, 14);

 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 5);

 for(i=0; i<20; i++)
 delay(35);

 outtextxy(130, 130, "e");

 for(i=0; i<20; i++)
 delay(15);

 outtextxy(150, 130, "c");

 for(i=0; i<20; i++)
 delay(15);

 outtextxy(170, 130, "c");

 for(i=0; i<20; i++)
 delay(15);

 outtextxy(190, 130, "e");

 for(i=0; i<20; i++)
 delay(15);

 outtextxy(210, 130, "n");

 for(i=0; i<20; i++)
 delay(15);

 outtextxy(230, 130, "t");

 for(i=0; i<20; i++)
 delay(15);

 outtextxy(245, 130, "r");

 for(i=0; i<20; i++)
 delay(15);

 outtextxy(260, 130, "i");

 for(i=0; i<20; i++)
 delay(15);

 outtextxy(270, 130, "c");

 for(i=0; i<20; i++)
 delay(25);

 outtextxy(330, 130, "c");

 for(i=0; i<20; i++)
 delay(15);

 outtextxy(350, 130, "r");

 for(i=0; i<20; i++)
 delay(15);

 outtextxy(365, 130, "e");

 for(i=0; i<20; i++)
 delay(15);

 outtextxy(385, 130, "a");

 for(i=0; i<20; i++)
 delay(15);

 outtextxy(405, 130, "t");

 for(i=0; i<20; i++)
 delay(15);

 outtextxy(420, 130, "i");

 for(i=0; i<20; i++)
 delay(15);

 outtextxy(430, 130, "o");

 for(i=0; i<20; i++)
 delay(15);

 outtextxy(450, 130, "n");

 for(i=0; i<20; i++)
 delay(15);

 outtextxy(470, 130, "s");

 for(i=0; i<20; i++)
 delay(25);

 settextstyle(SMALL_FONT, HORIZ_DIR, 5);
 outtextxy(215, 450, "A Manthan Bhatt Company");

 for(i=0; i<20; i++)
 delay(180);

 page_index();

 exit(0);
}

void page_index()
{
 int i, j;

 clearviewport();

 setfillstyle(SOLID_FILL, 1);
 floodfill(14,14,14);

 settextstyle(SANS_SERIF_FONT , HORIZ_DIR, 8);
 setcolor(WHITE);
 outtextxy(40, 120, "MEMORY MATRIX");

 rectangle(220, 350, 420, 370);

  for(i=0; i<50; i++)
  delay(10);

  for(i=222; i<=418; i++)
  {
   if(i<350)
   delay(25+i-222);
   else
   delay(420-i);
   for(j=352; j<=368; j++)
   putpixel(i,j,2);
  }


 settextstyle(DEFAULT_FONT , HORIZ_DIR, 1);
 setcolor(WHITE);
 outtextxy(275, 380, "press enter");

 getch();
 page_home();


}


void page_home()
{

 int i, j, k, chkc, ctr=0;
 int num1, num2, cordi1, cordj1, cordi2, cordj2;
 char buf[1];
 char ch;


 clearviewport();

 setfillstyle(SOLID_FILL, 1);
 floodfill(2,2,2);

 for(i=0;i<4;i++)
 {
  for(j=40; j<=290; j++)
  {
   for(k=130+i*70; k<=170+i*70; k++)
    putpixel(j,k, 2);
  }
 }

 setcolor(WHITE);

 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 6);
 outtextxy(135, 20, "MEMORY MATRIX");

 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
 outtextxy(70, 128, "1.New Game");
 outtextxy(50, 198, "2.How To Play?");
 outtextxy(90, 268, "3.Controls");
 outtextxy(120, 338, "4.Quit");

 {
  //block for displaying the high score

  ifstream fin;
  int s;
  char buf[1];

  fin.open("highscores.txt");

  fin>>s;

  settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);

  sprintf(buf, "%d", s);
  outtextxy(520, 400, buf);

  outtextxy(450, 400, "Best :");

  fin.close();

 }


 for(i=350;i<=590;i++)
 {
  for(j=150; j<=390; j=j+40)
  {
   putpixel(i, j, 3);
  }
 }

 for(i=350;i<=590;i=i+40)
 {
  for(j=150; j<=390; j++)
  {
   putpixel(i, j, 3);
  }
 }

 randomize();

 while(ctr<=0)
 {

 if(kbhit())
 {
  ch=getch();

  setcolor(WHITE);

  switch(ch)
  {
   case '1': matcalc();
	     break;
   case '2': howtoplay_1();
	     break;
   case '3': controls();
	     break;
   case '4': exit(0);
	     break;
  }

 }


 setcolor(WHITE);

 num1=random(18);
 num2=random(18);
 cordi1=random(5);
 cordi2=random(5);
 cordj1=random(5);
 cordj2=random(5);

 if(cordi1==cordi2 && cordj1==cordj2)
 {
  if(cordi2<3)
  cordi2=cordi2+3;
  else
  cordi2=cordi2-2;
 }

 settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);

 if(num1>9)
  chkc=5;
 else
  chkc=0;

 sprintf(buf, "%d", num1);
 outtextxy((cordi1*40)+20+350 - chkc , (cordj1*40)+20+150, buf);

 if(num2>9)
  chkc=5;
 else
  chkc=0;

 for(i=0; i<20; i++)
 delay(50);

 sprintf(buf, "%d", num2);
 outtextxy((cordi2*40)+20+350 - chkc , (cordj2*40)+20+150, buf);

 for(i=0;i<20;i++)
 delay(90);

 for(i=cordi1*40+3+350; i<=cordi1*40+37+350; i++)
 {
  for(j=cordj1*40+3+150; j<=cordj1*40+37+150; j++)
  {
   putpixel(i,j,1);
  }
 }

 for(i=cordi2*40+3+350; i<=cordi2*40+37+350; i++)
 {
  for(j=cordj2*40+3+150; j<=cordj2*40+37+150; j++)
  {
   putpixel(i,j,1);
  }
 }

 ctr--;
 }

}

void main()
{
   int gdriver = DETECT, gmode;
   initgraph(&gdriver, &gmode, "");
   page_index();
   getch();
   closegraph();
}
