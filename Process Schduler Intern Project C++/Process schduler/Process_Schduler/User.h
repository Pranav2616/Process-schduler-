#pragma once
#include<iostream>
#include<vector>
#include"Structure.h"
using namespace std; 
class User
{
protected : 

	vector<Logindetails>login_list; 
	int size_of_login_list; 
	vector<Process>processlist; 
	int size_of_processlist; 
	vector<Processqueue>ready_to_run; 
	int cpucount; 
	int processcount; 

	const char* start = "Ready to run "; 
	const char* wait = " waiting";
	const char* stop = " Stopped"; 
	const char* complete = " Completed"; 
	const char* running = " Running";

	void intiateUser();
	void readUser();
	void readProcess(); 
	void show_ProcessList(); 
	void addprocessbyUser(); 
	void waitingtimereduction(); 
	void process_status(); 
	void restart_Process(); 
	bool Process_completioncheck(); 
	void Process_log(); 

public : 

	void authenticate(); 


};

