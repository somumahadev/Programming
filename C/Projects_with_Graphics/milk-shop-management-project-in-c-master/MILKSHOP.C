//***************************************************************************
//***          M I L K S H O P  M A N A G E M E N T                     *****
//***************************************************************************
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>


union REGS in,out;
int button,x,y;
int i,j;
int key;
int design=176,designcolor=2;
FILE *fp,*fp1,*fp2;

//   F U N C T I O N S
int dcolor();
void showmouseptr();
void getmouseptr(int*,int*,int*);
void mainpage(int ,int);
void menu(int);
void data();
void customer();
void totalamount();
void myprofile();
void login();
void allcustomer();
void sortbyname();
void sortbyuserid();
void about();
void themecolor();
void box(int ,int , int ,int ,int,int);
void scrollbox(int,int,int,int,int);
void newdata();
void editdata();
void deletedata();
void deleteonedata();
void deletealldata();
void adjustbillnumber(char userid[30]);
void viewdata();
void newcustomer();
void editcustomer();
void searchcustomer();
void deletecustomer();
void viewcustomer();
void editname();
void editnumber();
void editaddress();
void editidproof();
void edituserid();
void deleteonecustomer();
void deleteallcustomer();
void login();
void editmyprofile();
void about();
void myprofile();
void deleteprofile();
struct time t;
struct date d;

void main()
{

	  int scroll=3,a;
	   char ch;
	    system("cls");
     fp2=fopen("userid1.txt","r");
     if(fp2!=NULL)
     {
      system("cls");
      login();

	}
	  start:
		    mainpage(design ,designcolor);
	  menu(scroll);
	a=getch();
	if(a==80)
	{
	  scroll+=2;
	  if(scroll>15)
	  {
	   scroll=23;
	   if(scroll>23)
	   {
	    scroll=23;
	   }
	  }
	  goto start;
	}
	else if(a==72)
	{
	 scroll-=2;
	 if(scroll>15)
	 {
	 scroll=15;
	 }
	 if(scroll<=3)
	 {
	  scroll=3;

	 }
	   goto start;
	}
	else if(a==27|| scroll==23 && a==13)
	{
	  exit(1);

	}
	else if(a==13 && scroll==3)
	{
	  menu(3);
	  data();
	  goto start;
	}

	else if(a==13 && scroll==5)
	{
	  menu(5);
	  customer();

	  goto start;
	}

	else if(a==13 && scroll==7)
	{
	  menu(7);
	  allcustomer();
	  goto start;
	}

	else if(a==13 && scroll==9)
	{
	  menu(9);
	  totalamount();
	  goto start;
	}

	else if(a==13 && scroll==11)
	{
	  menu(11);
	themecolor();

	  goto start;
	}

	else if(a==13 && scroll==13)
	{


	      scroll=13;

	 myprofile();
	 ch=getch();
	 if(ch=='1')
	 {
	   editmyprofile();
	   goto start;

	 }
	 else if(ch=='2')
	 {
	   deleteprofile();
	   goto start;
	 }
	 else
	 {
	 goto start;
	 }

	}

	else if(a==13 && scroll==15)
	{
	  menu(15);
	about();
	  getch();
	  goto start;
	}


       else
	{
	 goto start;
	}


}

void showmouseptr()
{
   in.x.ax=1;
   int86(0x33,&in,&out);

}
void getmouseptr(int *button,int *x,int *y)
{
      in.x.ax=3;
      int86(0x33,&in,&out);
      *button=out.x.bx;
      *x=out.x.cx;
      *y=out.x.dx;


}
void mainpage(int design,int designcolor)
{
     for(i=1; i<=24; i++)
     {
      for(j=1; j<=80; j++)
      {
	if(j<20)
	{

	textcolor(15); textbackground(15);
	gotoxy(j,i); cprintf(" ");
	}
	else
	{
	textcolor(designcolor); textbackground(15);
	gotoxy(j,i); cprintf("%c",design);
	}
      }

     }

}
void menu( int k)
{
  int  bkcolor=7,texcolor=0,fcolor=0;
  int scrollcolor=designcolor;
   _setcursortype(_NOCURSOR);
     gotoxy(1,k);
    textbackground(scrollcolor);
    textcolor(texcolor);
    cprintf("                   ");

     gotoxy(1,k+1);
    textbackground(scrollcolor);
    textcolor(texcolor);
    cprintf("                   ");


    if(k==1)
    {
       bkcolor=scrollcolor;
       texcolor=14;
    }
    else
    {
     bkcolor=7;
     texcolor=0;
    }

    gotoxy(2,1);
    textbackground(bkcolor);
    textcolor(1);
    cprintf("ð   M");

    gotoxy(7,1);
    textbackground(bkcolor);
    textcolor(texcolor);
    cprintf("enu");



    if(k==3)
    {
       bkcolor=scrollcolor;
       texcolor=14;
       fcolor=14;
    }
    else
    {
     bkcolor=7;
     texcolor=0;
     fcolor=1;
    }

    gotoxy(2,3);

    textbackground(bkcolor);
    textcolor(fcolor);
    cprintf("D");

    gotoxy(3,3);

    textbackground(bkcolor);
    textcolor(texcolor);
    cprintf("ata            >");


    if(k==5)
    {
       bkcolor=scrollcolor;
       texcolor=14;
       fcolor=14;
    }
    else
    {
     bkcolor=7;
     texcolor=0;
     fcolor=1;
    }

    gotoxy(2,5);

    textbackground(bkcolor);
    textcolor(fcolor);
    cprintf("C");

    gotoxy(3,5);

    textbackground(bkcolor);
    textcolor(texcolor);
    cprintf("ustomer        >");


    if(k==7)
    {
       bkcolor=scrollcolor;
       texcolor=14;
       fcolor=14;
    }
    else
    {
     bkcolor=7;
     texcolor=0;
     fcolor=1;
    }

    gotoxy(2,7);

    textbackground(bkcolor);
    textcolor(fcolor);
    cprintf("A");

    gotoxy(3,7);

    textbackground(bkcolor);
    textcolor(texcolor);
    cprintf("ll Customer    >");



    if(k==9)
    {
       bkcolor=scrollcolor;
       texcolor=14;
       fcolor=14;
    }
    else
    {
     bkcolor=7;
     texcolor=0;
     fcolor=1;
    }

    gotoxy(2,9);

    textbackground(bkcolor);
    textcolor(fcolor);
    cprintf("T");

    gotoxy(3,9);

    textbackground(bkcolor);
    textcolor(texcolor);
    cprintf("otal Amount    >");


    if(k==11)
    {
       bkcolor=scrollcolor;
       texcolor=14;
       fcolor=14;
    }
    else
    {
     bkcolor=7;
     texcolor=0;
     fcolor=1;
    }

    gotoxy(2,11);

    textbackground(bkcolor);
    textcolor(fcolor);
    cprintf("T");

    gotoxy(3,11);

    textbackground(bkcolor);
    textcolor(texcolor);
    cprintf("heme Color     >");


    if(k==13)
    {
       bkcolor=scrollcolor;
       texcolor=14;
       fcolor=14;
    }
    else
    {
     bkcolor=7;
     texcolor=0;
     fcolor=1;
    }

    gotoxy(2,13);

    textbackground(bkcolor);
    textcolor(fcolor);
    cprintf("M");

    gotoxy(3,13);

    textbackground(bkcolor);
    textcolor(texcolor);
    cprintf("y profile      >");


    if(k==15)
    {
       bkcolor=scrollcolor;
       texcolor=14;
       fcolor=14;
    }
    else
    {
     bkcolor=7;

       texcolor=0;
       fcolor=1;
    }

    gotoxy(2,15);

    textbackground(bkcolor);
    textcolor(texcolor);
    cprintf("A out           >");

    gotoxy(3,15);

    textbackground(bkcolor);
    textcolor(fcolor);
    cprintf("b");




    if(k==23)
    {
       bkcolor=scrollcolor;

       texcolor=14;
       fcolor=14;
    }
    else
    {
     bkcolor=7;

       texcolor=0;
       fcolor=1;
    }

    gotoxy(2,23);

    textbackground(bkcolor);
    textcolor(fcolor);
    cprintf("Exit");


    gotoxy(7,23);

    textbackground(bkcolor);
    textcolor(texcolor);
    cprintf("[ ESC KEY ]");
}

void box(int x1,int y1,int space,int height,int boxcolor ,int boxbkcolor)
{
  int i2,i3;
  gotoxy(x1,y1-1);
  textcolor(boxcolor);
  textbackground(boxbkcolor);
  cprintf("Ú");

  for(i3=0; i3<height; i3++)
  {
  gotoxy(x1,y1+i3);
  textcolor(boxcolor);
  textbackground(boxbkcolor);
  cprintf("³");
   }
  gotoxy(x1,y1+height);
  textcolor(boxcolor);
  textbackground(boxbkcolor);
  cprintf("À");
  for(i2=1; i2<=space; i2++)
  {

  gotoxy(x1+i2,y1+height);
  textcolor(boxcolor);
  textbackground(boxbkcolor);
  cprintf("Ä");

  gotoxy(x1+i2,y1-1);
  textcolor(boxcolor);
  textbackground(boxbkcolor);
  cprintf("Ä");

  }

  gotoxy(x1+space,y1-1);
  textcolor(boxcolor);
  textbackground(boxbkcolor);
  cprintf("¿");

  for(i3=0; i3<height; i3++)
  {
  gotoxy(x1+space,y1+i3);
  textcolor(boxcolor);
  textbackground(boxbkcolor);
  cprintf("³");
   }

  gotoxy(x1+space,y1+height);
  textcolor(boxcolor);
  textbackground(boxbkcolor);
  cprintf("Ù");
}
void scrollbox(int x1,int y1,int x2,int y2 ,int scrollboxcolor)
{

   for(i=y1; i<=y2; i++)
   {
    for(j=x1; j<=x2; j++)
    {
      gotoxy(j,i);
       textbackground(scrollboxcolor);
      cprintf(" ");
    }
   }
   box(x1,y1+1,x2-x1,y2-y1-1,0,scrollboxcolor);

}


