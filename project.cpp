#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;

class Admin
{
private:
	int id;
	string name;
	string address;
	string phone;
	int age;
	string designation;

public:
	void admin();
	void addEmployee();
	void removeEmployee();
	void viewEmployeeRecord();
	void updateEmployeeRecord();
	void viewAllRecord();
	void viewSales();
};

void Admin::admin()
{
	int choice;
m:
	system("cls");
	cout << "\t\t\t\t#######################################\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#          Administrator Menu         #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#######################################\n";
	cout << "\t\t\t\t#   1 ---> Add Employee               #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#   2 ---> Remove Employee            #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#   3 ---> View Employee Record       #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#   4 ---> View All Records           #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#   5 ---> Update Employee Record     #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#   6 ---> View Total Sales           #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#   7 ---> Exit                       #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#######################################\n";
	cout << "\n\t\t\t Please select: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		addEmployee();
		break;
	}

	case 2:
	{
		removeEmployee();
		break;
	}

	case 3:
	{
		viewEmployeeRecord();
		break;
	}

	case 4:
	{
		viewAllRecord();
		break;
	}

	case 5:
	{
		updateEmployeeRecord();
		break;
	}

	case 6:
	{
		viewSales();
		break;
	}

	case 7:
	{
		return;
	}

	default:
	{
		cout << "Invalid choice! Please choose from the given options  :" << endl
			 << endl;
		goto m;
	}
	}
}

void Admin::addEmployee()
{
	system("cls");
	cout << "\t\t\t\t\t---------------------------------------------\n";
	cout << "\t\t\t\t\t|            Enter Information               |\n";
	cout << "\t\t\t\t\t---------------------------------------------\n";
	cout << "\t\t\t\t\t|   NAME            : ";
	cin >> name;
	cout << "\t\t\t\t\t|   AGE             : ";
	cin >> age;
	cout << "\t\t\t\t\t|   CONTACT NO      : ";
	cin >> phone;
	cout << "\t\t\t\t\t|   DESIGNATION     : ";
	cin >> designation;
	cout << "\t\t\t\t\t|   ADDRESS         : ";
	cin >> address;
	cout << "\t\t\t\t\t---------------------------------------------\n";

	srand(time(0));
	id = rand() % 100000;

	fstream emp("employee.txt", ios::out | ios::app);
	if (!emp)
	{
		cout << "Error opening file :" << endl;
	}
	else
	{
		emp << " " << id << " " << name << " " << age << " " << phone << " " << designation << " " << address << endl;
		cout << "\t\t\t\t\tEmployee has been added " << endl;
	}
	cout << "\t\t\t\t\tPress any key to choose another option...";
	getch();
	admin();
}

void Admin::removeEmployee()
{
	bool recordFound;
	int num;
	int count = 0;
	system("cls");
	cout << "\t\t\t\t\t---------------------------------------------\n";
	cout << "\t\t\t\t\t|            Remove Employee                 |\n";
	cout << "\t\t\t\t\t---------------------------------------------\n";
	cout << "\t\t\t\t\tEnter the Id of the employee     :           ";
	cin >> num;

	ifstream emp("employee.txt");
	ofstream temp("employee1.txt");

	if (!emp)
	{
		cout << "Error opening file :" << endl;
	}
	else if (!temp)
	{
		cout << "Error creating temporary file :" << endl;
	}
	else
	{
		while (emp >> id >> name >> age >> phone >> designation >> address)
		{
			if (id == num)
			{
				recordFound = true;
			}
			else
			{
				temp << id << " " << name << " " << age << " " << phone << " " << designation << " " << address << endl;
			}
		}
	}

	emp.close();
	temp.close();

	if (recordFound)
	{
		remove("employee.txt");
		rename("employee1.txt", "employee.txt");
		cout << "\t\t\t\t\tRecord deleted successfully." << endl;
	}

	else
	{
		remove("employee1.txt");
		cout << "\t\t\t\t\tRecord not found." << endl;
	}
	cout << "\t\t\t\t\tPress any key to choose another option...";
	getch();
	admin();
}

void Admin::viewEmployeeRecord()
{
	int num;
	int count = 0;
	system("cls");
	cout << "\t\t\t\t\t---------------------------------------------\n";
	cout << "\t\t\t\t\t|            View Record                     |\n";
	cout << "\t\t\t\t\t---------------------------------------------\n";
	cout << "\t\t\t\t\tEnter the Id of the employee   :";
	cin >> num;

	fstream emp("employee.txt", ios::in);

	if (!emp)
	{
		cout << "Error opening file  :" << endl;
	}

	else
	{
		emp >> id >> name >> age >> phone >> designation >> address;

		while (!emp.eof())
		{
			if (num == id)
			{
				cout << "\t --------------------------------------------" << endl;
				cout << "\t|               Employee Information          |" << endl;
				cout << "\t --------------------------------------------" << endl;
				cout << "\t|  ID            :   " << id << "\t\t |" << endl;
				cout << "\t|  NAME          :   " << name << "\t\t |" << endl;
				cout << "\t|  AGE           :   " << age << "\t\t |" << endl;
				cout << "\t|  CONTACT NO    :   " << phone << "\t\t |" << endl;
				cout << "\t|  DESIGNATION   :   " << designation << "\t\t |" << endl;
				cout << "\t|  ADDRESS       :   " << address << "\t\t |" << endl;
				cout << "\t --------------------------------------------" << endl;

				count++;
			}

			emp >> id >> name >> age >> phone >> designation >> address;
		}

		if (count == 0)
		{
			cout << "\t\t\t\t\tRecord not found sorry !" << endl;
		}
	}
	cout << "\t\t\t\t\tPress any key to choose another option...";
	getch();
	admin();
}

void Admin::updateEmployeeRecord()
{
	int num;
	string nm;
	int ag;
	string pn;
	string ds;
	string ad;
	int count = 0;

	cout << "\t\t\t----------------------------UPDATE RECORD------------------------------\n\n";
	cout << "\t\t\tEnter the Id of employee      :";
	cin >> num;

	fstream emp("employee.txt", ios::in);
	if (!emp)
	{
		cout << "Error opening file  !" << endl;
	}

	else
	{
		fstream emp1("employee1.txt", ios::out | ios::app);

		emp >> id >> name >> age >> phone >> designation >> address;

		while (!emp.eof())
		{
			if (num == id)
			{
				cout << "\t\t --------------------------------------------" << endl;
				cout << "\t\t|               Modify Employee Details       |" << endl;
				cout << "\t\t --------------------------------------------" << endl;

				cout << "\t\t|  Name           :   ";
				cin >> nm;
				cout << "\t\t|  Age            :   ";
				cin >> ag;
				cout << "\t\t|  Contact no     :   ";
				cin >> pn;
				cout << "\t\t|  Designation    :   ";
				cin >> ds;
				cout << "\t\t|  Address        :   ";
				cin >> ad;

				cout << "\t\t --------------------------------------------" << endl;

				emp1 << " " << id << " " << nm << " " << ag << " " << pn << " " << ds << " " << ad << endl;
				cout << "\t\t\t\t\tRecord updated  !" << endl;
				count++;
			}

			else
			{
				emp1 << id << " " << name << " " << age << " " << phone << " " << designation << " " << address << endl;
			}

			emp >> id >> name >> age >> phone >> designation >> address;
		}
		emp.close();
		emp1.close();

		remove("employee.txt");
		rename("employee1.txt", "employee.txt");
		if (count == 0)
		{
			cout << "\t\t\t\t\tRecord not found sorry  !" << endl;
		}
	}
	cout << "\t\t\t\t\tPress any key to choose another option...";
	getch();
	admin();
}

void Admin::viewAllRecord()
{
	int count = 1;

	fstream emp("employee.txt", ios::in);
	if (!emp)
	{
		cout << "Error opening file  !" << endl;
	}
	else
	{

		emp >> id >> name >> age >> phone >> designation >> address;

		while (!emp.eof())
		{

			cout << "-----------------------------------ALL RECORDS-----------------------------------" << endl
				 << endl;
			cout << "\t\t\t\t Employee  :     " << count << endl;
			cout << "\t\t --------------------------------------------" << endl;
			cout << "\t\t|               Employee Details             |" << endl;
			cout << "\t\t --------------------------------------------" << endl;
			cout << "\t\t|  ID             :   " << id << "\t\t |" << endl;
			cout << "\t\t|  NAME           :   " << name << "\t\t |" << endl;
			cout << "\t\t|  AGE            :   " << age << "\t\t |" << endl;
			cout << "\t\t|  CONTACT NO     :   " << phone << "\t\t |" << endl;
			cout << "\t\t|  DESIGNATION    :   " << designation << "\t\t |" << endl;
			cout << "\t\t|  ADDRESS        :   " << address << "\t\t |" << endl;
			cout << "\t\t --------------------------------------------" << endl;

			count++;

			emp >> id >> name >> age >> phone >> designation >> address;
		}

		emp.close();
	}
	cout << "\t\t\t\t\tPress any key to choose another option...";
	getch();
	admin();
}

