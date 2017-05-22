#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>
#include <ctype.h>
#include <iostream.h>
#include <fstream.h>
#include "CAS\cardmenu.h"
#include "CAS\frtscr.cpp"
#include "CAS\promenu.cpp"
void menu();
void menu1();
void firstmenu();
void graph();
void main()
{
	float y;
	clrscr();
	graph();
	firstmenu();
}
void menu()
{
	clrscr();
	closegraph();
	textbackground(WHITE);
	textcolor(BLUE);
	Cwindow w(1,1,79,23);
	gotoxy(3,25);
	cprintf("ESC -> previous menu");
	gotoxy(45,25);
	cprintf(" UP / DOWN arrows + ENTER -> select");
	w.showWindow();
	w.setTitle(" ENTRANCE SEAT ALLOTMENT SYSTEM ",BLACK);
	while(1)
	{
		//window to display the menu
		Cwindow w1(5,4,71,18);
		w1.setAttributes(DARKGRAY,RED,0,1);
		w1.showWindow();
		w1.setTitle("",BLACK);
		CMenu main;
		CMenu main1("College   ");
		CMenu main2("Course     ");
		CMenu main3("Seat Allotment ");
		CMenu main4("Exit        ");
		main.addMenu(main1);
		main.addMenu(main2);
		main.addMenu(main3);
		main.addMenu(main4);
		CMenu cs1("Add College  ");
		CMenu cs2("Delete College");
		CMenu cs3("View College  ");
		CMenu cs4("Back");
		main1.addMenu(cs1);
		main1.addMenu(cs2);
		main1.addMenu(cs3);
		main1.addMenu(cs4);
		CMenu cos1("Add Course  ");
		CMenu cos2("Delete Course");
		CMenu cos3("View Course  ");
		CMenu cos4("Back");
		main2.addMenu(cos1);
		main2.addMenu(cos2);
		main2.addMenu(cos3);
		main2.addMenu(cos4);
	     //	CMenu sa1("Read Students");
		CMenu sa2("Allot Seats");
		CMenu sa3("Allotment Details ");
		CMenu sa4("Back");
	      //main3.addMenu(sa1);
		main3.addMenu(sa2);
		main3.addMenu(sa3);
		main3.addMenu(sa4);
		CMenu *selmenu= main.showSubMenu(10,10);
	       if (selmenu==&cs1)
		{
			 c1.add_college();
			 menu();
		}
		else if (selmenu==&cs3)
		{
			 c1.show_college();
			 getch();
			 menu();
		}
		else if (selmenu==&cos1)
		{
			 co1.add_course();
			 menu();
		}
		else if (selmenu==&cos3)
		{
			co1.show_course();
			getch();
			menu();
		}
		else if (selmenu==&cos2)
		{
			co1.del_course();
			menu();
		}
		else if(selmenu==&cos4)
		{
			 menu();
		}
		else if (selmenu==&cs2)
		{
			c1.del_college();
			menu();
		}
		else if (selmenu==&sa2)
		{
		       a1.allot_seat();
		       getch();
		       menu();
		}
		else if (selmenu==&sa3)
		{
			a1.display_allotment();
			getch();
			menu();
		}
		else if(selmenu==&sa4)
		{
			menu();
		}
		 if(selmenu==&main4)
			firstmenu();
	}
}
void menu1()
{
	clrscr();
	closegraph();
	textbackground(WHITE);
	textcolor(BLUE);
	Cwindow w(1,1,79,23);
	gotoxy(3,25);
	cprintf("ESC -> previous menu");
	gotoxy(45,25);
	cprintf(" UP / DOWN arrows + ENTER -> select");
	w.showWindow();
	w.setTitle(" ENTRANCE SEAT ALLOTMENT SYSTEM ",BLACK);
	while(1)
	{
		//window to display the menu           x
		Cwindow w1(5,4,71,18);
		w1.setAttributes(DARKGRAY,RED,0,1);
		w1.showWindow();
		w1.setTitle("",BLACK);
		CMenu main;
		CMenu college("College Details");
		CMenu course("Course Details");
		CMenu read("Input Your Details");
		CMenu request("Request For Allotment");
		CMenu ext("Exit ");
		main.addMenu(college);
		main.addMenu(course);
		main.addMenu(read);
		main.addMenu(request);
		main.addMenu(ext);
		CMenu *selmenu= main.showSubMenu(10,10);
		if(selmenu==&college)
		{
			c1.show_college();
			getch();
			menu1();
		}else if(selmenu==&course)
		{
			co1.show_course();
			getch();
			menu1();
		}else if(selmenu==&request)
		{
			req.col_request();
			menu1();
		}else if(selmenu==&read)
		{
			a1.read_details();
			menu1();
		}
		if(selmenu==&ext)
		{
			firstmenu();
		 }

	}
}
void graph()
{
	int gd=DETECT,gm=0;
	initgraph(&gd,&gm,"");
}
void firstmenu()
{
	clrscr();
	closegraph();
	textbackground(WHITE);
	textcolor(BLUE);
	Cwindow w(1,1,79,23);
	w.showWindow();
	w.setTitle(" ENTRANCE SEAT ALLOTMENT SYSTEM ",BLACK);
	while(1)
	{
		//window to display the menu
		Cwindow w1(5,4,71,18);
		w1.setAttributes(DARKGRAY,RED,0,1);
		w1.showWindow();
		w1.setTitle("",BLACK);
		CMenu admenu;
		CMenu admin("Adminstrator");
		CMenu user("Candidates");
		CMenu ex("Exit ");
		admenu.addMenu(admin);
		admenu.addMenu(user);
		admenu.addMenu(ex);
		CMenu *selmenu= admenu.showSubMenu(10,10);
		graph();
		if(selmenu==&admin)
		{
			//int pwd=get_password();
			 //if(pwd==1){
			   //	end();
			     //	closegraph();
			       //	exit(0);
			// }
			// if(pwd==0){
				menu();
			  //	getch();
			 // }
		}else if(selmenu==&user)
		{
			 menu1();
		 }
		else if(selmenu==&ex)
		{
			exit(0);
		}
	}
}