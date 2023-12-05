#include <iostream>
#include<bits/stdc++.h>
#include <string.h>
#include <fstream>
#include<ctype.h>
#include<time.h>
#include<conio.h>
using namespace std;
struct Donor                                      // Structure declaration
{
    string name,department,email,bloodType,date;  // Member (string variable)
    int age;                                      // Member (int variable)
    long long int id;                             // Member (long long int variable)
    long long int number;                         // Member (long long int variable)
    long long int num;                            // Member (long long int variable)
};

const int MAX_DONORS = 100;
Donor donors[MAX_DONORS];
int numdonors = 0;
void savedonerdata()     //save data for doner info in file.function
{
    ofstream file("donors.csv");      //add doner info in file
    if (file.is_open())
    {
        for (int i = 0; i < numdonors; i++)
        {
            file << donors[i].name << "  " << donors[i].id<<"  "<< donors[i].department<<"  "<< donors[i].bloodType << "  " << donors[i].age <<"  "<< donors[i].date<<"  "<< donors[i].num<<"  "<< donors[i].number<<"  " << donors[i].email<<"  "<<endl;
        }
        file.close();
    } else {
        cout << "Unable to open the file for saving." << endl;
    }
}
void DonorsdataFile()     //show doner info from file. function
{
    ifstream file("donors.csv"); // show doner info

    if (file.is_open())
    {
        numdonors = 0;
        while (file >> donors[numdonors].name >> donors[numdonors].id >> donors[numdonors].department >> donors[numdonors].bloodType >> donors[numdonors].age>> donors[numdonors].date>> donors[numdonors].num>> donors[numdonors].number>> donors[numdonors].email)
        {
            numdonors++;
        }
        file.close();
    } else {
        cout << "Unable to open the file.Doner List Is Empty" << endl;
    }
}

