
#define _CRT_SECURE_NO_WARNINGS
#include"Structure.h"
#include "Admin.h"
#include"User.h"
#include<iostream>
using namespace std; 

void Admin::authenticate() {

	char username[30]; 
	char password[30]; 

	cout << " Enter Username:- " << endl; 
	cin >> username; 
	cout << " Enter password:- " << endl; 
	cin >> password; 

	if (strcmp(username, "admin") && strcmp(password, "admin")) {
		intiateAdminProcess(); 
	}
	else {
		cout << " Invalid admin Username or password" << endl; 
	}

}

void Admin :: intiateAdminProcess() {

}

int Admin::print_admin_option() {

	int option; 

	cout << "Press 1 create the User" << endl; 
	cout << "Press 2 see all the User" << endl;
	cout << "Press 3 delete the User" << endl;
	cout << "Press 4 create the process" << endl;
	cout << "Press 5 see all the Process" << endl;
	cout << "Press 6 delete the Process" << endl;
	cout << "Press 0 to exit " << endl; 
	cin >> option; 
	return option; 

}

void Admin::createUser() {

	Logindetails ld; 
	cout << "Enter the Username :" << endl; 
	cin >> ld.username; 
	cout << "Enter the password: " << endl; 
	cin >> ld.password; 

	size_of_login_list = login_list.size();

	login_list.push_back(ld); 
	writeUser(); 
}

void Admin::PrintUser() {

	int n = login_list.size();

	for (int i = 0; i < n; i++) {
		cout << i + 1 << "\t" << login_list[i].username << "\t" << login_list[i].password << endl;
	}

}

void Admin::writeUser() {

	FILE* fp = fopen("User details By admin .txt", "wt"); 

	for (auto i : login_list)
		fwrite(&i, sizeof(Logindetails), 1, fp);
    
	fclose(fp); 
}

void Admin::DeleteUser() {

	int n; 
	cout << " Enter the User Id which you want delete" << endl; 
	while (true) {

		cin >> n; 
		if (n > size_of_login_list)
			break; 
		cout << " inavlid User id " << endl;
	}
	login_list.erase(login_list.begin() + n - 1); 
}

void Admin::createProcess() {

	Process p; 

	cout << "Enter the name of Process" << endl; 
	cin >> p.name;
	cout << " Enter the waiting cycles required:-  " << endl; 
	cin >> p.waiting_cycles;
	cout << "Enter the completion cycles required :- " << endl;
	cin >> p.completion_cycles; 

	processlist.push_back(p); 
	size_of_processlist = sizeof(processlist); 
	writeProcess(); 
}

void Admin::writeProcess() {

	FILE* fp = fopen("Process details.txt", "wt"); 

	for (auto i : processlist)
		fwrite(&i, sizeof(Process), 1, fp); 

	fclose(fp);
}

void Admin::deleteProcess()
{
	int enter_id; 

	while (true) {
		show_ProcessList(); 
		cout << "Enter 0 to skip deletion " << endl;
		cin >> enter_id; 
		if (enter_id <= size_of_processlist && enter_id != 0)
			processlist.erase(processlist.begin() + enter_id - 1);
		if (enter_id == 0)
			break; 
	}
	size_of_processlist = processlist.size(); 
	writeProcess(); 

}

void User::show_ProcessList()
{
	for (int i = 0; i < size_of_processlist; i++)
		cout << i + 1 << "\t" << processlist[i].name << endl;

}
