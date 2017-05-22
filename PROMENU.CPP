#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
void readLine(char *str, int size);
//  Class containing college Details //
class college
{
	private:
		char cname[25];
		char cplace[25];
	public:
		char ctype;
		int ccode;
		college();
		void add_college();
		void show_college();
		void del_college();
		int college_search(char [],char[]);
}c1;
class request
{
	public:
		int rkno;
		int col1;
		int col2;
		int col3;
		   void col_request();
}req;
// Class containing Reservation Groups /
class reserv
{
	public:
		int mr_seat;
		int sc_seat;
		int obc_seat;
		int ez_seat;
		int mu_seat;
		int nc_seat;
};
 // Class contining course Details //
class course:public college,public reserv
{
	public:
		int seatno;
		int cocode;
		char branch[30];
		void add_course();
		void del_course();
		void show_course();
}co1;
// Class containing Allottment Details //
class allotment:public course
{
	char br;
	char st_name[10];
	int rankno;
	int res_type;
	char addr[10];
	public:
		void read_details();
		void allot_seat();
		void display_allotment();
}a1;
// Constructor to initialize data....//
college::college()
{
	ctype=' ';
	ccode=0;
	strcpy(cname,"");
	strcpy(cplace,"");
}
// Function to add a new college //
void college::add_college()
{
	fstream f;
	int flag=0;
	//f.open("CAS\college.txt",ios::out|ios::app);
	FILE *fp;
	fp=fopen("CAS/college.txt","a");
	Cwindow w5(8,5,65,16);
	w5.setAttributes(LIGHTGRAY,BLACK,7,0);
	w5.showWindow();
	_setcursortype(_NORMALCURSOR);
	textcolor(BLUE);
	if(fp==NULL)
	{
		gotoxy(15,8);
		cprintf("Canno topen file exiting");
		getch();
		return;
	}
bb:
	gotoxy(15, 8);
	cprintf("College Type(Eng-e/Med-m) : ");
	gotoxy(45,8);
	cin>>c1.ctype;
	//cprintf("%c",c1.ctype);
	if(c1.ctype=='m')
		flag=1;
	else if(c1.ctype=='e')
		flag=1;
	if(flag!=1)
	{
		gotoxy(15, 10);
		cprintf("Enter Type(Eng-e/Med-m), Press any key to continue");
		getch();
		flag=0;
		gotoxy(15, 10);
		cprintf("                                                    ");
		goto bb;
	}
	gotoxy(15, 9);
	cprintf("College Code        : ");
	gotoxy(40,9);
	cin>>c1.ccode;
	gotoxy(15, 10);
	cprintf("College Name        : ");
	gotoxy(40,10);
	cin>>c1.cname;
	gotoxy(15,11);
	cprintf("College Place        : ");
	gotoxy(40,11);
	cin>>c1.cplace;
	gotoxy(15,11);
	//f.write((char *)&c1,sizeof(c1));
	//f.close();
	fwrite((char *)&c1,sizeof(c1),1,fp);
	fclose(fp);
}
void college::show_college()
{
	//fstream f;
	int i;
	char pat[25];
	clrscr();
	//f.open("CAS/college.txt",ios::in);
	Cwindow w5(8,5,65,16);
	w5.setAttributes(LIGHTGRAY,BLACK,7,0);
	 w5.showWindow();
	_setcursortype(_NORMALCURSOR);
	textcolor(YELLOW);
	FILE *fp;
	fp=fopen("CAS/college.txt","r");
	if(fp==NULL)
	{
		gotoxy(15,8);
		cprintf("Cannot open file exiting");
		getch();
		return;
	}

	gotoxy(15,6);
	cout<<"Enter Search Term(use only small letters)";
	cin>>pat;
	gotoxy(15,8);
	cprintf("   Type           Code           Name           Place");
	textcolor(RED);
	i=9;
	//f.seekg(0,ios::beg);
	//while(f.read((char*)&c1,sizeof(c1)))
	while(fread((char *)&c1,sizeof(c1),1,fp))
	{
		if(college_search(c1.cname,pat)==1)

		{gotoxy(19,i);   cprintf("%c",c1.ctype);
		gotoxy(34,i);	cprintf("%d",c1.ccode);
		gotoxy(48,i);	cprintf("%s",c1.cname);
		gotoxy(66,i);  	cprintf("%s",c1.cplace);
		i++; }
	}
	//f.close();
	fclose(fp);
}


void computeLPSArray(char *pat, int M, int *lps);

int KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  // index for pat[]

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0;  // index for txt[]
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
	j++;
	i++;
      }

      if (j == M)
      {

	j = lps[j-1];
	return 1;
      }

      // mismatch after j matches
      else if (i < N && pat[j] != txt[i])
      {
	// Do not match lps[0..lps[j-1]] characters,
	// they will match anyway
	if (j != 0)
	 j = lps[j-1];
	else
	 i = i+1;
      }
    }
    free(lps); // to avoid memory leak
    return 0;
}

void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;  // length of the previous longest prefix suffix
    int i;

    lps[0] = 0; // lps[0] is always 0
    i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
	 len++;
	 lps[i] = len;
	 i++;
       }
       else // (pat[i] != pat[len])
       {
	 if (len != 0)
	 {
	   // This is tricky. Consider the example
	   // AAACAAAA and i = 7.
	   len = lps[len-1];

	   // Also, note that we do not increment i here
	 }
	 else // if (len == 0)
	 {
	   lps[i] = 0;
	   i++;
	 }
       }
    }
}

// Driver program to test above function
int college::college_search(char txt[25],char pat[25])
{
   if(KMPSearch(pat,txt)==1)
   {
       return 1;
   }
   else
    {return 0;}

}
// Function to delete a particular college //
void college::del_college()
{
	fstream f1,f2,f3,f4;
	int code,ff=0;
	f1.open("CAS/college.txt",ios::in);
	f2.open("CAS/temp1.txt",ios::in|ios::out|ios::app);
	f3.open("CAS/course.txt",ios::in);
	f4.open("CAS/temp2.txt",ios::in|ios::out|ios::app);
	Cwindow w5(8,5,65,16);
	w5.setAttributes(LIGHTGRAY,BLACK,7,0);
	w5.showWindow();
	_setcursortype(_NORMALCURSOR);
	textcolor(BLUE);
	gotoxy(15, 8);
	cprintf("Enter College Code    : ");
	gotoxy(45,8);
	cin>>code;
	f1.seekg(0,ios::beg);
	while(f1.read((char *)&c1,sizeof(c1)))
	{
		if(code==c1.ccode)
		{
			ff=1;
			gotoxy(15, 12);
			cprintf("Record Deleted !");
			getch();
		}
		else
			f2.write((char *)&c1,sizeof(c1));
	}
	if(ff==1)
	{
		f3.seekg(0,ios::beg);
		while(f3.read((char *)&co1,sizeof(co1)))
		{
			if(code==co1.ccode);
			else
				f4.write((char *)&co1,sizeof(co1));
		}
		f3.close();
		f4.close();
		remove("CAS/course.txt");
		rename("CAS/temp2.txt","CAS/course.txt");
		f1.close();
		f2.close();
		remove("CAS/college.txt");
		rename("CAS/temp1.txt","CAS/college.txt");
	}
	if(ff==0)
	{
		gotoxy(15, 12);
		cprintf("College Code does not exist! ");
		getch();
	}
}
// Function to Add a new course //
void course::add_course()
{
	fstream f1,f2;
	FILE *fp1,*fp2;
	int ff=0;
	int col_code,ts;
	char ty;
	long size;
	int n;
	f1.open("CAS/college.txt",ios::in);
	f2.open("CAS/course.txt",ios::in|ios::out|ios::app);
	Cwindow w5(8,5,65,16);
	w5.setAttributes(LIGHTGRAY,BLACK,7,0);
	 w5.showWindow();
	_setcursortype(_NORMALCURSOR);
	textcolor(BLUE);
	gotoxy(15, 8);
	cprintf("Enter the College Code: ");
	gotoxy(40,8);
	cin>>col_code;
	f1.seekg(0,ios::beg);
	while(f1.read((char *)&c1,sizeof(c1)))
	{
		if(col_code==c1.ccode)
		{
			ff=1;
			ty=c1.ctype;
			break;
		}
	}
	if(ff==0)
	{
		gotoxy(17, 12);
		cprintf("College Code Not Exist");
		goto last;
	}
	if(ty=='m')
	{
		gotoxy(18,18);
		cprintf("MBBS-22,BDS-32,BSc Nursing-42");
	}
	if(ty=='e')
	{
		gotoxy(18,18);
		cprintf("Mechanical -11,IT-21,Electrical-31");
	}
	co1.ccode=col_code;
	gotoxy(15, 9);
	cprintf("Enter Course Code   : ");
	gotoxy(40,9);
	cin>>co1.cocode;
	if(ty=='m')
	{
		if(co1.cocode!=22&&co1.cocode!=32&&co1.cocode!=42)
		{
			gotoxy(40,9);
			textcolor(RED);
			cprintf("Invalid course code!!!!");
			getch();
			add_course();
		}
	}
	if(ty=='e')
	{
		if(co1.cocode!=11&&co1.cocode!=21&&co1.cocode!=31)
		{
			gotoxy(40,9);
			textcolor(RED);
			cprintf("Invalid course code!!!!");
			getch();
			add_course();
		}
	}
	gotoxy(15, 10);
	cprintf("Enter Course Name   : ");
	gotoxy(40,10);
	cin>>co1.branch;
aa:
	gotoxy(15, 11);
	cprintf("Total Seat (30 Or 50): ");
	gotoxy(40,11);
	cin>>ts;
	if(ts!=30 && ts!=50)
	{
		gotoxy(40,11);
		cprintf("enter seat no 30 or 50");
		getch();
		gotoxy(40,11);
		cprintf("                      ");
		goto aa;
	}
	co1.ctype=ty;
	co1.seatno=ts;
	if(co1.seatno==50)
	{
		co1.mr_seat=25;
		co1.sc_seat=5;
		co1.obc_seat=5;
		co1.ez_seat=5;
		co1.mu_seat=5;
		co1.nc_seat=5;
	}
	if(co1.seatno==30)
	{
		co1.mr_seat=15;
		co1.sc_seat=3;
		co1.obc_seat=3;
		co1.ez_seat=3;
		co1.mu_seat=3;
		co1.nc_seat=3;
	}
	f2.write((char *)&co1,sizeof(co1));
	gotoxy(25,15);
	cprintf("Course details updated");
	getch();
last:
	f1.close();
	f2.close();
}
// Delete a particular course from a college
void course::del_course()
{
	fstream f1,f2;
	int code,ff=0;
	int c;
	f2.open("CAS/temp1.txt",ios::in|ios::out|ios::app);
	f1.open("CAS/course.txt",ios::in);
	Cwindow w5(8,5,65,16);
	w5.setAttributes(LIGHTGRAY,BLACK,7,0);
	w5.showWindow();
	_setcursortype(_NORMALCURSOR);
	textcolor(BLUE);
	_setcursortype(_NORMALCURSOR);
	textcolor(BLUE);
	gotoxy(15, 8);
	cprintf("Enter College Code    : ");
	gotoxy(45,8);
	cin>>code;
	gotoxy(15, 9);
	cprintf("Enter Course Code    : ");
	gotoxy(45,9);
	cin>>c;
	f1.seekg(0,ios::beg);
	while(f1.read((char *)&co1,sizeof(co1)))
	{
		if(code==co1.ccode && c==co1.cocode)
		{
			ff=1;
			gotoxy(15, 12);
			cprintf("Record Deleted !");
			getch();
		}
		else
			f2.write((char *)&co1,sizeof(co1));
	}
	if(ff==0)
	{
		gotoxy(15, 12);
		cprintf("No such Entry ! ");
		remove("CAS/temp1.txt");
		getch();
	}
	if(ff==1)
	{
		remove("CAS/course.txt");
		rename("CAS/temp1.txt","CAS/course.txt");
	}
	f1.close();
	f2.close();
}
// Function to show all courses //
void course::show_course()
{
	fstream f;
	int i;
	f.open("CAS/course.txt",ios::in|ios::binary);
	textcolor(RED);
	Cwindow w5(8,5,65,16);
	w5.setAttributes(LIGHTGRAY,BLACK,7,0);
	w5.showWindow();
	_setcursortype(_NORMALCURSOR);
	textcolor(BLACK);
	gotoxy(9,8);
	cprintf("CollegeCode CourseCode  Branch TotalSeat  MR  SC  OBC  EZ  MU  NC");
	textcolor(BLUE);
	i=9;
	f.seekg(0,ios::beg);
	while(f.read((char*)&co1,sizeof(co1)))
	{
		gotoxy(15,i);   cprintf("%d",co1.ccode);
		gotoxy(26,i);	cprintf("%d",co1.cocode);
		gotoxy(33,i);	cprintf("%s",co1.branch);
		gotoxy(43,i);	cprintf("%d",co1.seatno);
		gotoxy(52,i);   cprintf("%d",co1.mr_seat);
		gotoxy(56,i);   cprintf("%d",co1.sc_seat);
		gotoxy(60,i);   cprintf("%d",co1.obc_seat);
		gotoxy(65,i);   cprintf("%d",co1.ez_seat);
		gotoxy(69,i);   cprintf("%d",co1.mu_seat);
		gotoxy(72,i);   cprintf("%d",co1.nc_seat);
		i++;
	}
	f.close();
}
// Function to read student details  //
void allotment::read_details()
{
	int ff=0;
	int cocode;
	fstream f,f1;
	f.open("CAS/allot.txt",ios::in|ios::out|ios::app);
	f1.open("CAS/course.txt",ios::in);
	Cwindow w5(8,5,65,16);
	w5.setAttributes(LIGHTGRAY,BLACK,7,0);
	w5.showWindow();
	_setcursortype(_NORMALCURSOR);
	textcolor(BLUE);
	gotoxy(15, 8);
	cprintf("Enter Branch (e/m): ");
	gotoxy(40,8);
	cin>>a1.ctype;
	gotoxy(15, 9);
	gotoxy(15, 10);
	cprintf("Course Code        : ");
	gotoxy(40,10);
	cin>>cocode;
	f1.seekg(0,ios::beg);
	while(f1.read((char *)&co1,sizeof(co1)))
	{
		if(co1.cocode==cocode)
		{
			ff=1;
			break;
		}
	}
	if(ff==1)
	{
		a1.cocode=cocode;
		gotoxy(15, 11);
		cprintf("Student Name        : ");
		gotoxy(40,11);
		cin>>a1.st_name;
		gotoxy(15, 12);
		cprintf("Rank No             : ");
		gotoxy(40,12);
		cin>>a1.rankno;
		gotoxy(15, 13);
		cprintf("Reservation Type  : ");
		gotoxy(15,24);
		cprintf("1 - SC, 2 - OBC, 3 - EZ, 4 - MU, 5 - NC ! ");
		gotoxy(40,13);
		cin>>a1.res_type;
		f.write((char *)&a1,sizeof(a1));
		gotoxy(20,20);
		cprintf("Request details received");
		getch();
	}
	else if(ff==0)
	{
		gotoxy(30,12);
		cprintf("No such course on this college");
		getch();
	}
	f.close();
	f1.close();
}
	// Function to allot seats to the students //
