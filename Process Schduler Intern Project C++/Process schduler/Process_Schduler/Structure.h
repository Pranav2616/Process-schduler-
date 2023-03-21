#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std; 

typedef struct login {
	char username[20]; 
	char password[20]; 
}Logindetails;

typedef struct process {
	char name[20]; 
	int waiting_cycles; 
	int completion_cycles; 
}Process;

typedef struct process_data {
	char name[20]; 
	char status[20]; 
	int waiting_count;
	int waiting_cycles; 
	int completion_cycles; 
	int completion_count; 
	int total_time; 
} Processqueue;

class Structure
{
};

