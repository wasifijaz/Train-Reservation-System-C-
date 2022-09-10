#include <iostream>
#include <string.h>
#include <fstream>	//for file handling
#include <cstdlib>	//to generate a random number
#include <ctime>	//to generate a random number
#include <sstream>	//to convert interger type to string type

using namespace std;

void menu ();
void admin ();
void user ();
void reservation();
void datacompile();

const int SIZE=5

struct train{
	string name;
	string id;
	string stops [SIZE];
	string arrival [SIZE];
	string departure [SIZE];
}obj;

struct user{
	string name;
	string cnic;
	string city;
	string destination;
	string date;
	string uID;
	int tickets;
}uip;

int main ()
{
	menu ();
	
	return 0;
}

void menu ()
{
	int ch;
	do
	{
		cout<<"=========================================================================\n";
		cout<<"=========================================================================";
		cout<<"\n\n";
		cout<<"\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	    cout<<"\t..........WELCOME TO RAILWAY RESERVATION SYSTEM..........\n";
		cout<<"\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cout<<"\t************************MAIN MENU************************\n\n";
		cout<<"\t1.Administrator mode\n\t2.User mode\n\t3.Exit\n\n";
	    cout<<"\tEnter your choice: ";
	    cin>>ch;
	    cout<<endl;
		switch(ch)
	    {
		    case 1:
	 	     	admin ();
	  	    	break;
	   		case 2:
		   		user();
	        	break;
	    	case 3:
	        	exit(0);
	    }
	}
	while(ch<=3);
}