void Admin::viewSales()
{
	int day;
	string month;
	int year;
	int id;
	int amount;
	string pname;
	int pcode;
	int price;
	int qty;
	string m;
	int d, y;
	string time;
	int count = 0;
	int choice;
	int total = 0;
v:
	system("cls");
	cout << "\t\t\t------------------------------VIEW SALES---------------------------------\n\n";
	cout << "\t\t\t 1--> View monthly sales   \n\n";
	cout << "\t\t\t 1--> View total sales   \n\n";
	cout << "\t\t\t Enter your choice  :      ";
	cin >> choice;

	switch (choice)
	{
	case 1:

	{
		cout << "\t\t\t Enter the date to check sales of that month     :          \n\n";
		cout << "\t\t\t Enter the day  in single digit :       ";
		cin >> day;
		cout << "\t\t\t Enter the month with first letter capital like Jun  :       ";
		cin >> month;
		cout << "\t\t\t Enter the year in  (2024) format  :       ";
		cin >> year;

		fstream ord("orders.txt", ios::in);
		if (!ord)
		{
			cout << "Error opening file !" << endl;
		}

		else
		{
			cout << "\t\t\tProduct code \t\tName \t\t Qty \t\t Price \n\n";
			while (ord >> id >> pcode >> pname >> qty >> price >> amount >> m >> d >> y >> time)
			{
				if (m == month && d == day && y == year)
				{
					cout << "\t\t\t" << pcode << "\t\t\t" << pname << "\t\t" << qty << "\t\t" << price << endl;
					count = 1;
				}
			}
		}
		if (count == 0)
		{
			cout << "Record not found  !" << endl;
		}
		ord.close();
		break;
	}
	case 2:

	{
		fstream ord("orders.txt", ios::in);
		if (!ord)
		{
			cout << "Error opening file !" << endl;
		}

		else
		{

			while (ord >> id >> pcode >> pname >> qty >> price >> amount >> m >> d >> y >> time)
			{
				total += amount;
			}

			cout << "\t\t\t Total sales   :      " << total << endl;
		}
		ord.close();
		break;
	}
	default:
	{
		cout << "Invalid choice   " << endl;
		goto v;
	}
	}

	cout << "\t\t\t\t\tPress any key to choose another option...";
	getch();
	admin();
}

class Manager
{
private:
	int id;
	string name;
	string address;
	string phone;
	int age;
	string designation;
	int pcode;
	int price;
	float dis;
	string pname;

public:
	void manager();
	void add_product();
	void remove_product();
	void modify_product();
	void viewCustomerRecords();
	void viewProfile();
	void viewSupply();
	void viewOrders();
	void removeLoyalty();
	void checkUsername();
	void changeUsername();
};

void Manager::manager()
{
	int choice;
m:
	system("cls");
	cout << "\t\t\t\t#######################################\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#             Manager Menu            #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#######################################\n";
	cout << "\t\t\t\t#   1) View Profile                   #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#   2) View Customer Records          #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#   3) See Username and Password      #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#   4) Change Username and Password   #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#   5) View Product supply            #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#   6) Remove Loyaty Customer         #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#   7) View Orders                    #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#   8) Add Product                    #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#   9) Remove Product                 #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#   10) Modify Product                #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#   11) Exit                          #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#######################################\n";
	cout << "\n\t\t\t Please select: ";

	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		viewProfile();
		break;
	}

	case 2:
	{
		viewCustomerRecords();
		break;
	}

	case 3:
	{
		checkUsername();
		break;
	}

	case 4:
	{
		changeUsername();
		break;
	}

	case 5:
	{
		viewSupply();
		break;
	}

	case 6:
	{
		removeLoyalty();
		break;
	}

	case 7:
	{
		viewOrders();
		break;
	}

	case 8:
	{
		add_product();
		break;
	}

	case 9:
	{
		remove_product();
		break;
	}

	case 10:
	{
		modify_product();
		break;
	}

	case 11:
	{
		return;
	}

	default:
	{
		cout << "Invlaid choice ! Please choose from the given options :" << endl;
		goto m;
	}
	}
}

void Manager::viewProfile()
{
	int num;
	int count = 0;
	system("cls");
	cout << "\t\t\t----------------------------------------Check Profile--------------------------------------\n\n";
	cout << "\t\t\tEnter your Id            :           ";
	cin >> num;

	fstream emp("employee.txt", ios::in);

	if (!emp)
	{
		cout << "Error opening file  !" << endl;
	}

	else
	{
		emp >> id >> name >> age >> phone >> designation >> address;

		while (!emp.eof())
		{
			if (id == num)
			{
				cout << "\t --------------------------------------------" << endl;
				cout << "\t|               Your Profile                  |" << endl;
				cout << "\t --------------------------------------------" << endl;
				cout << "\t|  ID            :   " << id << "\t\t |" << endl;
				cout << "\t|  NAME          :   " << name << "\t\t |" << endl;
				cout << "\t|  AGE           :   " << age << "\t\t |" << endl;
				cout << "\t|  CONTACT NO    :   " << phone << "\t\t |" << endl;
				cout << "\t|  DESIGNATION   :   " << designation << "\t\t |" << endl;
				cout << "\t|  ADDRESS       :   " << address << "\t\t |" << endl;
				cout << "\t --------------------------------------------" << endl;
				count++;
			}

			emp >> id >> name >> age >> phone >> designation >> address;
		}
		emp.close();

		if (count == 0)
		{
			cout << "\t\t\tRecord not fund sorry!";
		}
	}
	cout << "\t\t\t\t\tPress any key to choose another option...";
	getch();
	manager();
}

void Manager::changeUsername()
{
	int count = 0;
	string nm;
	string ps;
	string username;
	string pass;
	system("cls");
	cout << "\t\t\t------------------------------Username | Password----------------------------------\n\n";
	cout << "\t\t\tEnter your username           :            ";
	cin >> name;

	fstream login("login.txt", ios ::in);
	if (!login)
	{
		cout << "Error opening file   ! " << endl;
	}

	else
	{
		fstream login1("login1.txt", ios::out | ios::app);
		login >> designation >> username >> pass;

		while (!login.eof())
		{
			if (username == name)
			{
				cout << "\t\t\t+-------------------------------Enter Modify Details--------------------------------+\n";
				cout << "\t\t\t|                                                                              |\n";
				cout << "\t\t\t|                             Username          : ";
				cin >> nm;
				cout << "\t\t\t|                             Password          : ";
				cin >> ps;
				cout << "\t\t\t|                                                                              |\n";
				cout << "\t\t\t+--------------------------------------------------------------------------------+\n";
				login1 << " " << designation << " " << nm << " " << ps << endl;
				count++;
				cout << "Username and Password change successfully  !" << endl;
			}

			else
			{
				login1 << " " << designation << " " << username << " " << pass << endl;
			}

			login >> designation >> username >> pass;
		}

		login.close();
		login1.close();
		remove("login.txt");
		rename("login1.txt", "login.txt");
	}

	if (count == 0)
	{
		cout << "\t\t\tUsername not found sorry !" << endl;
	}

	cout << "\t\t\t\t\tPress any key to choose another option...";
	getch();
	manager();
}

void Manager::checkUsername()
{
	string username;
	string pass;
	system("cls");
	cout << "\t\t\t------------------------------Username | Password----------------------------------\n\n";
	cout << "Enter your username           :            ";
	cin >> name;

	fstream login("login.txt", ios ::in);
	if (!login)
	{
		cout << "Error opening file   ! " << endl;
	}

	else
	{
		login >> designation >> username >> pass;

		while (!login.eof())
		{
			if (username == name)
			{
				cout << "\t\t\t\t+-----------------------------------------+" << endl;
				cout << "\t\t\t\t|               Credentials               |" << endl;
				cout << "\t\t\t\t+-----------------------------------------+" << endl;
				cout << "\t\t\t\t|   Username          :   " << username << "      |" << endl;
				cout << "\t\t\t\t|   Password          :   " << pass << "     |" << endl;
				cout << "\t\t\t\t+-----------------------------------------+" << endl;
			}

			login >> designation >> username >> pass;
		}
		login.close();
	}
	cout << "\t\t\t\t\tPress any key to choose another option...";
	getch();
	manager();
}

