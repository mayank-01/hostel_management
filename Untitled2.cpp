#include<iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<string.h>
#include<stdio.h>
#include<process.h>
using namespace std;

class hostel
{
	char sname[20],fatname[20],motname[20],dept[30],droll[12], year[30],peradd[40],gdname[20],gdadd[40];
	char snum[15],fatnum[15],motnum[15],gdnum[15], dob[15], gender[10];
	int Distance, room_no, floor;
	char hostel_no[4], block, hroll[4];
	public:
	void main_menu();
	void getInfo();
	void showData();
	void addData();
	void displayInfo();
	void displayInfo1();
	void login();
	void allot();
	void roomDetails();
	void search();
	void update();
	void deleteStudent();
	void fees();
}h ;

class mess{
	char hroll[4], month[20];
	int extra, bill, diets;
	public:
		void addBill();
		void getBill();
		void showBill();
		void displayBill();
	
}m;

void hostel::addData()
{
	 ofstream fout;
	 fout.open("Temp.txt",ios::binary|ios::out|ios::app);
	 h.getInfo();
	 fout.write((char*)&h,sizeof(h));
	 fout.close();
	 cout<<"\n\nData Successfully Saved to File....\n";
}

void hostel::getInfo()
	{
	  	cout<<setw(70);
		cout<<"\n\n\t\t\t Welcome to Student Information Module"<<endl;
		cout<<"\n";
		
		cin.ignore();
		cout<<" Student's Name:-"<<"\t\t";   
		gets(sname);
		cout<<" Father's Name:-"<<"\t\t";
		gets(fatname);
		cout<<" Mother's Name:-"<<"\t\t";
		gets(motname); 
		cout<<" Date of Birth(dd/mm/yy):-"<<"\t\t";   
		gets(dob);
		cout<<" Gender:-"<<"\t\t";   
		gets(gender);
		cout<<" Name Of The Department:-\t\t";
		gets(dept);
		cout<<" Department Roll No.:-\t\t";
		gets(droll);
		cout<<" Enter the year:-"<<"\t\t";
		gets(year);
		cout<<" Permanent Address:-"<<"\t\t";
		gets(peradd);
		cout<<" Name of Local Guardian:-\t";
		gets(gdname);
		cout<<" Address Of Local Guardian:-\t";
		gets(gdadd);
		cout<<" Student's Mobile Number:-\t";
		gets(snum);
		cout<<" Father's Mobile Number:-\t";
		gets(fatnum);
		cout<<" Mother's Mobile Number:-\t";
		gets(motnum); 
		cout<<" Guardian's Mobile Number:-\t";
		gets(gdnum);
		cout<<"Distance of University from Your Permanent Address(in Kilometres):-\t";
		cin>>Distance;
		
		system("pause");	
	}
	
	
void hostel::showData(){
	 ifstream fin;
	 fin.open("Record.txt",ios::in|ios::binary);
	 while(fin.read((char*)&h,sizeof(h)))
	 {
	  h.displayInfo();
	 }
	 fin.close();
	 cout<<"\n\nData Reading from File Successfully Done....\n";
		
	}

void hostel::displayInfo1()
{
	 cout<<"\n\n.......Student Details......\n";
	cout<<" Student's Name:-            "<<sname<<endl;   
	cout<<" Father's Name:-             "<<fatname<<endl;
	cout<<" Mother's Name:-             "<<motname<<endl;
	cout<<" Date Of Birth:-             "<<dob<<endl;
	cout<<" Gender:-                    "<<gender<<endl;
	cout<<" Name Of The Department:-    "<<dept<<endl;
	cout<<" Department Roll No.         "<<droll<<endl;
	cout<<" Enter the year:-            "<<year<<endl;
	cout<<" Permanent Address:-         "<<peradd<<endl;
	cout<<" Name of Local Guardian:-    "<<gdname<<endl;
	cout<<" Address Of Local Guardian:- "<<gdadd<<endl;
	cout<<" Student's Mobile Number:-   "<<snum<<endl;	
	cout<<" Father's Mobile Number:-    "<<fatnum<<endl;
	cout<<" Mother's Mobile Number:-    "<<motnum<<endl;
	cout<<" Guardian's Mobile Number:-  "<<gdnum<<endl;
	cout<<" Distance of University from \nYour Permanent Address(in Kilometres):-"<<Distance<<endl; 
}

