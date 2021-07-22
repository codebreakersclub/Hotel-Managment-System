#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include <ctime>
#include <conio.h>
using namespace std;


void addcust();
int searchcustbyid(int id);
void searchcustbyphone();
void searchcustomerbooking();
void enquirerese();
void booking();
void cancelbooking();
void readrese();
void writerese();
void initrese();

struct customer{
	char phone[22];
	char name[20];
	char address[50];
};

struct reservation{
	int yearday, month, date;
	int customerid[20];//note that array index is hotel room number.
};

