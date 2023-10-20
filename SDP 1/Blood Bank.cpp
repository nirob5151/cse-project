#include <iostream>
#include <string>

using namespace std;

struct Donor {
    string name;
    string bloodType;
    int age;
    long long int id;
    long long int number;
};

const int MAX_DONORS = 100;
Donor donors[MAX_DONORS];
int numDonors = 0;

void addDonor() {
    if (numDonors < MAX_DONORS) {
        Donor newDonor;
        cout << "Enter donor name: ";
        cin >> newDonor.name;
        cout<<"Enter Your Id: ";
        cin>>newDonor.id;
        cout << "Enter blood type: ";
        cin >> newDonor.bloodType;
        cout << "Enter donor age: ";
        cin >> newDonor.age;

        donors[numDonors] = newDonor;
        numDonors++;

        cout << "Donor added successfully!" << endl;
    } else {
        cout << "The blood bank is full. Cannot add more donors." << endl;
    }
}

void displayDonors() {
    cout << "Donor List:" << endl;
    for (int i = 0; i < numDonors; i++) {
        cout << "Donor " << i + 1 << ":" << endl;
        cout << "Name: " << donors[i].name << endl;
        cout<<"Student ID: "<<donors[i].id<<endl;
        cout << "Blood Type: " << donors[i].bloodType << endl;
        cout << "Age: " << donors[i].age << endl;
        cout<<" :-:Contact Info:-:";

        cout << "---------------------" << endl;
    }
}

int main() {
    int choice;

    while (true) {
       // cout << "Blood Bank Management System" << endl;
        //cout << "1. Add Donor" << endl;
        //cout << "2. Display Donors" << endl;
        //cout << "3. Exit" << endl;
        //cout << "Enter your choice: ";
        cout<<"\n\t\t===========================================";
        cout<<"\n\t\t|   BUBT Student Blood Bank Management System   |"<<endl;
        cout<<"\t\t===========================================";
        cout<<"\n\t \t \t ::Enter Your Choice::"<<endl;
        cout<<"\n\t\t\tTo Add New Data \t(1)\n\t\t\tTo View List Of Donar   (2)\n\t\t\tTo Search Donar \t(3)\n\t\t\tTo Exit \t\t(4)"<<endl;
        cout<<"\t\t\t: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addDonor();
                break;
            case 2:
                displayDonors();
                break;
            case 3:
             //cout<<
            case 4:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