void newcustomer()
{
     char username[30],name[30],lastname[15],addres[50],addres1[50];
     char mobileno[15],idname1[15],idname[15],idnumber[20],checkid[15],userid[15];
     int texcolor;
     char add[50],add1[50],idnumber1[20];
     _setcursortype(_NORMALCURSOR);
     scrollbox(20,3,75,20,7);
     gotoxy(21,4);
     textcolor(0); textbackground(2);
     cprintf("                 Create a New Account                 ");

     textcolor(8); textbackground(7);
     gotoxy(30,7);
     cprintf(" * ÄÄÄÄÄÄÄÄ0ÄÄÄÄÄÄÄÄ0ÄÄÄÄÄÄÄÄ0ÄÄÄÄÄÄÄÄ0");

      box(35,11,35,1,0,7);

     textcolor(1); textbackground(7);
     gotoxy(22,11);  cprintf("First Name :");


      box(35,15,35,1,0,7);

     textcolor(1); textbackground(7);
     gotoxy(22,15);  cprintf("Last  Name :");

       textcolor(7); textbackground(1);
      gotoxy(68,18);  cprintf(" Next ");

      gotoxy(38,11);
      gets(name);

       if(name[0]>=97 &&name[0]<=122)
       {
	name[0]-=32;

       }
       j=0;
       for(i=0; i<strlen(name); i++)
       {
	 if(name[i]!=' ')
	 {
	   username[j]=name[i];
	   j++;
	 }

       }

       username[j]='\0';
      gotoxy(38,15);
      gets(lastname);

       if(lastname[0]>=97 &&lastname[0]<=122)
       {
	lastname[0]-=32;

       }
      strcat(username,lastname);

     delay(100);
     scrollbox(20,3,75,20,7);
     gotoxy(21,4);
     textcolor(0); textbackground(2);
     cprintf("                 Create a New Account                 ");

     textcolor(8); textbackground(7);
     gotoxy(30,7);
     cprintf(" 0ÄÄÄÄÄÄÄÄ * ÄÄÄÄÄÄÄÄ0ÄÄÄÄÄÄÄÄ0ÄÄÄÄÄÄÄÄ0");
      box(39,11,30,1,0,7);

     textcolor(1); textbackground(7);
     gotoxy(22,11);  cprintf("Mobile Number :");


       textcolor(7); textbackground(1);
      gotoxy(68,18);  cprintf(" Next ");
      textcolor(0);  textbackground(7);
      gotoxy(40,11);  cprintf("                             ");
      cprintf("");
       _setcursortype(_NORMALCURSOR);
	textcolor(6); textbackground(7);
       gotoxy(42,11); gets(mobileno);


     scrollbox(20,3,75,20,7);
     gotoxy(21,4);
     textcolor(0); textbackground(2);
     cprintf("                 Create a New Account                 ");

     textcolor(8); textbackground(7);
     gotoxy(30,7);
     cprintf(" 0ÄÄÄÄÄÄÄÄ0ÄÄÄÄÄÄÄÄ * ÄÄÄÄÄÄÄÄ0ÄÄÄÄÄÄÄÄ0");
      box(39,11,30,1,0,7);

     textcolor(1); textbackground(7);
     gotoxy(22,11);  cprintf("Address Line 1 :");

      box(39,14,30,1,0,7);

     textcolor(1); textbackground(7);
     gotoxy(22,14);  cprintf("Address Line 2 :");


       textcolor(7); textbackground(1);
      gotoxy(68,18);  cprintf(" Next ");
       gotoxy(42,11);

      gets(add);

       j=0;
       for(i=0; i<strlen(add); i++)
       {
	 if(add[i]!=' ')
	 {
	   addres[j]=add[i];
	   j++;
	 }

	 else
	 {
	   addres[j]='_';
	   j++;
	 }

       }
       addres[j]='\0';

      gotoxy(42,14);
      gets(add1);

       j=0;
       for(i=0; i<strlen(add1); i++)
       {
	 if(add1[i]!=' ')
	 {
	   addres1[j]=add1[i];
	   j++;
	 }

	 else
	 {
	   addres1[j]='_';
	   j++;
	 }

       }

       addres1[j]='\0';
     scrollbox(20,3,75,20,7);
     gotoxy(21,4);
     textcolor(0); textbackground(2);
     cprintf("                 Create a New Account                 ");

     textcolor(8); textbackground(7);
     gotoxy(30,7);
     cprintf(" 0ÄÄÄÄÄÄÄÄ0ÄÄÄÄÄÄÄÄ0ÄÄÄÄÄÄÄÄ * ÄÄÄÄÄÄÄÄ0");
      box(45,11,28,1,0,7);
      box(45,14,28,1,0,7);

     textcolor(1); textbackground(7);
     gotoxy(22,11);  cprintf("Identity Proof Name   :");

     textcolor(1); textbackground(7);
     gotoxy(22,14);  cprintf("Identity Proof Number :");



       textcolor(7); textbackground(1);
      gotoxy(68,18);  cprintf(" Next ");
      textcolor(6);  textbackground(7);
      gotoxy(46,11);  cprintf("                        ");

      textcolor(0);  textbackground(7);
      gotoxy(46,14);  cprintf("                        ");

       _setcursortype(_NORMALCURSOR);
	textcolor(6); textbackground(7);
       gotoxy(47,11); gets(idname1);

       if(idname1[0]>=97 &&idname1[0]<=122)
       {
	idname1[0]-=32;

       }
       j=0;
       for(i=0; i<strlen(idname1); i++)
       {
	 if(idname1[i]!=' ')
	 {
	   idname[j]=idname1[i];
	   j++;
	 }

       }
       idname[j]='\0';
	textcolor(6); textbackground(7);
       gotoxy(47,14); gets(idnumber1);

       j=0;
       for(i=0; i<strlen(idnumber1); i++)
       {
	 if(idnumber1[i]!=' ')
	 {
	   idnumber[j]=idnumber1[i];
	   j++;
	 }

	 else
	 {
	   idnumber[j]='-';
	   j++;
	 }

       }
       idnumber[j]='\0';



      userid:
     scrollbox(20,3,75,20,7);
     gotoxy(21,4);
     textcolor(0); textbackground(2);
     cprintf("                 Create a New Account                 ");

     textcolor(8); textbackground(7);
     gotoxy(30,7);
     cprintf(" 0ÄÄÄÄÄÄÄÄ0ÄÄÄÄÄÄÄÄ0ÄÄÄÄÄÄÄÄ0ÄÄÄÄÄÄÄÄ *");
      box(39,11,30,1,0,7);

     textcolor(1); textbackground(7);
     gotoxy(22,11);  cprintf("User id :");

      textcolor(8);textbackground(7);
      gotoxy(22,18); cprintf("Info :- Userid Must be less than 8 characters");

       textcolor(7); textbackground(1);
      gotoxy(68,18);  cprintf(" Next ");
      textcolor(4);  textbackground(7);
      gotoxy(40,11);  cprintf("                             ");
      cprintf("");
       _setcursortype(_NORMALCURSOR);
	textcolor(6); textbackground(7);
       gotoxy(42,11); gets(checkid);

       strcpy(userid,checkid);
       strcat(userid,".txt");
       fp1=fopen(userid,"r");
       if(fp1!=NULL)
       {
       _setcursortype(_NOCURSOR);
	 fclose(fp);
	 gotoxy(35,15);
	 textcolor(4+BLINK);
	 textbackground(7);
	 cprintf("Erorr : Userid Already Taken");

	 gotoxy(33,17);
	 textcolor(6);
	 textbackground(7);
	 cprintf(" <<  Press Any Key To Reenter  >>");
	 getch();
	 goto userid;

       }
       texcolor=6;
      scrollbox(20,3,75,23,7);
     gotoxy(21,4);
     textcolor(0); textbackground(2);
     cprintf("                 Create a New Account                 ");
     textcolor(texcolor);  textbackground(7);
      gotoxy(22,6);  cprintf("User Name          :");

     textcolor(0);  textbackground(7);
      gotoxy(45,6); cprintf("%s",username);

       textcolor(texcolor);  textbackground(7);
      gotoxy(22,8);  cprintf("Mobile Number      :");

     textcolor(0);  textbackground(7);
      gotoxy(45,8); cprintf("%s",mobileno);
       textcolor(texcolor);  textbackground(7);
      gotoxy(22,10); cprintf("Address  Line  1    :");

     textcolor(0);  textbackground(7);
      gotoxy(45,10); cprintf("%s",addres);


       textcolor(texcolor);  textbackground(7);
      gotoxy(22,12); cprintf("Address  Line 2     :");

     textcolor(0);  textbackground(7);
      gotoxy(45,12); cprintf("%s",addres1);
       textcolor(texcolor);  textbackground(7);
      gotoxy(22,14); cprintf("Identity Proof     :");

     textcolor(0);  textbackground(7);
      gotoxy(45,14); cprintf("%s",idname);

       textcolor(texcolor);  textbackground(7);
      gotoxy(22,16); cprintf("Identity Proof No. :");

     textcolor(0);  textbackground(7);
      gotoxy(45,16); cprintf("%s",idnumber);

       textcolor(texcolor);  textbackground(7);
      gotoxy(22,18); cprintf("User id            :");

     textcolor(0);  textbackground(7);
      gotoxy(45,18); cprintf("%s",checkid);

      textcolor(7); textbackground(1);
      gotoxy(22,21); cprintf(" Create Account [Enter] ");


      textcolor(7); textbackground(4);
      gotoxy(52,21); cprintf(" Cancel [Back Space] ");
       key:
       _setcursortype(_NOCURSOR);
       key=getch();
      if(key==13)
      {

	   fp=fopen("customer.txt","a");


	   fprintf(fp,"\n%s %s\n%s %s\n%s %s %s",username,mobileno,addres,addres1,idname,idnumber,checkid);
	   fclose(fp);
	    fp1=fopen(userid,"a");
	   fclose(fp1);

	   scrollbox(20,3,75,23,7);
	   gotoxy(32,12);
	   textcolor(0);
	   textbackground(2);
	   cprintf(" New Account Succesfully Created");
	  delay(1000);


      }
      else if(key==8)
      {



      }
      else
      {

       goto key;
      }
}

void customer()
{

	int k=5;
	customer:
	scrollbox(20,4,39,10,7);
	textcolor(0); textbackground(2);
	gotoxy(21,k);  cprintf("             ");

	if(k==5)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(22,5);  cprintf(" New    Customer ");

	if(k==6)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(22,6);  cprintf(" Edit   Customer ");

	if(k==7)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(22,7);  cprintf(" Search Customer ");

	if(k==8)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(22,8);  cprintf(" Delete Customer ");

	if(k==9)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(22,9);  cprintf(" View   Customer ");
	key=getch();
	if(key==8)
	{

	}
	else if(key==13)
	{
	  if(k==5)
	  {
	    newcustomer();

	  }
	  else if(k==6)
	  {
	    editcustomer();
	  }
	  else if(k==7)
	  {
	   searchcustomer();
	  }
	  else if(k==8)
	  {
	     deletecustomer();
	  }

	  else if(k==9)
	  {
	     viewcustomer();
	  }

	}
	else if(key==0)
	{
	  key=getch();
	  if(key==80)
	  {
	    k++;
	    if(k>9)
	    {
	    k=5;
	    }
	    goto customer;
	  }
	  else if(key==72)
	  {
	   k--;
	   if(k<5)
	   {
	   k=9;
	   }

	   goto customer;
	  }
	  else if(key==8)
	  {


	  }
	  else
	  {
	  goto customer;
	  }

	}
	else if(key==8)
	{

	}

}

void data()
{
	int k=3;
	data:
	scrollbox(20,2,35,7,7);
	textcolor(0); textbackground(2);
	gotoxy(21,k);  cprintf("             ");

	if(k==3)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(22,3);  cprintf(" New   Data");

	if(k==4)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(22,4);  cprintf(" Edit  Data");

	if(k==5)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(22,5);  cprintf(" View  Data ");

	if(k==6)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(22,6);  cprintf(" Delete Data ");
	key=getch();
	if(key==8)
	{

	}
	else if(key==13)
	{
	  if(k==3)
	  {
	    newdata();

	  }
	  else if(k==4)
	  {
	    editdata();
	  }
	  else if(k==5)
	  {
	   viewdata();
	  }
	  else if(k==6)
	  {
	  deletedata();
	  }

	}
	else if(key==0)
	{
	  key=getch();
	  if(key==80)
	  {
	    k++;
	    if(k>6)
	    {
	    k=3;
	    }
	    goto data;
	  }
	  else if(key==72)
	  {
	   k--;
	   if(k<3)
	   {
	   k=6;
	   }

	   goto data;
	  }
	  else if(key==8)
	  {


	  }
	  else
	  {
	  goto data;
	  }

	}
	else if(key==8)
	{

	}

}

