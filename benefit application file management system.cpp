#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstdio>
 

using namespace std;

class  contact {
private:
	char firstName[10];
	char lastName[10];
	char city[10];
	char ShoppingWeeks[10];
	char ServiceProvided[10];
	char weeks[10];
	long long  ARC,phNo;
public:
	void createContact() {
		cout << "\n\n\n Enter Your First Name:";
		cin >> firstName;
        cout << "\n\n\n Emter Your Last Name:";
		cin >> lastName;
        cout << "\n\n\n Enter Your Phone Number:";
		cin >> phNo;
        cout << "\n\n\n Enter your Alien  Number:";
		cin >> ARC;
        cout << "\n\n\n Enter City:";
		cin >> city;
        cout << "\n\n\n Enter Number of Shopping Weeks :";
		cin >> ShoppingWeeks;
        cout << "\n\n\n Service Provided:" ;
		cin >> ServiceProvided;
        cout << "\n\n\n Enter Shoping Day & Date :" ;
		cin >> weeks;


	}
	void showContact() {
		cout << "NAME                ::  "<< firstName << " " << lastName <<endl;
		cout << "ALIEN               ::  "<< ARC <<endl;
		cout << "CITY                ::  "<< city <<endl;
		cout << "SHOPPING WEEKS      ::  "<< ShoppingWeeks <<endl;
		cout << "PHONE               ::  "<< phNo <<endl;
		cout << "SERVICE PROVIDED    ::  "<< ServiceProvided <<endl;
		cout << "SHOPPING DAY & DATE ::  "<< weeks <<endl<<endl;
		
	}
	void writeonfile() {
		char ch;
		ofstream f1;
		f1.open("CMS.dat", ios::binary | ios::app);
		do{
	createContact();
	f1.write(reinterpret_cast<char*>(this), sizeof(*this));

	
	cout << "DO YOU HAVE NEXT REGISTRATION DATA?(y/n)" << endl;;
	cin >> ch;
		} while (ch == 'y');
		cout << "Contact has been successfully Created...";
		f1.close();
	}
	void readFromFile() {
		ifstream f2;
		f2.open("CMS.dat", ios::binary);
		cout << "\n==========================================\n";
		cout << "LIST OF REGISTRATION CONTACT";
		cout << "\n=============================================\n";

		while (!f2.eof()) {
			if (f2.read(reinterpret_cast<char*>(this), sizeof(*this)
			)) {
				showContact();
				cout << "\n========================================\n";

			}
		}
		f2.close();
	}
		
	void searchonFile() {
	
		ifstream f3;

		long long AlienNumber;
		cout << "ENTER  ALIEN NUMBERS:";
		cin  >> AlienNumber;
		f3.open("CMS.dat", ios::binary);


		while (!f3.eof()) {
			if (f3.read(reinterpret_cast<char*>(this), sizeof(*this)
			)) {
				if (AlienNumber == ARC) {
					showContact();

					cout << "You Are Already A Dignity Center Memebers:)";
					return;
				}
			}
		}
		cout << "\n\nNo record found";
		f3.close();
	}
	void deletFromFile() {
		long long phNo;
		int flag = 0;
		ofstream f4;
		ifstream f5;

		f5.open("CMS.dat", ios::binary);
		f4.open("temp.dat", ios::binary);

		cout << "Enter alien number to be delete::";
		cin >> phNo;

		while (!f5.eof()) {
			if (f5.read(reinterpret_cast<char*>(this), sizeof(*this)
			)) {
				if (phNo != phNo) {
					f4.write(reinterpret_cast<char*>(this), sizeof(*this));
				}


				else flag = 1;
			
			}
		}
	
		f5.close();
		f4.close();
		remove("CMS.dat");
		rename("temp.dat", "CSM.dat");

		flag == 1 ?
			cout << "\t\Contact Deleted...":
		cout << "\tContact Not Found...";
	}
	void editContact() {
		long long AlienNumber;
		fstream f6;
		cout << "Edit contact";
		cout << "\n==============================================\n";
		cout << "Enter the alien number to be edit:";
		cin  >> AlienNumber;
		f6.open("CMS.dat", ios::binary|ios::out | ios::in);
		while (!f6.eof()) {
			if (f6.read(reinterpret_cast<char*>(this), sizeof(*this)
			)) {
				if (AlienNumber == AlienNumber) {
					cout << "Enter new record\n";
					createContact();

					int pos = -1 * sizeof(*this);
						f6.seekp(pos, ios::cur);
						f6.write(reinterpret_cast<char*>(this), sizeof(*this));
						cout << endl << "\tcontact successfully updated...";
						return;
				}
			}
		}
		cout << "\n\nNo Record foudn";
		f6.close();
	}
};

int main()
{
	ofstream image;
	image.open ("image.ppn");
	if (image.is_open()) {
		// place header infro
		image << "p3" << endl;
		image << "250 250 " << endl;
		image << "255" << endl;
		image.close();
	}
	system("cls");
	system("color 4F"), // Color XYZ, X= background color,Y= text color, Z= mixted colour

		cout << "\n\n\n\n\t\t\t\t *WELCOME TO THE DIGNITY CENTRE FILE MANAGEMENT SYSTEM*"<<endl<<endl;

	    cout << " PLEASE SELECT ONE DIGIT FOR MAIN MENUE ::) " << endl;

		getchar ();

	while (1) {
		contact c1;
		int choice;
		 
		system("cls");
		system("color 2");
		cout << "\n\DIGNITY CENTRE MANAGEMENT SYSTEM";
		cout << "\n\n\MAIN MENU";
		cout << "\n==========================================\n";
		cout << "[1] Add A New Member\n";
		cout << "[2] List Of All Member Contact\n";
		cout << "[3] Search For Member Contact\n";
		cout << "[4] Delete Member Contact\n";
		cout << "[5] Edit Member Contact\n";
		cout << "[0] Exit";
		cout << "\n=================================================\n";
		cout << "Enter your choice:";
		cin  >> choice;

		switch (choice) {
		case 1:
			system("cls");
			c1.writeonfile();
			break;

		case 2:
			system("cls");
			c1.readFromFile();
			break;
		case 3:
			system("cls");
			c1.searchonFile();
			break;
		case 4:
			system("cls");
			c1.deletFromFile();
			break;
		case 5:
			system("cls");
			c1.editContact();
			break;
		case 0:
			system("cls");
			cout << "\n\n\n\n\t\t THANK YOU FOR USING DIGNITY CENTRE FILE MANAGMENT SYSTEM." << endl<<endl;
			cout << " TRY AGAIN:) PLEASE SELECT ONE DIGIT FOR MAIN MENUE :: " << endl;
		
			exit(0);
			break;
		

		default:
			continue;
		}
		int opt;
		cout << "\n\n>>..:: Enter the choice:\n[1] Main Menu\t\t[0] Exit\n";
		cin >> opt;

		switch (opt) {
		case 0:
			system("cls");
			cout << "\n\n\n\n\t\t THANK YOU FOR USING DIGNITY CENTRE FILE MANAGMENT SYSTEM." << endl << endl;
			cout << " SERVICE AVAILABLE  : " << endl;
			exit(0);
			break;

		default:
			continue;
		}

	}

	return 0;
}

 