void Manager::add_product()
{
m:
	fstream data;
	int c;
	int q;
	int token = 0;
	float p;
	string n;
	system("cls");
	cout << "\t\t+------------------------- Add New Product -------------------------+\n";
	cout << "\t\t| Product code: ";
	cin >> pcode;
	cout << "\t\t| Product name: ";
	cin >> pname;
	cout << "\t\t| Product price: ";
	cin >> price;
	cout << "\t\t+-------------------------------------------------------------------+\n";

	cout << endl;

	data.open("database.txt", ios::in);
	if (!data)
	{
		data.open("database.txt", ios::app | ios::out);
		data << " " << pcode << " " << pname << " " << price << endl;
		data.close();
	}
	else
	{
		data >> c >> n >> p;

		while (!data.eof())
		{

			if (c == pcode)
			{

				token++;
			}
			data >> c >> n >> p;
		}
		data.close();

		if (token == 1)
		{
			cout << "\t\t\tDUPLICATE CODE enter again" << endl;

			goto m;
		}
		else
		{
			data.open("database.txt", ios::app | ios::out);
			data << " " << pcode << " " << pname << " " << price << endl;
			cout << "  \t\t\t Record inserted   !" << endl;
			data.close();
		}
	}
	cout << "\t\t\tPress any key to choose another option...";
	getch();
	manager();
}

void Manager::modify_product()
{
	fstream data, data1;
	int pkey;
	int token = 0;
	int c;
	int q;
	float p;
	string n;
	system("cls");
	cout << "______Modify the record_______" << endl;
	cout << "_____Product code_______" << endl;
	cin >> pkey;

	data.open("database.txt", ios::in);
	if (!data)
	{
		cout << "File does not exit !";
	}

	else
	{
		data1.open("database1.txt", ios::app | ios::out);
		data >> pcode >> pname >> price;

		while (!data.eof())
		{
			if (pkey == pcode)
			{
				cout << "  product new code  :" << endl;
				cin >> c;
				cout << "  Name of the product  :" << endl;
				cin >> n;
				cout << "  Price    :" << endl;
				cin >> p;
				data1 << " " << c << " " << n << " " << p << endl;
				cout << " \t\t\t RECORD INSERTED  " << endl;
				token++;
			}

			else
			{
				data1 << " " << pcode << " " << pname << " " << price << endl;
			}
			data >> pcode >> pname >> price;
		}
		data.close();
		data1.close();

		remove("database.txt");
		rename("database1.txt", "database.txt");

		if (token == 0)
		{
			cout << " \t\t\t RECORD NOT FOUND SORRY!" << endl;
		}
	}
	cout << "\t\t\tPress any key to choose another option...";
	getch();
	manager();
}

void Manager::remove_product()
{
	fstream data, data1;
	int pkey;
	int token = 0;
	system("cls");
	cout << "  \t\t----------------- Delete product-----------------" << endl;
	cout << " \t\t  product code  " << endl;
	cin >> pkey;

	data.open("database.txt", ios::in);
	if (!data)
	{

		cout << " File does not exit ";
	}

	else
	{
		data1.open("database1.txt", ios::app | ios::out);
		data >> pcode >> pname >> price;

		while (!data.eof())
		{
			if (pcode == pkey)
			{
				cout << "  \t\t\t Product deleted successfully" << endl;
				cout << endl;
				token++;
			}
			else
			{
				data1 << " " << pcode << " " << pname << " " << price << endl;
			}

			data >> pcode >> pname >> price;
		}

		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt", "database.txt");

		if (token == 0)
		{
			cout << " \t\t\t RECORD NOT FOUND SORRY!" << endl;
		}
	}
	cout << "\t\t\tPress any key to choose another option...";
	getch();
	manager();
}

void Manager::viewCustomerRecords()
{
	system("cls");
	fstream cust("customer.txt", ios::in);
	if (!cust)
	{
		cout << "Error opening file  :";
	}

	else
	{
		cust >> id >> name >> phone;
		cout << "\t+-------------------------------------------------------------------+" << endl;
		cout << "\t|                       Customer Information                        |" << endl;
		cout << "\t+-------------------+-----------------------+-----------------------+" << endl;
		cout << "\t|  Customer ID      |  Customer Name        |  Phone No             |" << endl;
		cout << "\t+-------------------+-----------------------+-----------------------+" << endl;

		while (cust >> id >> name >> phone)
		{
			cout << "\t|  " << id << "\t\t    |  " << name << "\t\t        |  " << phone << "\t\t\t|" << endl;
		}

		cout << "\t+-------------------+-----------------------+-----------------------+" << endl;

		cust.close();
	}
	cout << "\t\t\tPress any key to choose another option...";
	getch();
	manager();
}

void Manager::viewOrders()
{
	system("cls");
	fstream order("orders.txt", ios::in);
	if (!order)
	{
		cout << "Error opening file  :";
	}

	else
	{
		order >> id >> pcode >> pname >> price;
		cout << "\t+-----------------+--------------+-----------------------+-----------+" << endl;
		cout << "\t|   Customer ID   |  Product ID  |     Product Name      |     Price    | |" << endl;
		cout << "\t+-----------------+--------------+-----------------------+--------------++" << endl;

		while (order >> id >> pcode >> pname >> price)
		{
			cout << "\t| " << id
				 << "\t\t| " << pcode
				 << "\t  | " << pname
				 << "\t  | " << price
				 << "\t  |" << endl;
		}

		cout << "\t+-----------------+--------------+-----------------------+--------------+----+" << endl;

		order.close();
		cout << endl
			 << endl
			 << endl;
	}
	cout << "\t\t\t\t\tPress any key to choose another option...";
	getch();
	manager();
}

void Manager::removeLoyalty()
{
	string type;
	bool recordFound;
	int num;
	int count = 0;
	system("cls");
	cout << "\t\t\t\t\t---------------------------------------------\n";
	cout << "\t\t\t\t\t|            Remove Customer                 |\n";
	cout << "\t\t\t\t\t---------------------------------------------\n";
	cout << "\t\t\t\t\tEnter the Id of the customer     :           ";
	cin >> num;

	ifstream emp("loyalty.txt");
	ofstream temp("loyalty1.txt");

	if (!emp)
	{
		cout << "Error opening file :" << endl;
	}
	else if (!temp)
	{
		cout << "Error creating temporary file :" << endl;
	}
	else
	{
		while (emp >> type >> id >> name >> phone)
		{
			if (id == num)
			{
				recordFound = true;
			}
			else
			{
				temp << type << " " << id << " " << name << " " << phone << endl;
			}
		}
	}

	emp.close();
	temp.close();

	if (recordFound)
	{
		remove("loyalty.txt");
		rename("loyalty1.txt", "loyalty.txt");
		cout << "\t\t\t\t\tRecord deleted successfully." << endl;
	}

	else
	{
		remove("loyalty1.txt");
		cout << "\t\t\t\t\tRecord not found." << endl;
	}
	cout << "\t\t\t\t\tPress any key to choose another option...";
	getch();
	manager();
}

void Manager::viewSupply()
{
	system("cls");
	fstream data("database.txt", ios::in);

	if (!data)
	{
		cout << "Error opening file  :";
	}

	else
	{
		data >> pcode >> pname >> price;
		cout << "\t+--------------+-----------------------+------------+" << endl;
		cout << "\t|  Product ID  |     Product Name      |     Price    |   |" << endl;
		cout << "\t+--------------+-----------------------+--------------+--+" << endl;

		while (data >> pcode >> pname >> price)
		{
			cout << "\t| " << pcode
				 << "\t\t | " << pname
				 << "\t\t | " << price
				 << "\t\t |" << endl;
		}

		cout << "\t+--------------+-----------------------+--------------+--------------+" << endl;
		data.close();
		cout << endl
			 << endl
			 << endl;
	}

	cout << "\t\t\t\t\tPress any key to choose another option...";
	getch();
	manager();
}