void newdata()
{
     char *userid,*checkid,*alldata,*billno;
     float price,qty,total;
     int hr,min,sec,billnumber=0;
     char *shift;

      _setcursortype(_NORMALCURSOR);
    scrollbox(20,2,75,20,7);
    textbackground(2);
    gotoxy(21,3);
    textcolor(6);
     cprintf("                     New Entry                        ");

    box(45,7,25,1,0,7);
    textcolor(1);  textbackground(7);
    gotoxy(23,7);  cprintf("Enter User id       :");

     fflush(stdin);
     gotoxy(47,7);
    gets(userid);
    strcpy(checkid,userid);
    strcat(userid,".txt");
    fp1=fopen(userid,"r");
    if(fp1==NULL)
    {
       fclose(fp1);
       _setcursortype(_NOCURSOR);
	gotoxy(30,13);
	textcolor(4);  textbackground(7);
	cprintf("Erorr : Incorrect User Id !");
	delay(1200);

    }
    else
    {
	 fclose(fp1);


    box(45,10,25,1,0,7);
    textcolor(1);  textbackground(7);
    gotoxy(23,10);  cprintf("Enter Price        :");

    box(45,14,25,1,0,7);
    textcolor(1);  textbackground(7);
    gotoxy(23,14);  cprintf("Enter Quantity (ltr) :");



     gotoxy(47,10);
      fflush(stdin);
    scanf("%f",&price);

     gotoxy(47,14);
      fflush(stdin);
    scanf("%f",&qty);
    total=qty*price;

    fp1=fopen(userid,"r");
    while(fscanf(fp1,"%s %[^\n]\n",billno,alldata)!=EOF);
    strcpy(alldata,"");
    fclose(fp1);
    if(billno==NULL)
    {
      billno=0;
    }
     billnumber=atoi(billno);

      getdate(&d);
      gettime(&t);
      hr=t.ti_hour;
      min=t.ti_min;
      if(hr>12)
      {
	hr-=12;
	strcpy(shift,"PM");

      }
      else
      {
       strcpy(shift,"AM");
      }

    scrollbox(20,2,75,20,7);
    textbackground(2);
    gotoxy(21,3);
    textcolor(6);
     cprintf("                      BILL                          ");

       _setcursortype(_NOCURSOR);

     gotoxy(23,4);textbackground(7);textcolor(1);
     cprintf("Bill number :");
      gotoxy(42,4); textbackground(7); textcolor(0);
      cprintf("%d",billnumber+1);

     gotoxy(23,6);textbackground(7);textcolor(1);
     cprintf("User id     :");
      gotoxy(42,6); textbackground(7); textcolor(0);
      cprintf("%s",checkid);

     gotoxy(23,8);textbackground(7);textcolor(1);
     cprintf("Price       :");
      gotoxy(42,8); textbackground(7); textcolor(0);
      cprintf("%0.2f rup./ltr.",price);

     gotoxy(23,10);textbackground(7);textcolor(1);
     cprintf("Quantity    :");
      gotoxy(42,10); textbackground(7); textcolor(0);
      cprintf("%0.3f ltr.",qty);


     gotoxy(23,12);textbackground(7);textcolor(1);
     cprintf("Bill        :");
      gotoxy(42,12); textbackground(7); textcolor(0);
      cprintf("%0.2f rupees",total);

     gotoxy(23,14);textbackground(7);textcolor(1);
     cprintf("Time        :");
      gotoxy(42,14); textbackground(7); textcolor(0);
      cprintf("%d:%d-%s",hr,min,shift);


     gotoxy(23,16);textbackground(7);textcolor(1);
     cprintf("Date        :");

      gotoxy(42,16); textbackground(7); textcolor(0);
      cprintf("%d/%d/%d",d.da_day,d.da_mon,d.da_year);

     textcolor(7); textbackground(1);
      gotoxy(22,18); cprintf(" Submit Data [Enter] ");


      textcolor(7); textbackground(4);
      gotoxy(52,18); cprintf(" Cancel [Back Space] ");
      key:
      key=getch();
      if(key==13)
      {
       fp1=fopen(userid,"a");
       fprintf(fp1,"%d %0.2f %0.3f %0.2f %d:%d-%s %d/%d/%d\n",billnumber+1,price,qty,total,hr,min,shift,d.da_day,d.da_mon,d.da_year);
       fclose(fp1);
	   scrollbox(20,2,75,20,7);
	   gotoxy(32,10);
	   textcolor(0);
	   textbackground(2);
	   cprintf(" Data Succesfully Submited ");
	   delay(1000);

      }
      else if(key==8)
      {

      }
      else
      {
       goto key;
      }


    }


}
void deleteonedata()
{




     char *userid,*checkid;

  char alldata[180],price[150],qty[150],total[150],realdate[400],realtime[400];
  int n,i,chk;
  char bn[150],billno[150];

      _setcursortype(_NORMALCURSOR);
    scrollbox(20,2,75,20,7);
    textbackground(2);
    gotoxy(21,3);
    textcolor(6);
     cprintf("                     New Entry                        ");

    box(45,7,25,1,0,7);
    textcolor(1);  textbackground(7);
    gotoxy(23,7);  cprintf("Enter User id       :");

     fflush(stdin);
     gotoxy(47,7);
    gets(userid);
    strcpy(checkid,userid);
    strcat(userid,".txt");
    fp1=fopen(userid,"r");
    if(fp1==NULL)
    {
       fclose(fp1);
       _setcursortype(_NOCURSOR);
	gotoxy(30,13);
	textcolor(4);  textbackground(7);
	cprintf("Erorr : Incorrect User Id !");
	delay(1200);

    }
    else
    {
	 fclose(fp1);



    box(45,10,25,1,0,7);
    textcolor(1);  textbackground(7);
    gotoxy(23,10);  cprintf("Enter Bill Number  :");
    gotoxy(47,10);  scanf("%s",bn);
   fp=fopen(userid,"r");
   fp1=fopen("temp.txt","a");
 while(fscanf(fp,"%s %s %s %s %s %s\n",billno,price,qty,total,realtime,realdate)!=EOF)


 {     chk=strcmp(bn,billno);
	if(chk==0)
	{
    scrollbox(20,2,75,20,7);
    textbackground(2);
    gotoxy(21,3);
    textcolor(6);
     cprintf("                      Delete Data                       ");

       _setcursortype(_NOCURSOR);

     gotoxy(23,4);textbackground(7);textcolor(1);
     cprintf("Bill number :");
      gotoxy(42,4); textbackground(7); textcolor(0);
      cprintf("%s",billno);

     gotoxy(23,6);textbackground(7);textcolor(1);
     cprintf("User id     :");
      gotoxy(42,6); textbackground(7); textcolor(0);
      cprintf("%s",checkid);

     gotoxy(23,8);textbackground(7);textcolor(1);
     cprintf("Price       :");
      gotoxy(42,8); textbackground(7); textcolor(0);
      cprintf("%s rup./ltr.",price);

     gotoxy(23,10);textbackground(7);textcolor(1);
     cprintf("Quantity    :");
      gotoxy(42,10); textbackground(7); textcolor(0);
      cprintf("%s ltr.",qty);


     gotoxy(23,12);textbackground(7);textcolor(1);
     cprintf("Bill        :");
      gotoxy(42,12); textbackground(7); textcolor(0);
      cprintf("%s rupees",total);

     gotoxy(23,14);textbackground(7);textcolor(1);
     cprintf("Time        :");
      gotoxy(42,14); textbackground(7); textcolor(0);
      cprintf("%s",realtime);


     gotoxy(23,16);textbackground(7);textcolor(1);
     cprintf("Date        :");

      gotoxy(42,16); textbackground(7); textcolor(0);
      cprintf("%s",realdate);

     textcolor(7); textbackground(1);
      gotoxy(22,18); cprintf(" Confirm [Enter] ");


      textcolor(7); textbackground(4);
      gotoxy(52,18); cprintf(" Cancel [Back Space] ");
      key:
      key=getch();
      if(key==13)
      {

	   scrollbox(20,2,75,20,7);
	   gotoxy(32,10);
	   textcolor(0);
	   textbackground(2);
	   cprintf(" Data Delected Sucessfully ");
	   delay(1000);
	   mainpage(design ,designcolor);


	}
	else if(key==8)
	{
	    fprintf(fp1,"%s %s %s %s %s %s\n",billno,price,qty,total,realtime,realdate);
	}
	else
	{
	 goto key;
	}
	}
      else
      {

	  fprintf(fp1,"%s %s %s %s %s %s\n",billno,price,qty,total,realtime,realdate);

     }



 }
 fclose(fp1);
  fclose(fp);
  fp=fopen(userid,"w");
  fclose(fp);
  fp1=fopen("temp.txt","r");
  fp=fopen(userid,"a");

  n=1;
  while(fscanf(fp1,"%s %s %s %s %s %s\n",billno,price,qty,total,realtime,realdate)!=EOF)
  {

	       itoa(n,bn,10);
	       fprintf(fp,"%s %s %s %s %s %s\n",bn,price,qty,total,realtime,realdate);


       n++;

 //  fprintf(fp,"%s %s %s %s %s %s\n",billno,price,qty,total,realtime,realdate);
  }

 fclose(fp1);
  fclose(fp);
  fp1=fopen("temp.txt","w");
  fclose(fp1);


	 }


}
void deletealldata()
{

     char *userid,*checkid;



      _setcursortype(_NORMALCURSOR);
    scrollbox(20,2,75,12,7);
    textbackground(2);
    gotoxy(21,3);
    textcolor(6);
     cprintf("                     New Entry                        ");

    box(45,7,25,1,0,7);
    textcolor(1);  textbackground(7);
    gotoxy(23,7);  cprintf("Enter User id       :");

     fflush(stdin);
     gotoxy(47,7);  textcolor(0); textbackground(7); cprintf("                     ");

    gotoxy(47,7);  gets(userid);
    strcpy(checkid,userid);
    strcat(userid,".txt");
    fp1=fopen(userid,"r");
    if(fp1==NULL)
    {
       fclose(fp1);
       _setcursortype(_NOCURSOR);
	gotoxy(30,10);
	textcolor(4);  textbackground(7);
	cprintf("Erorr : Incorrect User Id !");
	delay(1200);

    }
    else
    {
	 fclose(fp1);

     textcolor(7); textbackground(1);
      gotoxy(22,10); cprintf(" Delete All [Enter] ");


      textcolor(7); textbackground(4);
      gotoxy(52,10); cprintf(" Cancel [Back Space] ");
      key:
      key=getch();
      if(key==13)
      {

	    scrollbox(20,2,75,12,7);

      fp1=fopen(userid,"w");
      fclose(fp1);
       _setcursortype(_NOCURSOR);
	gotoxy(37,7);
	textcolor(0);  textbackground(2);
	cprintf(" All data delected ");
	delay(1000);


	}
	else  if(key==8)
	{

	}
	else
	{
	goto key;
	}
    }

}
void deletedata()
{



	int k=7;
	deletedata:
	 scrollbox(36,6,50,9,7);

	if(k==7)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(37,7);  cprintf(" Delete One ");

	if(k==8)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(37,8);  cprintf(" Delete All ");

	key=getch();
	if(key==8)
	{

	}
	else if(key==13)
	{
	  if(k==7)
	  {
	    deleteonedata();

	  }
	  else if(k==8)
	  {
	  deletealldata();
	  }
	}
	else if(key==0)
	{
	  key=getch();
	  if(key==80)
	  {
	    k++;
	    if(k>8)
	    {
	    k=7;
	    }
	    goto deletedata;
	  }
	  else if(key==72)
	  {
	   k--;
	   if(k<7)
	   {
	   k=8;
	   }

	   goto deletedata;
	  }
	  else if(key==8)
	  {


	  }
	  else
	  {
	  goto deletedata;
	  }

	}
	else if(key==8)
	{

	}



}

void editdata()
{



     char *userid,*checkid;

  char alldata[180],price[150],qty[150],total[150],realdate[400],realtime[400];
  int n,i;
  char bn[150],billno[150];
  float newprice,newqty,newtotal;
     int chk;

     char *shift;

      _setcursortype(_NORMALCURSOR);
    scrollbox(20,2,75,13,7);
    textbackground(2);
    gotoxy(21,3);
    textcolor(6);
     cprintf("                     Edit Data                        ");

    box(45,7,25,1,0,7);
    textcolor(1);  textbackground(7);
    gotoxy(23,7);  cprintf("Enter User id       :");

     fflush(stdin);
     gotoxy(47,7);
    gets(userid);
    strcpy(checkid,userid);
    strcat(userid,".txt");
    fp1=fopen(userid,"r");
    if(fp1==NULL)
    {
       fclose(fp1);
       _setcursortype(_NOCURSOR);
	gotoxy(30,10);
	textcolor(4);  textbackground(7);
	cprintf("Erorr : Incorrect User Id !");
	delay(1200);

    }
    else
    {
	 fclose(fp1);



    box(45,10,25,1,0,7);
    textcolor(1);  textbackground(7);
    gotoxy(23,10);  cprintf("Enter Bill Number  :");
    gotoxy(47,10);  scanf("%s",bn);
   fp=fopen(userid,"r");
   fp1=fopen("temp.txt","a");
 while(fscanf(fp,"%s %s %s %s %s %s\n",billno,price,qty,total,realtime,realdate)!=EOF)


 {     chk=strcmp(bn,billno);
	if(chk==0)
	{
		   scrollbox(20,2,75,20,7);
      textbackground(2);
      gotoxy(21,3);
      textcolor(6);
      cprintf("                     Edit Data                        ");
	  gotoxy(40,5);  textcolor(0); textbackground(7);
	  cprintf("...Data Found...");
	  gotoxy(23,7); textcolor(6); textbackground(7);
	  cprintf("Old price   = %s\n",price);
	  gotoxy(23,9);  textcolor(6); textbackground(7);
	  cprintf("Old Qty     = %s \n",qty);
	  gotoxy(23,11); textcolor(6); textbackground(7);
	  cprintf("Old Total   = %s\n",total);
	   box(45,13,25,1,0,7);
	       gotoxy(23,13); textcolor(1); textbackground(7);
		      cprintf("Enter New Price    :");

		 box(45,17,25,1,0,7);
	       gotoxy(23,17); textcolor(1); textbackground(7);
		      cprintf("Enter New Quantity :");
		fflush(stdin);
	       gotoxy(47,13);
	       scanf("%f",&newprice);

		fflush(stdin);
	       gotoxy(47,17);
	       scanf("%f",&newqty);

	       newtotal=newprice*newqty;



    scrollbox(20,2,75,20,7);
    textbackground(2);
    gotoxy(21,3);
    textcolor(6);
     cprintf("                      BILL                          ");

       _setcursortype(_NOCURSOR);

     gotoxy(23,4);textbackground(7);textcolor(1);
     cprintf("Bill number :");
      gotoxy(42,4); textbackground(7); textcolor(0);
      cprintf("%s",billno);

     gotoxy(23,6);textbackground(7);textcolor(1);
     cprintf("User id     :");
      gotoxy(42,6); textbackground(7); textcolor(0);
      cprintf("%s",checkid);

     gotoxy(23,8);textbackground(7);textcolor(1);
     cprintf("Price       :");
      gotoxy(42,8); textbackground(7); textcolor(0);
      cprintf("%0.2f rup./ltr.",newprice);

     gotoxy(23,10);textbackground(7);textcolor(1);
     cprintf("Quantity    :");
      gotoxy(42,10); textbackground(7); textcolor(0);
      cprintf("%0.3f ltr.",newqty);


     gotoxy(23,12);textbackground(7);textcolor(1);
     cprintf("Bill        :");
      gotoxy(42,12); textbackground(7); textcolor(0);
      cprintf("%0.2f rupees",newtotal);

     gotoxy(23,14);textbackground(7);textcolor(1);
     cprintf("Time        :");
      gotoxy(42,14); textbackground(7); textcolor(0);
      cprintf("%s",realtime);


     gotoxy(23,16);textbackground(7);textcolor(1);
     cprintf("Date        :");

      gotoxy(42,16); textbackground(7); textcolor(0);
      cprintf("%s",realdate);

     textcolor(7); textbackground(1);
      gotoxy(22,18); cprintf(" Submit Data [Enter] ");


      textcolor(7); textbackground(4);
      gotoxy(52,18); cprintf(" Cancel [Back Space] ");
      key:
      key=getch();
      if(key==13)
      {

	  fprintf(fp1,"%s %0.2f %0.3f %0.2f %s %s\n",billno,newprice,newqty,newtotal,realtime,realdate);

	   scrollbox(20,2,75,20,7);
	   gotoxy(32,10);
	   textcolor(0);
	   textbackground(2);
	   cprintf(" Data Succesfully Submited ");
	   delay(1000);

      }
      else if(key==8)
      {

	  fprintf(fp1,"%s %s %s %s %s %s\n",billno,price,qty,total,realtime,realdate);


      }
      else
      {
       goto key;
      }



	}
	else
	{

	  fprintf(fp1,"%s %s %s %s %s %s\n",billno,price,qty,total,realtime,realdate);

	}



 }
 fclose(fp1);
  fclose(fp);
  fp=fopen(userid,"w");
  fclose(fp);
  fp1=fopen("temp.txt","r");
  fp=fopen(userid,"a");

  while(fscanf(fp1,"%s %s %s %s %s %s\n",billno,price,qty,total,realtime,realdate)!=EOF)
  {

   fprintf(fp,"%s %s %s %s %s %s\n",billno,price,qty,total,realtime,realdate);
  }

 fclose(fp1);
  fclose(fp);
  fp1=fopen("temp.txt","w");
  fclose(fp1);


	 }

}
void viewdata()
{
      char *checkid,*userid;
     char readtime[80][40],readdate[80][40],billno[80][5];

     char price[80][10],qty[80][10],total[80][10];
     int bkcolor=7,scrollnumber=1,scroll,start,texcolor,n=0;
     long int grandtotal=0;
      _setcursortype(_NORMALCURSOR);
    scrollbox(20,2,75,12,7);
    textbackground(2);
    gotoxy(21,3);
    textcolor(6);
     cprintf("                     View Data                       ");

    box(45,7,25,1,0,7);
    textcolor(1);  textbackground(7);
    gotoxy(23,7);  cprintf("Enter User id       :");
    gotoxy(47,7);
    fflush(stdin);
    gets(userid);
    strcpy(checkid,userid);
    strcat(checkid,".txt");
    fp1=fopen(checkid,"r");
    if(fp1==NULL)
    {
     _setcursortype(_NOCURSOR);
       fclose(fp1);
	gotoxy(37,10);
	textcolor(4);  textbackground(7);
	cprintf("Incorrect User Id !");
	delay(1000);


    }
    else if(fp1!=NULL)
    {

      while(fscanf(fp1,"%s %s %s %s %s %s\n",billno[n],price[n],qty[n],total[n],readtime[n],readdate[n])!=EOF)
      {


       grandtotal+=atoi(total[n]);
       n++;
      }

      fclose(fp1);

	  start=0;
	  scroll=5;

	  viewdata:

	  _setcursortype(_NOCURSOR);
    scrollbox(20,2,78,22,7);


	gotoxy(21,21);
	textcolor(1);
	textbackground(3);
	cprintf("        Total Bill    =    %d                         ",grandtotal);


    textbackground(4);
    gotoxy(21,3);
    textcolor(15);

   cprintf(" #    Price   Qty(ltr.)   Bill(rup.)   Time   Date      ");


	      scrollnumber=start+1;

       for(i=start,j=5; j<=19; i++,j+=2)
     {


	 if(i<n)
	 {


	      if(scroll==j)
	      {

		gotoxy(23,scroll);
		textbackground(2);
		cprintf("                                                    ");
		bkcolor=2;
		texcolor=15;
	      }
	      else
	      {
	      bkcolor=7;
	      texcolor=0;

	      }

       gotoxy(22,j);
       textcolor(1);
       textbackground(bkcolor);
       cprintf("[%s]",billno[i]);
       gotoxy(28,j);
       textcolor(texcolor);
       textbackground(bkcolor);
       cprintf("%s",price[i]);
       gotoxy(38,j);
       textcolor(texcolor);
       textbackground(bkcolor);
       cprintf("%s",qty[i]);

       gotoxy(48,j);
       textcolor(texcolor);
       textbackground(bkcolor);
       cprintf("%s",total[i]);


       gotoxy(58,j);
       textcolor(texcolor);
       textbackground(bkcolor);
       cprintf("%s",readtime[i]);


     gotoxy(68,j);
       textcolor(texcolor);
       textbackground(bkcolor);
       cprintf("%s",readdate[i]);

	 scrollnumber++;
	   }
     }
    key=getch();
    if(key==8||key==13)
    {


    }
    else
    {
     key=getch();
     if(key==80)
     {
	  scroll+=2;
       scrollnumber-=1;
       if(scrollnumber<8)
       {
	if(scroll>=(scrollnumber*2)+3)
	{
	 scroll=(scrollnumber*2)+3;
	}

       }
       if(scroll>19)
       {

       start++;
       if(start>n-8)
       {
	 start=n-8;
       }
       scroll=19;
       }

	goto viewdata;
     }
     else if(key==72)
     {
	scroll-=2;

	if(scroll<5)
	{
	  start--;
	  if(start<0)
	  {
	   start=0;
	  }
	scroll=5;
	}
       goto viewdata;
     }
     else
     {
     goto viewdata;

     }
    }

 }
}

