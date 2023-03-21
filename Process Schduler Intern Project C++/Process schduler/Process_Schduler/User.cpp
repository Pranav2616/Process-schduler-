#include "User.h"
#include<iostream>
#include"Structure.h"
using namespace std; 

void User::authenticate() {

	readProcess();
	readUser(); 
	char Username[20]; 
	char password[20]; 

	bool flag = true; 

	while (true) {
		cout << "Enter The Username :-"; 
		cin >> Username; 
		cout << " Enter the Password :-";
		cin >> password; 

		for (int i = 0; i < size_of_login_list; i++) {
			if (!strcmp(login_list[i].username, Username) && !strcmp(login_list[i].password, password)) {
				cout << "Logged in as" << login_list[i].username << endl; 
				intiateUser(); 
				flag = false; 
				break; 
			}
		}

		if(flag)
		  cout << " Invalid User" << endl; 
	}
}

void User::Process_log() {

	cout << " Process Log :- " << endl; 
	cout << "Process name" << "\t" << "time taken" << endl; 
	for (int i = 0; i < processcount; i++) {
		cout << ready_to_run[i].name << "\t" << ready_to_run[i].total_time << endl;
	}
}