void admin ()
{
	system("cls");
	int ch, op, conpass;
	const int pass= 123;
	
	cout<<"=========================================================================\n";
	cout<<"=========================================================================";
	cout<<"\n\n";
	cout<<"\t~~~~~~~~~~~~~~~~~~Administrator Mode~~~~~~~~~~~~~~~~~~~~~\n";
	cout<<"\n\tEnter your Password: ";
	cin>>conpass;
	if ( conpass == pass )
		{
			cout<<"\n\tADMINISTRATOR MENU\n";
			cout<<"\t1.Create a New data base\n\t2.Edit details\n\t3.Check Reservations\n\t4.Return to Main menu\n\n\tEnter your choice: ";
			cin>>ch;
			switch(ch)
		    {
				case 1:
					{
						ofstream idb,nos,ni;
						
						cout<<"\n\tPlease Enter the Name of Train: ";
						cin.ignore();
						getline(cin,obj.name);
						cout<<"\tPlease Enter Train ID: ";
						getline(cin,obj.id);
								
						ni.open("Name and ID.txt");
						ni<<"Name of Train: "<<obj.name<<endl<<"ID of Train: "<<obj.id<<"\n"<<endl;
						ni.close();
						
						idb.open((obj.id).c_str());
						idb<<"Name of Train: "<<obj.name<<endl<<"ID of Train: "<<obj.id<<endl;
								
						cout<<"\tInformation of stops (upto 5)";
						for(int i=0; i<SIZE; i++ )
						{
							cout<<"\n\t\tPlease Enter the Name of Stop "<<i+1<<": ";
							getline(cin,obj.stops[i]);
							cout<<"\t\tArrival Time: ";
							getline(cin,obj.arrival[i]);
							cout<<"\t\tDeparture Time: ";
							getline(cin,obj.departure[i]);
									
							idb<<"\tName of Stop "<<i+1<<": "<<obj.stops[i]<<endl<<"\t\tArrival Time: "<<obj.arrival[i]<<endl<<"\t\tDeparture Time: "<<obj.departure[i]<<endl;
						}
						
						nos.open((obj.name).c_str());
						nos<<"150"<<endl;
						
						nos.close();
						idb.close();
						datacompile();
					}
			  		break;
			   	case 2:
			    	{
				    	cout<<"\n\t\t1.Add New Train\n\t\t2.Update Search Panel\n\t\t3.Delete Train\n\n\t\tEnter your choice: ";
				    	cin>>op;
				    	if(op == 1)
						{
							ofstream db,nos,idb,ni;
							
							cout<<"\n\tPlease Enter the Name of Train: ";
							cin.ignore();
							getline(cin,obj.name);
							cout<<"\tPlease Enter Train ID: ";
							getline(cin,obj.id);
							
							ni.open("Name and ID.txt",ios::app);
							ni<<"Name of Train: "<<obj.name<<endl<<"ID of Train: "<<obj.id<<"\n"<<endl;
							ni.close();
						
							db.open("Admin Data.txt",ios::app);
							db<<"Name of Train: "<<obj.name<<endl <<"ID of Train: "<<obj.id<<endl;
							
							idb.open(obj.id.c_str());
							idb<<"Name of Train: "<<obj.name<<endl<<"ID of Train: "<<obj.id<<endl;
							
							cout<<"\tInformation of stops (upto 5)";
							for(int i=0; i<SIZE; i++ )
							{
								cout<<"\n\t\tPlease Enter the Name of Stop "<<i+1<<": ";
								getline(cin,obj.stops[i]);
								cout<<"\t\tArrival Time: ";
								getline(cin,obj.arrival[i]);
								cout<<"\t\tDeparture Time: ";
								getline(cin,obj.departure[i]);
								
								db<<"\tName of Stop "<<i+1<<": "<<obj.stops[i]<<endl<<"\t\tArrival Time: "<<obj.arrival[i]<<endl<<"\t\tDeparture Time: "<<obj.departure[i]<<endl;

								idb<<"\tName of Stop "<<i+1<<": "<<obj.stops[i]<<endl<<"\t\tArrival Time: "<<obj.arrival[i]<<endl<<"\t\tDeparture Time: "<<obj.departure[i]<<endl;
							}
							cout<<"\n";
						
							nos.open((obj.name).c_str());
							nos<<"150"<<endl;
						
							nos.close();
							db.close();
							idb.close();
						}
						else if (op == 2)
						{
							string id, getcontent;
							char x;
							ofstream edb,nos;
							ifstream db;
						{
							 
							cout<<"\n\tPlease Enter Train ID: ";
							cin.ignore();
							getline(cin,id);
							db.open(id.c_str());
							if (db.is_open())
							{	
								while(getline(db, getcontent))
								{
							    	cout <<"\n\t\t"<< getcontent << endl;
								}
								cout<<"\n\tIs this the Train that you wish to edit?[y/n]: ";
								cin>>x;
								if (x == 'y')
								{
									cout<<"\n\tPlease Enter the Name of Train: ";
									cin.ignore();
									getline(cin,obj.name);
									cout<<"\tPlease Enter Train ID: ";
									getline(cin,obj.id);
									
									edb.open((obj.id).c_str());
									edb<<"Name of Train: "<<obj.name<<endl <<"ID of Train: "<<obj.id<<endl;
									cout<<"\tInformation of stops (upto 10)";
									for(int i=0; i<SIZE; i++ )
									{
										cout<<"\n\t\tPlease Enter the Name of Stop "<<i+1<<": ";
										getline(cin,obj.stops[i]);
										cout<<"\t\tArrival Time: ";
										getline(cin,obj.arrival[i]);
										cout<<"\t\tDeparture Time: ";
										getline(cin,obj.departure[i]);
																			
										edb<<"\tName of Stop "<<i+1<<": "<<obj.stops[i]<<endl<<"\t\tArrival Time: "<<obj.arrival[i]<<endl<<"\t\tDeparture Time: "<<obj.departure[i]<<endl;
									}
									cout<<"\n\tData Entry Succussfully!\n";
									
									nos.open((obj.name).c_str());
									nos<<"150"<<endl;
									
									edb.close();
									nos.close();
									
									remove("Admin Data.txt");
									datacompile();
								}
								else
								{
									cout<<"\n";
									admin();
								}
							}
							else
							{
								cout << "\tCould not open file." << endl;
							}
						}
						}
						else if (op == 3)
						{
							{
								char x;
								string id,getcontent,name;
								ifstream db,nos;
								
								cout<<"\n\tPlease enter Train name: ";
								cin.ignore();
								getline(cin,name);
								cout<<"\tPlease enter the Train ID:  ";
								getline(cin,id);
								
								db.open(id.c_str());
								while(getline(db, getcontent))
								{
							    	cout <<"\n\t\t"<< getcontent << endl;
								}
								db.close();
								
								cout<<"\n\tAre you sure you want to remove this data? [y/n]: ";
								cin>>x;
								if(x =='y')
								{
									remove(name.c_str());
									remove(id.c_str());
									cout<<"\n\tTrain removed Successfully!\n";
								}
								remove("Admin Data.txt");
								datacompile();
							}
						}
					}
			    	break;
				case 3:
					{
						system("cls");
						string getcontent;
						ifstream infile,rev;
						
						rev.open("Total Revenue.txt");
						
						while(getline(rev, getcontent))
						{
						    cout <<"\n\tTotal Revenue: "<< getcontent << endl;
						}
						rev.close();
						
						cout<<"\n\t\tDetails of Reservation\n";
						
						infile.open("User Data.txt");
						if(infile.is_open())
						{
							while(getline(infile, getcontent))
							{
							    cout <<"\n\t"<< getcontent << "\n\n";
							}
							infile.close();
						}
						else
						{
							cout<<"\n\tSorry! No User Data found\n";
						}
						infile.close();
						
					}
					break;
				case 4:
					{
						system("cls");
						menu ();
						break;
					}
			}
		}
		else
		{
			cout<<"\tInvalid Password\n\n";
			menu ();
		}
}