void viewcustomer()
{

     char username[20][20],mobileno[20][15],addres1[20][25],addres2[20][25],idname[20][15],idno[20][20],userid[20][12];

     int chk,n=0,texcolor;
     char *checkid,*check1id;
      _setcursortype(_NORMALCURSOR);
    scrollbox(20,3,75,12,7);
    textbackground(2);
    gotoxy(21,4);
    textcolor(6);
     cprintf("                     View Customer                     ");

    box(45,7,25,1,0,7);
    textcolor(1);  textbackground(7);
    gotoxy(23,7);  cprintf("Enter User id       :");

    textcolor(0);  textbackground(7);
    gotoxy(47,7);  cprintf("                       ");
     fflush(stdin);
     gotoxy(47,7);
    gets(checkid);
    strcpy(check1id,checkid);
    strcat(checkid,".txt");
    fp1=fopen(checkid,"r");
    if(fp1==NULL)
    {
       fclose(fp1);
       _setcursortype(_NOCURSOR);
	gotoxy(30,10);
	textcolor(4);  textbackground(7);
	cprintf("Erorr : Incorrect User Id !");
	delay(1200);

    }
    else
    {
	 fclose(fp1);


	fp=fopen("customer.txt","r");

     while(fscanf(fp,"%s %s\n%s %[^\n]\n%s %s %s",username[n],mobileno[n],addres1[n],addres2[n],idname[n],idno[n],userid[n])!=EOF)

     {
	chk=strcmp(userid[n],check1id);
	if(chk==0)
	{
       texcolor=1;
      scrollbox(20,3,75,20,7);
       _setcursortype(_NOCURSOR);
     gotoxy(21,4);

     textcolor(0); textbackground(2);
     cprintf("                   User Account                       ");
     textcolor(texcolor);  textbackground(7);
      gotoxy(22,6);  cprintf("User Name          :");

     textcolor(0);  textbackground(7);
      gotoxy(45,6); cprintf("%s",username[n]);

       textcolor(texcolor);  textbackground(7);
      gotoxy(22,8);  cprintf("Mobile Number      :");

     textcolor(0);  textbackground(7);
      gotoxy(45,8); cprintf("%s",mobileno[n]);
       textcolor(texcolor);  textbackground(7);
      gotoxy(22,10); cprintf("Address  Line  1   :");

     textcolor(0);  textbackground(7);
      gotoxy(45,10); cprintf("%s",addres1[n]);

       textcolor(texcolor);  textbackground(7);
      gotoxy(22,12); cprintf("Address  Line  2   :");

     textcolor(0);  textbackground(7);
      gotoxy(45,12); cprintf("%s",addres2[n]);
       textcolor(texcolor);  textbackground(7);
      gotoxy(22,14); cprintf("Identity Proof     :");

     textcolor(0);  textbackground(7);
      gotoxy(45,14); cprintf("%s",idname[n]);

       textcolor(texcolor);  textbackground(7);
      gotoxy(22,16); cprintf("Identity Proof No. :");

     textcolor(0);  textbackground(7);
      gotoxy(45,16); cprintf("%s",idno[n]);

       textcolor(texcolor);  textbackground(7);
      gotoxy(22,18); cprintf("User id            :");

     textcolor(0);  textbackground(7);
      gotoxy(45,18); cprintf("%s",check1id);
      getch();



	}
	else
	{

	}
       n++;
     }

     fclose(fp);
    }


}

void allcustomer()
{



	int k=7;
	allcustomer:
	 scrollbox(20,6,37,9,7);

	if(k==7)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(21,7);  cprintf(" Sort By Name   ");

	if(k==8)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(21,8);  cprintf(" Sort By userid ");

	key=getch();
	if(key==8)
	{

	}
	else if(key==13)
	{
	  if(k==7)
	  {
	    sortbyname();

	  }
	  else if(k==8)
	  {
	  sortbyuserid();
	  }
	}
	else if(key==0)
	{
	  key=getch();
	  if(key==80)
	  {
	    k++;
	    if(k>8)
	    {
	    k=7;
	    }
	    goto 	allcustomer;
	  }
	  else if(key==72)
	  {
	   k--;
	   if(k<7)
	   {
	   k=8;
	   }

	   goto 	allcustomer;
	  }
	  else if(key==8)
	  {


	  }
	  else
	  {
	  goto 	allcustomer;
	  }

	}
	else if(key==8)
	{

	}



}

void sortbyuserid()
{

     int n=0;
     int start;
     char *temp;
     int scroll,scrollnumber,bkcolor,texcolor;
     char username[20][20],contactno[20][15],addres[20][50],idname[20][20],idno[20][20],userid[20][10];
     fp=fopen("customer.txt","r");
     while(fscanf(fp,"%s %s\n%[^\n]\n%s %s %s",username[n],contactno[n],addres[n],idname[n],idno[n],userid[n])!=EOF)

     {
      n++;

     }
     fclose(fp);



	for(i=0; i<n; i++)
	{
	   for(j=i+1; j<n; j++)
	   {
	     if(strcmp(userid[i],userid[j])>0)
	     {
	       strcpy(temp,"");
	      strcpy(temp,username[i]);
	     strcpy(username[i],username[j]);
	     strcpy(username[j],temp);
	      strcpy(temp,"");
	     strcpy(temp,contactno[i]);

	     strcpy(contactno[i],contactno[j]);
	    strcpy(contactno[j],temp);
	      strcpy(temp,"");

	     strcpy(temp,addres[i]);

	     strcpy(addres[i],addres[j]);
	    strcpy(addres[j],temp);

	      strcpy(temp,"");

	     strcpy(temp,idname[i]);

	     strcpy(idname[i],idname[j]);
	    strcpy(idname[j],temp);
	      strcpy(temp,"");

	     strcpy(temp,idno[i]);

	     strcpy(idno[i],idno[j]);
	    strcpy(idno[j],temp);
	      strcpy(temp,"");

	     strcpy(temp,userid[i]);

	     strcpy(userid[i],userid[j]);
	    strcpy(userid[j],temp);


	     }


	   }
	}
	  start=0;
	  scroll=5;

	  viewdata:

	  _setcursortype(_NOCURSOR);
    scrollbox(20,2,78,20,7);



    textbackground(4);
    gotoxy(21,3);
    textcolor(15);

   cprintf(" #    CustomerName        Contact Number     Userid      ");


	      scrollnumber=start+1;

       for(i=start,j=5; j<=19; i++,j+=2)
     {


	 if(i<n)
	 {


	      if(scroll==j)
	      {

		gotoxy(23,scroll);
		textbackground(2);
		cprintf("                                                    ");
		bkcolor=2;
		texcolor=15;
	      }
	      else
	      {
	      bkcolor=7;
	      texcolor=0;

	      }

       gotoxy(22,j);
       textcolor(1);
       textbackground(bkcolor);
       cprintf("[%d]",scrollnumber);
       gotoxy(28,j);
       textcolor(texcolor);
       textbackground(bkcolor);
       cprintf("%s",username[i]);
       gotoxy(48,j);
       textcolor(texcolor);
       textbackground(bkcolor);
       cprintf("%s",contactno[i]);

       gotoxy(69,j);
       textcolor(texcolor);
       textbackground(bkcolor);
       cprintf("%s",userid[i]);


	 scrollnumber++;
	   }
     }
    key=getch();
    if(key==8||key==13)
    {


    }

    else
    {
     key=getch();
     if(key==80)
     {
	  scroll+=2;
       scrollnumber-=1;
       if(scrollnumber<8)
       {
	if(scroll>=(scrollnumber*2)+3)
	{
	 scroll=(scrollnumber*2)+3;
	}

       }
       if(scroll>19)
       {

       start++;
       if(start>n-8)
       {
	 start=n-8;
       }
       scroll=19;
       }

	goto viewdata;
     }
     else if(key==72)
     {
	scroll-=2;

	if(scroll<5)
	{
	  start--;
	  if(start<0)
	  {
	   start=0;
	  }
	scroll=5;
	}
       goto viewdata;
     }
     else
     {
     goto viewdata;

     }
  }

}
void sortbyname()
{
     int n=0;
     int start;
     char *temp;
     int scroll,scrollnumber,bkcolor,texcolor;
     char username[20][20],contactno[20][15],addres[20][50],idname[20][20],idno[20][20],userid[20][10];
     fp=fopen("customer.txt","r");
     while(fscanf(fp,"%s %s\n%[^\n]\n%s %s %s",username[n],contactno[n],addres[n],idname[n],idno[n],userid[n])!=EOF)

     {
      n++;

     }
     fclose(fp);



	for(i=0; i<n; i++)
	{
	   for(j=i+1; j<n; j++)
	   {
	     if(strcmp(username[i],username[j])>0)
	     {
	       strcpy(temp,"");
	      strcpy(temp,username[i]);
	     strcpy(username[i],username[j]);
	     strcpy(username[j],temp);
	      strcpy(temp,"");
	     strcpy(temp,contactno[i]);

	     strcpy(contactno[i],contactno[j]);
	    strcpy(contactno[j],temp);
	      strcpy(temp,"");

	     strcpy(temp,addres[i]);

	     strcpy(addres[i],addres[j]);
	    strcpy(addres[j],temp);

	      strcpy(temp,"");

	     strcpy(temp,idname[i]);

	     strcpy(idname[i],idname[j]);
	    strcpy(idname[j],temp);
	      strcpy(temp,"");

	     strcpy(temp,idno[i]);

	     strcpy(idno[i],idno[j]);
	    strcpy(idno[j],temp);
	      strcpy(temp,"");

	     strcpy(temp,userid[i]);

	     strcpy(userid[i],userid[j]);
	    strcpy(userid[j],temp);


	     }


	   }
	}
	  start=0;
	  scroll=5;

	  viewdata:

	  _setcursortype(_NOCURSOR);
    scrollbox(20,2,78,20,7);



    textbackground(4);
    gotoxy(21,3);
    textcolor(15);

   cprintf(" #    CustomerName        Contact Number     Userid      ");


	      scrollnumber=start+1;

       for(i=start,j=5; j<=19; i++,j+=2)
     {


	 if(i<n)
	 {


	      if(scroll==j)
	      {

		gotoxy(23,scroll);
		textbackground(2);
		cprintf("                                                    ");
		bkcolor=2;
		texcolor=15;
	      }
	      else
	      {
	      bkcolor=7;
	      texcolor=0;

	      }

       gotoxy(22,j);
       textcolor(1);
       textbackground(bkcolor);
       cprintf("[%d]",scrollnumber);
       gotoxy(28,j);
       textcolor(texcolor);
       textbackground(bkcolor);
       cprintf("%s",username[i]);
       gotoxy(48,j);
       textcolor(texcolor);
       textbackground(bkcolor);
       cprintf("%s",contactno[i]);

       gotoxy(69,j);
       textcolor(texcolor);
       textbackground(bkcolor);
       cprintf("%s",userid[i]);


	 scrollnumber++;
	   }
     }
    key=getch();
    if(key==8||key==13)
    {


    }

    else
    {
     key=getch();
     if(key==80)
     {
	  scroll+=2;
       scrollnumber-=1;
       if(scrollnumber<8)
       {
	if(scroll>=(scrollnumber*2)+3)
	{
	 scroll=(scrollnumber*2)+3;
	}

       }
       if(scroll>19)
       {

       start++;
       if(start>n-8)
       {
	 start=n-8;
       }
       scroll=19;
       }

	goto viewdata;
     }
     else if(key==72)
     {
	scroll-=2;

	if(scroll<5)
	{
	  start--;
	  if(start<0)
	  {
	   start=0;
	  }
	scroll=5;
	}
       goto viewdata;
     }
     else
     {
     goto viewdata;

     }
  }

}

