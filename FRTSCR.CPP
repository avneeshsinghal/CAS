#define DOWN 	'\x50'
#define UP 		'\x48'
#define pixTOrc(x) (8*(x-1))  //convert pixel into row and col format
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>
#include <ctype.h>
#include <iostream.h>
#include <fstream.h>
void  displayMe(int x,int y,const char *ch,int delayTime);
int get_password();
void end();
void  loading();
void  loading()
{
	 //progressbar logic
	int i=1,j,cnt,clrflag=0;
	setcolor(LIGHTGRAY);
	j=160;
	cnt=5;
	for(i=j;i<420;i++)
	{
		gotoxy(35,25);
	       //	cout<<cnt;
		rectangle(j,375,i,405);
		outtextxy(240,340,"LOADING ");
		if(i==(j+10))
		{
			j=j+13;
			i=j;
			if(clrflag==1)
			{
				clrflag=0;
				setcolor(LIGHTGRAY);
			}
			else
			{
				clrflag=1;
				setcolor(LIGHTBLUE);
			}
			cnt=cnt+5;
		}
	}
	delay(1000);
}
void  displayMe(int x,int y,const char *ch,int delayTime)
{
	char d[2];
	int len=strlen(ch);
	for(int i=0;i<=len;i++)
	{
		d[0]=ch[i];
		d[1]='\0';
		outtextxy(x+pixTOrc((i+1)*2),y,d);
		delay(delayTime);
	}
}
int get_password()
{
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,0,640,480);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
	setcolor(BLACK);
	outtextxy(pixTOrc(15),pixTOrc(2),"ENTRANCE SEAT ALLOTMENT");
	setfillstyle(LINE_FILL,6);
	bar(pixTOrc(8),pixTOrc(7),pixTOrc(70),pixTOrc(7.5));
	setcolor(GREEN);
	settextstyle(3,HORIZ_DIR,3);
	outtextxy(pixTOrc(20),pixTOrc(6),"Administrator Section");
	int i,j;
	setfillstyle(LINE_FILL,6);
	for(i=5,j=80;i<40||j>40;i++,j--)
	{
		bar(pixTOrc(2),pixTOrc(10),pixTOrc(i),pixTOrc(55));
		delay(10);
		bar(pixTOrc(j),pixTOrc(10),pixTOrc(80),pixTOrc(55));
		//sound(400+(i*50));
		delay(10);
		//nosound();
	}
	setcolor(WHITE);
	int c=pixTOrc(40),a=-1;
	char pass[20],correctpassword[20]="admin";
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	outtextxy(pixTOrc(16),pixTOrc(19),"Enter password : ");
	setcolor(WHITE);
	while (pass[a]!='\r')
	{
		pass[++a]=getch();
		if  (pass[a]=='\r' || a>=19)
		{
			pass[a]='\0';
			pass[++a]='\r';
			break;
		}
		c+=16;
		outtextxy(c,pixTOrc(20), "*");
	}
     if(strcmp(pass,correctpassword)==0)
	{
		outtextxy(pixTOrc(20),pixTOrc(24),"Password Accepted");
		loading();
			return(0);
	}
	else
	{
		outtextxy(pixTOrc(20),pixTOrc(24),"Wrong Password!!!");
		setcolor(WHITE);
		getche();
		return (1);
	}
}
void end()
{
	int i,j;
	setfillstyle(4,LIGHTRED);
	for(i=5,j=80;i<40||j>40;i++,j--)
	{
		bar(pixTOrc(2),pixTOrc(10),pixTOrc(i),pixTOrc(55));
		delay(10);
		bar(pixTOrc(j),pixTOrc(10),pixTOrc(80),pixTOrc(55));
		//sound(400+(i*50));
		delay(10);
	       //	nosound();
	}
	settextstyle(1,HORIZ_DIR,3);
	displayMe(pixTOrc(5),pixTOrc(18),"YOU ARE EXITING THE PROGRAM...",50);
	delay(500);
	settextstyle(1,HORIZ_DIR,3.5);
	displayMe(pixTOrc(8),pixTOrc(30),"THANK YOU!!!............",50);
	setcolor(WHITE);
	delay(2000);
}