// Add this function for input validation
long long int  getNumericInput() {
    long long int input;
    while (true) {
        cin >> input;
        if (cin.fail()) {
            cout << "Invalid input. Please enter number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return input;
}

void addDonors()             //add doner info in this function
 {
    cout<<"\n\t\t=============================================";
        cout<<"\n\t\t|   Enter Your Information for Your Profile |"<<endl;
        cout<<"\t\t=============================================";
        cout<<endl;
        cout<<endl;
    if (numdonors < MAX_DONORS)
    {
        Donor newdonor;                        // Get user input
        cout << "Enter donor name: ";
       // cin>>newdonor.name;
        cin.ignore();
        getline(cin,newdonor.name);             //using getline() function

        cout<<"Enter Your Id: ";                //input user student id
        newdonor.id = getNumericInput();
        //cin>>newdonor.id;

        cout<<"Enter Your Department: ";        //input user department
        //cin>>newdonor.department;
        cin.ignore();
        getline(cin,newdonor.department);       //using getline() function

        cout << "Enter blood type: ";           //input user blood type
        cin >> newdonor.bloodType;
       // cout << "Enter donor age: ";

        cout << "Enter donor age: ";
        newdonor.age = getNumericInput();           //input user age
        //cin >> newdonor.age;
        
        cout<<"Enter Last Date Of Donation: ";  //input user last date of donation
        //newdonor.date = getNumericInput();
        cin>>newdonor.date;

        cout<<"Enter Number Of Donation: ";     //input user number of donation
        newdonor.num = getNumericInput();
       // cin>>newdonor.num;
        cout<<"Enter Your Phone No: ";          //input user phone number
        newdonor.number = getNumericInput();
       // cin>>newdonor.number;
       
        cout<<"Enter Your Email: ";             //input user email
        cin>>newdonor.email;

        donors[numdonors] = newdonor;
        numdonors++;

        cout << "\t\t\t Donor added successfully!" << endl; //after add doner to show this
        savedonerdata();  // Save donors' data to the file after adding a new donor
    }else{
         cout << "\t\t\t The blood bank is full. Cannot add more donors." << endl;  //after don't add doner
    }
}
void displayDonors()    //display doner info in this function
 {
    cout << "::Donor List::" << endl;                      //display all donor info
    cout << "---------------" << endl;
    for (int i = 0; i < numdonors; i++)
    {
        cout << "Donor " << i + 1 << ":" << endl;
        cout << "Name: " << donors[i].name << endl;
        cout<<"Student ID: "<<donors[i].id<<endl;
        cout << "Blood Type: " << donors[i].bloodType << endl;
        cout << "Age: " << donors[i].age << endl;
        cout<<"Last Date Of Donation: "<<donors[i].date<<endl;
        cout<<"Number Of Donation: "<<donors[i].num<<endl;
        cout<<" :-:Contact Info:-:"<<endl;
        cout<<"Phone: "<<donors[i].number<<endl;
        cout<<"Email: "<<donors[i].email<<endl;

        cout << "---------------------" << endl;
    }
}
void searchDonors()  //search doner info fanction
{
    string search;
    cout<<"\n\t\t========================================";
        cout<<"\n\t\t|   Enter a blood type to search for   |"<<endl;
        cout<<"\t\t========================================";
        cout<<endl;
        cout<<"\t\t\t: ";
    cin >> search;
    cout << "::Search Results::" << endl;
    cout << "------------------" << endl;
    for (int i = 0; i < numdonors; i++) {
        try {
            if (donors[i].bloodType == search) {
                // Print donor information
                cout << "Donor " << i + 1 << ":" << endl;
                cout << "Name: " << donors[i].name << endl;
                cout << "Student ID: " << donors[i].id << endl;
                cout << "Blood Type: " << donors[i].bloodType << endl;
                cout << "Age: " << donors[i].age << endl;
                cout << "Last Date Of Donation: " << donors[i].date << endl;
                cout << "Number Of Donation: " << donors[i].num << endl;
                cout << " :-:Contact Info:-:" << endl;
                cout << "Phone: " << donors[i].number << endl;
                cout << "Email: " << donors[i].email << endl;
                cout << "---------------------" << endl;
            }
        } catch (...) {
            cout << "An error occurred while processing donor information." << endl;
        }
    }
}

void updateDonor()                  // update donar info function
{
    long long int updateinfo;
    cout<<"\n\t\t=====================================================";
        cout<<"\n\t\t|   Enter The Name of The Donor You Want to Update   |"<<endl;
        cout<<"\t\t====================================================";
        cout<<endl;
        cout<<"\t\t\t: ";
        cin >> updateinfo;

    for (int i = 0; i < numdonors; i++)
    {
        if (donors[i].id == updateinfo)     //upadet doner info
        {
            cout << "Enter the new Last Date Of Donation "<< updateinfo << ": ";
            //donors[i].date = getNumericInput();
            cin>>donors[i].date;
            cout << "Enter the new age for " << updateinfo << ": ";
            donors[i].age = getNumericInput();
            cout << "Enter the new Number Of Donation " << updateinfo << ": ";
             donors[i].num = getNumericInput();;
            cout << "\t\t\t Donor information updated!" << endl;
            savedonerdata();
            return;
        }
    }

    cout << "\t\t\t Donor not found. Could not update." << endl;
}
void deleteDonor()                  // delete doner function
 {
    long long int deleteprofile;
    int j;
    cout<<"\n\t\t=====================================================";
        cout<<"\n\t\t|   Enter The Id of The Donor You Want to Delete  |"<<endl;
        cout<<"\t\t====================================================";
        cout<<endl;
        cout<<"\t\t\t: ";
    cin >> deleteprofile;
    for (int i = 0; i < numdonors; i++) {
        if (donors[i].id == deleteprofile)               // delete doners info
        {

            for (j = i; j < numdonors - 1; j++)
             {
                donors[j] = donors[j + 1];
            }
            numdonors--;
            cout <<"\t\t\t"<<deleteprofile << " Has been deleted from the list." << endl;
            savedonerdata();
            return;
        }
    }
    cout << "\t\t\t Donor not found. Could not delete." << endl;
}
void delay(int time){
clock_t goal= time+clock();
while(goal>clock());
}
void Welcome() 
{
    // Setting console color
    system("COLOR 00 ");

    // Blood Bank Animation
    char load[1][100] = {"Tomar Rokto Nimu ...."};
    for (int i = 0; i < 2; i++) {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t    ";
        for (int j = 0; load[i][j] != '\0'; j++) {
            delay(350);
            cout << load[i][j];
        }
    }

    // Changing console color
    system("COLOR FC");
    delay(50);
    system("cls");

    // Displaying a border
    cout << "\n\t\t\t\t*";
    for (int str = 1; str < 54; str++) {
        delay(50);
        cout << "*";
    }

    // Displaying project name
    char prjct[300] = {"Simple Blood Bank Managment System "};
    cout << "\n\n\t\t\t";
    for (int i = 0; prjct[i] != '\0'; i++) {
        cout << " ";
        delay(100);
        cout << prjct[i];
    }

    cout << "\n";
    delay(250);
    cout << "\n\t\t\t\t*";
    for (int str = 1; str < 54; str++) {
        delay(50);
        cout << "*";
    }
    cout << "\n";

    // Creating a line
    for (int i = 0; i < 120; i++)
        cout << "_";

    delay(100);

    // Displaying additional text
    cout << "\n\n\n\n\t\t\t\t\t Made by- ";
    delay(350);
    char name[2][30] = {"Team Wizard\n\n\n"};
    for (int i = 0; i < 1; i++) {
        cout << "\n\t\t\t\t\t       ";
        for (int j = 0; name[i][j] != '\0'; j++) {
            delay(50);
            cout << name[i][j];
        }
    }

    delay(500);

    // Creating another line
    for (int i = 0; i < 120; i++)
        cout << "_";

    delay(100);

    // Displaying a message to press any key to continue
    cout << "\n\n\t\t\t Press any key to continue";
    delay(350);
    cout << ".";
    delay(350);
    cout << ".";
    delay(350);
    cout << ".";
    delay(350);
    cout << ".";
    //cin.ignore();
    getch();

}
int main()
{
    Welcome();

    system("COLOR FC");
 // delay(50);
 // system("cls");
    DonorsdataFile();
    char choice;

    while (true) {
        try {
           // delay(50);
            cout << "\n\t\t\t=================================================";
            cout << "\n\t\t\t|   BUBT Student Blood Bank Management System   |" << endl;
            cout << "\t\t\t=================================================";
            cout << "\n\t\t \t \t ::Enter Your Choice::" << endl;
            cout << "\n\t\t\t\tTo Add New Donor Data \t(1)\n\t\t\t\tTo View List Of Donor\t(2)\n\t\t\t\tTo Search Donor \t(3)" << endl;
            cout << "\t\t\t\tTo Update Donor Data \t(4)\n\t\t\t\tTo Delete Donor Data\t(5)\n\t\t\t\tTo Log Out \t\t(6)" << endl;
            cout << "\t\t\t\t: ";
            cin >> choice;

            if (!isdigit(choice)) {
                throw 1;
            }

            switch (choice) {
                case '1':
                    system("cls");
                    addDonors();
                    break;
                case '2':
                    system("cls");
                    displayDonors();
                    break;
                case '3':
                    system("cls");
                    searchDonors();
                    break;
                case '4':
                    system("cls");
                    updateDonor();
                    break;
                case '5':
                    system("cls");
                    deleteDonor();
                    break;
                case '6':
                    cout << "\n\t\t\t Thank You For Visiting Us!" << endl;
                    return 0;
                default:
                    system("cls");
                    cout << "\t\t\t Invalid choice. Please try again." << endl;
            }
        }

        catch (int error) {
            system("cls");
            cout << "\t\t\t Invalid input. Please enter a numeric choice." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;

}