void editnumber()
{

     char checkid[20],userid[20],name[20],checkname[20],oldnumber[20],newnumber[20],address1[30],address2[30],idname[20],idno[20],realuserid[20];
      int chk;

      char firstname[20],lastname[20];
      _setcursortype(_NORMALCURSOR);
    scrollbox(20,2,75,12,7);
    textbackground(2);
    gotoxy(21,3);
    textcolor(6);
     cprintf("                     Edit Number                     ");

    box(45,7,25,1,0,7);
    textcolor(1);  textbackground(7);
    gotoxy(23,7);  cprintf("Enter User id       :");

     fflush(stdin);
     gotoxy(47,7);
    gets(userid);
    strcpy(checkid,userid);
    strcat(userid,".txt");
    fp1=fopen(userid,"r");
    if(fp1==NULL)
    {
       fclose(fp1);
       _setcursortype(_NOCURSOR);
	gotoxy(30,10);
	textcolor(4);  textbackground(7);
	cprintf("Erorr : Incorrect User Id !");
	delay(1200);

    }
    else
    {
	 fclose(fp1);
	 fp=fopen("customer.txt","r");
	 fp1=fopen("temp.txt","a");
	 while(fscanf(fp,"%s %s\n%s %s\n%s %s %s\n",name,oldnumber,address1,address2,idname,idno,realuserid)!=EOF)
	 {
	   chk=strcmp(checkid,realuserid);
	   if(chk==0)
	   {


		   _setcursortype(_NORMALCURSOR);
		    scrollbox(20,2,75,20,7);
		    textbackground(2);
		    gotoxy(21,3);
		    textcolor(6);
		     cprintf("                     Edit Number                     ");

		    box(45,7,25,1,0,7);
		    textcolor(1);  textbackground(7);
		    gotoxy(23,7);  cprintf("Old Number       :");
		    textcolor(8);  textbackground(7);
		    gotoxy(47,7);  cprintf("%s",oldnumber);



		    textcolor(1);  textbackground(7);
		    gotoxy(23,13);  cprintf("New Number     :");
			box(45,13,25,1,0,7);
			    fflush(stdin);

		      gotoxy(47,13);
		      textcolor(0); textbackground(7);  cprintf("                     ");

		     fflush(stdin);
		    gotoxy(47,13);
		    gets(newnumber);

		   _setcursortype(_NOCURSOR);
		textcolor(7);  textbackground(1);
		   gotoxy(25,18);  cprintf(" Save [ Enter ]  ");


		textcolor(7);  textbackground(4);
		 gotoxy(52,18);  cprintf( " Cancel [ Backspace ] ");
		key:
		  key=getch();
		if(key==13)
		   {
			fprintf(fp1,"%s %s\n%s %s\n%s %s %s\n",name,newnumber,address1,address2,idname,idno,realuserid);


		   _setcursortype(_NORMALCURSOR);
		    scrollbox(20,2,75,20,7);
		    gotoxy(32,10);
		    textcolor(0); textbackground(2);
		    cprintf("Changes Successfully Submited");
		    delay(1000);
		    }
		  else if(key==8)
		   {
			fprintf(fp1,"%s %s\n%s %s\n%s %s %s\n",name,oldnumber,address1,address2,idname,idno,realuserid);

		   }
		   else

		   {
		   goto key;
		   }

	   }
	   else
	   {

	fprintf(fp1,"%s %s\n%s %s\n%s %s %s\n",name,oldnumber,address1,address2,idname,idno,realuserid);


	   }

	 }

 fclose(fp1);
  fclose(fp);
  fp=fopen("customer.txt","w");
  fclose(fp);
  fp1=fopen("temp.txt","r");
  fp=fopen("customer.txt","a");

  while(fscanf(fp1,"%s %s\n%s %s\n%s %s %s\n",name,oldnumber,address1,address2,idname,idno,realuserid)!=EOF)
  {

   fprintf(fp,"%s %s\n%s %s\n%s %s %s\n",name,oldnumber,address1,address2,idname,idno,realuserid);
  }

 fclose(fp1);
  fclose(fp);
  fp1=fopen("temp.txt","w");
  fclose(fp1);




	 }


}
void editname()
{
     char checkid[20],userid[20],oldname[20],newname[30],checkname[20],number[20],address1[30],address2[30],idname[20],idno[20],realuserid[20];
      int chk;

      char firstname[20],lastname[20];
      _setcursortype(_NORMALCURSOR);
    scrollbox(20,2,75,12,7);
    textbackground(2);
    gotoxy(21,3);
    textcolor(6);
     cprintf("                     Edit Name                        ");

    box(45,7,25,1,0,7);
    textcolor(1);  textbackground(7);
    gotoxy(23,7);  cprintf("Enter User id       :");

     fflush(stdin);
     gotoxy(47,7);
    gets(userid);
    strcpy(checkid,userid);
    strcat(userid,".txt");
    fp1=fopen(userid,"r");
    if(fp1==NULL)
    {
       fclose(fp1);
       _setcursortype(_NOCURSOR);
	gotoxy(30,10);
	textcolor(4);  textbackground(7);
	cprintf("Erorr : Incorrect User Id !");
	delay(1200);

    }
    else
    {
	 fclose(fp1);
	 fp=fopen("customer.txt","r");
	 fp1=fopen("temp.txt","a");
	 while(fscanf(fp,"%s %s\n%s %s\n%s %s %s\n",oldname,number,address1,address2,idname,idno,realuserid)!=EOF)
	 {
	   chk=strcmp(checkid,realuserid);
	   if(chk==0)
	   {


		   _setcursortype(_NORMALCURSOR);
		    scrollbox(20,2,75,20,7);
		    textbackground(2);
		    gotoxy(21,3);
		    textcolor(6);
		     cprintf("                     Edit Name                        ");

		    box(45,7,25,1,0,7);
		    textcolor(1);  textbackground(7);
		    gotoxy(23,7);  cprintf("Old Name       :");
		    textcolor(8);  textbackground(7);
		    gotoxy(47,7);  cprintf("%s",oldname);


		    textcolor(1);  textbackground(7);
		    gotoxy(23,10);  cprintf("First Name      :");
			box(45,10,25,1,0,7);

		    textcolor(1);  textbackground(7);
		    gotoxy(23,13);  cprintf("Last  Name      :");
			box(45,13,25,1,0,7);
			    fflush(stdin);
		      gotoxy(47,10);
		      textcolor(0); textbackground(7);  cprintf("                     ");
		    gotoxy(47,10);
		    gets(newname);

		    if(newname[0]>=97 &&newname[0]<=122)
		    {
		    newname[0]-=32;
		    }
		      gotoxy(47,13);
		      textcolor(0); textbackground(7);  cprintf("                     ");

		     fflush(stdin);
		    gotoxy(47,13);
		    gets(lastname);

		    if(lastname[0]>=97 &&lastname[0]<=122)
		    {
		    lastname[0]-=32;
		    }
		    strcat(newname,lastname);

		   _setcursortype(_NOCURSOR);
		textcolor(7);  textbackground(1);
		   gotoxy(25,18);  cprintf(" Save [ Enter ]  ");


		textcolor(7);  textbackground(4);
		 gotoxy(52,18);  cprintf( " Cancel [ Backspace ] ");
		key:
		  key=getch();
		if(key==13)
		   {
			fprintf(fp1,"%s %s\n%s %s\n%s %s %s\n",newname,number,address1,address2,idname,idno,realuserid);


		   _setcursortype(_NORMALCURSOR);
		    scrollbox(20,2,75,20,7);
		    gotoxy(32,10);
		    textcolor(0); textbackground(2);
		    cprintf("Changes Successfully Submited");
		    delay(1000);
		    }
		  else if(key==8)
		   {
			fprintf(fp1,"%s %s\n%s %s\n%s %s %s\n",oldname,number,address1,address2,idname,idno,realuserid);

		   }
		   else

		   {
		   goto key;
		   }

	   }
	   else
	   {

	fprintf(fp1,"%s %s\n%s %s\n%s %s %s\n",oldname,number,address1,address2,idname,idno,realuserid);


	   }

	 }

 fclose(fp1);
  fclose(fp);
  fp=fopen("customer.txt","w");
  fclose(fp);
  fp1=fopen("temp.txt","r");
  fp=fopen("customer.txt","a");

  while(fscanf(fp1,"%s %s\n%s %s\n%s %s %s\n",oldname,number,address1,address2,idname,idno,realuserid)!=EOF)
  {

   fprintf(fp,"%s %s\n%s %s\n%s %s %s\n",oldname,number,address1,address2,idname,idno,realuserid);
  }

 fclose(fp1);
  fclose(fp);
  fp1=fopen("temp.txt","w");
  fclose(fp1);
	 }
}
void editaddress()
{

     char checkid[20],userid[20],name[20],checkname[20],number[20],address1[30],address2[30],newaddress1[30],newaddress2[30],add1[30],add2[30],idname[20],idno[20],realuserid[10];
      int chk;

      char firstname[20],lastname[20];
      _setcursortype(_NORMALCURSOR);
    scrollbox(20,2,75,12,7);
    textbackground(2);
    gotoxy(21,3);
    textcolor(6);
     cprintf("                     Edit Address                     ");

    box(45,7,25,1,0,7);
    textcolor(1);  textbackground(7);
    gotoxy(23,7);  cprintf("Enter User id       :");

     fflush(stdin);
     gotoxy(47,7);
    gets(userid);
    strcpy(checkid,userid);
    strcat(userid,".txt");
    fp1=fopen(userid,"r");
    if(fp1==NULL)
    {
       fclose(fp1);
       _setcursortype(_NOCURSOR);
	gotoxy(30,10);
	textcolor(4);  textbackground(7);
	cprintf("Erorr : Incorrect User Id !");
	delay(1200);

    }
    else
    {
	 fclose(fp1);
	 fp=fopen("customer.txt","r");
	 fp1=fopen("temp.txt","a");
	 while(fscanf(fp,"%s %s\n%s %s\n%s %s %s\n",name,number,address1,address2,idname,idno,realuserid)!=EOF)
	 {
	   chk=strcmp(checkid,realuserid);
	   if(chk==0)
	   {


		   _setcursortype(_NORMALCURSOR);
		    scrollbox(20,2,75,20,7);
		    textbackground(2);
		    gotoxy(21,3);
		    textcolor(6);
		     cprintf("                     Edit Address                    ");

		    box(45,7,28,1,0,7);
		    textcolor(1);  textbackground(7);
		    gotoxy(23,7);  cprintf("Old Address Line 1 :");
		    textcolor(8);  textbackground(7);
		    gotoxy(47,7);  cprintf("%s",address1);


		    box(45,10,28,1,0,7);
		    textcolor(1);  textbackground(7);
		    gotoxy(23,10);  cprintf("Old Address Line 2 :");
		    textcolor(8);  textbackground(7);
		    gotoxy(47,10);  cprintf("%s",address2);


		    textcolor(1);  textbackground(7);
		    gotoxy(23,13);  cprintf("Address Line 1     :");
			box(45,13,28,1,0,7);

		    textcolor(1);  textbackground(7);
		    gotoxy(23,16);  cprintf("Address Line 2     :");
			box(45,16,28,1,0,7);
			    fflush(stdin);
		      gotoxy(47,13);
		      textcolor(0); textbackground(7);  cprintf("                          ");
		    gotoxy(47,13);
		    gets(add1);

		    j=0;
		    for(i=0; i<strlen(add1); i++)
		    {
		      if(add1[i]!=' ')
		      {
			newaddress1[j]=add1[i];
		      }
		      else
		      {
		       newaddress1[j]='_';
		      }
		      j++;

		    }
		    newaddress1[j]='\0';
		    if(newaddress1[0]>=97 &&newaddress1[0]<=122)
		    {
		    newaddress1[0]-=32;
		    }
		      gotoxy(47,16);
		      textcolor(0); textbackground(7);  cprintf("                          ");

		     fflush(stdin);
		    gotoxy(47,16);
		    gets(add2);

		    j=0;
		    for(i=0; i<strlen(add2); i++)
		    {
		      if(add2[i]!=' ')
		      {
			newaddress2[j]=add2[i];
		      }
		      else
		      {
		       newaddress2[j]='-';
		      }
			j++;
		    }
		    newaddress2[j]='\0';

		    if(newaddress2[0]>=97 &&newaddress2[0]<=122)
		    {
		    newaddress2[0]-=32;
		    }


		   _setcursortype(_NOCURSOR);
		textcolor(7);  textbackground(1);
		   gotoxy(25,18);  cprintf(" Save [ Enter ]  ");


		textcolor(7);  textbackground(4);
		 gotoxy(52,18);  cprintf( " Cancel [ Backspace ] ");
		key:
		  key=getch();
		if(key==13)
		   {
			fprintf(fp1,"%s %s\n%s %s\n%s %s %s\n",name,number,newaddress1,newaddress2,idname,idno,realuserid);


		   _setcursortype(_NORMALCURSOR);
		    scrollbox(20,2,75,20,7);
		    gotoxy(32,10);
		    textcolor(0); textbackground(2);
		    cprintf("Changes Successfully Submited");
		    delay(1000);
		    }
		  else if(key==8)
		   {
			fprintf(fp1,"%s %s\n%s %s\n%s %s %s\n",name,number,address1,address2,idname,idno,realuserid);

		   }
		   else

		   {
		   goto key;
		   }

	   }
	   else
	   {

	fprintf(fp1,"%s %s\n%s %s\n%s %s %s\n",name,number,address1,address2,idname,idno,realuserid);


	   }

	 }

 fclose(fp1);
  fclose(fp);
  fp=fopen("customer.txt","w");
  fclose(fp);
  fp1=fopen("temp.txt","r");
  fp=fopen("customer.txt","a");

  while(fscanf(fp1,"%s %s\n%s %s\n%s %s %s\n",name,number,address1,address2,idname,idno,realuserid)!=EOF)
  {

   fprintf(fp,"%s %s\n%s %s\n%s %s %s\n",name,number,address1,address2,idname,idno,realuserid);
  }

 fclose(fp1);
  fclose(fp);
  fp1=fopen("temp.txt","w");
  fclose(fp1);
	 }

}
void editidproof()
{


     char checkid[20],userid[20],name[20],checkname[20],number[20],address1[30],address2[30],idname[20],idno[20],newidname[20],newidno[20],checkidno[20],checkidname[20],realuserid[10];
      int chk;

      char firstname[20],lastname[20];
      _setcursortype(_NORMALCURSOR);
    scrollbox(20,2,75,12,7);
    textbackground(2);
    gotoxy(21,3);
    textcolor(6);
     cprintf("                     Edit IdProof                     ");

    box(45,7,25,1,0,7);
    textcolor(1);  textbackground(7);
    gotoxy(23,7);  cprintf("Enter User id       :");

     fflush(stdin);
     gotoxy(47,7);
    gets(userid);
    strcpy(checkid,userid);
    strcat(userid,".txt");
    fp1=fopen(userid,"r");
    if(fp1==NULL)
    {
       fclose(fp1);
       _setcursortype(_NOCURSOR);
	gotoxy(30,10);
	textcolor(4);  textbackground(7);
	cprintf("Erorr : Incorrect User Id !");
	delay(1200);

    }
    else
    {
	 fclose(fp1);
	 fp=fopen("customer.txt","r");
	 fp1=fopen("temp.txt","a");
	 while(fscanf(fp,"%s %s\n%s %s\n%s %s %s\n",name,number,address1,address2,idname,idno,realuserid)!=EOF)
	 {
	   chk=strcmp(checkid,realuserid);
	   if(chk==0)
	   {


		   _setcursortype(_NORMALCURSOR);
		    scrollbox(20,2,75,20,7);
		    textbackground(2);
		    gotoxy(21,3);
		    textcolor(6);
		     cprintf("                     Edit IdProof                     ");

		    box(45,7,28,1,0,7);
		    textcolor(1);  textbackground(7);
		    gotoxy(23,7);  cprintf("Id Proof Name        :");
		    textcolor(8);  textbackground(7);
		    gotoxy(47,7);  cprintf("%s",idname);


		    box(45,10,28,1,0,7);
		    textcolor(1);  textbackground(7);
		    gotoxy(23,10);  cprintf("Id Proof Number     :");
		    textcolor(8);  textbackground(7);
		    gotoxy(47,10);  cprintf("%s",idno);


		    textcolor(1);  textbackground(7);
		    gotoxy(23,13);  cprintf("New Id Proof Name   :");
			box(45,13,28,1,0,7);

		    textcolor(1);  textbackground(7);
		    gotoxy(23,16);  cprintf("New Id Proof Number :");
			box(45,16,28,1,0,7);
			    fflush(stdin);
		      gotoxy(47,13);
		      textcolor(0); textbackground(7);  cprintf("                     ");
		    gotoxy(47,13);
		    gets(checkidname);

		    j=0;
		    for(i=0; i<strlen(checkidname); i++)
		    {
		      if(checkidname[i]!=' ')
		      {
			newidname[j]=checkidname[i];
		      }
		      j++;

		    }
		    newidname[j]='\0';
		    if(newidname[0]>=97 &&newidname[0]<=122)
		    {
		    newidname[0]-=32;
		    }
		      gotoxy(47,16);
		      textcolor(0); textbackground(7);  cprintf("                     ");

		     fflush(stdin);
		    gotoxy(47,16);
		    gets(checkidno);

		    j=0;
		    for(i=0; i<strlen(checkidno); i++)
		    {
		      if(checkidno[i]!=' ')
		      {
			newidno[j]=checkidno[i];
		      }
		      else
		      {
		       newidno[j]='-';
		      }
			j++;
		    }
		    newidno[j]='\0';

		    if(newidno[0]>=97 &&newidno[0]<=122)
		    {
		    newidno[0]-=32;
		    }


		   _setcursortype(_NOCURSOR);
		textcolor(7);  textbackground(1);
		   gotoxy(25,18);  cprintf(" Save [ Enter ]  ");


		textcolor(7);  textbackground(4);
		 gotoxy(52,18);  cprintf( " Cancel [ Backspace ] ");
		key:
		  key=getch();
		if(key==13)
		   {
			fprintf(fp1,"%s %s\n%s %s\n%s %s %s\n",name,number,address1,address2,newidname,newidno,realuserid);


		   _setcursortype(_NORMALCURSOR);
		    scrollbox(20,2,75,20,7);
		    gotoxy(32,10);
		    textcolor(0); textbackground(2);
		    cprintf("Changes Successfully Submited");
		    delay(1000);
		    }
		  else if(key==8)
		   {
			fprintf(fp1,"%s %s\n%s %s\n%s %s %s\n",name,number,address1,address2,idname,idno,realuserid);

		   }
		   else

		   {
		   goto key;
		   }

	   }
	   else
	   {

	fprintf(fp1,"%s %s\n%s %s\n%s %s %s\n",name,number,address1,address2,idname,idno,realuserid);


	   }

	 }

 fclose(fp1);
  fclose(fp);
  fp=fopen("customer.txt","w");
  fclose(fp);
  fp1=fopen("temp.txt","r");
  fp=fopen("customer.txt","a");

  while(fscanf(fp1,"%s %s\n%s %s\n%s %s %s\n",name,number,address1,address2,idname,idno,realuserid)!=EOF)
  {

   fprintf(fp,"%s %s\n%s %s\n%s %s %s\n",name,number,address1,address2,idname,idno,realuserid);
  }

 fclose(fp1);
  fclose(fp);
  fp1=fopen("temp.txt","w");
  fclose(fp1);
	 }

}
void edituserid()
{

     char checkid[20],userid[20],name[20],checkname[20],number[20],address1[30],address2[30],idname[20],idno[20],realuserid[10],newuserid[10];
      int chk;
      FILE *fp3,*fp4;
      char alldata[80];
      char newuserid1[10];
      char firstname[20],lastname[20];
      int chk2;
      _setcursortype(_NORMALCURSOR);
    scrollbox(20,2,75,12,7);
    textbackground(2);
    gotoxy(21,3);
    textcolor(6);
     cprintf("                     Edit Userid                     ");

    box(45,7,25,1,0,7);
    textcolor(1);  textbackground(7);
    gotoxy(23,7);  cprintf("Enter User id       :");


    gotoxy(47,7);
      textcolor(0); textbackground(7);  cprintf("                     ");

     fflush(stdin);
     gotoxy(47,7);
    gets(userid);
    strcpy(checkid,userid);
    strcat(userid,".txt");
    fp1=fopen(userid,"r");
    if(fp1==NULL)
    {
       fclose(fp1);
       _setcursortype(_NOCURSOR);
	gotoxy(30,10);
	textcolor(4);  textbackground(7);
	cprintf("Erorr : Incorrect User Id !");
	delay(1200);

    }
    else
    {
	 fclose(fp1);
	 fp=fopen("customer.txt","r");
	 fp1=fopen("temp.txt","a");
	 while(fscanf(fp,"%s %s\n%s %s\n%s %s %s\n",name,number,address1,address2,idname,idno,realuserid)!=EOF)
	 {
	   chk=strcmp(checkid,realuserid);
	   if(chk==0)
	   {


		   _setcursortype(_NORMALCURSOR);
		    scrollbox(20,2,75,20,7);
		    textbackground(2);
		    gotoxy(21,3);
		    textcolor(6);
		     cprintf("                     Edit Userid                      ");

		    box(45,7,25,1,0,7);
		    textcolor(1);  textbackground(7);
		    gotoxy(23,7);  cprintf("Old Userid       :");
		    textcolor(8);  textbackground(7);
		    gotoxy(47,7);  cprintf("%s",realuserid);



		    textcolor(1);  textbackground(7);
		    gotoxy(23,13);  cprintf("New Userid     :");
			box(45,13,25,1,0,7);
			    fflush(stdin);

		      gotoxy(47,13);
		      textcolor(0); textbackground(7);  cprintf("                     ");

		     fflush(stdin);
		    gotoxy(47,13);
		    gets(newuserid);

		   _setcursortype(_NOCURSOR);
		textcolor(7);  textbackground(1);
		   gotoxy(25,18);  cprintf(" Save [ Enter ]  ");


		textcolor(7);  textbackground(4);
		 gotoxy(52,18);  cprintf( " Cancel [ Backspace ] ");
		key:
		  key=getch();
		if(key==13)
		   {
		   chk2=strcmp(newuserid,checkid);
		   if(chk2!=0)
		   {
		    strcpy(newuserid1,newuserid);
		    strcat(newuserid1,".txt");
		   fp3=fopen(userid,"r");
		   fp4=fopen(newuserid1,"a");

		   while(fscanf(fp3,"%[^\n]\n",alldata)!=EOF)
		   {
		      fprintf(fp4,"%s\n",alldata);
		   }
		   fclose(fp3);
		   fclose(fp4);

		   remove(userid);
		   }
			fprintf(fp1,"%s %s\n%s %s\n%s %s %s\n",name,number,address1,address2,idname,idno,newuserid);


		   _setcursortype(_NORMALCURSOR);
		    scrollbox(20,2,75,20,7);
		    gotoxy(32,10);
		    textcolor(0); textbackground(2);
		    cprintf("Changes Successfully Submited");
		    delay(1000);
		    }
		  else if(key==8)
		   {
			fprintf(fp1,"%s %s\n%s %s\n%s %s %s\n",name,number,address1,address2,idname,idno,realuserid);

		   }
		   else

		   {
		   goto key;
		   }

	   }
	   else
	   {

	fprintf(fp1,"%s %s\n%s %s\n%s %s %s\n",name,number,address1,address2,idname,idno,realuserid);


	   }

	 }

 fclose(fp1);
  fclose(fp);
  fp=fopen("customer.txt","w");
  fclose(fp);
  fp1=fopen("temp.txt","r");
  fp=fopen("customer.txt","a");

  while(fscanf(fp1,"%s %s\n%s %s\n%s %s %s\n",name,number,address1,address2,idname,idno,realuserid)!=EOF)
  {

   fprintf(fp,"%s %s\n%s %s\n%s %s %s\n",name,number,address1,address2,idname,idno,realuserid);
  }

 fclose(fp1);
  fclose(fp);
  fp1=fopen("temp.txt","w");
  fclose(fp1);




	 }



}
void editcustomer()
{


	int k=6;
	customer:
	scrollbox(40,5,56,11,7);
	textcolor(0); textbackground(2);
	gotoxy(41,k);  cprintf("               ");

	if(k==6)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(41,6);  cprintf(" Edit  Name ");

	if(k==7)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(41,7);  cprintf(" Edit  Number ");

	if(k==8)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(41,8);  cprintf(" Edit  Address ");

	if(k==9)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(41,9);  cprintf(" Edit  Idproof ");

	if(k==10)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(41,10); cprintf(" Edit  Userid ");
	key=getch();
	if(key==8)
	{

	    mainpage(design ,designcolor);
	     menu(5);
	     customer();
	}
	else if(key==13)
	{
	  if(k==6)
	  {
	    editname();

	  }
	  else if(k==7)
	  {
	    editnumber();
	  }
	  else if(k==8)
	  {
	   editaddress();
	  }
	  else if(k==9)
	  {
	     editidproof();
	  }

	  else if(k==10)
	  {
	     edituserid();
	  }

	}
	else if(key==0)
	{
	  key=getch();
	  if(key==80)
	  {
	    k++;
	    if(k>10)
	    {
	    k=6;
	    }
	    goto customer;
	  }
	  else if(key==72)
	  {
	   k--;
	   if(k<6)
	   {
	   k=10;
	   }

	   goto customer;
	  }
	  else if(key==8)
	  {


	  }
	  else
	  {
	  goto customer;
	  }

	}
	else if(key==8)
	{

	}


}