void user ()
{
	system("cls");
	int ch;
	ifstream f;
	int op;
	cout<<"=========================================================================\n";
	cout<<"=========================================================================";
	cout<<"\n\n";
	cout<<"\t~~~~~~~~~~~~~~~~~~~~~~~User Mode~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout<<"\n\t1.View Trains\n\t2.Make your Reservation\n\t3.Check Reservation\n\t4.Return to Main menu\n\n\tEnter your choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:
		    {
				cout<<"\n\t\t1.Dispaly Train Timings\n\t\t2.Search Train by ID\n\n\t\tEnter your choice: ";
			    cin>>op;
				switch(op)
			    {
			    	case 1:
						{
							string getcontent;
							ifstream infile;
							infile.open("Admin Data.txt");
							while(getline(infile, getcontent))
							{
							    cout <<"\n\t"<< getcontent << endl;
							}
							infile.close();	
						}
						break;
					
					case 2:
						{
							string getcontent;
							string id;
							cout<<"\n\t\tEnter Train ID: ";
							cin.ignore();
	    					getline(cin,id);
							ifstream db;
							
							db.open(id.c_str());
							if (db.is_open())
							{	
								while(getline(db, getcontent))
								{
							    	cout <<"\n\t\t"<< getcontent << endl;
								}
							}
							else
							{
								cout<<"\n\tSorry! Train not found\n";
							}
							db.close();
						}
						break;
				}
			}
			break;
		case 2:
   			reservation ();
		    break;
	    case 3:
	    	{
	    		string getcontent;
				string id;
				cout<<"\n\t\tEnter Booking ID: ";
				cin.ignore();
	    		getline(cin,id);
				ifstream db;
							
				db.open(id.c_str());
				if (db.is_open())
				{	
					while(getline(db, getcontent))
					{
						cout <<"\n\t\t"<< getcontent << endl;
					}
				}
				else
				{
					cout<<"\n\tSorry! No booking record found\n";
				}
			}
	        break;
	    case 4:
	    	system("cls");
			menu ();
			break;
		}
}

