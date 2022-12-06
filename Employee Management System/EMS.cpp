// Employee Management System With File Handling in C++.
#include <bits/stdc++.h>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <windows.h>
using namespace std;
class emp
{

public:
	int emp_id, sal;
	string name, address, phone;
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
class child : public emp
{
public:
	void login();
	void main_menu();
	void child_menu();
	void attendence();
} obj;
void intro()
{
	system("cls");
	cout << "\n\n\n\n\n\n\n";
	cout << "\t\t\t==============================";
	cout << "\n\t\t\t==============================";
	cout << "\n\n\t\t\t  Employee Management System";
	cout << "\n\n\t\t\t==============================";
	cout << "\n\t\t\t==============================";
	getch();
	system("cls");
	cout << "\n\n\n";
	cout << "\t\t\t===================================================";
	cout << "\n\t\t\t===================================================";
	cout << "\n\n\t\t\t\t\t   Introduction";
	cout << "\n\n\t\t\t===================================================";
	cout << "\n\t\t\t===================================================";
	cout << "\n\n\t\t\t Name        :   Arfan Uddin";
	cout << "\n\t\t\t ID No.      :   221-35-888";
	cout << "\n\t\t\t Section     :   D";
	cout << "\n\t\t\t Department  :   Software Engineering";
	cout << "\n\t\t\t Institute   :   Daffodil International University";
	cout << "\n\n\t\t\t===================================================";
	cout << "\n\t\t\t===================================================";
	getch();
}
void child::login()
{
p:
	system("cls");
	emp::menu();
	/*char ch;
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
			Sleep(300);
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
	}*/
}
void child::main_menu()
{
p:
	int choice;
	system("cls");
	cout << "\n\n\t\t\t=====================";
	cout << "\n\n\t\t\t    Control Panel";
	cout << "\n\n\t\t\t=====================";
	cout << "\n\n 1. Admin";
	cout << "\n 2. Employee";
	cout << "\n 3. Exit";
	cout << "\n\n Enter Your Choice (1-3): ";
	cin >> choice;
	switch (choice)
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
		cout << "\n\n\t\t\t Invalid Choice, Please try Again...";
	}
	getch();
	goto p;
}
void child::child_menu()
{
p:
	int choice;
	system("cls");
	cout << "\n\n\t\t\t======================";
	cout << "\n\n\t\t\t    Employee Panel";
	cout << "\n\n\t\t\t======================";
	cout << "\n\n 1. Attendence";
	cout << "\n 2. Check Details";
	cout << "\n 3. Go Back";
	cout << "\n\n Enter Your Choice (1-3) : ";
	cin >> choice;
	switch (choice)
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
		cout << "\n\n\t\t\t Invalid Choice, Please Try Again...";
	}
	getch();
	goto p;
}
void emp::menu()
{
p:
	system("cls");
	int x;
	cout << "\n\n\t\t\t===========================";
	cout << "\n\n\t\t\t    Admin Control Panel";
	cout << "\n\n\t\t\t===========================";
	cout << "\n\n\n 1. Insert Record";
	cout << "\n 2. Display Record";
	cout << "\n 3. Check Attendence";
	cout << "\n 4. Search Attendence";
	cout << "\n 5. Search Record";
	cout << "\n 6. Modify Record";
	cout << "\n 7. Delete Record";
	cout << "\n 8. Go Back";
	cout << "\n\n Enter Your Choice (1-8) : ";
	cin >> x;
	switch (x)
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
		cout << "\n\n\t\t\t Invalid Choice, Please try Again...";
	}
	getch();
	goto p;
}
void child::attendence()
{
	system("cls");
	fstream file;
	int test_id, found = 0, a_date, a_month, a_year, t_id, count = 0;
	SYSTEMTIME x;
	cout << "\n\n\t\t\tEmployee Attendence";
	file.open("D://Arfan_s Capstone Project/Employee Management System/emp.txt", ios::in);
	if (!file)
	{
		cout << "\n\n File Opening Error....";
	}
	else
	{
		cout << "\n\n Employee ID : ";
		cin >> test_id;
		file >> emp_id >> name >> sal >> address >> phone;
		while (!file.eof())
		{
			if (test_id == emp_id)
				found = 1;
			file >> emp_id >> name >> sal >> address >> phone;
		}
		file.close();
		if (found)
		{
			GetSystemTime(&x);
			file.open("D://Arfan_s Capstone Project/Employee Management System/attendence.txt", ios::in);
			if (!file)
			{
				file.open("D://Arfan_s Capstone Project/Employee Management System/attendence.txt", ios::app | ios::out);
				file << test_id << " " << x.wDay << " " << x.wMonth << " " << x.wYear << "\n";
				file.close();
				cout << "\n\n\t\t\t Your Attendence Added Successfully...";
			}
			else
			{
				file >> t_id >> a_date >> a_month >> a_year;
				while (!file.eof())
				{
					if (test_id == t_id && a_date == x.wDay && a_month == x.wMonth && a_year == x.wYear)
					{
						cout << "\n\n\t\t\t Your Attendence Already Added...";
						count = 1;
					}
					file >> t_id >> a_date >> a_month >> a_year;
				}
				file.close();
				if (count == 0)
				{
					file.open("D://Arfan_s Capstone Project/Employee Management System/attendence.txt", ios::app | ios::out);
					file << test_id << " " << x.wDay << " " << x.wMonth << " " << x.wYear << "\n";
					file.close();
					cout << "\n\n\t\t\t Your Attendence Added Successfully...";
				}
			}
		}
		else
			cout << "\n\n\t\t\t Invalid Employee ID....";
	}
}
void emp::check_attendence()
{
	system("cls");
	fstream file, file1;
	int m, y, a_date, a_month, a_year, t_id, count = 0;
	char ch;
	cout << "\n\n\t\t\tCheck Employee Attendence";
	file.open("D://Arfan_s Capstone Project/Employee Management System/emp.txt", ios::in);
	file1.open("D://Arfan_s Capstone Project/Employee Management System/attendence.txt", ios::in);
	if (!file || !file1)
	{
		cout << "\n\n File Opening Error...";
	}
	else
	{
		cout << "\n\n Year (yyyy) : ";
		cin >> y;
		cout << " Month (mm)  : ";
		cin >> m;
		file1.close();
		system("cls");
		cout << "\n\n\t   Attendence Of " << m << "/" << y;
		cout << "\n\n ========================================\n";
		cout << " " << left << setw(8) << "ID" << setw(12) << left << "Name" << setw(7) << "Present" << right << setw(13) << "Absent" << endl;
		cout << " ========================================\n";
		file >> emp_id >> name >> sal >> address >> phone;
		while (!file.eof())
		{
			file1.open("D://Arfan_s Capstone Project/Employee Management System/attendence.txt", ios::in);
			file1 >> t_id >> a_date >> a_month >> a_year;
			while (!file1.eof())
			{
				if (emp_id == t_id && m == a_month && y == a_year)
					count++;
				file1 >> t_id >> a_date >> a_month >> a_year;
			}
			file1.close();
			cout << " " << left << setw(8) << emp_id << left << setw(12) << name << right << setw(7) << count << right << setw(13) << 30 - count << endl;
			count = 0;
			file >> emp_id >> name >> sal >> address >> phone;
		}
		cout << "\n\n\t\t Press Any Key To Continue...";
		file.close();
	}
}
void emp::search_attendence()
{
	system("cls");
	fstream file, file1;
	int d, m, y, a_date, a_month, a_year, t_id, count = 0, present = 0;
	cout << "\n\n\t\t\tCheck Employee Attendence";
	file.open("D://Arfan_s Capstone Project/Employee Management System/emp.txt", ios::in);
	file1.open("D://Arfan_s Capstone Project/Employee Management System/attendence.txt", ios::in);
	if (!file || !file1)
	{
		cout << "\n\n File Opening Error...";
	}
	else
	{
		cout << "\n\n Employee ID : ";
		cin >> t_id;
		file >> emp_id >> name >> sal >> address >> phone;
		while (!file.eof())
		{
			if (emp_id == t_id)
			{
				count = 1;
				break;
			}
			file >> emp_id >> name >> sal >> address >> phone;
		}
		file.close();
		if (!count)
			cout << "\n\n\t\t\t Employee ID Not Found...";
		else
		{
			cout << " Year (yyyy) : ";
			cin >> y;
			cout << " Month (mm)  : ";
			cin >> m;
			cout << " Date (dd)   : ";
			cin >> d;
			system("cls");
			cout << "\n\n\t\t\tCheck Employee Attendence";
			count = 0;
			file1 >> t_id >> a_date >> a_month >> a_year;
			while (!file1.eof())
			{
				if (emp_id == t_id && d == a_date && m == a_month && y == a_year)
					present = 1;
				if (emp_id == t_id && m == a_month && y == a_year)
					count++;
				file1 >> t_id >> a_date >> a_month >> a_year;
			}
			file1.close();
			if (present)
				cout << "\n\n " << d << "/" << m << "/" << y << " : Present";
			else
				cout << "\n\n " << d << "/" << m << "/" << y << " : Absent";
			cout << "\n\n\t   Attendence Of " << m << "/" << y;
			cout << "\n\n ========================================\n";
			cout << " " << left << setw(8) << "ID" << setw(12) << left << "Name" << setw(7) << "Present" << right << setw(13) << "Absent" << endl;
			cout << " ========================================\n";
			cout << " " << left << setw(8) << emp_id << left << setw(12) << name << right << setw(7) << count << right << setw(13) << 30 - count << endl;
			cout << "\n\n\t\t Press Any Key To Continue...";
		}
	}
}
void emp::insert()
{
	system("cls");
	int test_id, found = 0;
	fstream file, file1;
	cout << "\n\n\t\t\t\tInsert Record";
	cout << "\n\n Employee ID      : ";
	cin >> emp_id;
	cout << " Employee Name    : ";
	cin >> name;
	cout << " Employee Sallary : ";
	cin >> sal;
	cout << " Employee Address : ";
	cin >> address;
	cout << " Employee Phone   : ";
	cin >> phone;
	file.open("D://Arfan_s Capstone Project/Employee Management System/emp.txt", ios::out | ios::app);
	file << emp_id << " " << name << " " << sal << " " << address << " " << phone << "\n";
	file.close();
	cout << "\n\n\t\t\tNew Record Inserted Successfully...";
}
void emp::display()
{
	system("cls");
	fstream file;
	cout << " ====================================================================\n";
	cout << " " << left << setw(8) << "ID" << left << setw(15) << "Name" << left << setw(15) << "Salary" << left << setw(15) << "Address" << right << setw(15) << "Phone" << endl;
	cout << " ====================================================================\n";
	file.open("D://Arfan_s Capstone Project/Employee Management System/emp.txt", ios::in);
	if (!file)
	{
		cout << "\n\n File Openning Error...";
		getch();
		menu();
	}
	file >> emp_id >> name >> sal >> address >> phone;
	while (!file.eof())
	{
		cout << " " << left << setw(8) << emp_id << left << setw(15) << name << left << setw(15) << sal << left << setw(15) << address << right << setw(15) << phone << endl;
		file >> emp_id >> name >> sal >> address >> phone;
	}
	cout << "\n\n\t\t\t Press Any Key To Continue...";
	file.close();
}
void emp::search()
{
	system("cls");
	fstream file;
	int emp_idd, found = 0;
	cout << "\n\n\t\t\t\tSearch Record";
	file.open("D://Arfan_s Capstone Project/Employee Management System/emp.txt", ios::in);
	if (!file)
	{
		cout << "\n\n File Openning Error...";
	}
	else
	{
		cout << "\n\n Employee ID For Search : ";
		cin >> emp_idd;
		file >> emp_id >> name >> sal >> address >> phone;
		while (!file.eof())
		{
			if (emp_idd == emp_id)
			{
				system("cls");
				cout << "\n\n\t\t\t\tFound Record";
				cout << "\n\n Employee ID      : " << emp_id;
				cout << "\n Employee Name    : " << name;
				cout << "\n Employee Salary  : " << sal;
				cout << "\n Employee Address : " << address;
				cout << "\n Employee Phone   : " << phone;
				found = 1;
			}
			file >> emp_id >> name >> sal >> address >> phone;
		}
		file.close();
		if (found == 0)
			cout << "\n\n\t\t\t Employee ID Can't Found...";
		else
			cout << "\n\n\n\t\t\t Press Any Key To Continue...";
	}
}
void emp::modify()
{
	system("cls");
	int sal1, test_id, found = 0;
	string name1, address1, phone1;
	fstream file, file1;
	cout << "\n\n\t\t\t\tModify Record";
	file.open("D://Arfan_s Capstone Project/Employee Management System/emp.txt", ios::in);
	if (!file)
	{
		cout << "\n\n File Openning Error...";
		getch();
		menu();
	}
	cout << "\n\n Employee ID For Modify : ";
	cin >> test_id;
	file1.open("D://Arfan_s Capstone Project/Employee Management System/emp1.txt", ios::app | ios::out);
	file >> emp_id >> name >> sal >> address >> phone;
	while (!file.eof())
	{
		if (test_id == emp_id)
		{
			system("cls");
			cout << "\n\n\t\t\t\tModify Record";
			cout << "\n\n Employee Name    : ";
			cin >> name1;
			cout << " Employee Salary  : ";
			cin >> sal1;
			cout << " Employee Address : ";
			cin >> address1;
			cout << " Employee Phone   : ";
			cin >> phone1;
			file1 << emp_id << " " << name1 << " " << sal1 << " " << address1 << " " << phone1 << "\n";
			found = 1;
		}
		else
		{
			file1 << emp_id << " " << name << " " << sal << " " << address << " " << phone << "\n";
		}
		file >> emp_id >> name >> sal >> address >> phone;
	}
	file.close();
	file1.close();
	remove("D://Arfan_s Capstone Project/Employee Management System/emp.txt");
	rename("D://Arfan_s Capstone Project/Employee Management System/emp1.txt", "D://Arfan_s Capstone Project/Employee Management System/emp.txt");
	if (found == 0)
		cout << "\n\n\t\t\t Employee ID Can't Found...";
	else
		cout << "\n\n\t\t\t Record Modify Successfully...";
}
void emp::del()
{
	system("cls");
	int test_id, found = 0;
	char confirm;
	fstream file, file1;
	cout << "\n\n\t\t\t\tDelete Record";
	file.open("D://Arfan_s Capstone Project/Employee Management System/emp.txt", ios::in);
	if (!file)
	{
		cout << "\n\n File Openning Error...";
		getch();
		menu();
	}
	cout << "\n\n Employee ID For Delete : ";
	cin >> test_id;
	file1.open("D://Arfan_s Capstone Project/Employee Management System/emp1.txt", ios::app | ios::out);
	file >> emp_id >> name >> sal >> address >> phone;
	while (!file.eof())
	{
		if (test_id == emp_id)
		{
			cout << "\n\n\t\t\t\tFound Record";
			cout << "\n\n Employee ID      : " << emp_id;
			cout << "\n Employee Name    : " << name;
			cout << "\n Employee Salary  : " << sal;
			cout << "\n Employee Address : " << address;
			cout << "\n Employee Phone   : " << phone;
			cout << "\n\n Delete Confirmation (y/n): ";
			cin >> confirm;
			if (tolower(confirm) != 'y')
				file1 << emp_id << " " << name << " " << sal << " " << address << " " << phone << "\n";
			found = 1;
		}
		else
		{
			file1 << emp_id << " " << name << " " << sal << " " << address << " " << phone << "\n";
		}
		file >> emp_id >> name >> sal >> address >> phone;
	}
	file.close();
	file1.close();
	remove("D://Arfan_s Capstone Project/Employee Management System/emp.txt");
	rename("D://Arfan_s Capstone Project/Employee Management System/emp1.txt", "D://Arfan_s Capstone Project/Employee Management System/emp.txt");
	if (found == 0)
		cout << "\n\n\t\t\t Employee ID Can't Found...";
	else if (tolower(confirm) == 'y')
		cout << "\n\n\t\t\t Record Deleted Successfully...";
	else
		cout << "\n\n\t\t\t Press Any Key To Continue...";
}
main()
{
	intro();
	obj.main_menu();
}
