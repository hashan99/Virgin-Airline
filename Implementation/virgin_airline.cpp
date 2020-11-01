#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<bits/stdc++.h>
#include<iomanip>

using namespace std;

class FlightDetails
{
private:
	string FlightNo;
	string DepDateandTime;
	string DepAirport;
	string ArrAirport;
	int SeatCount_E;
	int SeatCount_B;
	
public:
	int FlightSeats[60][7];
	
	FlightDetails(){}

	FlightDetails (string flightno,string depdateandtime,string depairport,string arrairport,int arr[60][7],int seatcount_E,int seatcount_B)
	{   
		FlightNo = flightno;
		DepDateandTime = depdateandtime;
		DepAirport = depairport;
		ArrAirport = arrairport;
		SeatCount_E = seatcount_E;
		SeatCount_B = seatcount_B;
		
		for(int i=0;i<60;i++)
		{                							//*******reset array..
			for(int j=0;j<7;j++)
				FlightSeats[i][j]='\0';
		}

		
		for(int x=0;x<60;x++)
		{  											//copying class array......
			for(int y=0;y<7;y++)
			{
				if(arr[x][0]!=0)
				{
					FlightSeats[x][y]=arr[x][y];
				}
			}
		}
	}
	
	string view_FlightNo();
	string view_DepDateandTime();
	string view_DepAirport();
	string view_ArrAirport();
	
	int view_SeatCount_E();
	int view_SeatCount_B();

	void display_details();
	void display_seats();
	void display_array();
	void booking_complete();
	void not_avail();

	int book(int x, char y);

};

void FlightDetails::display_details()
{   
	
	

	if(SeatCount_E+SeatCount_B>0)
	{
		cout << "\t" << "--------------------------------" << endl;
		cout << endl << "\t" <<  FlightNo << endl;
		cout << "\t" << DepDateandTime << endl;;
		cout << "\t" << DepAirport << endl;
		cout << "\t" << ArrAirport << endl << endl;

		cout << "\t" << "Available Seats in Class E : " << SeatCount_E << endl;
		cout << "\t" << "Available Seats in Class B : " << SeatCount_B << endl << endl;
		cout << "\t" << "--------------------------------" << endl;
	}
}


string FlightDetails::view_FlightNo()
{
	return FlightNo;
}

string FlightDetails::view_DepDateandTime()
{
	return DepDateandTime;
}

string FlightDetails::view_DepAirport()
{
	return DepAirport;
}

string FlightDetails::view_ArrAirport()
{
	return ArrAirport;
}

int FlightDetails::view_SeatCount_E()
{
	return SeatCount_E;
}

int FlightDetails::view_SeatCount_B()
{
	return SeatCount_B;
}

void FlightDetails::display_seats()
{
	for(int i=0; i<60; i++)
	{
		if(FlightSeats[i][0]==1)
		{
			cout << "\t" << "\t" << "    " <<  i << " E ";
			for(int j=1; j<7; j++)
			{
				if(FlightSeats[i][j]==1)
				{
					if(j==1)
						cout << "A";
					else if(j==2)
						cout << "B";
					else if(j==3)
						cout << "C";
					else if(j==4)
						cout << "D";
					else if(j==5)
						cout << "E";
					else if(j==6)
						cout << "F";
				}
			}
			cout << endl;
		}
		else if(FlightSeats[i][0]==2)
		{
			cout << "\t" << "\t" << "    " <<  i << " B ";
			for(int j=1; j<7; j++)
			{
				if(FlightSeats[i][j]==1)
				{
					if(j==1)
						cout << "A";
					else if(j==2)
						cout << "B";
					else if(j==3)
						cout << "C";
					else if(j==4)
						cout << "D";
					else if(j==5)
						cout << "E";
					else if(j==6)
						cout << "F";
				}
			}
			cout << endl;
		}
	}
}
	
