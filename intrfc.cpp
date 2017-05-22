#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<process.h>
#include<ctype.h>
#define ENTER      13
#define ESC        27
#define SPACE      32
#define UP_ARROW   72
#define DOWN_ARROW 80
void displayAt(int x, int y, int z)
{
	gotoxy(x,y);
	cout<<z<<endl;
}
void displayAt(int x, int y, float z)
{
	gotoxy(x,y); 
	cout<<z<<endl;
}
void displayAt(int x, int y, const char* z)
{
	gotoxy(x,y);
	cout<<z<<endl;
}
class Cwindow
{
	int left,top,width,height,backColor,textColor,borderStyle;
	int shadowFlag;
	char title[];
	public:
		Cwindow (int=0,int=0,int=0,int=0);
		void setAttributes(int,int=3,int=0,int =0);
		void showWindow ();
		void setTitle(const char* =NULL,int=3);
};
Cwindow::Cwindow (int l,int t, int w,int h):left(l),top(t),width(w),height(h)
{
	backColor=YELLOW;
	textColor=WHITE;
	borderStyle=2;
}
void Cwindow::setAttributes(int back, int text, int shadow,int border)
{
	backColor=back;
	textColor=text;
	shadowFlag=shadow;
	borderStyle=border;
}
void Cwindow::showWindow()
{
	char symbol[6];
	_setcursortype(_NOCURSOR);
	window(left,top,left+width,top+height);
	textbackground(backColor);
	textcolor (textColor);
	clrscr();
	window(1,1,79,24);
    if (borderStyle)
     {
	  if (borderStyle==1)
	   {
		symbol[0]='Ä';
		symbol[1]='³';
		symbol[2]='Ú';
		symbol[3]='¿';
		symbol[4]='À';
		symbol[5]='Ù';
	   }
	  if (borderStyle==2)
	   {
		symbol[0]='Í';
		symbol[1]='º';
		symbol[2]='É';
		symbol[3]='»';
		symbol[4]='È';
		symbol[5]='¼';
	}
	for(int i=left+1;i<left+width;i++)
	{
		gotoxy(i,top);
		//delay(10);
		printf("%c",symbol[0]);
	 }
		gotoxy(left+width-1,top);
		printf("%c",symbol[3]);
		for( int j=top+1;j<top+height;j++)
		{
			gotoxy(left+width-1,j);
			//delay(10);
			printf("%c",symbol[1]);
		}
		gotoxy(left+width-1,top+height);
		printf("%c",symbol[5]);
		for( j=left+width-2;j>left+1;j--)
		{
			  gotoxy(j,top+height);
			//delay(10);
			printf("%c",symbol[0]);
		}
		gotoxy(left+1,top+height);
		printf("%c",symbol[4]);
		for(int k=top+height-1;k>top;k--)
		{
			gotoxy(left+1,k);
			//delay(10);
			printf("%c",symbol[1]);
		}
		gotoxy(left+1,top);
		printf("%c",symbol[2]);

    }
}
void Cwindow::setTitle(const char* title,int color)
{
	 int l=strlen(title);
	 gotoxy((left+(width/2)-(l/2)),top+1);
	 textbackground(backColor);
	 textcolor(color);
	 for(int i=0;i<l;i++)
	 {
		cprintf("%c",title[i]);
		//delay(20);
	 }
	 char symbol;
	 if(borderStyle==1) symbol='Ä';
	 if(borderStyle==2) symbol='Í';
	 textcolor(textColor);
	 for ( i=left+3;i<(left+width-2);i++)
	 {
		gotoxy(i,top+2);
		cprintf("%c",symbol);
	 }
}