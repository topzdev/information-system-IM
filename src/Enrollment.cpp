#include <iostream>
#include <conio.h>
#include "string.h"
#include <windows.h>
#include "Enrollment.h"
#include "Model.h"
#include "Controller.h"

using namespace std;

int enroll_menu()
{
    int choosen;
    system("cls");
    cout << "\xDB";
    cout << "\t\t\t\t  =================================================\n";
    cout << "\t\t\t\t  ||  \t\t                \t\t ||\n";
    cout << "\t\t\t\t  ||  \t\t  ENROLLMENT FORM \t\t ||\n";
    cout << "\t\t\t\t  ||  \t\t                \t\t ||\n";
    cout << "\t\t\t\t  =================================================\n";
    cout << "\n\n\n\t\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t\t\t\t\t\t[1] Add Student Record\n";
    cout << "\t\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t\t\t\t\t\t[2] Search Student Record\n";
    cout << "\t\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t\t\t\t\t\t[3] Show All Student Record\n";
    cout << "\t\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t\t\t\t\t\tEnter your choosen number: ";
    cin >> choosen;

    switch (choosen)
    {

    case 1:
        system("cls");
        cout << "\t\t\t\t    =================================================\n";
        cout << "\t\t\t\t    ||  \t\t              \t\t   ||\n";
        cout << "\t\t\t\t    ||  ENROLLMENT FORM (PLEASE FILL UP THE FORM)  ||\n";
        cout << "\t\t\t\t    ||  \t\t              \t\t   ||\n";
        cout << "\t\t\t\t    =================================================\n";
        addRecordPrompt();
        break;

    case 2:
        system("cls");
        cout << "\t\t\t\t    =================================================\n";
        cout << "\t\t\t\t    ||  \t\t              \t\t   ||\n";
        cout << "\t\t\t\t    ||  \t  SEARCH A STUDENT RECORD \t   ||\n";
        cout << "\t\t\t\t    ||  \t\t              \t\t   ||\n";
        cout << "\t\t\t\t    =================================================\n";
        findStudent();
        break;

    case 3:
        system("cls");
        cout << "\t\t\t\t    =================================================\n";
        cout << "\t\t\t\t    ||  \t\t              \t\t   ||\n";
        cout << "\t\t\t\t    ||  \t    LIST OF STUDENTS \t\t   ||\n";
        cout << "\t\t\t\t    ||  \t\t              \t\t   ||\n";
        cout << "\t\t\t\t    =================================================\n";
        showAllRecord();
        break;
    }

    return 0;
}

int addRecordPrompt()
{
    totalRecord++;
    STUDENT input;
    cout << "\n\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t\t\t\t\t\t ADD STUDENT INFORMATION\n";
    cout << "\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t\t\t\t\t\t    YOUR STUDENT ID:" << totalRecord << "\n";
    cout << "\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

    cout << "\t\t\t\t\tEnter your First Name: ";
    cin >> input.firstName;

    cout << "\n\t\t\t\t\tEnter your Last Name: ";
    cin >> input.lastName;

    cout << "\n\t\t\t\t\tEnter your address: ";
    cin >> input.address;

    cout << "\n\t\t\t\t\tEnter your Tel Number: ";
    cin >> input.tel;

    cout << "\n\t\t\t\t\tEnter your Course: ";
    cin >> input.course;

    int i = totalRecord;
    record[i].id = i;

    strcpy(record[i].firstName, input.firstName);
    strcpy(record[i].lastName, input.lastName);
    strcpy(record[i].address, input.address);
    strcpy(record[i].tel, input.tel);
    strcpy(record[i].course, input.course);

    saveFileRecord();
    cout << "\n\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\n\t\t\t\t\t    Student Record Successfully Added\n";
    getch();
    enroll_menu();

    return 0;
}

int findStudent()
{
    int i = 1, id, found = 0;
    cout << "\n\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t\t\t\t\t\t   FIND STUDENT RECORD\n";
    cout << "\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    cout << "\n\t\t\t\t\t\t    Enter student id: ";
    cin>>id;

    while (i <= totalRecord)
    {
        if (i == id)
        {
            cout << "\n\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "\t\t\t\t\t\t      STUDENT RECORD\n";
            cout << "\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "\n\t\t\t\t\t\t   Student ID: " << record[i].id << "\n";
            cout << "\n\t\t\t\t\t\t   Full Name:" << record[i].firstName << " " << record[i].lastName << "\n";
            cout << "\n\t\t\t\t\t\t   Address:" << record[i].address << "\n";
            cout << "\n\t\t\t\t\t\t   Telephone Number:" << record[i].tel << "\n";
            cout << "\n\t\t\t\t\t\t   Course:" << record[i].course << "\n";
            found++;
        }
        i++;
    }

    if (found == 0)
    {
        cout << "\n\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\t\t\t\t\t\t      STUDENT RECORD\n";
        cout << "\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\n\n\t\t\t\t\t\t    Student not found...\n";
    }

    getch();
    enroll_menu();
    return 0;
}

int showAllRecord()
{
    int i = 1;
    cout << "\n\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t\t\t\t\t\t SHOWING STUDENTS DATA\n";
    cout << "\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\n\t\t\t\tID NO. \t NAME \t\t\tADDRESS  CONTACT NO. \t COURSE\n";


    while (i <= totalRecord)
    {
        cout << "\t\t\t\t  "  <<record[i].id << "\t" << record[i].firstName << "\t " << record[i].lastName << "\t\t" << record[i].address << "\t " << record[i].tel << " " << record[i].course<<endl;


        i++;
    }
    cout << "\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t\t\t\t\t\tEnd of Record NOTHING FOLLOWS\n";

    getch();
    enroll_menu();
    return 0;
}