class Employee
{
protected:
	int id;
	string name;
	string age;
	string address;
	string phone;
	string designation;

public:
	void employee();
	void check_username();
	void change_password();
	void calculate_salary();
	void view_profile();
	void view_customer_bills();
};

void Employee::employee()
{
	int choice;
m:
	system("cls");
	cout << "\t\t\t\t#######################################\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#             Employee Menu           #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#######################################\n";
	cout << "\t\t\t\t#   1--> View Profile                 #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#   2--> See Username and Password    #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#   3--> Change Username and Password #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#   4--> View Customer Bills          #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#   5--> Calculate Salary             #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#   6--> Exit                         #\n";
	cout << "\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t#######################################\n";
	cout << "\n\t\t\t Please select: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		view_profile();
		break;
	}

	case 2:
	{
		check_username();
		break;
	}

	case 3:
	{
		change_password();
		break;
	}

	case 4:
	{
		view_customer_bills();
		break;
	}

	case 5:
	{
		calculate_salary();
		break;
	}

	case 6:
	{
		return;
	}

	default:
	{
		cout << "Invlaid choice ! Please choose from the given options :" << endl;
		goto m;
	}
	}
}

void Employee::view_profile()
{
	int num;
	system("cls");
	cout << "\t\t\t----------------------------------------Check Profile--------------------------------------\n\n";
	cout << "\t\t\tEnter your Id            :           ";
	cin >> num;

	ifstream emp("employee.txt");

	if (!emp)
	{
		cout << "Error opening file  !" << endl;
	}

	else
	{
		emp >> id >> name >> age >> phone >> designation >> address;

		while (!emp.eof())
		{
			if (id == num)
			{
				cout << "\t\t\t\t---------------------------- Your Profile ----------------------------\n\n";
				cout << "\t\t\t\t ____________________________________________________________________" << endl;
				cout << "\t\t\t\t|\t ID              :   " << id << "                                     |" << endl;
				cout << "\t\t\t\t|--------------------------------------------------------------------|" << endl;
				cout << "\t\t\t\t|\t NAME            :   " << name << "                           |" << endl;
				cout << "\t\t\t\t|--------------------------------------------------------------------|" << endl;
				cout << "\t\t\t\t|\t AGE             :   " << age << "                                     |" << endl;
				cout << "\t\t\t\t|--------------------------------------------------------------------|" << endl;
				cout << "\t\t\t\t|\t CONTACT NO      :   " << phone << "                              |" << endl;
				cout << "\t\t\t\t|--------------------------------------------------------------------|" << endl;
				cout << "\t\t\t\t|\t DESIGNATION     :   " << designation << "                        |" << endl;
				cout << "\t\t\t\t|--------------------------------------------------------------------|" << endl;
				cout << "\t\t\t\t|\t ADDRESS         :   " << address << "                        |" << endl;
				cout << "\t\t\t\t|____________________________________________________________________|" << endl;
				break;
			}

			emp >> id >> name >> age >> phone >> designation >> address;
		}
		emp.close();
	}
	cout << "\t\t\t\t\tPress any key to choose another option...";
	getch();
	employee();
}

void Employee::check_username()
{
	string username;
	string pass;
	system("cls");
	cout << "\t\t\t------------------------------Username | Password----------------------------------\n\n";
	cout << "\t\t\tEnter your username           :            ";
	cin >> name;

	fstream login("login.txt", ios ::in);
	if (!login)
	{
		cout << "Error opening file   ! " << endl;
	}

	else
	{
		login >> designation >> username >> pass;

		while (!login.eof())
		{
			if (designation == "employee" && username == name)
			{
				cout << "\t\t\t\t+-----------------------------------------+" << endl;
				cout << "\t\t\t\t|               Credentials               |" << endl;
				cout << "\t\t\t\t+-----------------------------------------+" << endl;
				cout << "\t\t\t\t|   Username          :   " << username << "      |" << endl;
				cout << "\t\t\t\t|   Password          :   " << pass << "     |" << endl;
				cout << "\t\t\t\t+-----------------------------------------+" << endl;
			}

			login >> designation >> username >> pass;
		}
		login.close();
	}
	cout << "\t\t\t\t\tPress any key to choose another option...";
	getch();
	employee();
}

void Employee::change_password()
{
	int count = 0;
	string nm;
	string ps;
	string username;
	string pass;
	system("cls");
	cout << "\t\t\t------------------------------Username | Password----------------------------------\n\n";
	cout << "\t\t\tEnter your username           :            ";
	cin >> name;

	fstream login("login.txt", ios ::in);
	if (!login)
	{
		cout << "Error opening file   ! " << endl;
	}

	else
	{
		fstream login1("login1.txt", ios::out | ios::app);
		login >> designation >> username >> pass;

		while (!login.eof())
		{
			if (username == name && designation == "employee")
			{
				cout << "\t\t\t+-------------------- Enter Modify Details --------------------+\n";
				cout << "\t\t\t|                                                             |\n";
				cout << "\t\t\t|  Username : ";
				cin >> nm;
				cout << "\t\t\t|                                                             |\n";
				cout << "\t\t\t|  Password : ";
				cin >> ps;
				cout << "\t\t\t|                                                             |\n";
				cout << "\t\t\t+-------------------------------------------------------------+\n";
				login1 << " " << designation << " " << nm << " " << ps << endl;
				count++;
				cout << "\t\t\tUsername and Password change successfully  !" << endl;
			}

			else
			{
				login1 << " " << designation << " " << username << " " << pass << endl;
			}

			login >> designation >> username >> pass;
		}

		login.close();
		login1.close();
		remove("login.txt");
		rename("login1.txt", "login.txt");
	}

	if (count == 0)
	{
		cout << "Username not found sorry !" << endl;
	}
	cout << "\t\t\t\t\tPress any key to choose another option...";
	getch();
	employee();
}

void Employee::calculate_salary()
{
	int choice;
	int hours;
	int payRate;
	int total;
t:
	system("cls");
	cout << "\t\t\t+--------------------------------------------+" << endl;
	cout << "\t\t\t|                 SALARY                     |" << endl;
	cout << "\t\t\t+--------------------------------------------+" << endl;
	cout << "\t\t\t|  1) Calculate Hourly Salary                |" << endl;
	cout << "\t\t\t|                                            |" << endl;
	cout << "\t\t\t|  2) Calculate Weekly Salary                |" << endl;
	cout << "\t\t\t|                                            |" << endl;
	cout << "\t\t\t|  3) Calculate Monthly Salary               |" << endl;
	cout << "\t\t\t|                                            |" << endl;
	cout << "\t\t\t|  4) Calculate Yearly Salary                |" << endl;
	cout << "\t\t\t|                                            |" << endl;
	cout << "\t\t\t|  5) Exit                                   |" << endl;
	cout << "\t\t\t+--------------------------------------------+" << endl;
	cout << "\t\t\t  Enter your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		cout << "\t\t\tEnter the number of hours worked  :			";
		cin >> hours;
		cout << "\t\t\tEnter the Hourly pay rate         :			";
		cin >> payRate;
		cout << endl
			 << endl;
		total = hours * payRate;

		cout << "\t\t\tYour salary is   : 			" << total;
		cout << endl;
		break;
	}

	case 2:
	{
		cout << "\t\t\tEnter the number of hours worked per day :			";
		cin >> hours;
		cout << "\t\t\tEnter the Hourly pay rate         :			";
		cin >> payRate;
		cout << endl
			 << endl;
		total = hours * payRate * 7;

		cout << "\t\t\tYour Weekly salary is   : 			" << total;
		cout << endl;
		break;
	}

	case 3:
	{
		cout << "\t\t\tEnter the number of hours worked  per day:			";
		cin >> hours;
		cout << "\t\t\tEnter the Hourly pay rate         :			";
		cin >> payRate;
		cout << endl
			 << endl;
		total = hours * payRate * 30;

		cout << "\t\t\tYour Monthly salary is   : 			" << total;
		cout << endl;
		break;
	}

	case 4:
	{
		cout << "\t\t\tEnter the number of hours worked per day :			";
		cin >> hours;
		cout << "\t\t\tEnter the Hourly pay rate         :			";
		cin >> payRate;
		cout << endl
			 << endl;
		total = hours * payRate * 365;

		cout << "\t\t\tYour Yearly salary is   : 			" << total;
		cout << endl;
		break;
	}

	case 5:
	{
		return;
	}

	default:
	{
		cout << "\t\t\tInvalid choice  !Enter again" << endl;
		goto t;
	}
	}
	cout << "\t\t\t\t\tPress any key to choose another option...";
	getch();
	employee();
}

