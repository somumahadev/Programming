//  ************************************************************************
//  ****            C O N T A C T   M A N A G E M E N T                 ****
//  ************************************************************************
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<string.h>

#include<stdlib.h>
 int a,button,x=0,y=0;
 int b;
 int quit=1;
 int sound1=0;

int i,j;
FILE *fp,*fp1,*fp2;
int scroll=3;
int enter=0;
int texcolor,bkcolor;
char name[30],mobno[15];
union REGS in,out;
void showmouseptr();
void getmouseptr(int*,int* ,int *);
void editmyprofile();
void searchnumber();
void searchname();
void openscrollbox(int x1,int y1,int x2,int y2,int scrollboxcolor);
void box(int x1,int y1,int space,int height,int boxcolor,int boxbkcolor);
int scrollboxcolor=15;
void keysound()
{

     sound(sound1);
     delay(50);
     nosound();

}
void mainpage()
{

     for(i=1; i<=24; i++)
     {

      for(j=1; j<=79; j++)
      {
	  if(j<20)
	  {
	     gotoxy(j,i);
	    textbackground(7);
	    cprintf(" ");

	  }
	  else if(j==20)
	  {
	     textbackground(3);
	     cprintf(" ");

	  }

	  else if( j>20 &&j<=80)
	  {


	    gotoxy(j,i);
	    textcolor(3);
	    textbackground(1);
	    cprintf("°");
	    }


	    if(i==1 && j>23 && j<78)
	    {
	       gotoxy(j,i);
	       textcolor(15);
	       cprintf("Í");

	    }
	    else if(i==23 && j>23 && j<78)
	    {
	       gotoxy(j,i);
	       textcolor(15);
	       cprintf("Í");

	    }


	    if(j==23 && i>1 && i<24)
	    {
	       gotoxy(j,i);

	       textcolor(15);
	       cprintf("º");

	    }
	    else if(j==78 && i>1 && i<24)
	    {
	       gotoxy(j,i);
	      textcolor(15);
	      cprintf("º");

	    }



      }
     }

		 gotoxy(23,23);
	       textcolor(15);
	       cprintf("È");


		 gotoxy(23,1);
	       textcolor(15);
	       cprintf("É");

		 gotoxy(78,1);
	       textcolor(15);
	       cprintf("»");

		 gotoxy(78,23);
	       textcolor(15);
	       cprintf("¼");



}

void menu(int k,int f)
{

    bkcolor=7,texcolor=0;
   _setcursortype(_NOCURSOR);
     gotoxy(1,k);
    textbackground(2);
    textcolor(texcolor);
    cprintf("                   ");

     gotoxy(1,k+1);
    textbackground(2);
    textcolor(texcolor);
    cprintf("                   ");


    if(k==1)
    {
       bkcolor=2;
    }
    else
    {
     bkcolor=7;
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
       bkcolor=2;
    }
    else
    {
     bkcolor=7;
    }

    gotoxy(2,3);

    textbackground(bkcolor);
    textcolor(1);
    cprintf("N");

    gotoxy(3,3);

    textbackground(bkcolor);
    textcolor(texcolor);
    cprintf("ew contact     >");


    if(k==5)
    {
       bkcolor=2;
    }
    else
    {
     bkcolor=7;
    }

    gotoxy(2,5);

    textbackground(bkcolor);
    textcolor(1);
    cprintf("S");

    gotoxy(3,5);

    textbackground(bkcolor);
    textcolor(texcolor);
    cprintf("earch          >");


    if(k==7)
    {
       bkcolor=2;
    }
    else
    {
     bkcolor=7;
    }

    gotoxy(2,7);

    textbackground(bkcolor);
    textcolor(1);
    cprintf("E");

    gotoxy(3,7);

    textbackground(bkcolor);
    textcolor(texcolor);
    cprintf("dit            >");



    if(k==9)
    {
       bkcolor=2;
    }
    else
    {
     bkcolor=7;
    }

    gotoxy(2,9);

    textbackground(bkcolor);
    textcolor(1);
    cprintf("D");

    gotoxy(3,9);

    textbackground(bkcolor);
    textcolor(texcolor);
    cprintf("elete          >");


    if(k==11)
    {
       bkcolor=2;
    }
    else
    {
     bkcolor=7;
    }

    gotoxy(2,11);

    textbackground(bkcolor);
    textcolor(1);
    cprintf("A");

    gotoxy(3,11);

    textbackground(bkcolor);
    textcolor(texcolor);
    cprintf("ll Contacts    >");


    if(k==13)
    {
       bkcolor=2;
    }
    else
    {
     bkcolor=7;
    }

    gotoxy(2,13);

    textbackground(bkcolor);
    textcolor(1);
    cprintf("M");

    gotoxy(3,13);

    textbackground(bkcolor);
    textcolor(texcolor);
    cprintf("y profile      >");


    if(k==15)
    {
       bkcolor=2;
    }
    else
    {
     bkcolor=7;
    }

    gotoxy(2,15);

    textbackground(bkcolor);
    textcolor(texcolor);
    cprintf("A out           >");

    gotoxy(3,15);

    textbackground(bkcolor);
    textcolor(1);
    cprintf("b");





    if(k==21)
    {
       bkcolor=2;
    }
    else
    {
     bkcolor=7;
    }


    gotoxy(2,21);

    textbackground(bkcolor);
    textcolor(1);
    cprintf("Sound");


    gotoxy(7,21);

    textbackground(bkcolor);
    textcolor(texcolor);
    cprintf(" [ Tab Key ]");
    if(k==23)
    {
       bkcolor=2;
    }
    else
    {
     bkcolor=7;
    }

    gotoxy(2,23);

    textbackground(bkcolor);
    textcolor(1);
    cprintf("Exit");


    gotoxy(7,23);

    textbackground(bkcolor);
    textcolor(texcolor);
    cprintf(" [ Esc Key ]");
	      /*
    if(f==0)
    {
      do
      {
	  _setcursortype(_NOCURSOR);

    gotoxy(35,10);

    textbackground(1);
    textcolor(14+BLINK);
    cprintf("<<<                         >>>");


    gotoxy(39,10);

    textbackground(1);
    textcolor(10);
    cprintf("PRESS ENTER TO CONTINUE");
     delay(100);
    gotoxy(35,10);

    textbackground(1);
    textcolor(1);
    cprintf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");

    showmouseptr();
    getmouseptr(&button,&x,&y);
    }
    while(!kbhit() && button!=1);
     }
     else if(f==1)
     {

    gotoxy(35,10);

    textbackground(1);
    textcolor(1);
    cprintf("°°°°°°°°°°°°°°°°°°°°°°°°°°°");
     }
		*/
   k=f;
}

