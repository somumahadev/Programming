#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>

int l=100;
int b=50;
int k=100;
int c;
void logo()
{
       //for backgraound
  setcolor(BLUE);
  setfillstyle(10,BLUE);
  rectangle(0,0,600,440);
  floodfill(1,1,BLUE);


  //outer circle

  setcolor(14);
  setfillstyle(1,14);
  circle(300,60,50);
  floodfill(346,60,14);
  //innner circle
    setcolor(BLUE);
  setfillstyle(1,BLUE);
  circle(300,60,45);
  floodfill(301,61,BLUE);

    //inner text
    setcolor(14);
    settextstyle(7,0,1);
    outtextxy(280,50,"KBC");




}
void quit()
{


    //quit button
    setcolor(GREEN);
    setfillstyle(0,BLUE);
    rectangle(375,400,600,430);
    settextstyle(8,0,1);
    outtextxy(380,400,"QUIT  = ESC KEY");
}
void conti()
{
    //quit button
    setcolor(GREEN);
    setfillstyle(0,GREEN);
    rectangle(375,350,600,380);
    settextstyle(8,0,1);
    outtextxy(380,350,"PLAY  =PRESS SPACE");
}
void quesbg()
{
       setcolor(14);
       line(0,200,100,200);
       line(100,200,130,170);
       line(100,200,130,230);
       line(130,170,470,170);
       line(130,230,470,230);
       line(470,170,500,200);
       line(470,230,500,200);
       line(500,200,600,200);

}
void optnbg()
{
//option a
    setcolor(14);
   line(200,270,220,250);
   line(220,250,340,250);
   line(340,250,360,270);

   line(200,270,220,290);
   line(220,290,340,290);
   line(340,290,360,270);
   //option b
   line(200-l,270+b,220-l,250+b);
   line(220-l,250+b,340-l,250+b);
   line(340-l,250+b,360-l,270+b);

   line(200-l,270+b,220-l,290+b);
   line(220-l,290+b,340-l,290+b);
   line(340-l,290+b,360-l,270+b);

  //option c
    line(200+l,270+b,220+l,250+b);
   line(220+l,250+b,340+l,250+b);
   line(340+l,250+b,360+l,270+b);

   line(200+l,270+b,220+l,290+b);
   line(220+l,290+b,340+l,290+b);
   line(340+l,290+b,360+l,270+b);

   //option d
    setcolor(14);
   line(200,270+k,220,250+k);
   line(220,250+k,340,250+k);
   line(340,250+k,360,270+k);

   line(200,270+k,220,290+k);
   line(220,290+k,340,290+k);
   line(340,290+k,360,270+k);

}
void sorry()
{
int i;

  setcolor(RED);

  settextstyle(8,0,1);
  setfillstyle(0,1);
  rectangle(10,50,200,150);
  floodfill(11,51,4);
  outtextxy(20,60,"SORRY");
  outtextxy(20,100,"WRONG ANSWER");
    for(i=1000; i>=0; i-=10)
    {
     sound(i);
     delay(10);
    }
    nosound();
  delay(1000);

}
void right()
{
   int i;
 setcolor(GREEN);
  settextstyle(8,0,1);
  setfillstyle(0,1);
  rectangle(10,50,240,150);
  floodfill(11,51,GREEN);
  outtextxy(20,60,"RIGHT ANSWER");
  outtextxy(20,100,"YOUR SCORE IS +100");
    for(i=0; i<=1500; i+=30)
    {
     sound(i);
     delay(10);
    }


    nosound();
  delay(1000);

}
void help()
{        int i;
	cleardevice();
	logo();
	quesbg();
	   setcolor(GREEN);
     settextstyle(8,0,1);
     outtextxy(145,185,"KBC");
     outtextxy(190,185,":INTRUCTIONS");
      setcolor(CYAN);
  settextstyle(8,0,1);
  rectangle(200,250,420,380);
  outtextxy(220,260,"ANSWER A=PRESS A ");
  outtextxy(220,290,"ANSWER B=PRESS B");
  outtextxy(220,320,"ANSWER C=PRESS C");
  outtextxy(220,350,"ANSWER D=PRESS D");

  delay(3000);
}
void aboutlogo()
{

   //quit button
    setcolor(GREEN);
    setfillstyle(0,GREEN);
    rectangle(375,300,600,340);
    settextstyle(8,0,1);
    outtextxy(380,305,"ABOUT = PRESS A");
}
void about()
{
     cleardevice();
	logo();
	quesbg();
	setcolor(GREEN);
     settextstyle(8,0,1);
     outtextxy(180,180,"KBC");
     outtextxy(250,180,":   ABOUT");
      setcolor(CYAN);
  settextstyle(8,0,1);
  rectangle(100,250,600,410);
  setcolor(GREEN);
     outtextxy(110,260,"DEVELOPER  :");
       setcolor(CYAN);
  outtextxy(230,260,"   AJAYSINH RATHOD");
  setcolor(GREEN);
   outtextxy(110,290,  "MADE ON    :");
     setcolor(CYAN);
  outtextxy(230,290,"   12TH OCTOBER 2019");
  setcolor(GREEN);
   outtextxy(110,320,  "CONDITIONS  :");
   setcolor(CYAN);
  outtextxy(180,350," ONE TIME YOU PRESS ANY OPTION");
  outtextxy(180,380," AFTER THAT YOU CAN'T CHANGE IT");




}
int main()
{
  int gd=DETECT,gm,a,i;
  char o[10],ab;

  initgraph(&gd,&gm,"c:\\turboc3\\bgi");

  //for backgraound
  setcolor(BLUE);
  setfillstyle(10,BLUE);
  rectangle(0,0,600,440);
  floodfill(1,1,BLUE);

  //outer circle
  setcolor(14);
  setfillstyle(1,14);
  circle(300,200,100);
  floodfill(391,200,14);
  //innner circle
    setcolor(BLUE);
  setfillstyle(1,BLUE);
  circle(300,200,90);
  floodfill(301,201,BLUE);
  delay(10);

    //inner text
    setcolor(14);
    settextstyle(7,0,7);
    outtextxy(230,160,"KBC");
    //upper text
     setcolor(LIGHTBLUE);
    settextstyle(8,0,3);
    outtextxy(20,10,"WELCOME TO KON BANEGA CROREPATI 2019");

     //loading

      for(i=0; i<=595; i+=1)
      {


       setcolor(CYAN);
     settextstyle(8,0,1);
     outtextxy(5,410,"LOADING...");
     rectangle(0,435,600,440);

     setfillstyle(1,CYAN);
     circle(5+i,438,2);
     floodfill(5+i,438,CYAN);
     delay(5);
     }
     //continue option
    //quit option
       quit();
       conti();
       aboutlogo();


      a=getch();
      if(a==27)
      {
	exit(0);
      }
      if(a=='a'||a=='A')
      {
       cleardevice();
       about();


    //quit button
    setcolor(GREEN);
    setfillstyle(0,BLUE);
    rectangle(350,100,600,140);
    settextstyle(8,0,1);
    outtextxy(360,110,"HOME=BACKSPACE KEY");
    outtextxy(460,410,"VERSION:8.0.1");
    ab=getch();
    if(ab==8)
    {
      cleardevice();
      main();
    }
      }
      if(a==32)
      {


      help();
      cleardevice();

     logo();
     quesbg();
     optnbg();

      setcolor(15);
     settextstyle(8,0,1);
     outtextxy(112,185,"Q.");
     outtextxy(135,185,"What is ascci code of A");

     setcolor(GREEN);
     settextstyle(8,0,2);
     outtextxy(210,255,"A");
     setcolor(WHITE);
     settextstyle(8,0,1);
     outtextxy(230,252,": 23");


      setcolor(GREEN);
     settextstyle(8,0,2);
     outtextxy(210-l,255+b,"B");
     setcolor(WHITE);
     settextstyle(8,0,1);
     outtextxy(230-l,252+b,": 65");

	setcolor(GREEN);
     settextstyle(8,0,2);
     outtextxy(210+l,255+b,"C");
     setcolor(WHITE);
     settextstyle(8,0,1);
     outtextxy(230+l,252+b,": 90");

	setcolor(GREEN);
     settextstyle(8,0,2);
     outtextxy(210,255+k,"D");
     setcolor(WHITE);
     settextstyle(8,0,1);
     outtextxy(230,252+k,": 97");

      setcolor(GREEN);
      rectangle(480,50,600,80);
     settextstyle(8,0,GREEN);
     outtextxy(485,50,"SCORE:  0 ");



     o[1]=getch();
     }
     if(o[1]=='a'||o[1]=='c'||o[1]=='d')
     {

      sorry();
      main();
     }
     if(o[1]=='b')
     {
       right();
	 cleardevice();
     logo();
     quesbg();
     optnbg();


      setcolor(15);
     settextstyle(8,0,1);
     outtextxy(112,185,"Q.");
     outtextxy(135,185,"HTML is used to design");

     setcolor(GREEN);
     settextstyle(8,0,2);
     outtextxy(210,255,"A");
     setcolor(WHITE);
     settextstyle(8,0,1);
     outtextxy(230,252,": Webpage");


      setcolor(GREEN);
     settextstyle(8,0,2);
     outtextxy(210-l,255+b,"B");
     setcolor(WHITE);
     settextstyle(8,0,1);
     outtextxy(230-l,252+b,": Website");

	setcolor(GREEN);
     settextstyle(8,0,2);
     outtextxy(210+l,255+b,"C");
     setcolor(WHITE);
     settextstyle(8,0,1);
     outtextxy(230+l,252+b,": Frames");

	setcolor(GREEN);
     settextstyle(8,0,2);
     outtextxy(210,255+k,"D");
     setcolor(WHITE);
     settextstyle(8,0,1);
     outtextxy(230,252+k,":Tables ");

      setcolor(GREEN);
      rectangle(475,50,600,80);
     settextstyle(8,0,GREEN);
     outtextxy(480,50,"SCORE: 100 ");


     o[2]=getch();
     }
     if(o[2]=='b'||o[2]=='d'||o[2]=='c')
     {

      sorry();
      main();
     }
     if(o[2]=='a')
     {
       right();
	 cleardevice();
     logo();
     quesbg();
     optnbg();


      setcolor(15);
     settextstyle(8,0,1);
     outtextxy(112,185,"Q.");
     outtextxy(135,185,"C is____ language");

     setcolor(GREEN);
     settextstyle(8,0,2);
     outtextxy(210,255,"A");
     setcolor(WHITE);
     settextstyle(8,0,1);
     outtextxy(230,252,": Midel level");


      setcolor(GREEN);
     settextstyle(8,0,2);
     outtextxy(210-l,255+b,"B");
     setcolor(WHITE);
     settextstyle(8,0,1);
     outtextxy(230-l,252+b,": High level");

	setcolor(GREEN);
     settextstyle(8,0,2);
     outtextxy(210+l,255+b,"C");
     setcolor(WHITE);
     settextstyle(8,0,1);
     outtextxy(230+l,252+b,":low level ");

	setcolor(GREEN);
     settextstyle(8,0,2);
     outtextxy(210,255+k,"D");
     setcolor(WHITE);
     settextstyle(8,0,1);
     outtextxy(230,252+k,": A & C");

      setcolor(GREEN);
      rectangle(475,50,600,80);
     settextstyle(8,0,GREEN);
     outtextxy(480,50,"SCORE: 200 ");


     o[3]=getch();
     }
     if(o[3]=='b'||o[3]=='c'||o[3]=='a')
     {

      sorry();
      main();
     }
     if(o[3]=='d')
     {
       right();
	 cleardevice();
     logo();
     quesbg();
     optnbg();


      setcolor(15);
     settextstyle(8,0,1);
     outtextxy(112,185,"Q.");
     outtextxy(135,185,"A float requires_bytes in memory");

     setcolor(GREEN);
     settextstyle(8,0,2);
     outtextxy(210,255,"A");
     setcolor(WHITE);
     settextstyle(8,0,1);
     outtextxy(230,252,": 2 bytes");


      setcolor(GREEN);
     settextstyle(8,0,2);
     outtextxy(210-l,255+b,"B");
     setcolor(WHITE);
     settextstyle(8,0,1);
     outtextxy(230-l,252+b,": 1 byte");

	setcolor(GREEN);
     settextstyle(8,0,2);
     outtextxy(210+l,255+b,"C");
     setcolor(WHITE);
     settextstyle(8,0,1);
     outtextxy(230+l,252+b,": 8 bytes");

	setcolor(GREEN);
     settextstyle(8,0,2);
     outtextxy(210,255+k,"D");
     setcolor(WHITE);
     settextstyle(8,0,1);
     outtextxy(230,252+k,": 4 bytes");

      setcolor(GREEN);
      rectangle(475,50,600,80);
     settextstyle(8,0,GREEN);
     outtextxy(480,50,"SCORE: 300 ");

     o[4]=getch();
     }
     if(o[4]=='b'||o[4]=='a'||o[4]=='c')
     {

      sorry();
      main();
     }
     if(o[4]=='d')
     {
       right();
	 cleardevice();
     logo();
     quesbg();
     optnbg();


      setcolor(15);
     settextstyle(8,0,1);
     outtextxy(112,185,"Q.");
     outtextxy(135,185,"Which are not looping structres?");

     setcolor(GREEN);
     settextstyle(8,0,2);
     outtextxy(210,255,"A");
     setcolor(WHITE);
     settextstyle(8,0,1);
     outtextxy(230,252,": Forloop");


      setcolor(GREEN);
     settextstyle(8,0,2);
     outtextxy(210-l,255+b,"B");
     setcolor(WHITE);
     settextstyle(8,0,1);
     outtextxy(230-l,252+b,": Do..whileloop");

	setcolor(GREEN);
     settextstyle(8,0,2);
     outtextxy(210+l,255+b,"C");
     setcolor(WHITE);
     settextstyle(8,0,1);
     outtextxy(230+l,252+b,": Whileloop");

	setcolor(GREEN);
     settextstyle(8,0,2);
     outtextxy(210,255+k,"D");
     setcolor(WHITE);
     settextstyle(8,0,1);
     outtextxy(230,252+k,": if..else");

      setcolor(GREEN);
      rectangle(475,50,600,80);
     settextstyle(8,0,GREEN);
     outtextxy(480,50,"SCORE: 400 ");

     o[4]=getch();
     if(o[4]=='a'||o[4]=='b'||o[4]=='c')
     {
      sorry();
      main();
     }
     if(o[4]=='d');
     {
       right();
       main();
      }
     }
  getch();
  closegraph();
  return 0;

}