void searchcustomer()
{

	 char sname[30];
	 int scrollnumber,cntkbkcolor,cntktxcolor;
	 char coname[50][30],conumber[50][30],couserid[50][10];
	 int i1=1,inc,k,j,scrolly=5,scrollx,ch;
	 int d,b,match=0;
	 char name[20];
	 char a;
	 char username[20],number[15],address1[25],address2[25],idname[15],idnumber[15],userid[12];
      scrollbox(20,2,77,12,7);


		scrollbox(20,2,77,20,7);
       scrollnumber=inc+1;

	 gotoxy(24,3);
	 textcolor(0);
	 textbackground(2);
	 cprintf("   Search   ",scrollnumber);


	 gotoxy(40,3);
	 textcolor(4);
	 textbackground(3);
	 cprintf(":                                 ",scrollnumber);

	   _setcursortype(_NORMALCURSOR);
	 gotoxy(43,3);
	 textcolor(4);
	 textbackground(3);
	 gets(sname);

     d=0;
     for(i=0; i<strlen(sname); i++)
     {
       if(sname[i]==' ')
       {

       }
       else
       {
	  name[d++]=sname[i];

       }

     }
      i1=0;
    name[d]='\0';
    fp=fopen("customer.txt","r");
      while(fscanf(fp,"%s %s\n%s %s\n%s %s %s",username,number,address1,address2,idname,idnumber,userid)!=EOF)

      {
      strlwr(username);
      strlwr(name);
	if(strstr(username,name)!=NULL)
	{

	  username[0]-=32;
	  strcpy(coname[i1],username);
	  strcpy(conumber[i1],number);
	  strcpy(couserid[i1],userid);
	  match=1;
	  i1++;
	}
      }
      fclose(fp);
      if(match==1)
      {
      inc=1,scrolly=5;
		scrollnumber=1;
		scrollx=21;
		cntkbkcolor=7;
		cntktxcolor=0;
		inc=0;
	scrollcontacts:

      //	system("cls");
	_setcursortype(_NOCURSOR);

 //	mainpage();
    //	menu(11,1);
		scrollbox(20,2,77,20,7);
       scrollnumber=inc+1;

	 gotoxy(24,3);
	 textcolor(0);
	 textbackground(2);
	 cprintf("   Search   ",scrollnumber);


	 gotoxy(40,3);
	 textcolor(1);
	 textbackground(3);
	 cprintf(":                                 ",scrollnumber);


	 gotoxy(43,3);
	 textcolor(4);
	 textbackground(3);
	 cprintf("%s",name);

      for(k=inc,j=5; k<i1,j<=19; k++,j+=2)
      {

	 if(k<i1)
	 {

	 if(scrolly!=j)
	 {
	 cntkbkcolor=7;
	 cntktxcolor=0;
	 }
	 else
	 {

	 for(i=scrollx+1; i<=76; i++)
	 {
	 gotoxy(i,scrolly);
	  textbackground(2);
	  textcolor(2);
	  cprintf(" ");
	 }

	 cntkbkcolor=2;
	 cntktxcolor=15;
	 }
	 gotoxy(24,j);
	 textcolor(cntktxcolor);
	 textbackground(cntkbkcolor);
	 cprintf("[%d] ",scrollnumber);


	 gotoxy(30,j);
	 textcolor(cntktxcolor);
	 textbackground(cntkbkcolor);
	 cprintf("%s",coname[k]);



	 gotoxy(55,j);
	 textcolor(cntktxcolor);
	 textbackground(cntkbkcolor);
	 cprintf("%s",conumber[k]);



	 gotoxy(70,j);
	 textcolor(cntktxcolor);
	 textbackground(cntkbkcolor);
	 cprintf("%s",couserid[k]);
	 scrollnumber++;
	  }

	   }
	   a=getch();
	   if(a==13||a==8)
	   {

	    }
	    else
	    {

	   b=getch();

	   if(b==80 || b==' ')
	   {
		scrollnumber-=1;
		if(scrollnumber<8)
		{
		if(scrolly>=(scrollnumber*2)+3)
		{
		 scrolly=((scrollnumber*2)+3)-2;
		}
		}
	     scrolly+=2;

	     if(scrolly>19)
	     {
	      inc++;
	      if(inc>i1-8)
	      {
		inc=i1-8;
	      }
	      scrolly=19;
	     }

	     goto scrollcontacts;
	   }
	   else if(b==72||b==8)
	   {
	     scrolly-=2;

	     if(scrolly<5)
	     {
	       inc--;
	       scrolly=5;
	      if(inc<0)
	      {
	       inc=0;

	      }

	     }
	     goto scrollcontacts;

	   }
	   else
	   {


	   }
	  }
	 for(k=0; k<=i1; k++)
	 {
	     strcpy(coname[k],"");
	     strcpy(conumber[k],"");
	 }
       }

     else
     {

      fclose(fp);
      scrollbox(20,2,77,20,7);


	  gotoxy(37,11);
	  textcolor(4);
	  textbackground(7);
	  _setcursortype(_NOCURSOR);
	  cprintf("Could Not Found !");
	  getch();

     }

}

