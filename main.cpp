#include <iostream>
#include <cstring>
#include <fstream>
#include <ctime>
#include <conio.h>
using namespace std;
time_t t; // t passed as argument in function time()
struct tm * tt; // declaring variable for localtime()

struct customer{
	char phone[22];
	char name[20];
	char address[50];
};

struct reservation{
	int yearday, month, date;
	int customerid[20];//note that array index is hotel room number.
};

reservation rese[366];
customer cust;

bool room[20]={0};
void addcust(){
// Add customer in customer.txt file in data folder 
//with attributes as given in struct customer.
	
	int dt,mon,yr;
	cout<<"Enter date:\n";
	cin>>dt;
	cout<<"Enter Month:\n";
	cin>>mon;

//check date
	int d=-1;

	for(int i=0;i<366;++i)
	{
		if(rese[i].date==dt && rese[i].month==mon)
		{
			d=i;
			break;
		}
	}

	if(d==-1)
	{
		cout<<"Invalid Date\n";
		return;
	}

// check room available
	int emp=-1;
	for(int j=0;j<20;j++)
	{
		if(rese[d].customerid[j]==-1)
		{	
			emp=j;
			room[j]=true;
			break;
		}
	}
	
	if(emp==-1)
	{
		cout<<"No room empty\n";
		return;
	}

//Read costumers from customer.txt in database folder
    fstream customerFile;
    customerFile.open("database/customer.txt", ios::binary | ios::in | ios::app);
	
	int customerId = 0;
	while(!customerFile.eof()) {
		customerFile.read((char*) &cust, sizeof(cust));
		customerId++;
	}

    cout<<"Enter Name: ";
    cin>>cust.name;
    
    cout<<"Enter Address: ";
    cin>>cust.address;
    
    cout<<"Enter Phone no.: ";
    cin>>cust.phone;

	rese[d].customerid[emp] = customerId;

    customerFile.write((char*) &cust, sizeof(cust));

}

int searchcustbyid(int id){
// search customer details with their id. Note that no id is stored	in a customer file.
//id is basically the number of record in customer file starting from 0.
	fstream customerFile;
    customerFile.open("database/customer.txt", ios::binary | ios::in);
	int i;
	
	for(i=0; i<=id && !customerFile.eof(); i++) {
		customerFile.read((char*) &cust, sizeof(cust));
	}

	if (i-1 == id) {
		cout<<"Customer Found\n";
		cout<<"Customer id\t"<<id<<endl;
		cout<<"Customer phone: "<<cust.phone<<endl;
		cout<<"Customer Name: "<<cust.name<<endl;
		cout<<"Customer Address: "<<cust.address<<endl;
		return 1;
	}

	cout<<"Customer not found!!!\n";
	return 0;

}

void searchcustbyphone(){
//search customer by phone number and display all the attributes including customer id.	
	char phone[22];

	cout<<"Enter phone number: ";
	cin>>phone;
	fstream customerFile;
    customerFile.open("database/customer.txt", ios::binary | ios::in | ios::app);

	int customerId = 0;
	while (!customerFile.eof()) {
		customerFile.read((char*) &cust, sizeof(cust));
		if (cust.phone == phone) {
			cout<<"Customer Found!\n";
			cout<<"Customer Id: "<<customerId;
			cout<<"Customer Phone: "<<cust.phone;
			cout<<"Customer Name: "<<cust.name;
			cout<<"Customer Address: "<<cust.address;
			return;
		}
		customerId++;
	}
	cout<<"Customer not found!!!\n";
}

void searchcustomerbooking(){
//search customer booking throughout the year using customer id.	
	int id;
	cin>>id;

	int booking[366][4] = {0};

	for(int i=0;i<366;++i)
	{
		for(int j=0;j<20;++j)
		{
			if(rese[i].customerid[j]==id)
			{

			}
		}
	}
}

void enquirerese(){
//Display all the rooms available for booking on a particular date. 
//Note that rooms with customer id == -1 are available.
	int dt,mon,yr;
	cout<<"Enter date:\n";
	cin>>dt;
	cout<<"Enter Month:\n";
	cin>>mon;
	cout<<"Enter Year:\n";
	cin>>yr;

	int d=-1;

	for(int i=0;i<366;++i)
	{
		if(rese[i].date==dt && rese[i].month==mon && rese[i].yearday==yr)
		{
			d=i;
			break;
		}
	}
	if(d==-1)
	{
		cout<<"Invalid Date\n";
		return;
	}
	for(int j=0;j<20;j++)
	{
		if(rese[d].customerid[j]==-1)
		{
			cout<<j<<" ";
		}
	}
	cout<<endl;
}

void booking(){
//First search customer in customer file by calling searchcustomerbyphone() in main menu. 
//If customer exist and if room is vacant, book the room by updating customer ID.
//If customer do not exist, call addcustomer in main menu. Then do the booking.


}
void cancelbooking(){
//Cancel the booking if customer booking exist for the rooms on a particular date.
}

void readrese(){//Fully defined.
//Read file "reservationbin.txt" in database folder and initialize global variable rese.
	ifstream ihs;
	ihs.open("database/reservationbin.txt", ios::in|ios::binary);
	ihs.read( (char *) & rese, sizeof(rese));
	ihs.close();
}

void writerese(){//Fully defined
//update file "database/reservationbin.txt" with current value of global variable rese.
	ofstream ohs;
	ohs.open("database/reservationbin.txt", ios::out|ios::binary);
	ohs.write( (char *) & rese, sizeof(rese));
	ohs.close();
}


void initrese() {// Fully defined.
// Setup local database reservation.txt
	time_t t0, t1=1577860200;
	for (int i=0;i<366;i++)	
	{
		t0 = t1 +24*3600*i;
		tm* tp = localtime(&t0);
		rese[i].date = tp->tm_mday;
		rese[i].month = tp->tm_mon+1;
		rese[i].yearday= tp->tm_yday;

		cout<<endl<<rese[i].yearday<<' '<<rese[i].date<<' '<<rese[i].month<<' ';

		for(int j=0;j<20;j++){
			rese[i].customerid[j]=-1;
			cout<<rese[i].customerid[j]<<' ';
		}
	}

	ofstream ohs;
	ohs.open("database/reservationbin.txt", ios::out|ios::binary);
	ohs.write( (char *) & rese, sizeof(rese));
	ohs.close();
}

int main()
{
	readrese();
	cout<<"Welcome to Hotel Management Software\n";
	int x;
	xx:
	cout<<"Press 0 for availability"<<endl;
	cout<<"Press 1 for search customer by phone no."<<endl;
	cout<<"Press 2 for search customer by id"<<endl;
	cout<<"Press 3 for adding new customer"<<endl;
	cout<<"Press 4 for reservation"<<endl;
	cout<<"Press 5 to search customer reservation"<<endl;
	cout<<"Press 6 to cancel reservation"<<endl;
	cout<<"Press 7 to exit"<<endl;


	cin>>x;

	switch(x){
		case 0:{enquirerese();	break;	}
		case 1:{searchcustbyphone();break;	}
		case 2:{long id; cout<<"Enter customer id\n";
					cin >>id;
					searchcustbyid(id); break; }
		case 3:{addcust(); break; }
		case 4:{booking(); break; }
		case 5:{searchcustomerbooking(); break; }
		case 6:{cancelbooking(); break; }
	}

	if(x!=7)
	goto xx;

	writerese();

}

