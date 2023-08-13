#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

// global variables
string fName, lName, phone_num;

void addContact();
void searchContact();
void help();
void exit();
bool checkDigit(string);
bool checkNumber(string);

int main()
{
    short int choice;
    system("clr");
    system("color 0A");
    cout << "\n\n\n\t\t\t Contact Management System : ";
    cout << "\n\n\t1. Add contact\n\t2. Search Contact\n\t3. Help\n\t4. Exit\n\t";

    cin >> choice;
    switch (choice)
    {
    case 1:
        addContact();
        break;

    case 2:
        searchContact();
        break;
    case 3:
        help();
        break;

    case 4:
        exit();
        break;

    default:
        cout << "\n\n\tInvalid input";
        cout << "\nPress any key to continue...";
        getch();
        main();
    }

    return 0;
}

void addContact()
{
    ofstream phone("number.txt", ios::app);
    cout << "\n\n\tEnter the First name : ";
    cin >> fName;
    cout << "\n\tEnter the Last name : ";
    cin >> lName;
    cout << "\n\tEnter the 10-digit phone number : ";
    cin >> phone_num;

    if (checkDigit(phone_num) == true)
    {
        if (checkNumber(phone_num) == true)
        {
            // if it a 10-digit number then write the data int the file.
            if (phone.is_open())
            {
                phone << fName << " " << lName << " " << phone_num << endl;
                cout << "\n\tContact Saved Successfully";
            }
            else
            {
                cout << "\n\tError Opening File!";
            }
        }
        else
        {
            cout << "\n\tA Phone Number Must Contain Number Only..";
        }
    }
    else
    {
        cout << "\n\n\n\tA Phone Number must contain 10-digits.";
    }

    phone.close();
}

void searchContact()
{
    bool found;
    ifstream myfile("number.txt");
    string keyword;
    cout << "\n\tEnter the Name to search : ";
    cin >> keyword;
    while (myfile >> fName >> lName >> phone_num)
    {
        if (keyword == fName || keyword == lName)
        {
            system("cls");
            cout << "\n\n\n\t\tContact Details..";
            cout << "\n\tFirst Name : " << fName;
            cout << "\n\tLast Name : " << lName;
            cout << "\n\tPhone Number : " << phone_num;
            found = true;
            break;
        }
    }

    if (found == false)
    {
        cout << "\n\tNo such contact found..";
    }
}

void help()
{
    cout << "\n\n\n\t\tThis Displays Help!" << endl;
}

void exit()
{
    system("cls");
    cout << "\n\n\n\t\t\tThank You For Using!\n\n"
         << endl;
    exit(1);
}

bool checkDigit(string x)
{
    if (x.length() == 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkNumber(string x)
{
    for (int i = 0; i < x.length(); i++)
    {
        if (!(int(x[i]) >= 48 && int(x[i]) <= 57))
        {
            return false;
        }
    }

    return true;
}