void Employee::view_customer_bills()
{
	system("cls");
	int ide;
	string no;
	cout << "\t\t\tEnter the id of the Customer  :                ";
	cin >> ide;

	fstream cust("customer.txt", ios::in);
	if (!cust)
	{
		cout << "Error  opening file !";
	}

	else
	{
		cust >> id >> name >> no;
		while (!cust.eof())
		{
			if (id == ide)
			{
				cout << "\t\t\t----------------------------Customer Details-------------------------------------\n\n";
				cout << "\t _________________________________________________________________________________________" << endl;
				cout << "\t|                                                                                        |" << endl;
				cout << "\t|  ID                       :               " << id << "                                    |" << endl;
				cout << "\t|  NAME                     :               " << name << "                                  |" << endl;
				cout << "\t|  AGE                      :               " << no << "                                    |" << endl;
				cout << "\t|_________________________________________________________________________________________|" << endl;

				break;
			}
			cust >> id >> name >> no;
		}
		cust.close();
	}
	cout << "\t\t\t\t\tPress any key to choose another option...";
	getch();
	employee();
}

class Shopping
{
private:
	int pcode;
	float price;
	float dis;
	string pname;
	int id;
	string name;
	string contact_no;

public:
	void list();
	void recipient();
};

void Shopping ::list()
{
	fstream data;
	system("cls");
	data.open("database.txt", ios::in);
	cout << "\n\n|====================================================\n";
	cout << "|\t\tProduct List\n";
	cout << "|====================================================\n";
	cout << "|\tProNo\t|\tName\t\t|\tPrice\n";
	cout << "|====================================================\n";

	while (data >> pcode >> pname >> price)
	{

		cout << "|\t" << pcode << "\t|\t" << pname << "\t\t|\t" << price << "\n";
		cout << "|====================================================\n";
	}

	data.close();
}

