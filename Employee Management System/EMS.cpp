// Employee Management System With File Handling in C++.
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<fstream>
#include<windows.h>
using namespace std;
class emp
{
	public:
		int emp_id,sal;
		string name,address,phone;
		void menu();
		void insert();
		void display();
		void search();
		void modify();
		void del();
		void group();
		void search_group();
		void show_group();
		void check_attendence();
		void search_attendence();
};
class child:public emp
{
	public:
		void login();
		void main_menu();
		void child_menu();
		void attendence();
}obj;
	void intro()
	{
		system("cls");
		cout<<"\n\n\n\n\n\n\n";
		cout<<"\t\t\t==============================";
		cout<<"\n\t\t\t==============================";
		cout<<"\n\n\t\t\t  Employee Management System";
		cout<<"\n\n\t\t\t==============================";
		cout<<"\n\t\t\t==============================";
		getch();
		system("cls");
		cout<<"\n\n\n";
		cout<<"\t\t\t===================================================";
		cout<<"\n\t\t\t===================================================";
		cout<<"\n\n\t\t\t\t\t   Introduction";
		cout<<"\n\n\t\t\t===================================================";
		cout<<"\n\t\t\t===================================================";
		cout<<"\n\n\t\t\t Name        :   Arfan Uddin";
		cout<<"\n\t\t\t ID No.      :   221-35-888";
		cout<<"\n\t\t\t Section     :   D";
		cout<<"\n\t\t\t Department  :   Software Engineering";
		cout<<"\n\t\t\t Institute   :   Daffodil International University";
		cout<<"\n\n\t\t\t===================================================";
		cout<<"\n\t\t\t===================================================";
		getch();
	}
	void child::login()
	{
		p:
		system("cls");
		char ch;
		string user,pass;
		cout<<"\n\n\n";
		cout<<"\n\n\t\t\t=============================";
		cout<<"\n\n\t\t\t        Login Process";
		cout<<"\n\n\t\t\t=============================";
		cout<<"\n\n\n Enter User Name : ";
		cin>>user;
		cout<<"\n\n Enter Password : ";
		for(int i=0; i < 3; i++)
		{
			pass+= getch();
			cout<<"*";
		}
		if(user == "Arfan" && pass == "888")
		{
			cout<<"\n\n\n\t\t\tCongratulation Login Successfully...";
			cout<<"\n\n\n\t\t\t\t\tLoading";
			for(int i=1;i<=6;i++)
			{
				Sleep(500);
				cout<<".";
			}
			emp::menu();
		}
		else if(user != "Arfan" && pass == "888")
		{
			cout<<"\n\n\n Your User Name is Wrong....";
			getch();
			goto p;
		}
		else if(user == "Arfan" && pass != "888")
		{
			cout<<"\n\n\n Your Password is Wrong....";
			getch();
			goto p;
		}
		else
		{
			cout<<"\n\n\n User Name & Password Both are Wrong....";
		}
	}
	void child::main_menu()
	{
		p:
		int choice;
		system("cls");
		cout<<"\n\n\t\t\t=====================";
		cout<<"\n\n\t\t\t    Control Panel";
		cout<<"\n\n\t\t\t=====================";
		cout<<"\n\n 1. Admin";
		cout<<"\n 2. Employee";
		cout<<"\n 3. Exit";
		cout<<"\n\n Enter Your Choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				login();
				break;
			case 2:
				child_menu();
				break;
			case 3:
				exit(0);
			default:
				cout<<"\n\n Invalid Value...Please Try Again...";
		}
		getch();
		goto p;
	}
	void child::child_menu()
	{
		p:
		int choice;
		system("cls");
		cout<<"\n\n\t\t\t======================";
		cout<<"\n\n\t\t\t    Employee Panel";
		cout<<"\n\n\t\t\t======================";
		cout<<"\n\n 1. Attendence";
		cout<<"\n 2. Check Details";
		cout<<"\n 3. Go Back";
		cout<<"\n\n Enter Your Choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				attendence();
				break;
			case 2:
				emp::search();
				break;
			case 3:
				main_menu();
			default:
				cout<<"\n\n Invalid Value...Please Try Again...";
		}
		getch();
		goto p;
	}
	void emp::menu()
	{
		p:
		system("cls");
		int x;
		cout<<"\n\n\t\t\t===========================";
		cout<<"\n\n\t\t\t    Admin Control Panel";
		cout<<"\n\n\t\t\t===========================";
		cout<<"\n\n\n 1. Insert Record";
		cout<<"\n 2. Display Record";
		cout<<"\n 3. Check Attendence";
		cout<<"\n 4. Search Attendence";
		cout<<"\n 5. Search Record";
		cout<<"\n 6. Modify Record";
		cout<<"\n 7. Delete Record";
		cout<<"\n 8. Go Back";
		cout<<"\n\n Your Choice : ";
		cin>>x;
		switch(x)
		{
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				check_attendence();
				break;
			case 4:
				search_attendence();
				break;
			case 5:
				search();
				break;
			case 6:
				modify();
				break;
			case 7:
				del();
				break;
			case 8:
				obj.main_menu();
			default:
				cout<<"\n\n Invalid Value...Please try Again...";
		}
		getch();
		goto p;
	}
main()
{
	intro();
	obj.main_menu();
}