void reservation()
{
	ofstream rs;
	ifstream ni,fin,nos;
	string tid,tn,getcontent;
	int s;
	
	ni.open("Name and ID.txt");
	while(getline(ni, getcontent))
	{
		cout <<"\n\t\t"<< getcontent << endl;
	}
	ni.close();
	
	cout<<"\n\tPlease Enter Name of Train: ";
	cin.ignore();
	getline(cin,tn);
	cout<<"\tPlease Enter Train ID: ";
	getline(cin,tid);
	
	fin.open(tid.c_str());
	nos.open(tn.c_str());
	int seats;
	nos>>seats;
	nos.close();
	
	if(fin.fail())
	{
		cout<<"\n\tSorry no Train Record found\n";
	}
	else
	{
		cout<<"\tNumber of Seats Remaining in "<<tid<<": "<<seats<<"\n\n";
		int bookedseats = 150 - seats;
		for(int i = 0; i<5; i++)
		{
			cout<<"\t";
			for (int j =0; j<25; j++)
			{
				if (bookedseats > 0)
				{
					cout<<"x ";
					bookedseats = bookedseats - 1;
				}
				else
				{
					cout<<"* ";
				}
			}
			cout<<"\n";
		}
		
		
		if(seats<=0)
		{
			cout<<"\tSORRY!"<<endl<<"\tNo  Seat Available\t\n";
		}
		else
		{
			string num;
			int number,fare;
			ostringstream oss;
			static const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			int n = 2; 
				
			srand(time(NULL));
			number = rand() % 9000 + 1000;
			srand(time(NULL)); 
			string res = ""; 
		    for (int i = 0; i < n; i++)
			{
		        res = res + alphanum[rand() % 26];
		    }
			oss<<number;
			num=res+=oss.str();
				
			cout<<"\n\tPlease Enter you Name: ";
			istream& ignore (streamsize n = 1, int delim = EOF);
			getline(cin,uip.name);
			cout<<"\tPlease Enter your CNIC: ";
			getline(cin,uip.cnic);
			cout<<"\tFrom where do you plan to travel (Use full name): ";
			getline(cin,uip.city);
			cout<<"\tWhere do you plan to travel (Use full name): ";
			getline(cin,uip.destination);
			cout<<"\tOn which date you plan to travel: ";
			getline(cin,uip.date);
			cout<<"\tNumber of tickets you want to book: ";
			cin>>uip.tickets;
			
			seats=seats-uip.tickets;
			rs.open(tn.c_str());
			rs<<seats;
			rs.close();
			
			cout<<"\n\tYour booking ID is: "<<num<<"\n";
			
			if(uip.city == "Rawalpindi" && uip.destination == "Karachi" || uip.city == "Karachi" && uip.destination == "Rawalpindi" || uip.city == "Peshawar" && uip.destination == "Karachi" || uip.city == "Karachi" && uip.destination == "Peshawar")
			{
				fare = uip.tickets*6000;
				cout<<"\tTotal Fare for "<<uip.tickets<<" tickets: "<<fare<<"\n";
			}
			else if(uip.city == "Rawalpindi" && uip.destination == "Hyderabad" || uip.city == "Hyderabad" && uip.destination == "Rawalpindi" || uip.city == "Karachi" && uip.destination == "Lahore" || uip.city == "Lahore" && uip.destination == "Karachi")
			{
				fare = uip.tickets*5500;
				cout<<"\tTotal Fare for "<<uip.tickets<<" tickets: "<<fare<<"\n";
			}
			else if(uip.city == "Jehlum" && uip.destination == "Sahiwal" || uip.city == "Sahiwal" && uip.destination == "Jehlum" || uip.city == "Sahiwal" && uip.destination == "Karachi" || uip.city == "Karachi" && uip.destination == "Sahiwal" || uip.city == "Hyderabad" && uip.destination == "Faisalabad" || uip.city == "Faisalabad" && uip.destination == "Hyderabad" || uip.city == "Multan" && uip.destination == "Karachi" || uip.city == "Karachi" && uip.destination == "Multan")
			{
				fare = uip.tickets*4000;
				cout<<"\tTotal Fare for "<<uip.tickets<<" tickets: "<<fare<<"\n";
			}
			else if(uip.city == "Rawalpindi" && uip.destination == "Bahawalpur" || uip.city == "Bahawalpur" && uip.destination == "Rawalpindi" || uip.city == "Karachi" && uip.destination == "Faisalabad" || uip.city == "Faisalabad" && uip.destination == "Karachi" || uip.city == "Lahore" && uip.destination == "Hyderabad" || uip.city == "Hyderabad" && uip.destination == "Lahore" || uip.city == "Karachi" && uip.destination == "Bahawalpur" || uip.city == "Bahawalpur" && uip.destination == "Karachi" || uip.city == "Peshawar" && uip.destination == "Khanpur" || uip.city == "Khanpur" && uip.destination == "Peshawar" || uip.city == "Multan" && uip.destination == "Hyderabad" || uip.city == "Hyderabad" && uip.destination == "Multan")
			{
				fare = uip.tickets*3000;
				cout<<"\tTotal Fare for "<<uip.tickets<<" tickets: "<<fare<<"\n";
			}
			else if(uip.city == "Bahawalpur" && uip.destination == "Hyderabad" || uip.city == "Hyderabad" && uip.destination == "Bahawalpur" || uip.city == "Peshawar" && uip.destination == "Sahiwal" || uip.city == "Sahiwal" && uip.destination == "Peshawar" || uip.city == "Jehlum" && uip.destination == "Khanpur" || uip.city == "Khanpur" && uip.destination == "Jehlum" || uip.city == "Karachi" && uip.destination == "Khanpur" || uip.city == "Khanpur" && uip.destination == "Karachi" || uip.city == "Mirpur Khas" && uip.destination == "Dhabeji" || uip.city == "Dhabeji" && uip.destination == "Mirpur Khas" || uip.city == "Sukkur" && uip.destination == "Rahim Yar Khan" || uip.city == "Rahim Yar Khan" && uip.destination == "Sukkur")
			{
				fare = uip.tickets*2000;
				cout<<"\tTotal Fare for "<<uip.tickets<<" tickets: "<<fare<<"\n";
			}
			else if(uip.city == "Mirpur Khas" && uip.destination == "Jhimpir" || uip.city == "Jhimpir" && uip.destination == "Mirpur Khas" || uip.city == "Dhabeji" && uip.destination == "Kotri" || uip.city == "Kotri" && uip.destination == "Dhabeji" || uip.city == "Dhabeji" && uip.destination == "Tando Jam" || uip.city == "Tando Jam" && uip.destination == "Dhabeji" || uip.city == "Dhabeji" && uip.destination == "Jhimpir" || uip.city == "Jhimpir" && uip.destination == "Dhabeji" || uip.city == "Sukkar" && uip.destination == "Reti" || uip.city == "Reti" && uip.destination == "Sukkur" || uip.city == "Pani Akil" && uip.destination == "Rahim Yar Khan" || uip.city == "Rahim Yar Khan" && uip.destination == "Pani Akil")
			{
				fare = uip.tickets*1500;
				cout<<"\tTotal Fare for "<<uip.tickets<<" tickets: "<<fare<<"\n";
			}
			else if(uip.city == "Rawalpindi" && uip.destination == "Lahore" || uip.city == "Lahore" && uip.destination == "Rawalpindi" || uip.city == "Multan" && uip.destination == "Faisalabad" || uip.city == "Faisalabad" && uip.destination == "Multan" || uip.city == "Peshawar" && uip.destination == "Jehlum" || uip.city == "Jehlum" && uip.destination == "Peshawar" || uip.city == "Jehlum" && uip.destination == "Sahiwal" || uip.city == "Sahiwal" && uip.destination == "Jehlum" || uip.city == "Sahiwal" && uip.destination == "Khanpur" || uip.city == "Khanpur" && uip.destination == "Sahiwal" || uip.city == "Lahore" && uip.destination == "Multan" || uip.city == "Multan" && uip.destination == "Lahore" || uip.city == "Mirpur Khas" && uip.destination == "Kotri" || uip.city == "Kotri" && uip.destination == "Mirpur Khas"  || uip.city == "Jhimpur" && uip.destination == "Tando Jam" || uip.city == "Tando Jam" && uip.destination == "Jhimpur")
			{
				fare = uip.tickets*1000;
				cout<<"\tTotal Fare for "<<uip.tickets<<" tickets: "<<fare<<"\n";
			}
			else if(uip.city == "Mirpur Khas" && uip.destination == "Tando Jam" || uip.city == "Tando Jam" && uip.destination == "Mirpur Khas" || uip.city == "Kotri" && uip.destination == "Tando Jam" || uip.city == "Tando Jam" && uip.destination == "Kotri" || uip.city == "Lahore" && uip.destination == "Faisalabad" || uip.city == "Faisalabad" && uip.destination == "Lahore" || uip.city == "Karachi" && uip.destination == "Hyderabad" || uip.city == "Hyderabad" && uip.destination == "Karachi" || uip.city == "Kotri" && uip.destination == "Jhimpir" || uip.city == "Jhimpir" && uip.destination == "Kotri" || uip.city == "Sukkur" && uip.destination == "Sarhad" || uip.city == "Sarhad" && uip.destination == "Sukkur" || uip.city == "Pani Akil" && uip.destination == "Reti" || uip.city == "Reti" && uip.destination == "Pani Akil" || uip.city == "Rahim Yar Khan" && uip.destination == "Sarhad" || uip.city == "Sarhad" && uip.destination == "Rahim Yar Khan")
			{
				fare = uip.tickets*500;
				cout<<"\tTotal Fare for "<<uip.tickets<<" tickets: "<<fare<<"\n";
			}
			else if(uip.city == "Sukkar" && uip.destination == "Pani Akil" || uip.city == "Pani Akil" && uip.destination == "Sukkur" || uip.city == "Pani Akil" && uip.destination == "Sarhad" || uip.city == "Sarhad" && uip.destination == "Pani Akil" || uip.city == "Reti" && uip.destination == "Sarhad" || uip.city == "Sarhad" && uip.destination == "Reti" || uip.city == "Reti" && uip.destination == "Rahim Yar Khan" || uip.city == "Rahim Yar Khan" && uip.destination == "Reti")
			{
				fare = uip.tickets*200;
				cout<<"\tTotal Fare for "<<uip.tickets<<" tickets: "<<fare<<"\n";
			}
			
			ofstream f,fdata,rev;
			
			f.open(num.c_str());
			f<<"User ID: "<<num<<endl<<"Name: "<<uip.name<<endl<<"CNIC: "<<uip.cnic<<endl<<"City: "<<uip.city<<endl<<"Destination: "<<uip.destination<<endl<<"Travelling Date: "<<uip.date<<endl<<"Train Booked: "<<tid<<endl<<"No. of Tickets: "<<uip.tickets<<endl<<"Total Fare: "<<fare<<"\n=========================================================================\n";
			f.close();
				
			fdata.open("User Data.txt",ios::app);	
			fdata<<"User ID: "<<num<<endl<<"Name: "<<uip.name<<endl<<"CNIC: "<<uip.cnic<<endl<<"City: "<<uip.city<<endl<<"Destination: "<<uip.destination<<endl<<"Travelling Date: "<<uip.date<<endl<<"Train Booked: "<<tid<<endl<<"No. of Tickets: "<<uip.tickets<<endl<<"Total Fare: "<<fare<<"\n=========================================================================\n";
			fdata.close();
			
			ifstream r;
			r.open("Total Revenue.txt");
			int revenue;
			r>>revenue;
			r.close();
			
			revenue=revenue+fare;
			rev.open("Total Revenue.txt");
			rev<<revenue<<endl;
			rev.close();
		}
	}
}

