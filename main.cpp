#include "func.h"

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