void request::col_request()
{
	fstream freq;
	freq.open("CAS/request.txt",ios::in|ios::out|ios::app);
	Cwindow w5(8,5,65,16);
	w5.setAttributes(LIGHTGRAY,BLACK,7,0);
	w5.showWindow();
	_setcursortype(_NORMALCURSOR);
	textcolor(YELLOW);
	_setcursortype(_NORMALCURSOR);
	textcolor(BLUE);
	gotoxy(15, 8);
	cprintf("Enter Rank No:");
	gotoxy(40,8);
	cin>>req.rkno;
	gotoxy(15, 9);
	cprintf("Enter 3 Colleges you wish to join:");
	gotoxy(15,10);
	cprintf("Your First Choice:");
	gotoxy(40, 10);
	cin>>req.col1;
	gotoxy(15,11);
	cprintf("Your Second Choice:");
	gotoxy(40, 11);
	cin>>req.col2;
	gotoxy(15,12);
	cprintf("Your Third Choice:");
	gotoxy(40,12);
	cin>>req.col3;
	freq.write((char *)&req,sizeof(req));
	freq.close();
}
void allotment::allot_seat()
{
	fstream freq,ft,fcour,fallot,fstud,ftemp;
	freq.open("CAS/request.txt",ios::in);
	fcour.open("CAS/course.txt",ios::in|ios::binary);
	fallot.open("CAS/allot.txt",ios::in);
	ft.open("CAS/modify.txt",ios::app|ios::out);
	ftemp.open("CAS/temp.txt",ios::out);
	int rk1,nd=1,p,md=0;
	int col[3],colg,cour,rtype;
	int coscode,stno,mrst,scst,obc,ez,mu,nc;
	char brh[30],type;
	Cwindow w5(8,5,65,16);
	w5.setAttributes(LIGHTGRAY,BLACK,7,0);
	w5.showWindow();
	_setcursortype(_NORMALCURSOR);
	textcolor(RED);
	gotoxy(15, 8);
	cprintf("Enter Rank No:");
	gotoxy(40,8);
	cin>>rk1;
	freq.seekg(0,ios::beg);
	while(freq.read((char*)&req,sizeof(req)))
	{
		if(rk1==req.rkno)
		{
			col[0]=req.col1;
			col[1]=req.col2;
			col[2]=req.col3;
		}
	}
	freq.close();
	fallot.seekg(0,ios::beg);
	while(fallot.read((char*)&a1,sizeof(a1)))
	{
		if(rk1==a1.rankno)
		{
			rtype=a1.res_type;
			coscode=a1.cocode;
		}
	}
	fallot.close();
	p=0;
    cont:
	fcour.seekg(0,ios::beg);
	while(fcour.read((char *)&co1,sizeof(co1)))
	{
		if(coscode==co1.cocode&&col[p]==co1.ccode)
		{
			md=1;
			type=co1.ctype;
			colg=co1.ccode;
			cour=co1.cocode;
			strcpy(brh,co1.branch);
			stno=co1.seatno;
			mrst=co1.mr_seat;
			scst=co1.sc_seat;
			obc=co1.obc_seat;
			ez=co1.ez_seat;
			mu=co1.mu_seat;
			nc=co1.nc_seat;
			gotoxy(21,14);	cprintf("merit: %d",mrst);
			gotoxy(21,15);	cprintf("seat : %d",stno);
		}else{
			ft.write((char *)&co1,sizeof(co1));
		}
	 }
	 fcour.close();
	 ft.close();
	 if(md==1)
	 {
		gotoxy(21,16);	cprintf("flag: %d",md);
		if(mrst>0)
		{
			mrst--;
		}else
		{
			switch(rtype)
			{
				case 1:
					if(scst>0)
					{
						scst--;
					}else
						nd=0;
					break;
				case 2:
					 if(obc>0)
					 {
						obc--;
					}else
						nd=0;
					break;
				case 3:
					 if(ez>0)
					 {
						ez--;
					}else
						nd=0;
					break;
				case 4:
					if(mu>0)
					{
						mu--;
					}else
						nd=0;
					break;
				case 5:
					 if(nc>0)
					 {
						nc--;
					 }else
						nd=0;
					 break;
					}
			}
			ft.open("CAS/modify.txt",ios::app|ios::out);
			co1.ctype=type;
			co1.ccode=colg;
			co1.cocode=cour;
			strcpy(co1.branch,brh);
			co1.seatno=stno;
			co1.mr_seat=mrst;
			co1.sc_seat=scst;
			co1.obc_seat=obc;
			co1.ez_seat=ez;
			co1.mu_seat=mu;
			co1.nc_seat=nc;
			gotoxy(21,20);	cprintf("cocode  : %d",co1.cocode);
			ft.write((char *)&co1,sizeof(co1));
		}
		ft.close();
		remove("CAS/course.txt");
		rename("CAS/modify.txt","CAS/course.txt");
		if(nd==0)
		{
			p++;
			goto cont;
		}
		if(nd==1)
		{
			fallot.open("CAS/allot.txt",ios::in);
			fallot.seekg(0,ios::beg);
			 while(fallot.read((char *)&a1,sizeof(a1)))
			 {
				if(rk1==a1.rankno)
				{
					 fstud.open("CAS/stud_list.txt",ios::out|ios::app);
					 a1.ccode=col[p];
					 fstud.write((char *)&a1,sizeof(a1));
					 gotoxy(14,17);
					 cprintf("Seat Alloted");
				}else
				{
					 ftemp.write((char *)&a1,sizeof(a1));
				}
			 }
			 ftemp.close();
		}
		remove("CAS/allot.txt");
		rename("CAS/temp.txt","CAS/allot.txt");
		fallot.close();
		fstud.close();
}
void allotment::display_allotment()
{
	fstream fstud;
	char br;
	Cwindow w5(8,5,65,16);
	w5.setAttributes(LIGHTGRAY,BLACK,7,0);
	 w5.showWindow();
	_setcursortype(_NORMALCURSOR);
	textcolor(YELLOW);
	gotoxy(15, 8);
	int i;
     fstud.open("CAS/stud_list.txt",ios::in);
	textcolor(RED);
	gotoxy(15,8);
	cprintf("Rank No   Name    Course Code  College Code ");
	textcolor(BLUE);
	i=9;
	fstud.seekg(0,ios::beg);
	while(fstud.read((char*)&a1,sizeof(a1)))
	{

		gotoxy(18,i);	cprintf("%d",a1.rankno);
		gotoxy(24,i);	cprintf("%s",a1.st_name);
		gotoxy(37,i);   cprintf("%d",a1.cocode);
		gotoxy(51,i);   cprintf("%d",a1.ccode);
		i++;
	}
	fstud.close();
}
