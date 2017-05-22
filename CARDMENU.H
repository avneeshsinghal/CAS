#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<process.h>
#include<ctype.h>
#include<fstream.h>
#include "CAS\intrfc.cpp"
#define ENTER      13
#define ESC        27
#define SPACE      32
#define UP_ARROW   72
#define DOWN_ARR   80
class CMenu
{
  char *menuItem;
  int length;
  CMenu **subMenu;
  public:
	CMenu(char* ="");
	void addMenu(CMenu&);
	CMenu *showSubMenu(int ,int);
	void showMainMenu(int,int);
	const char *caption();
	int items();
	~CMenu()
	{
		delete[] menuItem;
	}
};
const char *CMenu::caption(void)
{
	return menuItem;
}
int CMenu::items(void)
{
	return length;
}
CMenu::CMenu(char *item):menuItem(new char[strlen(item)+1])
{
	strcpy(menuItem,item);
	subMenu=NULL;
	length=0;
}
void CMenu::addMenu(CMenu &mnu)
{
   length++;
   CMenu**temp= new CMenu*[length];
   for(int i=0;i<length-1;i++)
   {
	temp[i]= subMenu[i];
   }
   temp[length-1]=&mnu;
   delete []subMenu;
   subMenu=temp;
}
CMenu *CMenu::showSubMenu(int x,int y)
{
	int maxWidth=5;
	int len;
	int sel=0;
	char ch;
	CMenu *selected=NULL;
	// To find the length of the longest menu item
	for(int i=0;i<length;i++)
	{
		len=strlen(subMenu[i]->menuItem);
		if(len>maxWidth)
		{
			maxWidth=len;
		}
	}
    int mainMenuFlag=0;
     //  Flag used to identify the main menu for diff. color settings.
    if (x+maxWidth < 50)   mainMenuFlag=1;
	Cwindow w(x-1,y-1,maxWidth+7,length+2);
	if (mainMenuFlag==1)
	{
			w.setAttributes(BLUE,WHITE,1,1);
	}
	else
	{
		       //	w.setAttributes(BROWN,BLUE,1,1);
	}
	w.showWindow();
	while(1)
	{
		for(i=0;i<length;i++)
		{
			if(i==sel)
			{
				  if (mainMenuFlag==1)
				  {
					{    
					    gotoxy(33,5);
						textcolor(BROWN);
						textbackground(BLACK);
						cprintf("<< MAIN MENU >>        ");
					 }
					textbackground(RED);
					textcolor(YELLOW);
				  }
				  else
				  {
					textbackground(WHITE);
					textcolor(RED);
				  }
			}
			else
			{
				  if (mainMenuFlag==1)
				  {
					textbackground(BLUE);
					textcolor(WHITE);
				  }
				  else
				  {
					textbackground(RED);
					textcolor(BLACK);
				  }
			 }
			 gotoxy(x+2,y+i);
			 if(subMenu[i]!=NULL)
			 {
				cprintf("%s ",subMenu[i]->menuItem);
			 }
		}
		while(!kbhit()) delay(100);
		flushall();
		ch=getch();
		if (ch==ESC)
		{
		   Cwindow w1(x-1,y-1,maxWidth+9,length+3);
		   w1.setAttributes(WHITE,WHITE,0,0);
		   w1.showWindow();
		   break;
		}
		if(ch==ENTER)
		{
			{    //     To print the title for each submenu
				char *s;
				gotoxy(33,5);
				textcolor(MAGENTA);
				textbackground(BLACK);
				int l=strlen(subMenu[sel]->menuItem);
				s=new char[l];
				for (int i=0;i<=l;i++)
				{
					if ((subMenu[sel]->menuItem[i])!='_')
					{
						s[i]=toupper(subMenu[sel]->menuItem[i]);
					}
					else
					{
						s[i]=' ';
					}
				}
				cprintf(" %s ",s);
			 }
			if (subMenu[sel]->items()){
				selected=subMenu[sel]->showSubMenu(x+maxWidth+10,y+length-2);
				if (!selected) continue;
			}
			else {
				selected=subMenu[sel];
			}
			break;
		}
		if(ch==0) ch=getch();
		if(ch==UP_ARROW)
		{
			sel--;
			if(sel<0) sel=length-1;
		}
		if(ch==DOWN_ARR)
		{
			sel++;
			if(sel>length-1) sel=0;
		}

	 }
	return selected;
}