void newcontact()
{

int x1=15,x2=22;
int y1=38,y2=58;
char ch;
char sname[30];
int k;
int chk1,chk2;
char nam[50],mob[30];
   fp=fopen("contacts.txt","r");
   if(fp==NULL)
   {
     fclose(fp);
     fopen("contacts.txt","w");
     fclose(fp);
   }
   else
   {
    fclose(fp);
    name:
     openscrollbox(21,2,77,12,7);

     gotoxy(22,3);
     textcolor(0);
     _setcursortype(_NORMALCURSOR);
     textbackground(2);
     cprintf("                  %c   New Contact  %c                   ",17,16);
     gotoxy(22,6);
     textcolor(0);
     _setcursortype(_NORMALCURSOR);
     textbackground(7);
     cprintf("  Enter Name    :");
     box(45,6,25,1,0,7);

     gotoxy(22,9);
     textcolor(0);
     textbackground(7);
     cprintf("  Contact Number:");
     box(45,9,25,1,0,7);
     textcolor(1);
     gotoxy(47,6);
     gets(sname);
     k=0;
     for(i=0; i<strlen(sname);  i++)
     {
      if(sname[i]==' ')
      {

      }
      else
      {

      name[k++]=sname[i];
      }

     }
     name[k]='\0';
     if(name[0]>=97 && name[0]<=122)
     {
       name[0]-=32;

     }


     textcolor(1);
     gotoxy(47,9);
     gets(mobno);


     for(i=x1; i<=x2; i++)
     {

     for(j=y1; j<=y2; j++)
     {
     if(i==x2)
     {

       gotoxy(j,i);
     textcolor(3);
     textbackground(1);
     cprintf("ß");


     }

     else if(i==x1)
     {

       gotoxy(j,i);
     textcolor(3);
     textbackground(1);
     cprintf("Ü");


     }
     else if(j==y1 || j==y2)
     {

       gotoxy(j,i);
     textcolor(3);
     textbackground(1);
     cprintf("Û");

     }
     else
     {
       gotoxy(j,i);
     textcolor(15);
     textbackground(7);
     cprintf(" ");
     }
      }
     }

     gotoxy(y1+3,x1+2);
     textcolor(0);
     textbackground(2);
     cprintf("Save Contact");


     gotoxy(y1+3,x1+5);
     textcolor(2);
     textbackground(15);
     cprintf("Y");


     gotoxy(y1+4,x1+5);
     textcolor(0);
     textbackground(15);
     cprintf("es");

     gotoxy(y1+13,x1+5);
     textcolor(4);
     textbackground(15);
     cprintf("N");

     gotoxy(y1+14,x1+5);
     textcolor(0);
     textbackground(15);
     cprintf("o");
     ch=getch();
     if(ch=='y'||ch=='Y'||ch==13)
     {

       fp=fopen("contacts.txt","r");
       while(fscanf(fp,"%s %s",nam,mob)!=EOF)
       {
	 chk1=strcmp(nam,name);
	 chk2=strcmp(mobno,mob);
	 if(chk1==0)

	 {

	  mainpage();
	  menu(3,enter);
	    openscrollbox(21,3,78,12,7);
	 // box(33,10,28,1,14,1);

	  gotoxy(30,6);
	  textcolor(4);
	  textbackground(7);
	  _setcursortype(_NOCURSOR);
	  cprintf("ERORR :");


	  gotoxy(38,6);
	  textcolor(0);
	  textbackground(7);
	  _setcursortype(_NOCURSOR);
	  cprintf("Contact Name Already Exist");

	    textcolor(1);

	  getch();
	  goto name;


	 }
	 else if(chk2==0 )
	 {


	  mainpage();
	  menu(3,enter);
	    openscrollbox(21,3,78,12,7);
	 // box(33,10,28,1,14,1);

	  gotoxy(30,6);
	  textcolor(4);
	  textbackground(7);
	  _setcursortype(_NOCURSOR);
	  cprintf("ERORR :");


	  gotoxy(38,6);
	  textcolor(0);
	  textbackground(7);
	  _setcursortype(_NOCURSOR);
	  cprintf("Contact Number Already Exist");

	  textcolor(1);
	   getch();
	   goto name;

	 }

       }
	 fclose(fp);
	  fp=fopen("contacts.txt","a");
	  fprintf(fp,"%s %s\n",name,mobno);
	  fclose(fp);

	  mainpage();
	  menu(3,enter);
	    openscrollbox(21,3,78,12,7);
	 // box(33,10,28,1,14,1);

	  gotoxy(35,7);
	  textcolor(0);
	  textbackground(7);
	  _setcursortype(_NOCURSOR);
	  cprintf("Contact Successfully Saved");


	   delay(1000);
	   mainpage();
	   menu(3,enter);


     }
     else if(ch=='N'||ch=='n')
     {




	   mainpage();
	   menu(3,enter);


     }


    }
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
void openscrollbox(int x1,int y1,int x2,int y2 ,int scrollboxcolor)
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

void allcontacts()

{
      int k,inc=0;
      char all;
      int x;
      int cntktxcolor,cntkbkcolor,scrollnumber;
      int i1=0,scrollx=21,scrolly=5;
      char temp1[50],temp2[80];
      char coname[50][30],conumber[50][15];
      fp=fopen("contacts.txt","r");

       if(fp==NULL)
       {
	     fclose(fp);
	_setcursortype(_NOCURSOR);

 //	mainpage();
    //	menu(11,1);
		openscrollbox(21,3,77,20,7);

	    gotoxy(37,11);
	    textcolor(6);
	    textbackground(7);
	    cprintf("No Contacts available");
	    getch();
	    keysound();
       }


      else if(fp!=NULL)
      {

      while(fscanf(fp,"%s %s\n",coname[i1],conumber[i1])!=EOF)
      {
	i1++;
      }
    /*  for(i=0; i<=i1; i++)
      {
	if(coname[i][0]>=97 && coname[i][0] <=122)
	{

	 coname[i][0]-=32;
	}

      }               */

	for(i=0; i<i1; i++)
	{
	   for(j=i+1; j<i1; j++)
	   {
	     if(strcmp(coname[i],coname[j])>0)
	     {
	      strcpy(temp1,coname[i]);
	     strcpy(coname[i],coname[j]);
	     strcpy(coname[j],temp1);

	     strcpy(temp1,conumber[i]);

	     strcpy(conumber[i],conumber[j]);
	    strcpy(conumber[j],temp1);


	     }


	   }
	}
	fclose(fp);
	fp=fopen("contacts.txt","w");

	for(i=0; i<i1; i++)
	{

	  fprintf(fp,"%s %s\n",coname[i],conumber[i]);
	}
	fclose(fp);
		scrollnumber=1;

		cntkbkcolor=7;
		cntktxcolor=0;

	scrollcontacts:

      //	system("cls");
	_setcursortype(_NOCURSOR);

 //	mainpage();
    //	menu(11,1);
		openscrollbox(21,3,77,20,7);

       scrollnumber=inc+1;

      for(k=inc,j=5; k<i1,j<=19; k++,j+=2)
      {

      if(k<i1)
      {
	if(scrolly!=j)
	{
	  cntkbkcolor=7;
	  cntktxcolor=6;
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
	   cntktxcolor=14;
	}


	 gotoxy(24,j);
	 textcolor(1);
	 textbackground(cntkbkcolor);
	 cprintf("[%d] ",scrollnumber);


	 gotoxy(30,j);
	 textcolor(0);
	 textbackground(cntkbkcolor);
	 cprintf("%s",coname[k]);



	 gotoxy(55,j);
	 textcolor(cntktxcolor);
	 textbackground(cntkbkcolor);
	 cprintf("%s",conumber[k]);
	 scrollnumber++;
	  }

	   }
	   a=getch();
	   keysound();
	   if(a==13||a==8)
	   {

	    }
	    else
	    {

	   b=getch();
	   keysound();

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



}
void deleteword()
{



int x1=15,x2=22;
int y1=38,y2=58;
char ch;
int chk1,chk2;
      int k,found=1;
      int i1=1;
      char temp1[50],temp2[80],sname[30];
      char dname[50],dnum[15];
      char coname[50],conumber[50];
      int cntkbkcolor=7;
      k=10;
     deletecontact:

     fp=fopen("contacts.txt","r");
     if(fp!=NULL)
     {       fclose(fp);
      openscrollbox(21,9,33,12,7);

      gotoxy(22,k);
      textcolor(2);
      textbackground(2);
      cprintf("          ");
      if(k==10)
      {
       cntkbkcolor=2;
      }
      else
      {
      cntkbkcolor=7;
      }
      _setcursortype(_NOCURSOR);
      gotoxy(22,10);
      textcolor(4);
      textbackground(cntkbkcolor);
      cprintf("Delete");

      gotoxy(29,10);
      textcolor(0);
      textbackground(cntkbkcolor);
      cprintf("One");


      if(k==11)
      {
       cntkbkcolor=2;
      }
      else
      {
      cntkbkcolor=7;
      }
      gotoxy(22,11);
      textcolor(4);
      textbackground(cntkbkcolor);
      cprintf("Delete");

      gotoxy(29,11);
      textcolor(0);
      textbackground(cntkbkcolor);
      cprintf("All");

      a=getch();
      keysound();

      if(a==13)
     {
	if(k==10)
	{
	 goto deleteone;

	}
	else if(k==11)
	{
	  goto deleteall;
	}

     }
     else if(a==8)
     {
     k=1200;
     }
     else
     {
     ch=getch();
     keysound();
     if(ch==' '||ch==80)
     {
	 k++;
	 if(k>11)
	 {
	 k=10;
	 }
	 goto deletecontact;

     }
     else if(ch==8||ch==72)
     {
       k--;
       if(k<10)
       {
	     k=11;
       }
       goto deletecontact;

     }

     else if(ch==13)
     {
	if(k==10)
	{
	 goto deleteone;

	}
	else if(k==11)
	{
	  goto deleteall;
	}

     }
     }
      deleteone:
      if(k==10)
      {
      openscrollbox(21,4,77,14,7);


     gotoxy(22,6);
     textcolor(0);
     _setcursortype(_NORMALCURSOR);
     textbackground(2);
     cprintf("                %c   Delete  Contact  %c                  ",17,16);

     gotoxy(23,9);
     textcolor(0);
     textbackground(7);
     cprintf(" Enter Name / Number :");
     box(47,9,25,1,0,7);


     gotoxy(50,9);
     gets(sname);
     k=0;
     for(i=0; i<strlen(sname); i++)
     {
       if(sname[i]==' ')
       {

       }
       else
       {
	  name[k++]=sname[i];

       }

     }

     name[k]='\0';
     if(name[0]>=97 && name[0]<=122)
     {
       name[0]-=32;

     }

     repeat:
     for(i=x1; i<=x2; i++)
     {

     for(j=y1; j<=y2; j++)
     {
     if(i==x2)
     {

       gotoxy(j,i);
     textcolor(3);
     textbackground(1);
     cprintf("ß");


     }

     else if(i==x1)
     {

       gotoxy(j,i);
     textcolor(3);
     textbackground(1);
     cprintf("Ü");


     }
     else if(j==y1 || j==y2)
     {

       gotoxy(j,i);
     textcolor(3);
     textbackground(1);
     cprintf("Û");

     }
     else
     {
       gotoxy(j,i);
     textcolor(15);
     textbackground(7);
     cprintf(" ");
     }
      }
     }

     gotoxy(y1+3,x1+2);
     textcolor(0);
     textbackground(2);
     cprintf("Delete Contact");


     gotoxy(y1+3,x1+5);
     textcolor(2);
     textbackground(15);
     cprintf("Y");


     gotoxy(y1+4,x1+5);
     textcolor(0);
     textbackground(15);
     cprintf("es");

     gotoxy(y1+13,x1+5);
     textcolor(4);
     textbackground(15);
     cprintf("N");

     gotoxy(y1+14,x1+5);
     textcolor(0);
     textbackground(15);
     cprintf("o");

     ch=getch();
     keysound();

     if(ch=='y'||ch=='Y'||ch==13)
     {

	   goto label1;

     }
     else if(ch=='N'||ch=='n')
     {


     strcpy(name,"");
     mainpage();
     menu(9,enter);
     found=3;

     }
     else
     {
	goto repeat;

     }

     label1:
     i1=0;

      fp=fopen("contacts.txt","r");
      fp1=fopen("temp.txt","a");
      while(fscanf(fp,"%s %s",coname,conumber)!=EOF)
      {


	 chk1=strcmp(name,coname);
	 chk2=strcmp(name,conumber);
	if(chk1==0||chk2==0)
	{
	      found=0;
	}
	else
	{
	      fprintf(fp1,"%s %s\n",coname,conumber);

	}
	i1++;
      }
       if(found==1)
       {
	  mainpage();
	  menu(9,enter);

      openscrollbox(21,6,77,14,7);


	  gotoxy(40,10);
	  textcolor(4);
	  textbackground(7);
	 _setcursortype(_NOCURSOR);
	  cprintf(" Contact Not Found !");

	  delay(1000);
	   mainpage();
	   menu(9,enter);


       }


       else if(found==0)
       {
	  mainpage();
	  menu(9,enter);

      openscrollbox(21,6,77,14,7);



	  gotoxy(35,10);
	  textcolor(0);
	  textbackground(2);
	  _setcursortype(_NOCURSOR);
	  cprintf(" Contact Delected SuccesFully");


	   delay(1000);
	   mainpage();
	   menu(9,enter);



       }


       fclose(fp1);
       fclose(fp);
       fp=fopen("contacts.txt","w");
	fclose(fp);
       fp1=fopen("temp.txt","r");
       fp=fopen("contacts.txt","a");
       while(fscanf(fp1,"%s %s\n",dname,dnum)!=EOF)
       {
	   fprintf(fp,"%s %s\n",dname,dnum);

       }

       fclose(fp);
       fclose(fp1);
      fp1=fopen("temp.txt","w");
       fclose(fp1);
	   }
      deleteall:
	       if(k==11)
	       {
		   repeat1:

      openscrollbox(21,4,77,17,7);

     _setcursortype(_NOCURSOR);
     gotoxy(22,6);
     textcolor(0);
     textbackground(2);
     cprintf("                %c   Delete  Contact  %c                  ",17,16);
      x1=8,x2=16,y1=35,y2=55;

     gotoxy(y1-3,x1+2);
     textcolor(7);
     textbackground(1);
     cprintf("     Delete ALL Contact     ");

     gotoxy(y1,x1+5);
     textcolor(3);
     textbackground(3);
     cprintf("     ");


     gotoxy(y1,x1+5);
     textcolor(4);
     textbackground(3);
     cprintf(" Y");



     gotoxy(y1+2,x1+5);
     textcolor(0);
     textbackground(3);
     cprintf("es");


     gotoxy(y1+15,x1+5);
     textcolor(3);
     textbackground(3);
     cprintf("     ");

     gotoxy(y1+15,x1+5);
     textcolor(4);
     textbackground(3);
     cprintf(" N");

     gotoxy(y1+17,x1+5);
     textcolor(0);
     textbackground(3);
     cprintf("o");

     ch=getch();

     if(ch=='y'||ch=='Y'||ch==13)
     {


     remove("contacts.txt");

	  mainpage();
	  menu(9,enter);

      openscrollbox(21,4,77,17,7);



	  gotoxy(35,10);
	  textcolor(0);
	  textbackground(2);
	  _setcursortype(_NOCURSOR);
	  cprintf(" Contact Delected SuccesFully");


	   delay(1000);
	   mainpage();
	   menu(9,enter);





     }
     else if(ch=='N'||ch=='n')
     {



     mainpage();
     menu(9,enter);

     }
     else
     {
	goto repeat1;

     }
	       }
 }
 else
 {
      fclose(fp);
	 openscrollbox(21,4,77,17,7);



	  gotoxy(35,10);
	  textcolor(6);
	  textbackground(7);
	  _setcursortype(_NOCURSOR);
	  cprintf("No Contacts Avilable");
	  getch();
	  keysound();


 }


}
void searchname()

{
	 char sname[30];
	 int scrollnumber,cntkbkcolor,cntktxcolor;
	 char coname[50][30],conumber[50][30];
	 char fname[30],fnumber[30];
	 int i1=1,inc,k,j,scrolly=5,scrollx,ch;
	 int d,b,match=0;

      openscrollbox(21,4,77,20,7);


     gotoxy(22,6);
     textcolor(0);
     _setcursortype(_NORMALCURSOR);
     textbackground(2);
     cprintf("                %c   Search Contect  %c                  ",17,16);

     gotoxy(23,8);
     textcolor(1);
     textbackground(7);
     cprintf(" Enter Name :");
     box(38,8,25,1,0,7);


     gotoxy(40,8);
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
    fp=fopen("contacts.txt","r");
      while(fscanf(fp,"%s %s\n",fname,fnumber)!=EOF)
      {
      strlwr(fname);
      strlwr(name);
	if(strstr(fname,name)!=NULL)
	{

	  fname[0]-=32;
	  strcpy(coname[i1],fname);
	  strcpy(conumber[i1],fnumber);
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
		openscrollbox(21,4,77,20,7);

       scrollnumber=inc+1;

      for(k=inc,j=5; k<i1,j<=19; k++,j+=2)
      {

	 if(k<i1)
	 {

	 if(scrolly!=j)
	 {
	 cntkbkcolor=7;
	 cntktxcolor=6;
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
	 cntktxcolor=14;
	 }
	 gotoxy(24,j);
	 textcolor(1);
	 textbackground(cntkbkcolor);
	 cprintf("[%d] ",scrollnumber);


	 gotoxy(30,j);
	 textcolor(0);
	 textbackground(cntkbkcolor);
	 cprintf("%s",coname[k]);



	 gotoxy(55,j);
	 textcolor(cntktxcolor);
	 textbackground(cntkbkcolor);
	 cprintf("%s",conumber[k]);
	 scrollnumber++;
	  }

	   }
	   a=getch();
	   keysound();
	   if(a==13||a==8)
	   {

	    }
	    else
	    {

	   b=getch();
	   keysound();

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
      openscrollbox(21,4,77,20,7);


	  gotoxy(37,11);
	  textcolor(4);
	  textbackground(7);
	  _setcursortype(_NOCURSOR);
	  cprintf("Could Not Found !");
	  getch();
	  keysound();

     }
}

void searchnumber()

{
	 char snumber[30],number;
	 int scrollnumber,cntkbkcolor,cntktxcolor;
	 char coname[50][30],conumber[50][30];
	 char fname[30],fnumber[30],match=0;
	 int i1=1,inc,k,j,scrolly=5,scrollx,ch;
	 int d,b;

      openscrollbox(21,4,77,20,7);


     gotoxy(22,6);
     textcolor(0);
     _setcursortype(_NORMALCURSOR);
     textbackground(2);
     cprintf("                %c   Search Context  %c                  ",17,16);

     gotoxy(23,8);
     textcolor(1);
     textbackground(7);
     cprintf(" Enter Number :");
     box(38,8,25,1,0,7);


     gotoxy(40,8);
     gets(snumber);

      i1=0;

    fp=fopen("contacts.txt","r");
      while(fscanf(fp,"%s %s\n",fname,fnumber)!=EOF)
      {

	if(strstr(fnumber,snumber)!=NULL)
	{

	  strcpy(coname[i1],fname);
	  strcpy(conumber[i1],fnumber);
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
		openscrollbox(21,2,77,20,7);
		gotoxy(22,3);
		textcolor(7);
		textbackground(6);
		cprintf("    All The Contacts Which Contains                  ");
		gotoxy(58,3);
		textcolor(7);
		textbackground(6);
		cprintf("\" %s \"",snumber);

       scrollnumber=inc+1;

      for(k=inc,j=5; k<i1,j<=19; k++,j+=2)
      {

	 if(k<i1)
	 {

	 if(scrolly!=j)
	 {
	 cntkbkcolor=7;
	 cntktxcolor=6;
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
	 cntktxcolor=14;
	 }
	 gotoxy(24,j);
	 textcolor(1);
	 textbackground(cntkbkcolor);
	 cprintf("[%d] ",scrollnumber);


	 gotoxy(30,j);
	 textcolor(0);
	 textbackground(cntkbkcolor);
	 cprintf("%s",coname[k]);



	 gotoxy(55,j);
	 textcolor(cntktxcolor);
	 textbackground(cntkbkcolor);
	 cprintf("%s",conumber[k]);
	 scrollnumber++;
	  }

	   }
	   a=getch();
	   keysound();
	   if(a==13||a==8)
	   {

	    }
	    else
	    {

	   b=getch();
	   keysound();

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
      openscrollbox(21,4,77,20,7);


	  gotoxy(37,11);
	  textcolor(4);
	  textbackground(7);
	  _setcursortype(_NOCURSOR);
	  cprintf("Could Not Found !");
	  getch();
	  keysound();

     }
}
void search()
{
    int ch,k=6,cntkbkcolor;

    fp=fopen("contacts.txt","r");
    if(fp!=NULL)
    {
      fclose(fp);
    searchcontact :
	  //   system("cls");
	    // mainpage();
	    // menu(5,1);

      openscrollbox(21,5,32,8,7);

      gotoxy(22,k);
      textcolor(2);
      textbackground(2);
      cprintf("          ");
      if(k==6)
      {
       cntkbkcolor=2;
      }
      else
      {
      cntkbkcolor=7;
      }
      _setcursortype(_NOCURSOR);
      gotoxy(23,6);
      textcolor(4);
      textbackground(cntkbkcolor);
      cprintf("By");

      gotoxy(25,6);
      textcolor(0);
      textbackground(cntkbkcolor);
      cprintf(" Name");


      if(k==7)
      {
       cntkbkcolor=2;
      }
      else
      {
      cntkbkcolor=7;
      }
      gotoxy(23,7);
      textcolor(4);
      textbackground(cntkbkcolor);
      cprintf("By");

      gotoxy(25,7);
      textcolor(0);
      textbackground(cntkbkcolor);
      cprintf(" Number");

     a=getch();
     keysound();

      if(a==13)
     {
	if(k==6)
	{
	 goto searchbyname;

	}
	else if(k==7)
	{
	  goto searchbynumber;
	}

     }
     else if(a==8)
     {
     k=1200;
     }
     else
     {
     ch=getch();
     keysound();
     if(ch==' '||ch==80)
     {
	 k++;
	 if(k>7)
	 {
	 k=6;
	 }
	 goto searchcontact;

     }
     else if(ch==8||ch==72)
     {
       k--;
       if(k<6)
       {
	     k=7;
       }
       goto searchcontact;

     }

     else if(ch==13)
     {
	if(k==6)
	{
	 goto searchbyname;

	}
	else if(k==7)
	{
	  goto searchbynumber;
	}

     }
     }
     searchbyname:
     if(k==6)
     {
    searchname();
      }
   searchbynumber:
	       if(k==7)
	       {
		 searchnumber();
		 }
	   }
     else
     {

      fclose(fp);
      openscrollbox(21,4,77,18,7);


	  gotoxy(37,11);
	  textcolor(6);
	  textbackground(7);
	  _setcursortype(_NOCURSOR);
	  cprintf("No contacts available");
	  getch();
	  keysound();

     }
}
void edit()
{
     char ch;
     char sname[30];
     int d,match=0;
     char fname[30],fnumber[30];
     int k=8;
     int cntkbkcolor=7;
     char oldname[30],newname[30];
     fp=fopen("contacts.txt","r");
     if(fp!=NULL)
     { fclose(fp);
     editcontact:

      openscrollbox(21,7,32,10,7);

      gotoxy(22,k);
      textcolor(2);
      textbackground(2);
      cprintf("          ");
      if(k==8)
      {
       cntkbkcolor=2;
      }
      else
      {
      cntkbkcolor=7;
      }
      _setcursortype(_NOCURSOR);
      gotoxy(23,8);
      textcolor(4);
      textbackground(cntkbkcolor);
      cprintf("N");

      gotoxy(24,8);
      textcolor(0);
      textbackground(cntkbkcolor);
      cprintf("ame");


      if(k==9)
      {
       cntkbkcolor=2;
      }
      else
      {
      cntkbkcolor=7;
      }
      gotoxy(23,9);
      textcolor(4);
      textbackground(cntkbkcolor);
      cprintf("N");

      gotoxy(24,9);
      textcolor(0);
      textbackground(cntkbkcolor);
      cprintf("umber");

     a=getch();
     keysound();
     if(a==13)
     {


	if(k==8)
	{
	 goto editname;

	}
	else if(k==9)
	{
	  goto editnumber;
	}


     }
     else if(a==8)
     {

     k=1200;
     }
     else
     {
     ch=getch();
     keysound();
     if(ch==' '||ch==80)
     {
	 k++;
	 if(k>9)
	 {
	 k=8;
	 }
	 goto editcontact;

     }
     else if(ch==8||ch==72)
     {
       k--;
       if(k<8)
       {
	     k=9;
       }
       goto editcontact;

     }

     else if(ch==13)
     {
	if(k==8)
	{
	 goto editname;

	}
	else if(k==9)
	{
	  goto editnumber;
	}

     }
     }
     editname:
       if(k==8)
       {

      openscrollbox(21,6,77,23,7);


     gotoxy(22,7);
     textcolor(0);
     _setcursortype(_NORMALCURSOR);
     textbackground(2);
     cprintf("                %c   Edit Contact  %c                  ",17,16);

     gotoxy(23,10);
     textcolor(1);
     textbackground(7);
     cprintf(" Enter Name / Number :");
     box(48,10,25,1,0,7);


     gotoxy(49,10);
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
    name[d]='\0';

	 if(name[0]>=97 &&name[0]<=122)
	 {
	  name[0]-=32;
	 }
     d=1;
     fp=fopen("contacts.txt","r");
     fp1=fopen("temp.txt","a");

     while(fscanf(fp,"%s %s\n",fname,fnumber)!=EOF)
     {

	  if(strcmp(fname,name)==0||strcmp(fnumber,name)==0)
	  {
	       _setcursortype(_NOCURSOR);
	 gotoxy(23,15);
	 textcolor(1);
	 textbackground(7);
	 cprintf("[%d]",d);

	 gotoxy(28,15);
	 textcolor(0);
	 textbackground(7);
	 cprintf("%s",fname);

	 gotoxy(48,15);
	 textcolor(6);
	 textbackground(7);
	 cprintf("%s",fnumber);
	 match=1;

      if(match==1)
     {

	  gotoxy(37,13);
	  textcolor(0);
	  textbackground(2);
	  _setcursortype(_NOCURSOR);
	  cprintf(" <<< Contact Found >>>");

     }

       gotoxy(23,18);
       textcolor(6);
       textbackground(7);
       cprintf(" Enter New Name  :");
	box(48,18,25,1,0,7);
       gotoxy(49,18);
       gets(oldname);
	 d=0;
	 for(i=0; i<strlen(oldname); i++)
	{
	 if(oldname[i]==' ')
	 {

	 }
	 else
	  {
	    newname[d++]=oldname[i];

	 }

	  }
	  newname[d]='\0';

	   if(newname[0]>=97 &&newname[0]<=122)
	   {
	    newname[0]-=32;
	   }
	       fprintf(fp1,"%s %s\n",newname,fnumber);

	  gotoxy(35,22);
	  textcolor(0);
	  textbackground(2);
	  _setcursortype(_NOCURSOR);
	  cprintf("<< Contact Successfully Saved >>");


	   delay(1000);
	  }
	  else
	  {
	    fprintf(fp1,"%s %s\n",fname,fnumber);
	  }
	  d++;
	}

     if(match==0)
     {
	  gotoxy(35,16);
	  textcolor(4);
	  textbackground(7);
	  _setcursortype(_NOCURSOR);
	  cprintf("ERORR : Contact Not Found ! ");
	  getch();
	  keysound();
     }
     fclose(fp);
     fclose(fp1);
     fp=fopen("contacts.txt","w");
     fclose(fp);
     fp=fopen("contacts.txt","a");
     fp1=fopen("temp.txt","r");
     while(fscanf(fp1,"%s %s\n",fname,fnumber)!=EOF)
     {
       fprintf(fp,"%s %s\n",fname,fnumber);
     }
     fclose(fp);
     fclose(fp1);
     fp1=fopen("temp.txt","w");
     fclose(fp1);
      }
     editnumber:

     if(k==9)
     {
     match=0;
      openscrollbox(21,6,77,23,7);


     gotoxy(22,7);
     textcolor(0);
     _setcursortype(_NORMALCURSOR);
     textbackground(2);
     cprintf("                %c   Edit Contact  %c                  ",17,16);

     gotoxy(23,10);
     textcolor(1);
     textbackground(7);
     cprintf(" Enter Name / Number :");
     box(48,10,25,1,0,7);


     gotoxy(49,10);
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
    name[d]='\0';

	 if(name[0]>=97 &&name[0]<=122)
	 {
	  name[0]-=32;
	 }
     d=1;
     fp=fopen("contacts.txt","r");
     fp1=fopen("temp.txt","a");

     while(fscanf(fp,"%s %s\n",fname,fnumber)!=EOF)
     {

	  if(strcmp(fname,name)==0||strcmp(fnumber,name)==0)
	  {
	       _setcursortype(_NOCURSOR);
	 gotoxy(23,15);
	 textcolor(1);
	 textbackground(7);
	 cprintf("[%d]",d);

	 gotoxy(28,15);
	 textcolor(0);
	 textbackground(7);
	 cprintf("%s",fname);

	 gotoxy(48,15);
	 textcolor(6);
	 textbackground(7);
	 cprintf("%s",fnumber);
	 match=1;

      if(match==1)
     {

	  gotoxy(37,13);
	  textcolor(0);
	  textbackground(2);
	  _setcursortype(_NOCURSOR);
	  cprintf(" <<  Contact Found >>");

     }

       gotoxy(23,18);
       textcolor(6);
       textbackground(7);
       cprintf(" Enter New Number  :");
	box(48,18,25,1,0,7);
       gotoxy(49,18);
       gets(oldname);
	 d=0;
	 for(i=0; i<strlen(oldname); i++)
	{
	 if(oldname[i]==' ')
	 {

	 }
	 else
	  {
	    newname[d++]=oldname[i];

	 }

	  }
	  newname[d]='\0';

	   if(newname[0]>=97 &&newname[0]<=122)
	   {
	    newname[0]-=32;
	   }
	       fprintf(fp1,"%s %s\n",fname,newname);

	  gotoxy(35,22);
	  textcolor(0);
	  textbackground(2);
	  _setcursortype(_NOCURSOR);
	  cprintf("<< Contact Successfully Saved >>");


	   delay(1000);
	  }
	  else
	  {
	    fprintf(fp1,"%s %s\n",fname,fnumber);
	  }

	  d++;
	}

     if(match==0)
     {
	  gotoxy(35,16);
	  textcolor(4);
	  textbackground(7);
	  _setcursortype(_NOCURSOR);
	  cprintf("ERORR : Contact Not Found ! ");
	  getch();
	  keysound();
     }
     fclose(fp);
     fclose(fp1);
     fp=fopen("contacts.txt","w");
     fclose(fp);
     fp=fopen("contacts.txt","a");
     fp1=fopen("temp.txt","r");
     while(fscanf(fp1,"%s %s\n",fname,fnumber)!=EOF)
     {
       fprintf(fp,"%s %s\n",fname,fnumber);
     }
     fclose(fp);
     fclose(fp1);
     fp1=fopen("temp.txt","w");
     fclose(fp1);
      }
      }
      else
      {
	    openscrollbox(21,6,77,23,7);
	  gotoxy(37,14);
	  textcolor(6);
	  textbackground(7);
	  _setcursortype(_NOCURSOR);
	  cprintf("No contacts available");
	  getch();
	  keysound();
       fclose(fp);

      }
}
void showmouseptr()
{
    in.x.ax=0;
    int86(0x33,&in,&out);


}
void getmouseptr(int *button,int *x, int *y)
{
      in.x.ax=3;
      int86(0x33,&in,&out);
     *button=out.x.bx;
     *x=out.x.cx;
     *y=out.x.dx;



}
void login()
{
	char username[30];
	char password[10],star[10];
	char name[30],number[30],pw[30];
	char ch;
	char k;

	for(i=1; i<=24; i++)
	{
	for(j=1; j<=80; j++)
	 {
	 gotoxy(j,i);
	 textcolor(1);
	 textbackground(15);
	cprintf("°");
	  }
	  }
	rename:
	  openscrollbox(20,7,65,16,7);
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
	      keysound();
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
	  fp2=fopen("userid.txt","r");
	  while(fscanf(fp2,"%s %s %s",name,number,pw)!=EOF)
	  fclose(fp2);
	  if(strcmp(username,name)==0&& strcmp(password,pw)==0)
	  {


	  openscrollbox(20,7,65,16,7);


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


	  openscrollbox(20,7,65,16,7);


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
		 keysound();
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
   char username[30],password[15],number[15];



 myprofile:
     strcpy(username,"");
     strcpy(password,"");
     strcpy(number,"");
	openscrollbox(21,8,70,23,7);

     gotoxy(22,10);
     textcolor(0);
     _setcursortype(_NOCURSOR);
     textbackground(2);
     cprintf("               %c   My Profile  %c                ",17,16);

     fp2=fopen("userid.txt","r");
     if(fp2!=NULL)
     {
	gotoxy(24,12);
	textcolor(7);
	textbackground(1);
	cprintf("  User Name   :");

	gotoxy(24,15);
	textcolor(7);
	textbackground(4);
	cprintf("  User Number :");

	gotoxy(24,18);
	textcolor(7);
	textbackground(5);
	cprintf("  Password    :");
	fp2=fopen("userid.txt","r");
	while(fscanf(fp2,"%s %s %s",username,number,password)!=EOF)
	{

	  gotoxy(40,12);
	  textbackground(7);
	  textcolor(0);
	  cprintf("  %s",username);

	  gotoxy(40,15);
	  textbackground(7);
	  textcolor(0);
	  cprintf("  %s",number);

	  gotoxy(40,18);
	  textbackground(7);
	  textcolor(0);
	  cprintf("  %s",password);

	}
       fclose(fp2);
	  gotoxy(22,22);
	  textbackground(2);
	  textcolor(15);
	  cprintf(" Press 1 :Edit Acoount  Press 2 :Delete Acoount ");

      }
      else
      {
	fclose(fp2);
	gotoxy(32,16);
	textcolor(1);
	textbackground(7);
	cprintf("You not set Your Profile");

	   gotoxy(22,22);
	  textbackground(2);
	  textcolor(15);
	  cprintf("          Press 1 To Set Your Profile          ");

      }

}
void deleteprofile()
{
	      remove("userid.txt");
		openscrollbox(21,8,70,23,7);
	  gotoxy(30,16);

	  textcolor(0);
	  textbackground(7);
	  _setcursortype(_NOCURSOR);
	  cprintf(" Acoount Succesfully Delected");
	   gotoxy(22,22);
	   textcolor(15);
	    textbackground(6);
	    cprintf("                  Press any Key                 ");
	    getch();
	    keysound();

}
void editmyprofile()
{

	   char newname[30],newpassword[15],newnumber[15];
	openscrollbox(21,8,70,23,7);


     strcpy(newname,"");
     strcpy(newpassword,"");
     strcpy(newnumber,"");
     gotoxy(22,10);
     textcolor(0);
     _setcursortype(_NOCURSOR);
     textbackground(2);
     cprintf("           %c   My Profile  %c                 ",17,16);

	gotoxy(24,12);
	textcolor(7);
	textbackground(2);
	cprintf(" User  Name   :");

	gotoxy(24,15);
	textcolor(7);
	textbackground(4);
	cprintf(" User  Number :");

	gotoxy(24,18);
	textcolor(7);
	textbackground(5);
	cprintf(" Set Password :");
	 _setcursortype(_NORMALCURSOR);
	gotoxy(40,12);
	textcolor(6);
	textbackground(3);
	cprintf("                           ");

	gotoxy(40,15);
	textcolor(6);
	textbackground(3);
	cprintf("                           ");

	gotoxy(40,18);
	textcolor(6);
	textbackground(3);
	cprintf("                            ");

       textcolor(4);

	 gotoxy(42,12);
	gets(newname);
	if(newname[0]>=97 &&newname[0]<=122)
	{
	 newname[0]-=32;
	}
	gotoxy(42,15);
	gets(newnumber);
	gotoxy(42,18);
	gets(newpassword);
	fp2=fopen("userid.txt","w");
	fprintf(fp2,"%s %s %s",newname,newnumber,newpassword);
	fclose(fp2);
		openscrollbox(21,8,70,23,7);
	  gotoxy(30,16);

	  textcolor(0);
	  textbackground(7);
	  _setcursortype(_NOCURSOR);
	  cprintf(" Changes Successfully Saved");
	  delay(1000);

}
void about()
{
  openscrollbox(21,15,65,23,7);
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
     cprintf(" : Contacts Management");

     gotoxy(23,22);
     textcolor(7);
     textbackground(5);
     cprintf(" Published On ");

     gotoxy(37,22);
     textcolor(0);
     textbackground(7);
     cprintf(" : 29th November 2019");


}
void keyintro()
{

	for(i=1; i<=24; i++)
	{
	for(j=1; j<=80; j++)
	 {
	 gotoxy(j,i);
	 textcolor(4);
	 textbackground(15);
	cprintf("°");
	  }
	  }

	rename:
	  openscrollbox(15,6,72-5,18,7);
	    _setcursortype(_NOCURSOR);
	    gotoxy(21-5,7);
	    textcolor(1);
	    textbackground(7);
	    cprintf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ KEY INTRUCTIONS ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");

     gotoxy(23-5,10);
     textcolor(7);
     textbackground(1);
     cprintf("  Down Key ");

     gotoxy(37-5,10);
     textcolor(0);
     textbackground(7);
     cprintf(": Scroll Down %c ",25);

     gotoxy(23-5,12);
     textcolor(7);
     textbackground(2);
     cprintf("  Up Key   ");

     gotoxy(37-5,12);
     textcolor(0);
     textbackground(7);
     cprintf(": Scroll Up %c",24);

     gotoxy(23-5,14);
     textcolor(7);
     textbackground(5);
     cprintf("  Enter    ");

     gotoxy(37-5,14);
     textcolor(0);
     textbackground(7);
     cprintf(": To Continue With Selected option");

     gotoxy(23-5,17);
     textcolor(7+BLINK);
     textbackground(LIGHTRED);
     cprintf("               Press Any Key                    ");


	    }
void main()
{

char ch;
    enter=0;


 //     fprintf(fp2,"Ajaysinh 9998502353 ajay2001");

     fp2=fopen("userid.txt","r");
     if(fp2!=NULL)
     {
      system("cls");
      login();

	}
	else
	{
	keyintro();
	getch();
	keysound();
	}
	fclose(fp2);


      startprograme:
		mainpage();
      menu(scroll,enter);

      a=getch();


      if(a==80 || a==' ')
      {  keysound();
	 scroll+=2;

	 if(scroll>=23)
	 {
	    scroll=23;
	 }
	 else
	 {

	 if(scroll>15)
	 {
	   scroll=21;
	   if(scroll>23)
	   {

	    scroll=23;
	   }
	 }
	 }
	 enter=0;
	 goto startprograme;

      }
      else if(a==72||a==8)
      {
	  keysound();
      if(scroll==21)
      {
       scroll=15;
      }
      else
      {
       scroll-=2;
       if(scroll<3)
       {
	 scroll=3;
       }
       }
	enter=0;
       goto startprograme;
      }
      else if(a==27||quit==0 || scroll==23 && a==13)
      {
	exit(1);

      }
      else if(a==9 || scroll==21 && a==13)
      {
	if(sound1==0)
	{
	  sound1=2500;
	}
	else
	{
	 sound1=0;
	}
	goto startprograme;

      }

      else if(a==13 && scroll==3 ||a=='n'||a=='N')
      {
//       <<  New contact  >>
	 enter=1;
	 scroll=3;


	 mainpage();
	 menu(3,enter);
	 newcontact();

	 goto startprograme;


      }

      else if(a==13 && scroll==5||a=='s'||a=='S')
      {
///////////////   search<<<<<<<<<

	 enter=1;
	 scroll=5;


	 mainpage();
	 menu(5,enter);
	 search();

      // closescrollbox(21,2,29,11);


	 goto startprograme;

      }

      else if(a==13 && scroll==7||a=='e'||a=='E')
      {
////////////////////// Edit   >>");
	 enter=1;
	 scroll=7;


	 mainpage();
	 menu(7,enter);
	 edit();


	 goto startprograme;


      }

      else if(a==13 && scroll==9||a=='d'||a=='D')
      {
//            DELETE  >>>>>>>>>>>>>>>>>>>>>>
	 enter=1;
	 scroll=9;

	 mainpage();
	 menu(9,enter);
	 deleteword();


	 goto startprograme;

      }

      else if(a==13 && scroll==11||a=='a'||a=='A')
      {
//          allcontacts >>>>>>>>>>>>>>>>>>>>>>>>>>>
	 enter=1;
	 scroll=11;
	 mainpage();
	 menu(11,enter);
	 allcontacts();

	 goto startprograme;

      }

      else if(a==13 && scroll==13||a=='m'||a=='M')
      {
////          my profile........
	 enter=1;
	      scroll=13;


	 mainpage();
	 menu(13,enter);
	 myprofile();
	 ch=getch();
	 keysound();
	 if(ch=='1')
	 {
	   editmyprofile();
	   goto startprograme;

	 }
	 else if(ch=='2')
	 {
	   deleteprofile();
	   goto startprograme;
	 }
	 else
	 {
	 goto startprograme;
	 }
      }

      else if(a==13 && scroll==15||a=='b'||a=='B')
      {
    //   ABOUT   ......................
	 enter=1;
	 system("cls");
	 mainpage();
	 scroll=15;
	 menu(15,enter);
	 about();
	 getch();
	 keysound();

	 goto startprograme;

      }


      else
      {

       enter=1;

	 goto startprograme;

      }
}