void Shopping::recipient()
{
	fstream data, loyal, data1;
	int arrc[100], arrq[100];
	char choice;
	int c = 0, amount = 0, total = 0, ide;
	string type, name, contact_no;
	int opinion;
	system("cls");
repeat:
	cout << "\t\t\t+----------------------------------------------+\n";
	cout << "\t\t\t|                Customer Type Menu            |\n";
	cout << "\t\t\t+----------------------------------------------+\n";
	cout << "\t\t\t|    Option    |           Customer Type       |\n";
	cout << "\t\t\t+----------------------------------------------+\n";
	cout << "\t\t\t|      1       |           Diamond             |\n";
	cout << "\t\t\t|      2       |           Gold                |\n";
	cout << "\t\t\t|      3       |           Silver              |\n";
	cout << "\t\t\t|      4       |           Normal              |\n";
	cout << "\t\t\t+----------------------------------------------+\n";

	cout << "\t\t\tEnter your customer type option: ";
	cin >> opinion;

	switch (opinion)
	{
	case 1:
	{
	w:
		loyal.open("loyalty.txt", ios::in);
		if (!loyal)
		{
			cout << "Error opening loyalty file." << endl;
			return;
		}

		cout << "\t\t\tEnter your id: ";
		cin >> id;

		bool isValidCustomer = false;
		while (loyal >> type >> ide >> name >> contact_no)
		{
			if (type == "diamond" && id == ide)
			{
				isValidCustomer = true;
				break;
			}
		}
		loyal.close();

		if (!isValidCustomer)
		{
			cout << "\t\t\tInvalid Diamond card ID." << endl;
			goto w;
		}

		cout << "\n\n\t\t\t\t RECEIPT  ";
		data.open("database.txt", ios::in);
		if (!data)
		{
			cout << "Empty database." << endl;
			return;
		}
		data.close();

		list();
		cout << "\t\t\t ________________________________________\n";
		cout << "\t\t\t|                                      |\n";
		cout << "\t\t\t|        Please Place Your Order       |\n";
		cout << "\t\t\t|                                      |\n";
		cout << "\t\t\t ________________________________________\n";

		do
		{
		ro:
			cout << "\t\t\tEnter product code: ";
			cin >> arrc[c];

			cout << "\t\t\tEnter the product quantity: ";
			cin >> arrq[c];

			for (int i = 0; i < c; i++)
			{
				if (arrc[c] == arrc[i])
				{
					cout << "\t\t\tDuplicate code. Please enter again." << endl;
					goto ro;
				}
			}

			c++;
			cout << "\t\t\tDo you want to buy another product? If yes then press y else no: ";
			cin >> choice;

		} while (choice == 'y');
		system("cls");
		cout << "\n\n\t\t\t\t\t\t\tRECEIPT\n";
		cout << "\t\t\t=======================================================================\n";
		cout << "\t\t\t CUSTOMER ID     :    " << id << endl;
		cout << "\t\t\t CUSTOMER NAME   :    " << name << endl;
		cout << "\t\t\t CONTACT NO      :    " << contact_no << endl;
		cout << "\t\t\t DATE            :    " << __DATE__ << endl;
		cout << "\t\t\t TIME            :    " << __TIME__ << endl;
		cout << "\t\t\t=======================================================================\n";
		cout << "\t\t\t|Product No\t| Name\t\t\t\t| Qty\t| Price\t|Amount\n";
		cout << "\t\t\t=======================================================================\n";

		for (int i = 0; i < c; i++)
		{
			ifstream data("database.txt");
			fstream ord("orders.txt", ios::out | ios::app);

			if (!data)
			{
				cout << "Unable to open file database.txt" << endl;
				return;
			}

			while (data >> pcode >> pname >> price)
			{
				if (pcode == arrc[i])
				{

					amount = price * arrq[i];
					total += amount;

					cout << "\n"
						 << "\t\t\t" << pcode << "|\t\t|" << pname << "\t\t\t\t|" << arrq[i] << "\t|" << price << "\t|" << amount << endl;
					ord << id << " " << pcode << " " << pname << " " << arrq[i] << " " << price << " " << amount << " " << __DATE__ << " " << __TIME__ << endl;
				}
			}

			data.close();
			ord.close();
		}

		float discount = 0.0;
		if (type == "diamond")
		{
			discount = 0.20;
		}
		else if (type == "gold")
		{
			discount = 0.15;
		}
		else if (type == "silver")
		{
			discount = 0.10;
		}

		dis = total * (1 - discount);
		cout << "\t\t\t=======================================================================\n";
		cout << "\t\t\t|Total Amount :" << total << endl;
		cout << "\t\t\t=======================================================================\n";
		cout << "\t\t\t|DISCOUNT   20 %\n";
		cout << "\t\t\t=======================================================================\n";
		cout << "\t\t\t|Amount after discount :" << dis << endl;
		cout << "\t\t\t=======================================================================\n";

		cout << endl;

		break;
	}

	case 2:
	{
		system("cls");
		loyal.open("loyalty.txt", ios::in);
		if (!loyal)
		{
			cout << "Error opening loyalty file." << endl;
			return;
		}

		cout << "Enter your id: ";
		cin >> id;

		bool isValidCustomer = false;
		while (loyal >> type >> ide >> name >> contact_no)
		{
			if (type == "gold" && id == ide)
			{
				isValidCustomer = true;
				break;
			}
		}
		loyal.close();

		if (!isValidCustomer)
		{
			cout << "\t\t\tInvalid Diamond card ID." << endl;
			return;
		}

		cout << "\n\n\t\t\t\t RECEIPT  ";
		data.open("database.txt", ios::in);
		if (!data)
		{
			cout << "Empty database." << endl;
			return;
		}
		data.close();

		list();
		cout << "\t\t\t ________________________________________\n";
		cout << "\t\t\t|                                      |\n";
		cout << "\t\t\t|        Please Place Your Order       |\n";
		cout << "\t\t\t|                                      |\n";
		cout << "\t\t\t ________________________________________\n";

		do
		{
		r:
			cout << "\t\t\tEnter product code: ";
			cin >> arrc[c];

			cout << "\t\t\tEnter the product quantity: ";
			cin >> arrq[c];

			for (int i = 0; i < c; i++)
			{
				if (arrc[c] == arrc[i])
				{
					cout << "\t\t\tDuplicate code. Please enter again." << endl;
					goto r;
				}
			}

			c++;
			cout << "\t\t\tDo you want to buy another product? If yes then press y else no: ";
			cin >> choice;

		} while (choice == 'y');
		system("cls");
		cout << "\n\n\t\t\t\t\t\t\tRECEIPT\n";
		cout << "\t\t\t=======================================================================\n";
		cout << "\t\t\t CUSTOMER ID     :    " << id << endl;
		cout << "\t\t\t CUSTOMER NAME   :    " << name << endl;
		cout << "\t\t\t CONTACT NO      :    " << contact_no << endl;
		cout << "\t\t\t DATE            :    " << __DATE__ << endl;
		cout << "\t\t\t TIME            :    " << __TIME__ << endl;
		cout << "\t\t\t=======================================================================\n";
		cout << "\t\t\t|Product No\t| Name\t\t\t\t| Qty\t| Price\t|Amount\n";
		cout << "\t\t\t=======================================================================\n";

		for (int i = 0; i < c; i++)
		{
			ifstream data("database.txt");
			fstream ord("orders.txt", ios::out | ios::app);

			if (!data)
			{
				cout << "Unable to open file database.txt" << endl;
				return;
			}

			while (data >> pcode >> pname >> price)
			{
				if (pcode == arrc[i])
				{

					amount = price * arrq[i];
					total += amount;

					cout << "\n"
						 << "\t\t\t" << pcode << "|\t\t|" << pname << "\t\t\t\t|" << arrq[i] << "\t|" << price << "\t|" << amount << endl;
					ord << id << " " << pcode << " " << pname << " " << arrq[i] << " " << price << " " << amount << " " << __DATE__ << " " << __TIME__ << endl;
				}
			}

			data.close();
			ord.close();
		}

		float discount = 0.0;
		if (type == "diamond")
		{
			discount = 0.20;
		}
		else if (type == "gold")
		{
			discount = 0.15;
		}
		else if (type == "silver")
		{
			discount = 0.10;
		}

		dis = total * (1 - discount);
		cout << "\t\t\t=======================================================================\n";
		cout << "\t\t\t|Total Amount :" << total << endl;
		cout << "\t\t\t=======================================================================\n";
		cout << "\t\t\t|DISCOUNT   15 %\n";
		cout << "\t\t\t=======================================================================\n";
		cout << "\t\t\t|Amount after discount :" << dis << endl;
		cout << "\t\t\t=======================================================================\n";

		cout << endl;

		break;
	}
	case 3:
	{
		system("cls");
		loyal.open("loyalty.txt", ios::in);
		if (!loyal)
		{
			cout << "Error opening loyalty file." << endl;
			return;
		}

		cout << "Enter your id: ";
		cin >> id;

		bool isValidCustomer = false;
		while (loyal >> type >> ide >> name >> contact_no)
		{
			if (type == "silver" && id == ide)
			{
				isValidCustomer = true;
				break;
			}
		}
		loyal.close();

		if (!isValidCustomer)
		{
			cout << "Invalid Silver card ID." << endl;
			return;
		}

		cout << "\n\n\t\t\t\t RECEIPT  ";
		data.open("database.txt", ios::in);
		if (!data)
		{
			cout << "Empty database." << endl;
			return;
		}
		data.close();

		list();
		cout << "\t\t\t ________________________________________\n";
		cout << "\t\t\t|                                      |\n";
		cout << "\t\t\t|        Please Place Your Order       |\n";
		cout << "\t\t\t|                                      |\n";
		cout << "\t\t\t ________________________________________\n";

		do
		{
		rl:
			cout << "\t\t\tEnter product code: ";
			cin >> arrc[c];

			cout << "\t\t\tEnter the product quantity: ";
			cin >> arrq[c];

			for (int i = 0; i < c; i++)
			{
				if (arrc[c] == arrc[i])
				{
					cout << "\t\t\tDuplicate code. Please enter again." << endl;
					goto rl;
				}
			}

			c++;
			cout << "\t\t\tDo you want to buy another product? If yes then press y else no: ";
			cin >> choice;

		} while (choice == 'y');
		system("cls");
		cout << "\n\n\t\t\t\t\t\t\tRECEIPT\n";
		cout << "\t\t\t=======================================================================\n";
		cout << "\t\t\t CUSTOMER ID     :    " << id << endl;
		cout << "\t\t\t CUSTOMER NAME   :    " << name << endl;
		cout << "\t\t\t CONTACT NO      :    " << contact_no << endl;
		cout << "\t\t\t DATE            :    " << __DATE__ << endl;
		cout << "\t\t\t TIME            :    " << __TIME__ << endl;
		cout << "\t\t\t=======================================================================\n";
		cout << "\t\t\t|Product No\t| Name\t\t\t\t| Qty\t| Price\t|Amount\n";
		cout << "\t\t\t=======================================================================\n";

		for (int i = 0; i < c; i++)
		{
			ifstream data("database.txt");
			fstream ord("orders.txt", ios::out | ios::app);

			if (!data)
			{
				cout << "Unable to open file database.txt" << endl;
				return;
			}

			while (data >> pcode >> pname >> price)
			{
				if (pcode == arrc[i])
				{

					amount = price * arrq[i];
					total += amount;

					cout << "\n"
						 << "\t\t\t" << pcode << "|\t\t|" << pname << "\t\t\t\t|" << arrq[i] << "\t|" << price << "\t|" << amount << endl;
					ord << id << " " << pcode << " " << pname << " " << arrq[i] << " " << price << " " << amount << " " << __DATE__ << " " << __TIME__ << endl;
				}
			}

			data.close();
			ord.close();
		}

		float discount = 0.0;
		if (type == "diamond")
		{
			discount = 0.20;
		}
		else if (type == "gold")
		{
			discount = 0.15;
		}
		else if (type == "silver")
		{
			discount = 0.10;
		}

		dis = total * (1 - discount);
		cout << "\t\t\t=======================================================================\n";
		cout << "\t\t\t|Total Amount :" << total << endl;
		cout << "\t\t\t=======================================================================\n";
		cout << "\t\t\t|DISCOUNT   10 %\n";
		cout << "\t\t\t=======================================================================\n";
		cout << "\t\t\t|Amount after discount :" << dis << endl;
		cout << "\t\t\t=======================================================================\n";

		cout << endl;

		break;
	}
	case 4:
	{
		string nm;
		string no;
	i:

		fstream cust("customer.txt", ios::in);

		if (!cust)
		{
			cout << "ERROR  opening file !";
		}

		srand(time(0));
		id = rand() % 1000000;
		cout << "\t\t\tEnter   Name   :              ";
		cin >> name;
		cout << "\t\t\tEnter  Phone no   :          ";
		cin >> contact_no;

		cust >> ide >> nm >> no;

		while (!cust.eof())
		{
			if (id == ide)
			{
				cout << "\t\t\tID already exists   !  Choose Unique one  :" << endl;
				cust.close();
				goto i;
			}

			cust >> ide >> nm >> no;
		}

		cust.close();
		cust.open("customer.txt", ios::out | ios::app);

		if (!cust)
		{
			cout << "Error opening  !";
		}

		else
		{
			cust << " " << id << " " << name << " " << contact_no << endl;
			cust.close();
		}
		cout << "\n\n\t\t\t\t RECEIPT  ";
		data.open("database.txt", ios::in);
		if (!data)
		{
			cout << "Empty database." << endl;
			return;
		}
		data.close();

		list();
		cout << "\t\t\t ________________________________________\n";
		cout << "\t\t\t|                                      |\n";
		cout << "\t\t\t|        Please Place Your Order       |\n";
		cout << "\t\t\t|                                      |\n";
		cout << "\t\t\t ________________________________________\n";
		data.open("database.txt", ios::in);

		do
		{
		rp:
			cout << "\t\t\tEnter product code: ";
			cin >> arrc[c];

			cout << "\t\t\tEnter the product quantity: ";
			cin >> arrq[c];

			for (int i = 0; i < c; i++)
			{
				if (arrc[c] == arrc[i])
				{
					cout << "\t\t\tDuplicate code. Please enter again." << endl;
					goto rp;
				}
			}

			c++;
			cout << "\t\t\tDo you want to buy another product? If yes then press y else no: ";
			cin >> choice;

		} while (choice == 'y');
		system("cls");
		cout << "\n\n\t\t\t\t\t\t\tRECEIPT\n";
		cout << "\t\t\t=======================================================================\n";
		cout << "\t\t\t CUSTOMER ID     :    " << id << endl;
		cout << "\t\t\t CUSTOMER NAME   :    " << name << endl;
		cout << "\t\t\t CONTACT NO      :    " << contact_no << endl;
		cout << "\t\t\t DATE            :    " << __DATE__ << endl;
		cout << "\t\t\t TIME            :    " << __TIME__ << endl;
		cout << "\t\t\t=======================================================================\n";
		cout << "\t\t\t|Product No\t| Name\t\t\t\t| Qty\t| Price\t|Amount\n";
		cout << "\t\t\t=======================================================================\n";

		for (int i = 0; i < c; i++)
		{
			ifstream data("database.txt");
			fstream ord("orders.txt", ios::out | ios::app);

			if (!data)
			{
				cout << "Unable to open file database.txt" << endl;
				return;
			}

			while (data >> pcode >> pname >> price)
			{
				if (pcode == arrc[i])
				{

					amount = price * arrq[i];
					total += amount;

					cout << "\n"
						 << "\t\t\t" << pcode << "|\t\t|" << pname << "\t\t\t\t|" << arrq[i] << "\t|" << price << "\t|" << amount << endl;
					ord << id << " " << pcode << " " << pname << " " << arrq[i] << " " << price << " " << amount << " " << __DATE__ << " " << __TIME__ << endl;
				}
			}

			data.close();
			ord.close();
		}

		cout << "\t\t\t=======================================================================\n";
		cout << "\t\t\t|Total Amount :" << total << endl;
		cout << "\t\t\t=======================================================================\n";
		cout << endl;

		if (total > 80000)
		{

			fstream loyal("loyalty.txt", ios::out | ios::app);
			loyal << "diamond" << " " << ide << " " << name << " " << contact_no << endl;
			loyal.close();
		}
		else if (total > 50000 && total < 80000)
		{
			fstream loyal("loyalty.txt", ios::out | ios::app);
			loyal << "gold" << " " << ide << " " << name << " " << contact_no << endl;
			loyal.close();
		}
		else if (total > 30000)
		{
			fstream loyal("loyalty.txt", ios::out | ios::app);
			loyal << "silver" << " " << ide << " " << name << " " << contact_no << endl;
			loyal.close();
		}

		break;
	}

	default:
		cout << "This functionality is not implemented yet." << endl;
		break;
	}
	cout << "\t\t\t\t\tPress any key to choose another option...";
	getch();
}