void deleteonecustomer()
{

     char *userid,*checkid;
     char username[20],number[15],address1[25],address2[20],idname[15],idno[15],realuserid[15];
	  char *shift;
	 int chk;
      _setcursortype(_NORMALCURSOR);
    scrollbox(20,2,75,20,7);
    textbackground(2);
    gotoxy(21,3);
    textcolor(6);
     cprintf("                     New Entry                        ");

    box(45,7,25,1,0,7);
    textcolor(1);  textbackground(7);
    gotoxy(23,7);  cprintf("Enter User id       :");

     fflush(stdin);
     gotoxy(47,7);
    gets(userid);
    strcpy(checkid,userid);
    strcat(userid,".txt");
    fp1=fopen(userid,"r");
    if(fp1==NULL)
    {
       fclose(fp1);
       _setcursortype(_NOCURSOR);
	gotoxy(30,13);
	textcolor(4);  textbackground(7);
	cprintf("Erorr : Incorrect User Id !");
	delay(1200);

    }
    else
    {
	 fclose(fp1);

   fp=fopen("customer.txt","r");
   fp1=fopen("temp.txt","a");
 while(fscanf(fp,"%s %s\n%s %s\n%s %s %s\n",username,number,address1,address2,idname,idno,realuserid)!=EOF)


 {     chk=strcmp(checkid,realuserid);
	if(chk==0)
	{
    scrollbox(20,2,75,20,7);
    textbackground(2);
    gotoxy(21,3);
    textcolor(6);
     cprintf("                   Delete Data                       ");

       _setcursortype(_NOCURSOR);

     gotoxy(23,4);textbackground(7);textcolor(1);
     cprintf(" User Name         :");
      gotoxy(45,4); textbackground(7); textcolor(0);
      cprintf("%s",username);

     gotoxy(23,6);textbackground(7);textcolor(1);
     cprintf(" Number            :");
      gotoxy(45,6); textbackground(7); textcolor(0);
      cprintf("%s",number);

     gotoxy(23,8);textbackground(7);textcolor(1);
     cprintf(" Address line  1   :");
      gotoxy(45,8); textbackground(7); textcolor(0);
      cprintf("%s",address1);

     gotoxy(23,10);textbackground(7);textcolor(1);
     cprintf(" Address line  2   :");
      gotoxy(45,10); textbackground(7); textcolor(0);
      cprintf("%s ",address2);


     gotoxy(23,12);textbackground(7);textcolor(1);
     cprintf(" Id Name          :");
      gotoxy(45,12); textbackground(7); textcolor(0);
      cprintf("%s ",idname);

     gotoxy(23,14);textbackground(7);textcolor(1);
     cprintf(" Id Number         :");
      gotoxy(45,14); textbackground(7); textcolor(0);
      cprintf("%s",idno);


     gotoxy(23,16);textbackground(7);textcolor(1);
     cprintf(" Userid            :");

      gotoxy(45,16); textbackground(7); textcolor(0);
      cprintf("%s",realuserid);

     textcolor(7); textbackground(1);
      gotoxy(22,18); cprintf(" Confirm [Enter] ");


      textcolor(7); textbackground(4);
      gotoxy(52,18); cprintf(" Cancel [Back Space] ");
      key:
      key=getch();
      if(key==13)
      {

	   scrollbox(20,2,75,20,7);
	   gotoxy(32,10);
	   textcolor(0);
	   textbackground(2);
	   cprintf(" Data Delected Sucessfully ");
	   delay(1000);
	   mainpage(design ,designcolor);
	   remove(userid);


	}
	else if(key==8)
	{
	    fprintf(fp1,"%s %s\n%s %s\n%s %s %s\n",username,number,address1,address2,idname,idno,realuserid);
	}
	else
	{
	 goto key;
	}
	}
      else
      {

	  fprintf(fp1,"%s %s\n%s %s\n%s %s %s\n",username,number,address1,address2,idname,idno,realuserid);

     }



 }
 fclose(fp1);
  fclose(fp);
  fp=fopen("customer.txt","w");
  fclose(fp);
  fp1=fopen("temp.txt","r");
  fp=fopen("customer.txt","a");


  while(fscanf(fp1,"%s %s\n%s %s\n%s %s %s\n",username,number,address1,address2,idname,idno,realuserid)!=EOF)
  {


	       fprintf(fp,"%s %s\n%s %s\n%s %s %s\n",username,number,address1,address2,idname,idno,realuserid);





  }

 fclose(fp1);
  fclose(fp);
  fp1=fopen("temp.txt","w");
  fclose(fp1);


	 }




}
void deleteallcustomer()
{

    char username[20],number[15],address1[25],address2[20],idname[15],idno[15],realuserid[15];

     char checkid[20];

	    scrollbox(20,2,75,12,7);

     textcolor(0); textbackground(7);
      gotoxy(37,5); cprintf("Are You Sure ? ");



     textcolor(7); textbackground(1);
      gotoxy(22,10); cprintf(" Delete All [Enter] ");


      textcolor(7); textbackground(4);
      gotoxy(52,10); cprintf(" Cancel [Back Space] ");
      key:
      key=getch();
      if(key==13)
      {
   fp=fopen("customer.txt","r");

 while(fscanf(fp,"%s %s\n%s %s\n%s %s %s\n",username,number,address1,address2,idname,idno,realuserid)!=EOF)

 {
       strcpy(checkid,realuserid);
       strcat(checkid,".txt");
       remove(checkid);
 }

	    scrollbox(20,2,75,12,7);

      fp1=fopen("customer.txt","w");
      fclose(fp1);
       _setcursortype(_NOCURSOR);
	gotoxy(37,7);
	textcolor(0);  textbackground(2);
	cprintf(" All data delected ");
	delay(1000);


	}
	else  if(key==8)
	{

	}
	else
	{
	goto key;
	}



}
void deletecustomer()
{


	int k=9;
	deletedata:
	 scrollbox(40,8,55,11,7);

	if(k==9)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(42,9);  cprintf(" Delete One ");

	if(k==10)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(42,10);  cprintf(" Delete All ");

	key=getch();
	if(key==8)
	{

	}
	else if(key==13)
	{
	  if(k==9)
	  {
	    deleteonecustomer();

	  }
	  else if(k==10)
	  {
	  deleteallcustomer();
	  }
	}
	else if(key==0)
	{
	  key=getch();
	  if(key==80)
	  {
	    k++;
	    if(k>10)
	    {
	    k=9;
	    }
	    goto deletedata;
	  }
	  else if(key==72)
	  {
	   k--;
	   if(k<9)
	   {
	   k=10;
	   }

	   goto deletedata;
	  }
	  else if(key==8)
	  {


	  }
	  else
	  {
	  goto deletedata;
	  }

	}
	else if(key==8)
	{

	}




}

int dcolor()
{

	 int color=4;
	int k=13;
	customer:

		scrollbox(28,12,33,18,7);

	textcolor(0); textbackground(2);
	gotoxy(29,k);  cprintf("    ");


	if(k==13)
	{

	textcolor(1);
	textbackground(2);
	}
	else
	{
	textcolor(1);
	textbackground(7);
	}
	gotoxy(29,13);  cprintf(" ÛÛ ");

	if(k==14)
	{

	textcolor(3);
	textbackground(2);
	}
	else
	{
	textcolor(3);
	textbackground(7);
	}
	gotoxy(29,14);  cprintf(" ÛÛ ");

	if(k==15)
	{

	textcolor(4);
	textbackground(2);
	}
	else
	{
	textcolor(4);
	textbackground(7);
	}
	gotoxy(29,15);  cprintf(" ÛÛ ");

	if(k==16)
	{

	textcolor(5);
	textbackground(2);
	}
	else
	{
	textcolor(5);
	textbackground(7);
	}
	gotoxy(29,16);  cprintf(" ÛÛ ");

	if(k==17)
	{

	textcolor(6);
	textbackground(2);
	}
	else
	{
	textcolor(6);
	textbackground(7);
	}
	gotoxy(29,17);  cprintf(" ÛÛ ");
	key=getch();
	if(key==8)
	{

	}
	else if(key==13)
	{
	  if(k==13)
	  {
	    color=1;


	  }
	  else if(k==14)
	  {
	    color=3;
	  }
	  else if(k==15)
	  {
	   color=4;
	  }
	  else if(k==16)
	  {
	  color=5;
	  }

	  else if(k==17)
	  {
	    color=6;
	  }

	}
	else if(key==0)
	{
	  key=getch();
	  if(key==80)
	  {
	    k++;
	    if(k>17)
	    {
	    k=13;
	    }
	    goto customer;
	  }
	  else if(key==72)
	  {
	   k--;
	   if(k<13)
	   {
	   k=17;
	   }

	   goto customer;
	  }
	  else if(key==8)
	  {


	  }
	  else
	  {
	  goto customer;
	  }

	}
	else if(key==8)
	{

	}
	       return color;
     }
void themecolor()
{


	int k=12;
	customer:
	scrollbox(20,11,27,17,7);
	textcolor(0); textbackground(2);
	gotoxy(21,k);  cprintf("      ");

	if(k==12)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(22,12);  cprintf(" °° ");

	if(k==13)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(22,13);  cprintf(" ±± ");

	if(k==14)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(22,14);  cprintf(" ²² ");

	if(k==15)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(22,15);  cprintf(" ÛÛ ");

	if(k==16)
	{

	textcolor(14);
	textbackground(2);
	}
	else
	{
	textcolor(0);
	textbackground(7);
	}
	gotoxy(22,16);  cprintf(" ³³ ");
	key=getch();
	if(key==8)
	{

	}
	else if(key==13)
	{
	  if(k==12)
	  {
	    design=176;
	     designcolor=dcolor();

	  }
	  else if(k==13)
	  {
	    design=177;
	    designcolor=dcolor();
	  }
	  else if(k==14)
	  {
	   design=178;
	     designcolor=dcolor();
	  }
	  else if(k==15)
	  {

	     design=219;
	       designcolor=dcolor();
	  }

	  else if(k==16)
	  {
	     design=179;
	       designcolor=dcolor();
	  }

	}
	else if(key==0)
	{
	  key=getch();
	  if(key==80)
	  {
	    k++;
	    if(k>16)
	    {
	    k=12;
	    }
	    goto customer;
	  }
	  else if(key==72)
	  {
	   k--;
	   if(k<12)
	   {
	   k=16;
	   }

	   goto customer;
	  }
	  else if(key==8)
	  {


	  }
	  else
	  {
	  goto customer;
	  }

	}
	else if(key==8)
	{

	}



}