void FlightDetails::display_array()
{
	for(int i=0; i<60; i++)						//display the seat array graphycally
	{   
		if(i==0)
			cout<<"***************************\n";
		if(FlightSeats[i][0]!=0)
		{
			for(int j=0; j<7; j++)
			{   
				cout<<FlightSeats[i][j]<<" | ";
					if(j==6)
						cout<<endl;
			}
		
		} 
		if(i==59)
			cout<<"***************************\n";
	}
}

void FlightDetails::booking_complete()
{
	cout << endl << "\t" << "--------------------------------";
	cout << endl << "\t" << "\t" << "Seat Booking Complete!" << endl;
	cout << "\t" << "--------------------------------" << endl;	
}

void FlightDetails::not_avail()
{
	cout << endl << "\t" << "--------------------------------";
	cout << endl << "\t" << '\t' << "Seat is Not Available!" << endl;
	cout << "\t" << "--------------------------------" << endl;
}

int FlightDetails::book(int x, char y)
{
	//return FlightSeats[x][1]=0;
	if(FlightSeats[x][0]==1 || FlightSeats[x][0]==2)
	{
		if(y=='a' || y=='A')
			if(FlightSeats[x][1]==1)
			{
				FlightSeats[x][1]=0;
				booking_complete();
			}
			else
			{
				not_avail();
			}
				
		else if(y=='b' || y=='B')
			if(FlightSeats[x][2]==1)
			{
				FlightSeats[x][2]=0;
				booking_complete();
			}
			else
			{
				not_avail();
			}
				
		else if(y=='c' || y=='C')
			if(FlightSeats[x][3]==1)
			{
				FlightSeats[x][3]=0;
				booking_complete();
			}
			else
			{
				not_avail();
			}
		
		else if(y=='d' || y=='D')
			if(FlightSeats[x][4]==1)
			{
				FlightSeats[x][4]=0;
				booking_complete();
			}
			else
			{
				not_avail();
			}
				
		else if(y=='e' || y=='E')
			if(FlightSeats[x][5]==1)
			{
				FlightSeats[x][5]=0;
				booking_complete();
			}
			else
			{
				not_avail();
			}

		else if(y=='f' || y=='F')
			if(FlightSeats[x][6]==1)
			{
				FlightSeats[x][6]=0;
				booking_complete();
			}
			else
			{
				not_avail();
			}	
											
	}
	else
	{
		cout << endl << "\t" << "--------------------------------";
		cout << endl << "\t" << "This Row Has No Available Seats!" << endl;
		cout << "\t" << "--------------------------------" << endl;
	}

}
	
	
int main()
{	
	ifstream inFile;
	inFile.open("Flights.txt");
	if(!inFile)
	{
		cout << "Unable to Open File!";
		exit(1);

	}
	string str;
	int EmptyLine=0;
	
	while(getline(inFile,str))
	{
		if(str.empty())
		{
			EmptyLine++;
		}
		//cout << str << endl; 				//print the file
	}
	//cout << EmptyLine; 					//print no of empty line

	inFile.close();

	FlightDetails FlightObjArr[EmptyLine];
	int  arr[60][7];						//*******index->|class|A|B|C|D|E|F|
	
    string flightno, depdateandtime, depairport, arrairport;
    int seatcount_E, seatcount_B;
	
	inFile.open("Flights.txt");

	for(int y=0; y<EmptyLine; y++)
	{
		for(int i=0;i<60;i++)
		{             						//********reset array
			for(int j=0;j<7;j++)
				arr[i][j]='\0';
		}

		getline(inFile, flightno);
		getline(inFile, depdateandtime);
		getline(inFile, depairport);
		getline(inFile, arrairport);

		while(getline(inFile,str))
		{
			if(str.empty())
			{
				FlightDetails obj(flightno, depdateandtime, depairport, arrairport, arr, seatcount_E, seatcount_B);
				FlightObjArr[y]= obj;		
				//obj.display_details();	

				break;
			}
			else
			{
				istringstream FileLine(str);
				string Row, ClassType, Seat;
				int index=0;
				FileLine >> Row >> ClassType >> Seat;
				stringstream convert(Row);
				convert >> index;
				//cout << Row << endl;

				int length = Seat.length();
				char SeatLetter_Arr[length+1];
				strcpy(SeatLetter_Arr, Seat.c_str());
				
					if(ClassType =="E")
						arr[index][0]=1;
						
					else
						arr[index][0]=2;
						
							
					for(int x=0;x<length;x++){
						if(SeatLetter_Arr[x]=='A')
							arr[index][1]=1;	
						
						else if(SeatLetter_Arr[x]=='B')
							arr[index][2]=1;
							
						else if(SeatLetter_Arr[x]=='C')
							arr[index][3]=1;
							
						else if(SeatLetter_Arr[x]=='D')
							arr[index][4]=1;
							
						else if(SeatLetter_Arr[x]=='E')
							arr[index][5]=1;
							
						else if(SeatLetter_Arr[x]=='F')
							arr[index][6]=1;
				}
					int count_E=0;
					int count_B=0;

					for(int i=0; i<60; i++)
					{
						if(arr[i][0]==1)
						{
							for(int j=1; j<7; j++)
							{
								if(arr[i][j]==1)
									count_E++;
							}
						}
						else if(arr[i][0]==2)
						{
							for(int j=1; j<7; j++)
							{
								if(arr[i][j]==1)
									count_B++;
							}
						}
					}
					seatcount_E = count_E;
					seatcount_B = count_B;
			}
		}
	}

	int case_identifier;
	do
	{
		cout << endl << "********** Virgin Airline **********" << endl;
		cout << endl << "     1. Display Available Flights" << endl;
		cout << "     2. View Flight" << endl;
		cout << "     3. Seat Availability" << endl;
		cout << "     4. Seat Booking" << endl;
		cout << "     5.Exit" << endl;
		cout << endl << "************************************" << endl;
		cout << endl << "Enter Your Option : ";
		
		cin >> case_identifier;

		string input1;
		int flag1=0;
		string input2;
		int flag2=0;
		string input3;
		int flag3=0;
		int input_row;
		char s;
		ofstream outFile;


		switch(case_identifier)
		{
			case 1 : 
					
					for(int i=0; i<EmptyLine; i++)
					{
						FlightObjArr[i].display_details();
					}

				break;

			case 2 : 
					//string input1;
					cout << "Enter Flight Number : ";
					cin >> input1;
					//int flag1=0;
					for(int i=0; i<EmptyLine; i++)
					{
						if(input1==FlightObjArr[i].view_FlightNo())
						{
							FlightObjArr[i].display_details();
							cout << "\t" << "--------------------------------" << endl;
							cout << endl << "\t" << "\t" << "|Available Seats|" << endl << endl;
							FlightObjArr[i].display_seats();
							flag1=1;
							break;
						}
						
					}
					cout << endl << "\t" << "--------------------------------";
					
					if(flag1==0)
					{
						cout << endl << "\t" << "Flight Number is Not Found!" << endl;
						cout << "\t" << "--------------------------------" << endl;
					}

				break;

			case 3 : 
					//string input2;
					int seat_E, seat_B;
					//int flag_2=0;
					cout << "Enter Flight Number : ";
					cin >> input2;
					
					

					for(int i=0; i<EmptyLine; i++)
					{
						if(input2==FlightObjArr[i].view_FlightNo())
						{
							// FlightObjArr[i].display();
							// cout << "\t" << "--------------------------------" << endl;
							// cout << endl << "\t" << "\t" << "Available Seats" << endl << endl;
							// FlightObjArr[i].display_seats();
							cout << "Enter Number of Seats in Class E : ";
							cin >> seat_E;
							cout << "Enter Number of Seats in Class B : ";
							cin >> seat_B;
							
							if(FlightObjArr[i].view_SeatCount_E() >= seat_E && FlightObjArr[i].view_SeatCount_B() >= seat_B )
							{
								cout << endl << "\t" << "--------------------------------" << endl;
								cout << "\t" << "Number of Seats Available!" << endl;
								cout << "\t" << "--------------------------------" << endl;
								cout << endl << "\t" << "\t" << "|Available Seats|" << endl << endl;
								FlightObjArr[i].display_seats();
								flag2=1;
							}
							else
							{
								cout << endl << "\t" << "--------------------------------" << endl;
								cout << "\t" << "Number of Seats Not Available!";
								flag2=1;	
								
							}

							
							break;
						}
						
					}
					cout << endl << "\t" << "--------------------------------" << endl;
					
					if(flag2==0)
					{
						cout << endl << "\t" << "Flight Number is Not Found!" << endl;
						cout << "\t" << "--------------------------------" << endl;
					}
					
				break;
//
			case 4 : 
					cout << "Enter Flight Number : ";
					cin >> input3;
					
					for(int i=0; i<EmptyLine; i++)
					{
						
						if(input3==FlightObjArr[i].view_FlightNo())
						{
							cout << "Row Number (1-60) : ";
							cin >> input_row;
							
							if(input_row >= 1 && input_row <= 60)
							{
								cout << "Seat Letter (A-F) : ";
								cin >> s;

								if(s=='a'||s=='A'||s=='b'||s=='B'||s=='c'||s=='C'||s=='d'||s=='D'||s=='e'||s=='E'||s=='f'||s=='F')
								{
									for(int j=0; j<60; j++)
									{
										if(j==input_row)
										{
											//FlightObjArr[i].display_array();
											FlightObjArr[i].book(j, s);
											//FlightObjArr[i].display_array();
											
											break;
										}
									}
								}
								else
								{
									cout << endl << "\t" << "--------------------------------";
									cout << endl << "\t" << "\t" << "Invalid Seat Letter!" << endl;
									cout << "\t" << "--------------------------------" << endl;
								}
							}
							else
							{
								cout << endl << "\t" << "--------------------------------";
								cout << endl << "\t" << "\t" << "Invalid Row Number!" << endl;
								cout << "\t" << "--------------------------------" << endl;
							}

							flag3=1;
							break;
						}
						
					}
					
					if(flag3==0)
					{
						cout << endl << "\t" << "--------------------------------";
						cout << endl << "\t" << "Flight Number is Not Found!" << endl;
						cout << "\t" << "--------------------------------" << endl;;
					}
				break;

			case 5 : 
					//ofstream outFile;
					outFile.open("FlightsWrite.txt" , ios::out);

					for(int i=0; i<EmptyLine; i++)
					{
						outFile << FlightObjArr[i].view_FlightNo() << endl;
						outFile << FlightObjArr[i].view_DepDateandTime() << endl;
						outFile << FlightObjArr[i].view_DepAirport() << endl;
						outFile << FlightObjArr[i].view_ArrAirport() << endl;
						
						for(int x=0; x<60; x++)
						{
							if(FlightObjArr[i].FlightSeats[x][0]==1)
							{
								outFile << x << " E ";
								for(int j=1; j<7; j++)
								{
									if(FlightObjArr[i].FlightSeats[x][j]==1)
									{
										if(j==1)
											outFile << "A";
										else if(j==2)
											outFile << "B";
										else if(j==3)
											outFile << "C";
										else if(j==4)
											outFile << "D";
										else if(j==5)
											outFile << "E";
										else if(j==6)
											outFile << "F";
									}
								}
								outFile << endl;
							}
							else if(FlightObjArr[i].FlightSeats[x][0]==2)
							{
								outFile << x << " B ";
								for(int j=1; j<7; j++)
								{
									if(FlightObjArr[i].FlightSeats[x][j]==1)
									{
										if(j==1)
											outFile << "A";
										else if(j==2)
											outFile << "B";
										else if(j==3)
											outFile << "C";
										else if(j==4)
											outFile << "D";
										else if(j==5)
											outFile << "E";
										else if(j==6)
											outFile << "F";
									}
								}
								outFile << endl;
							}
						}
						outFile << endl;

					}
					outFile.close();
				break;

				default : 
					case_identifier=5;
					cout << endl << "\t" << "--------------------------------";
					cout << endl << "\t" << "\t" << "Invalid User Input!" << endl;
					cout << "\t" << "--------------------------------" << endl;
				break;
		}
	}while(case_identifier!=5);
}