class LoginPage : public Admin, public Employee, public Manager, public Shopping
{
private:
	string designation;
	string username;
	string password;

public:
	void menu();
	void login();
	void sign_up();
};

void LoginPage::menu()
{
o:
	system("cls");
	int choice;
	cout << "\t\t\t\t\t###############################################################\n";
	cout << "\t\t\t\t\t#                                                             #\n";
	cout << "\t\t\t\t\t#                                                             #\n";
	cout << "\t\t\t\t\t#                                                             #\n";
	cout << "\t\t\t\t\t#                     WELCOME TO LOGIN PAGE                   #\n";
	cout << "\t\t\t\t\t#                                                             #\n";
	cout << "\t\t\t\t\t#                                                             #\n";
	cout << "\t\t\t\t\t###############################################################\n";
	cout << "\t\t\t\t\t#                          MENU                               #\n";
	cout << "\t\t\t\t\t###############################################################\n";
	cout << "\t\t\t\t\t#                                                             #\n";
	cout << "\t\t\t\t\t#  Press 1 ---> LOGIN                                         #\n";
	cout << "\t\t\t\t\t#                                                             #\n";
	cout << "\t\t\t\t\t#  Press 2 ---> SIGN UP                                       #\n";
	cout << "\t\t\t\t\t#                                                             #\n";
	cout << "\t\t\t\t\t#  Press 3 ---> Purchase                                      #\n";
	cout << "\t\t\t\t\t#                                                             #\n";
	cout << "\t\t\t\t\t#  Press 4 ---> EXIT                                          #\n";
	cout << "\t\t\t\t\t#                                                             #\n";
	cout << "\t\t\t\t\t###############################################################\n";
	cout << endl;
	cout << "\t\t\t Please enter your choice: ";
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 1:
		login();
		goto o;
		break;

	case 2:
		sign_up();
		goto o;
		break;

	case 3:
		recipient();
		goto o;
		break;

	case 4:
		cout << "\t\t\t Thank you !  " << endl
			 << endl;
		break;

	default:
		system("cls");
		cout << "\t\t\t Please select from the above options :" << endl
			 << endl;
		goto o;
	}
}

void LoginPage::login()
{
m:
	int ch;
	int choice;
	string des;
	int count = 0;
	string name, pass;
r:
	system("cls");
	cout << "\t\t\t\t\t#######################################\n";
	cout << "\t\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t\t#          Choose Designation         #\n";
	cout << "\t\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t\t#######################################\n";
	cout << "\t\t\t\t\t|   1) Administrator                 |\n";
	cout << "\t\t\t\t\t|                                    |\n";
	cout << "\t\t\t\t\t|   2) Manager                       |\n";
	cout << "\t\t\t\t\t|                                    |\n";
	cout << "\t\t\t\t\t|   3) Employee                      |\n";
	cout << "\t\t\t\t\t|                                    |\n";
	cout << "\t\t\t\t\t|   4) Exit                          |\n";
	cout << "\t\t\t\t\t|                                    |\n";
	cout << "\t\t\t\t\t#######################################\n";

	cout << "\n\t\t\t\t\t Please select: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPOINT BILLING SYSTEM" << endl;
		cout << "\t\t\t\t\t\t\t\t------------------------------" << endl;
		cout << "\n\t\t\t\t\t\t\t\tLOGIN\n";
		cout << "\t\t\t\t\t\t\t\t------------------------------\n\n";
		cout << "\t\t\t\t\t\t\t\tEnter Username: ";
		cin >> name;
		cout << "\t\t\t\t\t\t\t\tEnter Password: ";

		ch = _getch();
		while (ch != 13)
		{
			if (ch == 8 && !pass.empty())
			{
				pass = pass.substr(0, pass.length() - 1);
				cout << "\b \b";
			}
			else
			{
				if (ch != 8)
				{
					pass.push_back(ch);
					cout << '*';
				}
			}
			ch = _getch();
		}

		fstream login("login.txt", ios::in);

		login >> designation >> username >> password;

		while (!login.eof())
		{
			if (designation == "admin" && name == username && pass == password)
			{
				count = 1;
				system("cls");
			}

			login >> designation >> username >> password;
		}
		login.close();
		if (count == 1)
		{
			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t  Access Granted!  ";
			Sleep(1000);
			system("CLS");
			admin();
			goto r;
		}

		else
		{
			cout << "\n LOGIN ERROR \n Incorrect USERNAME or PASSWORD  :" << endl;
			goto m;
		}
		break;
	}

	case 2:
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPOINT BILLING SYSTEM" << endl;
		cout << "\t\t\t\t\t\t\t\t------------------------------" << endl;
		cout << "\n\t\t\t\t\t\t\t\tLOGIN\n";
		cout << "\t\t\t\t\t\t\t\t------------------------------\n\n";
		cout << "\t\t\t\t\t\t\t\tEnter Username: ";
		cin >> name;
		cout << "\t\t\t\t\t\t\t\tEnter Password: ";
		ch = _getch();
		while (ch != 13)
		{
			if (ch == 8 && !pass.empty())
			{
				pass = pass.substr(0, pass.length() - 1);
				cout << "\b \b";
			}
			else
			{
				if (ch != 8)
				{
					pass.push_back(ch);
					cout << '*';
				}
			}

			ch = _getch();
		}

		fstream login("login.txt", ios::in);

		login >> designation >> username >> password;

		while (!login.eof())
		{
			if (designation == "manager" && name == username && pass == password)
			{
				count = 1;
				system("cls");
			}

			login >> designation >> username >> password;
		}
		login.close();
		if (count == 1)
		{
			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t  Access Granted!  ";
			Sleep(1000);
			system("CLS");
			manager();
			goto r;
		}

		else
		{
			cout << "\n LOGIN ERROR \n Incorrect USERNAME or PASSWORD  :" << endl;
			goto m;
		}
	}

	break;

	case 3:
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPOINT BILLING SYSTEM" << endl;
		cout << "\t\t\t\t\t\t\t\t------------------------------" << endl;
		cout << "\n\t\t\t\t\t\t\t\tLOGIN\n";
		cout << "\t\t\t\t\t\t\t\t------------------------------\n\n";
		cout << "\t\t\t\t\t\t\t\tEnter Username: ";
		cin >> name;
		cout << "\t\t\t\t\t\t\t\tEnter Password: ";
		ch = getch();
		while (ch != 13)
		{
			if (ch == 8 && !pass.empty())
			{
				pass = pass.substr(0, pass.length() - 1);
				cout << "\b \b";
			}
			else
			{
				if (ch != 8)
				{
					pass.push_back(ch);
					cout << '*';
				}
			}

			ch = _getch();
		}

		fstream login("login.txt", ios::in);

		login >> designation >> username >> password;

		while (!login.eof())
		{
			if (designation == "employee" && name == username && pass == password)
			{
				count = 1;
				system("cls");
			}

			login >> designation >> username >> password;
		}
		login.close();
		if (count == 1)
		{
			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t  Access Granted!  ";
			Sleep(1000);
			system("CLS");
			employee();
			goto r;
		}

		else
		{
			cout << "\n LOGIN ERROR \n Incorrect USERNAME or PASSWORD  :" << endl;
			goto m;
		}
		break;
	}
	case 4:
		return;

	default:
		cout << "INVALID CHOICE   !";
		return;
		break;
	}
}

