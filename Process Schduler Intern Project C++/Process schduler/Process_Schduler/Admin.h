#pragma once
#include<iostream>
#include"Structure.h"; 
#include"User.h"; 

class Admin: private User
{
private:

	int print_admin_option(); 
	void intiateAdminProcess(); 

	void createUser(); 
	void DeleteUser(); 
	void writeUser(); 
	void PrintUser(); 

	void createProcess(); 
	void deleteProcess(); 
	void writeProcess();

public:

	void authenticate();

};

