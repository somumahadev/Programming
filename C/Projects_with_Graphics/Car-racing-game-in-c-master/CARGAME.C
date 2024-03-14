
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
int i=1,y=27,z=47;
int j=3,k=3;
int x=37,score=0,S;
 int n=100,life=3;
 int c1=1,c2=3,frq=2000;
void border()
{
    textbackground(0);
   textcolor(3);

   for(i=1; i<=25; i++)
   {
   window(1,i,2,i+1);
   cprintf("Û");

    window(80,i,80,i+1);
   cprintf("Û");

   }
   for(i=1; i<=24; i++)
   {

     textcolor(2);
    window(24,i,24,i+1);
    cprintf("Û");
    window(60,i,62,i+1);
    cprintf("Û");



   }

}
void car()
{

  window(x,18,x+9,20);
  textcolor(14);
  cprintf(" ÛÛ    ÛÛ");
  window(x,19,x+9,21);
  cprintf("ÛÛÛÛßßÛÛÛÛ");
  window(x,20,x+9,22);
  cprintf(" ÛÛÛ  ÛÛÛ");
  window(x,21,x+9,23);
  cprintf("ÛÛÛÛÛÛÛÛÛÛ");
  window(x,22,x+9,24);
  cprintf(" ßßßßßßßß");

  }

  void cargame()
  {
     textcolor(c1);
     window(y,j,y+9,j+1);
  cprintf(" ÜÜÜÜÜÜÜÜ");
   window(y,j+1,y+9,j+2);
  cprintf("ÛÛÛÛÛÛÛÛÛÛ");
   window(y,j+2,y+9,j+3);
  cprintf(" ÛÛÛ  ÛÛÛ");
   window(y,j+3,y+9,j+4);
  cprintf("ÛÛÛÛÜÜÛÛÛÛ");
   window(y,j+4,y+9,j+5);
  cprintf(" ÛÛ    ÛÛ ");

  }

  void cargame2()
  {
     textcolor(c2);
     window(z,k,z+9,k+1);
  cprintf(" ÜÜÜÜÜÜÜÜ");
   window(z,k+1,z+9,k+2);
  cprintf("ÛÛÛÛÛÛÛÛÛÛ");
   window(z,k+2,z+9,k+3);
  cprintf(" ÛÛÛ  ÛÛÛ");
   window(z,k+3,z+9,k+4);
  cprintf("ÛÛÛÛÜÜÛÛÛÛ");
   window(z,k+4,z+9,k+5);
  cprintf(" ÛÛ    ÛÛ ");

  }

  int A;
  void Score()
{


     textcolor(3);
     window(2,3,20,4);
    cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
    window(2,4,20,5);
    cprintf("º               º");
    window(2,5,20,6);
    cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
    window(4,4,20,5);
    cprintf("SCORE = %d",score);

}
void box()
{
    textcolor(3);
   window(2,7,20,8);
    cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
    window(2,8,20,9);
    cprintf("º               º");
    window(2,9,20,10);
    cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
}
void Life()
{

    textcolor(3);
   window(2,12,20,13);
    cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
    window(2,13,20,14);
    cprintf("º               º");
    window(2,14,20,15);
    cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
    textcolor(3);
    window(4,13,20,14);
    cprintf(" LIFE = %d",life);


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
      textcolor(LIGHTBLUE);
    cprintf("PAUCE = Space");

   textcolor(3);
   window(62,4,77,5);
    cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
    window(62,5,77,6);
    cprintf("³              ³");
    window(62,6,77,7);
    cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
      window(63,5,76,6);
      textcolor(LIGHTGREEN);
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
      textcolor(LIGHTGREEN);
    cprintf("QUIT = ESC");



}
void play()
{
      box();
      textcolor(2);
     window(3,8,20,9);
     cprintf("Press p to play");
}
void keysound()
{

 sound(frq);
 delay(100);
 nosound();
}
 int K,P;
void main()
{

     i=1;
 system("cls");
 _setcursortype(_NOCURSOR);
  border();
  key();

  car();
  cargame();
  Life();
  label3:
   Score();
   box();
   play();
 P=getch();
 keysound();
  if(P=='p' || P=='P'||P==13)
  {
    goto start;

  }
  else if(P==27)
  {

  exit(0);
  }
  else
  {
  goto label3;
  }
  start:
 system("cls");
   _setcursortype(_NOCURSOR);
  border();
  key();
  box();
  car();
  cargame();
  Life();
    score++;
  Score();
  j++;

 cargame2();
  k++;
     if(j==23 && k==23)
     {
     c1++;
     c2++;
     if(c1>=15)
     {
       c1=1;
     }
     else if(c2>=15)
     {
      c2=1;
     }
     }
     if(score%100==0)
     {
     n-=10;
     if(n<=30)
     {
      n=30;
     }
     }
  label:

  if(x==y && j>=14 ||x==z && k>=14)
  {

  if(life==1)
  {
     label1:
     life=0;
	textcolor(3);
     box();
     Life();
       textcolor(6);
      window(4,8,20,9);
    cprintf("GAME OVER !");
    sleep(1);
    S=getch();
    keysound();
    if(S=='p'||S=='P'||S==13)
    {
     i=1,y=27, j=3,x=y+10,score=0,z=37,k=3,n=100,life=3;
    goto start;
    }
    else if(S==27)
    {
     exit(0);
    }
    else
    {
     goto label1;
    }
  }
  else
  {

   life--;
   label2:
     i=1,y=27, j=3,x=y+10,z=37,k=3;
     play();
     K=getch();
     keysound();
     if(K=='p'||K=='P'||K==13)
     {
      goto start;
      }
      else if(K==27)
      {
	 exit(0);
      }
      else
      {
      goto label2;
      }
  }
  }
 if(j==23 )
  {
   j=2;
   y+=10;
   if(y>=55)
    {
     y=27;
    }    
  }
 if(k==23 )
  {
   k=2;
   z+=10;
   if(z>=55)
    {
     z=27;
    }
  }
  box();

  if(kbhit())
  {
  A=getch();
  keysound();
  if(A=='a'||A=='A')
  {
     x-=10;

     if(x<=27)
    {
     x=27;
     }
     goto start;
  }
  else if(A=='s'||A=='S')
  {
	x+=10;
	 if(x>=47)
	 {

	x=47;
	}
	goto start;
  }
  else if(A==0)
  {
   A=getch();

  if(A==75)
  {
     x-=10;

     if(x<=27)
    {
     x=27;
     }
     goto start;
  }
  else if(A==77)
  {
	x+=10;
	 if(x>=47)
	 {

	x=47;
	}
	goto start;

  }
  else
  {
   goto start;

  }

  }

  else if(A==27)
   {
	exit(0);
   }
   else if(A=='p'||A=='P'||A==13)
   {
     goto start;

   }
  else if(A==' ')
  {
   while(!kbhit())
   {
     textcolor(3);
   box();
      window(7,8,20,9);

     textcolor(2);
     cprintf("PAUSED");
     delay(100);

   }
   if(kbhit())
   {
    goto start;
   }
  }
 }

 else
 {
    textcolor(3);
   box();
      window(7,8,20,9);

     textcolor(2);
     cprintf("PLAYING..");
   delay(n);
   goto start;
 }

}