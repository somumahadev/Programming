#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
int i,j,A;
int  y[7]={4,9,14,19,24};
int x[7]={23,30,38,45,53};
int xo1=20,yo1=2,xo2=60,yo2=23;
int x1=31,y1=12,speed=300,score=0,life=2,n=3;

void border()
{
   for(i=1; i<=24; i++)
   {
   textcolor(1);
     window(20,i,31,i+1);
     cprintf("Û");
     window(60,i,61,i+1);
     cprintf("Û");

   }
   for(i=20; i<=60; i++)
   {


   textcolor(15);
     window(i,1,i+1,2);
     cprintf("Û");
     window(i,24,i+1,25);
     cprintf("Û");
   }

}
int d;
void obj()
{
   for(d=0; d<=4; d++)
   {
      textcolor(LIGHTCYAN);
      window(x[d],y[d],x[d]+5,y[d]+1);
      cprintf("ßßßßß");


   }
   for(j=21; j<=59; j++)
   {
      textcolor(4);
      window(j,yo1,j+1,yo1+1);
      cprintf("");
      textcolor(4);
      window(j,yo2,j+1 ,yo2+1);

      cprintf("");

   }
   textcolor(2);
  window(x1,y1,x1+1,y1+1);
  cprintf("");

}

  void Score()
{


     textcolor(9);
     window(2,3,20,4);
    cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
    window(2,4,20,5);
    cprintf("º               º");
    window(2,5,20,6);
    cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
    textcolor(15);
    window(4,4,20,5);
    cprintf("SCORE = %d",score);

}
void box()
{
    textcolor(9);
   window(2,7,20,8);
    cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
    window(2,8,20,9);
    cprintf("º               º");
    window(2,9,20,10);
    cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
}
void Life()
{

    textcolor(9);
   window(2,12,20,13);
    cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
    window(2,13,20,14);
    cprintf("º              º");
    window(2,14,20,15);
    cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
    textcolor(15);
    window(5,13,10,14);
    cprintf("LIFE=");
      if(life>0)
      {
    for(i=1; i<=life; i++)
    {
    textcolor(14);
    window(10+i,13,11+i,14);
    cprintf("%c",3);

   }
   }
   else
   {
	textcolor(14);
    window(10,13,13,14);
    cprintf(" 0 ");

   }

}
void key()
{

   textcolor(3);
   window(62,7,77,8);
    cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
    window(62,8,77,9);
    cprintf("³              ³");
    window(62,9,77,10);
    cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
      window(63,8,75,9);
      textcolor(LIGHTCYAN);
    cprintf("PAUCE = Space");

   textcolor(3);
   window(62,4,77,5);
    cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
    window(62,5,77,6);
    cprintf("³              ³");
    window(62,6,77,7);
    cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
      window(63,5,76,6);
      textcolor(LIGHTCYAN);
    cprintf("PLAY = press P");

      textcolor(3);
   window(62,10,77,11);
    cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
    window(62,11,77,12);
    cprintf("³              ³");
    window(62,12,77,13);
    cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
      window(63,11,76,12);
      textcolor(LIGHTCYAN);
    cprintf("LEFT = press A");


      textcolor(3);
   window(62,13,79,15);
    cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
    window(62,14,79,16);
    cprintf("³              ³");
    window(62,15,79,17);
    cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
      window(63,14,77,16);
      textcolor(LIGHTCYAN);
    cprintf("RIGHT =press S");



      textcolor(3);
   window(62,16,79,19);
    cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
    window(62,17,79,20);
    cprintf("³              ³");
    window(62,18,79,21);
    cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
      window(65,17,77,20);
      textcolor(LIGHTCYAN);
    cprintf("QUIT = ESC");



}
void keysound1()
{
  sound(2000);
  delay(100);
  nosound();
}
void gameover()
{



	 box();
	window(5,8,15,9);
	textcolor(4);
	cprintf("GAME OVER");
	keysound1();
	keysound1();
	keysound1();
	y1=12,life=2,score=0,n=3,speed=300;
	getch();
}

void main()
{
  system("cls");
  _setcursortype(_NOCURSOR);
  border();
  obj();
  key();
  Life();
  Score();
  score++;
  textbackground(0);

	 box();
	textcolor(2);
	window(5,8,15,9);
	cprintf("PLAYING...");
	Score();
	if(score%50==0)
	{
	speed-=30;
	if(speed<=60)
	{
	 speed=60;
	}
	}
  if(kbhit())
  {
     A=getch();
     if(A==27)
     {

     exit(0);
     }
     if(A=='A'||A=='a'||A==75)
     {
      x1--;
     }
     else if(A=='s'||A=='S'||A==77)
     {

      x1++;
     }
     else if(A==' ')
     {
	keysound1();
     while(!kbhit())
     {
	 box();
	textcolor(2);
	window(5,8,15,9);

	cprintf("PAUSED");
	delay(100);
     }
      if(kbhit())
      {
       keysound1();
       main();
      }
     }
    main();
  }
  if(!kbhit())
  {
    if(x1>=x[1] && x1<=x[1]+5 &&y1>=y[1]-2 && y1<=y[1]-1)
    {
    y1=y[1]-1;
       y1--;
       if(y1==2)
       {
	 if(life<1)
	 {
	 gameover();
	main();
	}
	else
	{
	 life--;
	 y1=12;
	 keysound1();
	 delay(500);
	 main();

	}
       }

    }

   else if(x1>=x[2] && x1<=x[2]+5 &&y1>=y[2]-2&& y1<=y[2]-1)
    {
	 y1=y[2]-1;
       y1--;
       if(y1==2)
       {
	 if(life==0)
	 {
	 gameover();
	main();
	}
	else
	{
	 life--;

	 keysound1();
	 delay(500);
	 y1=12;
	 main();

	}
       }
    }

  else if(x1>=x[3] && x1<=x[3]+5 &&y1>=y[3]-2 && y1<=y[3]-1)
    {
      y1=y[3]-1;
       y1--;
       if(y1==2)
       {

	 if(life==0)
	 {
	  gameover();
	main();
	}
	else
	{
	 life--;
	 y1=12;

	 keysound1();
	 delay(500);
	 main();

	}
       }

    }

   else if(x1>=x[4] && x1<=x[4]+5 &&y1>=y[4]-2 && y1<=y[4]-1)
    {
	 y1=y[4]-1;
       y1--;
       if(y1==2)
       {

	 if(life==0)
	 {
	 gameover();
	main();
	}
	else
	{
	 life--;
	 y1=12;

	 keysound1();
	 delay(500);
	 main();

	}

       }

    }

  else  if(x1>=x[0] && x1<=x[0]+5 &&y1>=y[0]-2  && y1<=y[0]-1)
    {
	 y1=y[0]-1;
       y1--;
       if(y1==2)
       {

	 if(life==0)
	 {
	 gameover();
	main();
	}
	else
	{
	 life--;
	 y1=12;

	 keysound1();
	 delay(500);
	 main();

	}
       }


    }

    else
    {
     y1++;
     if(y1>=24)
     {

	 if(life==0)
	 {
	 gameover();
	main();
	}
	else
	{
	 life--;
	 y1=12;

	 keysound1();
	 delay(500);
	 main();

	}
     }

    }
   for(j=0; j<5; j++)
   {
     y[j]--;
     if(y[j]<=1)
     {
      y[j]=23;

     }

   }
     delay(speed);
     main();
  }



}