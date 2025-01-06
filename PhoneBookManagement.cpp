#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

class PhoneBookManagement {
    private:
        string name, phoneNumber, address;
         ;
    public:
        // Constructor
        PhoneBookManagement(): name(""), phoneNumber(""), address(""){}

    // Setter Function (Have Parameter, No return) -> Encapsulation
    setName(string userName) {
        name = userName;
    }
    setPhoneNumber(string userNumber) {
        phoneNumber = userNumber;
    }
    setAddress(string userAddress) {
        address = userAddress;
    }

    // Getter Function (No Parameter, Have return) -> Encapsulation
    string getName() {
        return name;
    }
    string getPhoneNumber() {
        return phoneNumber;
    }
    string getAddress() {
        return address;
    }
};

// 1. Add Number
void addNumber(PhoneBookManagement pbm) {
    system("cls");
    string name, phoneNumber, address;

    cout << "\t Enter Name of User : ";
    std::getline(cin >> std::ws, name);
    pbm.setName(name);

    cout << "\t Enter Phone Number : ";
    cin >> phoneNumber;
    pbm.setPhoneNumber(phoneNumber);

    cout << "\t Enter Address of User : ";
    std::getline(cin >> std::ws, address);
    pbm.setAddress(address);

    // Connect the TXT file to store the data
    ofstream outfile("G:/C++ Learning Hub/Projects/PhoneBook.txt", ios::app);
    // ios::app -> used to save the new data without removing saved data in file

    if(!outfile) {
        cout << "\t Error : File can't open!";
    } else {
        // Add the contact into file
        outfile << pbm.getName() << " : " << pbm.getPhoneNumber() << " : " << pbm.getAddress() << endl << endl;
    }
    outfile.close();
    cout << "\t User Phone Number Added in the Phone Book!";

    Sleep(2000);
};


searchNumberByName() {
    system("cls");
    string userName;
    cout << "\t Enter name or phone number of user : ";
    getline(cin >> ws,userName);

    // Access the data from the file
    ifstream infile("G:/C++ Learning Hub/Projects/PhoneBook.txt");

    if (!infile) {
        cout << "\t Error : File can't open!" << endl;
    } else {
        string line;
        bool found = false;

        while (getline(infile, line)) {

            /*
            stringstream ss;

            ss << line;

            string name, phoneNumber, address;
            char delimiter;

            ss >> name >> delimiter >> phoneNumber >> delimiter >> address;

            if (userName == name) {
                found = true;
                cout<< "\tName : " << name << "\n"
                    << "\tPhone Number : " << phoneNumber << "\n"
                    << "\tAddress : " << address << endl;
            }
            */

            // Get data including space
            // size_t => Represents the size
            size_t firstColon = line.find(" : ");
            size_t secondColon = line.find(" : ", firstColon + 1);

            if (firstColon != string::npos && secondColon != string::npos) {

                string name = line.substr(0, firstColon);
                string phoneNumber = line.substr(firstColon + 3 , secondColon - (firstColon + 3));
                string address = line.substr(secondColon + 3);

                if (userName == name) {
                found = true;
                cout<< "\t Name : " << name << "\n"
                    << "\t Phone Number : " << phoneNumber << "\n"
                    << "\t Address : " << address << endl;
                }
            }

        }
        if (!found) {
            cout << "\t User Not Found!!!" << endl;
        }
    }
    infile.close();
    Sleep(5000);
};



/* Main Function */
int main() {
    // Access class fields & Functions
    PhoneBookManagement pbm;

    bool exit = false;

    while (!exit) {
        system("cls");
        int val;
        cout << "\t Welcome to Phone Book Management System!" << endl;
        cout << "\t ****************************************" << endl;
        cout << "\t 1. Add Number" << endl;
        cout << "\t 2. Search Number" << endl;
        cout << "\t 3. Exit" << endl;
        cout << "\t Enter Your choice : ";

        // Get value from user
        cin >> val;

        if (val == 1) {
            addNumber(pbm);
        } else if (val == 2) {
            searchNumberByName();
        } else if (val == 3) {
            system("cls");
            exit = true;
            cout << "\tThank You, Visit Again soon!!" << endl;
            Sleep(3000);
        }
    }

    return 0;
}