void hostel::displayInfo()
{
	 cout<<"\n\n.......Student Details......\n";
	cout<<" Student's Name:-            "<<sname<<endl;   
	cout<<" Father's Name:-             "<<fatname<<endl;
	cout<<" Mother's Name:-             "<<motname<<endl;
	cout<<" Date Of Birth:-             "<<dob<<endl;
	cout<<" Gender:-                    "<<gender<<endl;
	cout<<" Name Of The Department:-    "<<dept<<endl;
	cout<<" Department Roll No.         "<<droll<<endl;
	cout<<" Enter the year:-            "<<year<<endl;
	cout<<" Permanent Address:-         "<<peradd<<endl;
	cout<<" Name of Local Guardian:-    "<<gdname<<endl;
	cout<<" Address Of Local Guardian:- "<<gdadd<<endl;
	cout<<" Student's Mobile Number:-   "<<snum<<endl;	
	cout<<" Father's Mobile Number:-    "<<fatnum<<endl;
	cout<<" Mother's Mobile Number:-    "<<motnum<<endl;
	cout<<" Guardian's Mobile Number:-  "<<gdnum<<endl;
	cout<<" Distance of University from \nYour Permanent Address(in Kilometres):-"<<Distance<<endl;
	cout<<"\n\n........Hostel Details........\n";
	cout<<" Hostel No.:-    "<<hostel_no<<endl;
	cout<<" Hostel Roll No.:-    "<<hroll<<endl;
	cout<<" Block:-  "<<block<<endl;
	cout<<" Floor No.:-"<<floor<<endl;
	cout<<" Room No.:-"<<room_no<<endl;
}

void hostel::allot()
{
	ifstream fin;
	fin.open("Temp.txt",ios::in|ios::binary);
	ofstream fout;
	fout.open("Record.txt",ios::binary|ios::out|ios::app);
	 
	 while(fin.read((char*)&h,sizeof(h)))
	 {
	  h.displayInfo1();
	  cout<<"\nPress any key to enter data";
	  getch();
	  h.roomDetails();
	  fout.write((char*)&h,sizeof(h));
	 }
	 fin.close();
	 fout.close();
	 remove("Temp.txt");
}

void hostel::roomDetails(){
	system("cls");
	cout<<"\n\n\t\t\t Welcome to Room Allotment Section"<<endl;
	cout<<"\n";
	cout<<"Enter Hostel No.:-         ";
	cin>>hostel_no;
	cout<<"Enter Hostel Roll No.:-    ";
	cin>>hroll;
	cout<<"Enter Block:-              ";
	cin>>block;
	cout<<"Floor No.:-                ";
	cin>>floor;
	cout<<"Enter Room No:-            ";
	cin>>room_no;
}

void hostel::search(){
	char r[20];
	cout<<"\n\nEnter Your Department or Hostel Roll No.:  ";
	cin>>r;
	int flag=0;
	ifstream inf, fin;
	inf.open("Record.txt",ios::binary|ios::in|ios::app);
	fin.open("Temp.txt",ios::binary|ios::in|ios::app);
	
	while(inf.read((char*)&h,sizeof(h)))
	{
		if(stricmp(r, h.hroll)==0 || stricmp(r, h.droll)==0)
		{
			h.displayInfo();
			flag=1;
		}
	}
	while(fin.read((char*)&h,sizeof(h)))
	{
		if(stricmp(r, h.droll)==0)
		{
			h.displayInfo1();
			flag=1;
		}
	}
	if(flag==0){
		cout<<"\n\nStudent with Roll No. "<<r<<" not found.\n\n";
	}
}