void LoginPage::sign_up()
{
u:
	int ch;
	int choice;
	int count = 0;
	string name;
	string pass;
	system("cls");
	cout << "\t\t\t\t\t#######################################\n";
	cout << "\t\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t\t#          Choose Designation         #\n";
	cout << "\t\t\t\t\t#                                     #\n";
	cout << "\t\t\t\t\t#######################################\n";
	cout << "\t\t\t\t\t|   1) Administrator                 |\n";
	cout << "\t\t\t\t\t|                                    |\n";
	cout << "\t\t\t\t\t|   2) Manager                       |\n";
	cout << "\t\t\t\t\t|                                    |\n";
	cout << "\t\t\t\t\t|   3) Employee                      |\n";
	cout << "\t\t\t\t\t|                                    |\n";
	cout << "\t\t\t\t\t|   4) Exit                          |\n";
	cout << "\t\t\t\t\t|                                    |\n";
	cout << "\t\t\t\t\t#######################################\n";
	cout << "\n\t\t\t Please select!";
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPOINT BILLING SYSTEM" << endl;
		cout << "\t\t\t\t\t\t\t\t------------------------------" << endl;
		cout << "\n\t\t\t\t\t\t\t\tLOGIN\n";
		cout << "\t\t\t\t\t\t\t\t------------------------------\n\n";
		cout << "\t\t\t\t\t\t\t\tEnter Username: ";
		cin >> name;
		cout << "\t\t\t\t\t\t\t\tEnter Password: ";
		ch = getch();
		while (ch != 13)
		{
			if (ch == 8 && !pass.empty())
			{
				pass = pass.substr(0, pass.length() - 1);
				cout << "\b \b";
			}
			else
			{
				if (ch != 8)
				{
					pass.push_back(ch);
					cout << '*';
				}
			}

			ch = _getch();
		}

		fstream login("login.txt", ios::in);
		if (!login.is_open())
		{
			fstream login2("login.txt", ios::out);
			login2.close();

			login.open("login.txt", ios::in);
			if (!login.is_open())
			{
				cout << "Error creating file ! ";
				return;
			}
		}

		while (login >> designation >> name >> pass)
		{
			if (username == name || designation == "admin")
			{
				count = 1;
			}
		}
		login.close();

		if (count == 0)
		{
			fstream registeration("login.txt", ios::out | ios::app);
			registeration << " "
						  << "admin"
						  << " " << username << " " << password << endl;
			cout << "Register successfully :";
			registeration.close();
		}

		else

		{
			cout << "Admin have already register OR :" << endl;
			cout << "Username have been chosen ! Enter unique username :" << endl;
			goto u;
		}
		break;
	}

	case 2:
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPOINT BILLING SYSTEM" << endl;
		cout << "\t\t\t\t\t\t\t\t------------------------------" << endl;
		cout << "\n\t\t\t\t\t\t\t\tLOGIN\n";
		cout << "\t\t\t\t\t\t\t\t------------------------------\n\n";
		cout << "\t\t\t\t\t\t\t\tEnter Username: ";
		cin >> name;
		cout << "\t\t\t\t\t\t\t\tEnter Password: ";
		ch = getch();
		while (ch != 13)
		{
			if (ch == 8 && !pass.empty())
			{
				pass = pass.substr(0, pass.length() - 1);
				cout << "\b \b";
			}
			else
			{
				if (ch != 8)
				{
					pass.push_back(ch);
					cout << '*';
				}
			}

			ch = _getch();
		}

		fstream login("login.txt", ios::in);
		if (!login.is_open())
		{
			fstream login2("login.txt", ios::out);
			login2.close();

			login.open("login.txt", ios::in);
			if (!login.is_open())
			{
				cout << "Error creating file ! ";
				return;
			}
		}

		while (login >> designation >> name >> pass)
		{
			if (username == name || designation == "manager")
			{
				count = 1;
			}
		}
		login.close();

		if (count == 0)
		{
			fstream registeration("login.txt", ios::out | ios::app);
			registeration << " " << "manager" << " " << username << " " << password << endl;
			cout << "Register successfully :";
			registeration.close();
		}

		else

		{
			cout << "Manager have already register OR :" << endl;
			cout << "Username have been chosen ! Enter unique username :" << endl;
			goto u;
		}
		break;
	}
	case 3:
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPOINT BILLING SYSTEM" << endl;
		cout << "\t\t\t\t\t\t\t\t------------------------------" << endl;
		cout << "\n\t\t\t\t\t\t\t\tLOGIN\n";
		cout << "\t\t\t\t\t\t\t\t------------------------------\n\n";
		cout << "\t\t\t\t\t\t\t\tEnter Username: ";
		cin >> name;
		cout << "\t\t\t\t\t\t\t\tEnter Password: ";
		ch = getch();
		while (ch != 13)
		{
			if (ch == 8 && !pass.empty())
			{
				pass = pass.substr(0, pass.length() - 1);
				cout << "\b \b";
			}
			else
			{
				if (ch != 8)
				{
					pass.push_back(ch);
					cout << '*';
				}
			}

			ch = _getch();
		}

		fstream login("login.txt", ios::in);
		if (!login.is_open())
		{
			fstream login2("login.txt", ios::out);
			login2.close();

			login.open("login.txt", ios::in);
			if (!login.is_open())
			{
				cout << "Error creating file ! ";
				return;
			}
		}

		while (login >> designation >> name >> pass)
		{
			if (username == name)
			{
				count = 1;
			}
		}
		login.close();

		if (count == 0)
		{
			fstream registeration("login.txt", ios::out | ios::app);
			registeration << " "
						  << "employee"
						  << " " << username << " " << password << endl;
			cout << "Register successfully :";
			registeration.close();
		}

		else

		{
			cout << "Username have been chosen ! Enter unique username :" << endl;
			goto u;
		}
		break;
	}

	case 4:
	{
		return;
	}

	default:
	{
		cout << "Invalid choice !" << endl;
		goto u;
	}
	}
}

int main()
{
	system("cls");
	cout << "\t\t\t\t\t#############################################################################\n";
	cout << "\t\t\t\t\t##                                                                         ##\n";
	cout << "\t\t\t\t\t##                                                                         ##\n";
	cout << "\t\t\t\t\t##                                                                         ##\n";
	cout << "\t\t\t\t\t##                                                                         ##\n";
	cout << "\t\t\t\t\t##                               WELCOME TO                                ##\n";
	cout << "\t\t\t\t\t##                                                                         ##\n";
	cout << "\t\t\t\t\t##                          POINT BILLING SYSTEM                           ##\n";
	cout << "\t\t\t\t\t##                                                                         ##\n";
	cout << "\t\t\t\t\t##                                                                         ##\n";
	cout << "\t\t\t\t\t##                                                                         ##\n";
	cout << "\t\t\t\t\t##                                                                         ##\n";
	cout << "\t\t\t\t\t##                                                                         ##\n";
	cout << "\t\t\t\t\t#############################################################################\n";

	cout << "\n\n\n\n\t\t\t\t\t";

	cout << "Press any key to choose another option...";
	getch();
	system("cls");
	system("cls");

	LoginPage login;
	login.menu();
}