void  totalamount()
{

     int n=0;
     int start;
     char *temp,checkid[20];
     char billno[20][10],price[20][10],qty[20][10],total[20][20],readtime[20][25],readdate[20][25];
     int scroll,scrollnumber,bkcolor,texcolor,m;
     float grandtotal=0;
     float totalbill[20];
     char username[20][20],contactno[20][15],addres[20][50],idname[20][20],idno[20][20],userid[20][10];
     fp=fopen("customer.txt","r");
     n=0;
     while(fscanf(fp,"%s %s\n%[^\n]\n%s %s %s",username[n],contactno[n],addres[n],idname[n],idno[n],userid[n])!=EOF)

     {

      strcpy(checkid,userid[n]);
      strcat(checkid,".txt");
      fp1=fopen(checkid,"r");
       totalbill[n]=0;
       m=0;
      while(fscanf(fp1,"%s %s %s %s %s %s\n",billno[m],price[m],qty[m],total[m],readtime[m],readdate[m])!=EOF)

      {


       totalbill[n]+=atoi(total[m]);

       m++;
      }
       fclose(fp1);


       grandtotal+=totalbill[n];

      n++;
     }
     fclose(fp);



	for(i=0; i<n; i++)
	{
	   for(j=i+1; j<n; j++)
	   {
	     if(strcmp(userid[i],userid[j])>0)
	     {
	       strcpy(temp,"");
	      strcpy(temp,username[i]);
	     strcpy(username[i],username[j]);
	     strcpy(username[j],temp);
	      strcpy(temp,"");
	     strcpy(temp,contactno[i]);

	     strcpy(contactno[i],contactno[j]);
	    strcpy(contactno[j],temp);
	      strcpy(temp,"");

	     strcpy(temp,addres[i]);

	     strcpy(addres[i],addres[j]);
	    strcpy(addres[j],temp);

	      strcpy(temp,"");

	     strcpy(temp,idname[i]);

	     strcpy(idname[i],idname[j]);
	    strcpy(idname[j],temp);
	      strcpy(temp,"");

	     strcpy(temp,idno[i]);

	     strcpy(idno[i],idno[j]);
	    strcpy(idno[j],temp);
	      strcpy(temp,"");

	     strcpy(temp,userid[i]);

	     strcpy(userid[i],userid[j]);
	    strcpy(userid[j],temp);


	     }


	   }
	}

	  start=0;
	  scroll=5;

	  viewdata:

	  _setcursortype(_NOCURSOR);
    scrollbox(20,2,78,22,7);



    textbackground(4);
    gotoxy(21,3);
    textcolor(15);

   cprintf(" #Id    CustomerName      Contact Number        Bill    ");


	      scrollnumber=start+1;

       gotoxy(21,21);
       textcolor(0);
       textbackground(3);
       cprintf("                                 Grand Total = %0.2f",grandtotal);

       for(i=start,j=5; j<=19; i++,j+=2)
     {


	 if(i<n)
	 {


	      if(scroll==j)
	      {

		gotoxy(23,scroll);
		textbackground(2);
		cprintf("                                                    ");
		bkcolor=2;
		texcolor=15;
	      }
	      else
	      {
	      bkcolor=7;
	      texcolor=0;

	      }

       gotoxy(22,j);
       textcolor(1);
       textbackground(bkcolor);
       cprintf("[%s]",userid[i]);
       gotoxy(28,j);
       textcolor(texcolor);
       textbackground(bkcolor);
       cprintf("%s",username[i]);
       gotoxy(48,j);
       textcolor(texcolor);
       textbackground(bkcolor);
       cprintf("%s",contactno[i]);

       gotoxy(69,j);
       textcolor(texcolor);
       textbackground(bkcolor);
       cprintf("%0.2f",totalbill[i]);


	 scrollnumber++;
	   }
     }
    key=getch();
    if(key==8||key==13)
    {


    }

    else
    {
     key=getch();
     if(key==80)
     {
	  scroll+=2;
       scrollnumber-=1;
       if(scrollnumber<8)
       {
	if(scroll>=(scrollnumber*2)+3)
	{
	 scroll=(scrollnumber*2)+3;
	}

       }
       if(scroll>19)
       {

       start++;
       if(start>n-8)
       {
	 start=n-8;
       }
       scroll=19;
       }

	goto viewdata;
     }
     else if(key==72)
     {
	scroll-=2;

	if(scroll<5)
	{
	  start--;
	  if(start<0)
	  {
	   start=0;
	  }
	scroll=5;
	}
       goto viewdata;
     }
     else
     {
     goto viewdata;

     }
  }


}

void login()
{
 char pincode[8],number[15],shopname[30],address1[30],address2[30];
	char username[30];
	char password[10],star[10];
	char name[30],pw[30];
	char ch;
	char k;

	for(i=1; i<=24; i++)
	{
	for(j=1; j<=80; j++)
	 {
	 gotoxy(j,i);
	 textcolor(2);
	 textbackground(15);
	cprintf("°");
	  }
	  }
	rename:
	  scrollbox(20,7,65,16,7);
	    _setcursortype(_NORMALCURSOR);


	  gotoxy(21,8);
	  textbackground(7);
	  textcolor(1);
	  cprintf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ LOGIN ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");

	  gotoxy(23,10);
	  textbackground(7);
	  textcolor(0);
	  cprintf("Enter Name     :");

	  gotoxy(40,10);
	  textbackground(3);
	  textcolor(4);
	  cprintf("                       ");



	  gotoxy(23,14);
	  textbackground(7);
	  textcolor(0);
	  cprintf("Enter Password :");

	  gotoxy(40,14);
	  textbackground(3);
	  textcolor(15);
	  cprintf("                       ");

	  gotoxy(22,22);
	  textbackground(2);
	  textcolor(15+BLINK);
	  cprintf("<<<                                  >>>");

	  gotoxy(25,22);
	  textbackground(2);
	  textcolor(15);
	  cprintf("  Press Shift+1 to Watch Password ");

	  textbackground(3);
	  gotoxy(41,10);
	  textcolor(2);
	  gets(username);
	  if(username[0]>=97 &&username[0]<=122)
	  {
	  username[0]-=32;
	  }

	  gotoxy(41,14);
	  textcolor(4);
	  for(i=0; i<15; i++)
		  {

	    repeat:
	      ch=getch();
	      if(ch=='!')
	      {
	       gotoxy(41,14);

	       for(j=0; j<i; j++)
	       {
	       cprintf("%c",password[j]);
	       }
	       delay(1000);

	      gotoxy(41,14);
	      cprintf("%s",star);
		 goto repeat;
	      //ch=getch();

	      }
	      else if(ch==13 )
	      {
	      break;

	      }
	      password[i]=ch;
	      star[i]='*';
	      star[i+1]='\0';

	      gotoxy(41,14);
	      cprintf("%s",star);

	  }

	  password[i]='\0';

	  _setcursortype(_NOCURSOR);
	  fp2=fopen("userid1.txt","r");
	  while(fscanf(fp2,"%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]",shopname,name,number,address1,address2,pincode,pw)!=EOF)
	  fclose(fp2);
	    gotoxy(20,20);
	     textcolor(0);

	  if(strcmp(username,name)==0&& strcmp(password,pw)==0)
	  {


	  scrollbox(20,7,65,16,7);


	  gotoxy(21,8);
	  textbackground(7);
	  textcolor(1);
	  cprintf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ LOGIN ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");

		 gotoxy(32,12);
		 textcolor(0);
		 textbackground(2);
		 cprintf(" Login Succesfully  ");
		 delay(1000);

	  }
	  else
	  {


	  scrollbox(20,7,65,16,7);


	  gotoxy(21,8);
	  textbackground(7);
	  textcolor(1);
	  cprintf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ LOGIN ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");

		 gotoxy(30,10);
		 textcolor(4);
		 textbackground(7);
		 cprintf("Wrong Password Or Username");

		 gotoxy(27,12);
		 textcolor(1);
		 textbackground(7);
		 cprintf("<<< Press Enter to Try Again >>>");

		 gotoxy(48,15);
		 textcolor(6);
		 textbackground(7);
		 cprintf("Exit [ESC KEY]");
		 k=getch();
		 if(k==27)
		 {
		 exit(1);
		 }
		 else
		 {
		 ch='\0';
		 strcpy(password,"");
		 strcpy(username,"");
		  goto rename;
		 }
	  }



}
void myprofile()
{
   char username[30],password[15],pincode[8],number[15],shopname[30],address1[30],address2[30];



 myprofile:
     strcpy(username,"");
     strcpy(password,"");
     strcpy(number,"");
	scrollbox(20,3,70,24,7);

     gotoxy(21,4);
     textcolor(0);
     _setcursortype(_NOCURSOR);
     textbackground(2);
     cprintf("                  My Profile                    ");

     fp2=fopen("userid1.txt","r");
     if(fp2!=NULL)
     {

	gotoxy(22,6);
	textcolor(1);
	textbackground(7);
	cprintf("  Shop Name      :");

	gotoxy(22,8);
	textcolor(1);
	textbackground(7);
	cprintf("  User Name      :");

	gotoxy(22,10);
	textcolor(1);
	textbackground(7);
	cprintf("  User Number    :");


	gotoxy(22,12);
	textcolor(1);
	textbackground(7);
	cprintf("  Shop Address 1 :");

	gotoxy(22,14);
	textcolor(1);
	textbackground(7);
	cprintf("  Shop Address 2 :");

	gotoxy(22,16);
	textcolor(1);
	textbackground(7);
	cprintf("  City Pincode   :");


	gotoxy(22,18);
	textcolor(1);
	textbackground(7);
	cprintf("  Pass Word      :");



	fp2=fopen("userid1.txt","r");
	while(fscanf(fp2,"%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]",shopname,username,number,address1,address2,pincode,password)!=EOF)
	{

	gotoxy(41,6);
	textcolor(6);
	textbackground(7);
	cprintf("%s",shopname);

	gotoxy(42,8);
	textcolor(6);
	textbackground(7);
	cprintf("%s",username);

	gotoxy(42,10);
	textcolor(6);
	textbackground(7);
	cprintf("%s",number);


	gotoxy(42,12);
	textcolor(6);
	textbackground(7);
	cprintf("%s",address1);

	gotoxy(42,14);
	textcolor(6);
	textbackground(7);
	cprintf("%s",address2);

	gotoxy(42,16);
	textcolor(6);
	textbackground(7);
	cprintf("%s",pincode);


	gotoxy(42,18);
	textcolor(6);
	textbackground(7);
	cprintf("%s",password);



	}
       fclose(fp2);
	  gotoxy(21,22);
	  textbackground(1);
	  textcolor(15);
	  cprintf(" Press 1 :Edit Acoount ³ Press 2 :Delete Acoount ");

      }
      else
      {
	fclose(fp2);
	gotoxy(32,12);
	textcolor(1);
	textbackground(7);
	cprintf(" You not set Your Profile ! ");

	   gotoxy(22,22);
	  textbackground(2);
	  textcolor(15);
	  cprintf("          Press 1 To Set Your Profile          ");

      }

}
void deleteprofile()
{
	      remove("userid1.txt");
	      scrollbox(20,3,70,24,7);
	  gotoxy(30,10);

	  textcolor(0);
	  textbackground(7);
	  _setcursortype(_NOCURSOR);
	  cprintf(" Acoount Succesfully Delected");
	   gotoxy(22,22);
	   textcolor(15);
	    textbackground(6);
	    cprintf("                  Press any Key                 ");
	    getch();

}
void editmyprofile()
{

	      char username[30],password[15],pincode[8],number[15],shopname[30],address1[30],address2[30];
	scrollbox(20,3,70,24,7);


	gotoxy(22,6);
	textcolor(1);
	textbackground(7);
	cprintf("  Shop Name      :");

	gotoxy(22,8);
	textcolor(1);
	textbackground(7);
	cprintf("  User Name      :");

	gotoxy(22,10);
	textcolor(1);
	textbackground(7);
	cprintf("  User Number    :");


	gotoxy(22,12);
	textcolor(1);
	textbackground(7);
	cprintf("  Shop Address 1 :");

	gotoxy(22,14);
	textcolor(1);
	textbackground(7);
	cprintf("  Shop Address 2 :");

	gotoxy(22,16);
	textcolor(1);
	textbackground(7);
	cprintf("  City Pincode   :");


	gotoxy(22,18);
	textcolor(1);
	textbackground(7);
	cprintf("  Pass Word      :");
     gotoxy(22,4);
     textcolor(0);
     _setcursortype(_NOCURSOR);
     textbackground(2);
     cprintf("               My Profile                    ",17,16);

	 _setcursortype(_NORMALCURSOR);
	gotoxy(40,6);
	textcolor(4);
	textbackground(3);
	cprintf("                           ");

	gotoxy(40,8);
	textcolor(4);
	textbackground(3);
	cprintf("                           ");

	gotoxy(40,10);
	textcolor(4);
	textbackground(3);
	cprintf("                            ");

	gotoxy(40,12);
	textcolor(4);
	textbackground(3);
	cprintf("                            ");


	gotoxy(40,14);
	textcolor(4);
	textbackground(3);
	cprintf("                            ");


	gotoxy(40,16);
	textcolor(4);
	textbackground(3);
	cprintf("                            ");


	gotoxy(40,18);
	textcolor(4);
	textbackground(3);
	cprintf("                            ");


       textcolor(4);


	 gotoxy(42,6);
	gets(shopname);
	if(shopname[0]>=97 &&shopname[0]<=122)
	{
	 shopname[0]-=32;
	}

	 gotoxy(42,8);
	gets(username);
	if(username[0]>=97 &&username[0]<=122)
	{
	 username[0]-=32;
	}

	gotoxy(42,10);
	gets(number);

	 gotoxy(42,12);
	gets(address1);
	if(address1[0]>=97 &&address1[0]<=122)
	{
	 address1[0]-=32;
	}

	 gotoxy(42,14);
	gets(address2);
	if(address2[0]>=97 &&address2[0]<=122)
	{
	 address2[0]-=32;
	}

	 gotoxy(42,16);
	gets(pincode);
	gotoxy(42,18);
	gets(password);
	fp2=fopen("userid1.txt","w");
	fprintf(fp2," %s\n%s\n%s\n%s\n%s\n%s\n%s",shopname,username,number,address1,address2,pincode,password);
	fclose(fp2);
		scrollbox(20,3,70,24,7);
	  gotoxy(30,12);

	  textcolor(0);
	  textbackground(7);
	  _setcursortype(_NOCURSOR);
	  cprintf(" Account Succesfully Upadated");
	  delay(1000);

}
void about()
{
  scrollbox(20,15,65,23,7);
  _setcursortype(_NOCURSOR);
     gotoxy(22,16);
     textcolor(6);
     textbackground(7);
     cprintf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ ABOUTÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");

     gotoxy(23,18);
     textcolor(7);
     textbackground(1);
     cprintf("  DEVELOPER   ");

     gotoxy(38,18);
     textcolor(0);
     textbackground(7);
     cprintf(": Ajaysinh Rathod");

     gotoxy(23,20);
     textcolor(7);
     textbackground(2);
     cprintf(" PROJECT NAME ");

     gotoxy(37,20);
     textcolor(0);
     textbackground(7);
     cprintf(" : Milkshop Management");

     gotoxy(23,22);
     textcolor(7);
     textbackground(5);
     cprintf(" Published On ");

     gotoxy(37,22);
     textcolor(0);
     textbackground(7);
     cprintf(" : 10th December 2019");


}