void hostel::deleteStudent(){
	ifstream inf;
	inf.open("Record.txt", ios::binary|ios::in|ios::app);
	ofstream outf;
	outf.open("Temp_delete.txt", ios::binary|ios::out|ios::app);
	char r[10];
	int flag=0;
	cout<<"\nEnter Hostel Roll No.:- ";
	cin>>r;
	while(inf.read((char*)&h, sizeof(h)))
	{
		if(stricmp(r, h.hroll)==0)
		{
			cout<<"\n The following Student data will be deleted: \n\n";
			h.displayInfo();
			flag =1;
		}
		else{
			outf.write((char*)&h, sizeof(h));
		}
	}
	inf.close();
	outf.close();
	if(flag==0)
		{
			cout<<"\nStudent with Roll No. "<<r<<" not found";
		}
	remove("Record.txt");
	rename("Temp_delete.txt", "Record.txt");
}

void hostel::update(){
	int flag=0, pos;
	char r[10];
	fstream fio;
	fio.open("Record.txt",ios::in|ios::out|ios::binary);
	 
	cout<<"Enter Hostel Roll Number you want to Modify : ";
	cin>>r;
	 
	while(fio.read((char*)&h,sizeof(h)))
	{
	 pos=fio.tellg();
	 if(stricmp(r, h.hroll)==0)
	 {
	  cout<<"The Following Admission No. "<<r<<" will be modified with new data:\n";
	  h.displayInfo();
	  cout<<"\n\nNow Enter the New Details....\n";
	  h.getInfo();
	  fio.seekg(pos-sizeof(h));
	  fio.write((char*)&h,sizeof(h));
	  flag++;
	 }
 	}
	fio.close();
	 
	if(flag==0)
		 cout<<"The Admission No. "<<r<<" not found....\n\n";
}

void hostel::fees()
{
	int count=0, num, total, total_mess;
	ifstream fin;
	fin.open("Record.txt",ios::in|ios::binary);
	while(fin.read((char*)&h,sizeof(h)))
	{
	 count++;
	}
	fin.close();
	cout<<"\n\n\t\t...........Fees Information Module............\n\n";
	cout<<"\n\n\t\t\t\tTotal No. of Students:-   "<<count<<endl;
	cout<<"\t\t\t\tTotal Fees in Account:-   "<<count*19550<<endl;
	cout<<"\t\t\t\tTotal Mess Security:-    "<<count*6000<<endl<<endl;
}

void mess::addBill()
{
	 ofstream fout;
	 fout.open("Mess.txt",ios::binary|ios::out|ios::app);
	 m.getBill();
	 fout.write((char*)&m,sizeof(m));
	 fout.close();
	 cout<<"\n\nData Successfully Saved to File....\n";
}

void mess::getBill(){
	cout<<"\n\n\t\t\t...........Mess Information Module............\n\n";
	ifstream fin;
	fin.open("Mess.txt",ios::in|ios::binary);
	int flag=0;
	cout<<"Enter Hostel Roll No.:-     ";
	cin>>hroll;
	cout<<"Enter Month:-               ";
	cin>>month;
	cout<<"Enter Diets:-               ";
	cin>>diets;
	cout<<"Enter Extras:-              ";
	cin>>extra;
	bill = (diets * 32) + extra;
}

void mess::showBill(){
	 ifstream fin;
	 fin.open("Mess.txt",ios::in|ios::binary);
	 char r[5];
	 int flag=0;
	 cout<<"\nEnter Hostel Roll No.:-     ";
	 cin>>r;
	 while(fin.read((char*)&m,sizeof(m)))
	 {
	 	if(stricmp(m.hroll, r)==0){
			m.displayBill();
			flag=1;
		}
	 }
	 fin.close();
	 if(flag==0){
	 	cout<<"\n\nStudent with roll no. "<<r<<" not found.";
	 }
	 cout<<"\n\nData Reading from File Successfully Done....\n";
		
	}

