#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
int xx=40,yy=22;
int xx1=1,yy1=1;
int key;
int pcscore=0,userscore=0;
int x[50],y[50],k=0,i;
int xo[50],yo[50];
int xp[50],yp[50];
void score();
void machine()
{
    gotoxy(xx,yy); textcolor(14);  cprintf("   л  ");
    gotoxy(xx,yy+1); textcolor(2); cprintf(" млллм   ");
    gotoxy(xx,yy+2); textcolor(2); cprintf("ллл ллл   ");

     textbackground(0);
}

void bullet()
{
	  int flag=0;

	int k;


	  textcolor(14);
	  for(i=0; i<=20; i++)
	  {
	      if(x[i]!=0)
	      {
		flag++;
		gotoxy(x[i],y[i]);
		if(y[i]!=1)
		{

		cprintf("%c",4);
		}
		if(y[i]!=22 && y[i]>=0)
		{
		gotoxy(x[i],y[i]+1);
		 cprintf(" ");
		}
		y[i]--;
		delay(22/flag);
	      }

	      if(y[i]==0)
	      {

	       x[i]=0;
	      }

	  }

}
int temp=0;
void target()
{


   int flag=0;
     system("cls");
     _setcursortype(_NOCURSOR);
       score();
     machine();
     bullet();
    gotoxy(xx1,yy1);   textcolor(4); cprintf("ллл ллл   ");
    gotoxy(xx1,yy1+1); textcolor(4); cprintf(" плллп   ");
    gotoxy(xx1,yy1+2); textcolor(14);cprintf("   л   ");

    if(temp==0)
    {
      xx1++;
      if(xx1>55)
      {
       temp=1;
      }

    }
    if(temp==1)
    {
      xx1--;
      if(xx1<2)
      {
       temp=0;
      }

    }
    for(i=0; i<=10; i++)
    {
      if(xp[i]==0)
      {
      xp[i]=xx1+3;
      yp[i]=yy1+3;
       }
    }
    for(i=0; i<=10; i++)
    {
      if(xp[i]!=0)
      {
	  flag++;
	  if(yp[i]!=22)
	  {
	  textcolor(11);
	  gotoxy(xp[i],yp[i]);
	  cprintf("%c",4);

	  }
	  if(yp[i]!=4)
	  {
	  gotoxy(xp[i],yp[i]-1);
	  cprintf("  ");
	  }
	  if(yp[i]==21 && xp[i]>=xx && xp[i]<=xx+5)
	  {
	   pcscore++;

	   sound(200);
	   delay(10);
	   nosound();

	  }


	  if(y[i]<4 && x[i]>=xx1 &&x[i]<=xx1+6)
	  {
	   userscore++;


	   sound(2000);
	   delay(10);
	   nosound();
	  }

	  else if( y[i]<4 && x[i]<xx1 && x[i]!=0 ||y[i]<4 && x[i]>xx1+6&&x[i]!=0)
	  {
	   userscore--;

	   sound(1000);
	   delay(10);
	   nosound();
	   if(userscore<0)
	   {
	    userscore=0;
	   }

	  }
	  yp[i]++;

      }
      if(yp[i]>=24)
      {
       xp[i]=0;
       yp[i]=0;
      }

    }



       delay(20);
}

void box(int x1,int y1,int space,int height,int boxcolor ,int boxbkcolor)
{
  int i2,i3;
  gotoxy(x1,y1-1);
  textcolor(boxcolor);
  textbackground(boxbkcolor);
  cprintf("к");

  for(i3=0; i3<height; i3++)
  {
  gotoxy(x1,y1+i3);
  textcolor(boxcolor);
  textbackground(boxbkcolor);
  cprintf("Г");
   }
  gotoxy(x1,y1+height);
  textcolor(boxcolor);
  textbackground(boxbkcolor);
  cprintf("Р");
  for(i2=1; i2<=space; i2++)
  {

  gotoxy(x1+i2,y1+height);
  textcolor(boxcolor);
  textbackground(boxbkcolor);
  cprintf("Ф");

  gotoxy(x1+i2,y1-1);
  textcolor(boxcolor);
  textbackground(boxbkcolor);
  cprintf("Ф");

  }

  gotoxy(x1+space,y1-1);
  textcolor(boxcolor);
  textbackground(boxbkcolor);
  cprintf("П");

  for(i3=0; i3<height; i3++)
  {
  gotoxy(x1+space,y1+i3);
  textcolor(boxcolor);
  textbackground(boxbkcolor);
  cprintf("Г");
   }

  gotoxy(x1+space,y1+height);
  textcolor(boxcolor);
  textbackground(boxbkcolor);
  cprintf("й");
}
void score()
{

   box(69,2,6,10,15,0);
     for(i=userscore; i<10; i++)
     {
      gotoxy(70,i+2);
      textcolor(4);
      cprintf("ллллл");

     }
     gotoxy(71,1);
     textcolor(15);
     cprintf("PC");



   box(69,14,6,10,15,0);
     for(i=pcscore/11; i<10; i++)
     {
      gotoxy(70,i+14);
      textcolor(2);
      cprintf("ллллл");

     }

     gotoxy(71,13);
     textcolor(15);
     cprintf("YOU");

   if(pcscore/11 ==10)
   {
      box(25,9,23,3,15,0);

      gotoxy(27,10);
      textcolor(14);
      cprintf("C O P U T E R  W I N ");

			sound(100);
			delay(210);
			nosound();
			sound(250);
			delay(100);
			nosound();
			sound(100);
			delay(210);
			nosound();
			sound(250);
			delay(250);
			nosound();

      getch();
      exit(1);

   }

 if(userscore ==10)
   {
      box(25,9,23,3,15,0);

      gotoxy(27,10);
      textcolor(14);
      cprintf("   Y O U  W I N ");

			sound(100);
			delay(210);
			nosound();
			sound(250);
			delay(100);
			nosound();
			sound(100);
			delay(210);
			nosound();
			sound(250);
			delay(250);
			nosound();
      getch();
      exit(1);
   }



}