void datacompile()
{
	ifstream fin,fin1,fin2,fin3,fin4,fin5,fin6,fin7,fin8,fin9,fin10;

    ofstream fout;
    fout.open("Admin Data.txt",ios::app);
    string getcontent;

    fin.open("pk001",ios::in);
    while(getline(fin, getcontent))
	{
		fout << getcontent << endl;
	}
    fin.close();
    
	fin1.open("pk002",ios::in);
    while(getline(fin1, getcontent))
	{
		fout << getcontent << endl;
	}
    fin1.close();
    
    fin2.open("pk003",ios::in);
	while(getline(fin2, getcontent))
	{
		fout << getcontent << endl;
	}
	fin2.close();
	
	fin3.open("pk004",ios::in);
	while(getline(fin3, getcontent))
	{
		fout << getcontent << endl;
	}
	fin3.close();
	
	fin4.open("pk005",ios::in);
	while(getline(fin4, getcontent))
	{
		fout << getcontent << endl;
	}
	fin4.close();
	
	fin5.open("pk006",ios::in);
	while(getline(fin5, getcontent))
	{
		fout << getcontent << endl;
	}
	fin5.close();
	
	fin6.open("pk007",ios::in);
	while(getline(fin6, getcontent))
	{
		fout << getcontent << endl;
	}
	fin6.close();
	
	fin7.open("pk008",ios::in);
	while(getline(fin7, getcontent))
	{
		fout << getcontent << endl;
	}
	fin7.close();
	
	fin8.open("pk009",ios::in);
	while(getline(fin8, getcontent))
	{
		fout << getcontent << endl;
	}
	fin8.close();
	
	fin9.open("pk010",ios::in);
	while(getline(fin9, getcontent))
	{
		fout << getcontent << endl;
	}
	fin9.close();
	
	fin10.open("pk011",ios::in);
	while(getline(fin10, getcontent))
	{
		fout << getcontent << endl;
	}
	fin10.close();
}