void mess::displayBill(){
	cout<<"\n\n\t\t\t======"<<month<<"======\n\n";
	cout<<"Diets:          "<<diets<<endl;
	cout<<"Extras:         "<<extra<<endl;
	cout<<"Bill:           "<<bill<<endl;
}

void hostel::main_menu()
{

	system("cls");
	
	cout<<endl;

	cout<<"\n\n\t\t\t 0. Exit"<<endl;
	cout<<"\n\n\t\t\t 1. Allot Room"<<endl;
	cout<<"\n\n\t\t\t 2. View Student Information"<<endl;
	cout<<"\n\n\t\t\t 3. Search Student"<<endl;
	cout<<"\n\n\t\t\t 4. Delete Student"<<endl;
	cout<<"\n\n\t\t\t 5. Update Student Data"<<endl;
	cout<<"\n\n\t\t\t 6. Add Mess Information"<<endl;
	cout<<"\n\n\t\t\t 7. View Mess Information"<<endl;
	cout<<"\n\n\t\t\t 8. View Fees and Stats"<<endl;
	int choice;
	cout<<"\n\n\t\t\t Enter your choice: ";
	cin>>choice;
	
	if(choice==0){
		system("cls");
		system("pause");
		return;
	}
	else if(choice==1)
	{
		system("cls");
		h.allot();
		system("pause");
		main_menu();
	}
	else if (choice==2)
	{
		system("cls");
		h.showData();
		system("pause");
		main_menu();
	}
	else if (choice==3)
	{
		system("cls");
		h.search();
		system("pause");
		main_menu();
	}
	else if (choice==4)
	{
		system("cls");
		h.deleteStudent();
		system("pause");
		main_menu();
	}
	else if (choice==5)
	{
		system("cls");
		h.update();
		system("pause");
		main_menu();
	}
	else if(choice==6)
	{
		system("cls");
		m.addBill();
		system("pause");
		main_menu();
	}
	else if(choice==7)
	{
		system("cls");
		m.showBill();
		system("pause");
		main_menu();
	}
	else if(choice==8)
	{
		system("cls");
		h.fees();
		system("pause");
		main_menu();
	}
}

void hostel::login()
{
	char user[30], pass[30];
	cout<<"Enter UserName: ";
	cin>>user;
	cout<<"Enter Password: ";
	cin>>pass;
	if(stricmp(user,"abc12")==0 && stricmp(pass,"qwerty")==0)
	{
		main_menu();
	}
	else
	{
		cout<<"\n\nIncorrect Username or Password. Press any key to try again!";
		getch();
		system("cls");
		login();
	}
}

menu()
{
	hostel h1;
	mess m1;
	system("cls");
	cout<<"\n\n\t\t=========================== HOSTEL MANAGEMENT SYSYTEM ==========================\n\n";
	cout<<"\n\n\t\t1. Administration Login:\n";
	cout<<"\n\n\t\t2. Enter Data To Register:\n";
	cout<<"\n\n\t\t3. View Your Data:\n";
	cout<<"\n\n\t\t4. View Mess Info:\n";
	int choice;
	cout<<"\n\n\t\tEnter Your Choice: ";
	cin>>choice;
	
	if(choice==1)
	{
		system("cls");
		h1.login();
		system("pause");
		menu();
	}
	else if(choice==2)
	{
		system("cls");
		h1.addData();
		system("pause");
		menu();
	}
	else if (choice==3)
	{
		system("cls");
		h1.search();
		system("pause");
		menu();
	}
	else if (choice==4)
	{
		system("cls");
		m1.showBill();
		system("pause");
		menu();
	}
}
int main()
{
	menu();
	getch();
	return 0;
}