void scrollbox(int x1,int y1,int x2,int y2 ,int scrollboxcolor)
{

int j;
   for(i=y1; i<=y2; i++)
   {
    for(j=x1; j<=x2; j++)
    {
      gotoxy(j,i);
       textbackground(scrollboxcolor);
      cprintf(" ");
    }
   }
   box(x1,y1+1,x2-x1,y2-y1-1,15,scrollboxcolor);

}
void keyintro()
{
  scrollbox(10,2,70,24,0);
  gotoxy(20,2);

  textcolor(15);
  cprintf(" Key Intruction  & Game Rules [ TAB KEY ] ");
  textbackground(4);  textcolor(15);
   gotoxy(12,4);  cprintf(" ->  Press Space Key To Shoot                             ");
   gotoxy(12,6);  cprintf(" ->  Press Left Key To Move Left Side                     ");
   gotoxy(12,8);  cprintf(" ->  Press Right Key To Move Right Side                   ");
   gotoxy(12,10);  cprintf(" ->  Press Esc Key To Exit                                ");
   gotoxy(12,12);  cprintf(" ->  Press Tab Key To Open Key Intruction Box             ");

  //scrollbox(10,13,70,24,0);

  textbackground(1);  textcolor(15);
   gotoxy(12,15);  cprintf(" -> If Your Bullet Touch To the Computer's Gun Machine    ");
   gotoxy(12,16);  cprintf("    Then Computer's Life Decrease                         ");
   gotoxy(12,18);  cprintf(" -> If Your Bullet Not Touch To the Computer's Gun Machine");
   gotoxy(12,19);  cprintf("    Then Computer's Life Increase                         ");

   gotoxy(12,21);  cprintf(" -> If Computes's Bullet Touch To the Your Gun Machine    ");
   gotoxy(12,22);  cprintf("    Then Your Life decrease                               ");

   gotoxy(30,24); textcolor(1+BLINK);
    textbackground(15);
    cprintf(" Press Any Key To Play ");
   for(i=1; i<=10; i++)
   {
    textbackground(0);
    gotoxy(8,7+i);
    textcolor(15);
    cprintf("Г");

   }

    textbackground(2);
    gotoxy(8,7);
    textcolor(7);
   cprintf("  ");

    textbackground(2);
    gotoxy(8,17);
    textcolor(7);
   cprintf("  ");
    textbackground(0);
    gotoxy(1,12);
    textcolor(15);
   cprintf("ФФФФФФФ");
   for(i=2; i<=23; i++)
   {
  gotoxy(1,i); textcolor(15); cprintf("л");
    }
}
void main()
{
   int j;
	 system("cls");
	 _setcursortype(_NOCURSOR);
	   keyintro();
	   getch();


   start:
       score();

    _setcursortype(_NOCURSOR);

	for(i=0;i<20;i++)
	{
		xo[i]=0;
	}
    while(1)
    {
      while(!kbhit())
      {

       machine();
       score();
       target();
       bullet();

      }
       machine();
      key=getch();
   switch(tolower(key))
   {
      case ' '    :

			for(i=0; i<20;i++)
			{
			if(x[i]==0)
			{
			x[i]=xx+3;
			y[i]=21;

		       goto start;
			 }
			}
		       goto start;



      case 27  :    exit(1);

      case 0   :  key=getch();
		  if(key==77 && xx<=55)
		  {
		    xx++;
		  }
		  else if(key==75 && xx>1)
		  {
		   xx--;
		  }
		 goto start;
      case 9   :
		      system("cls");
		      _setcursortype(_NOCURSOR);
		      keyintro();
		      getch();
		      goto start;
      default :   goto start;



    };
     }
}
