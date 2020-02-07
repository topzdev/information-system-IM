#include "Guardian.h"
#include <iostream>
#include <string.h>
#include <conio.h>
// Context
#include "Enlistment.h"
#include "Model.h"
#include "Controller.h"
#include "Config.h"
#include "Views.h"
#include "Utils.h"
#include "Enrollment.h"
#include "main.h"

using namespace std;

void guardian_menu()
{
    system("cls");
    int choose;
    cout << "\t\t\t\t  =================================================\n";
    cout << "\t\t\t\t  ||  \t\t                \t\t ||\n";
    cout << "\t\t\t\t  ||  \t\t   GUARDIAN PAGE \t\t ||\n";
    cout << "\t\t\t\t  ||  \t\t                \t\t ||\n";
    cout << "\t\t\t\t  =================================================\n";
    cout << "\n\t\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout << "\t\t\t\t\t\tChoose any options" << endl;
    cout << "\n\t\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t\t\t\t\t\t[1] Add Student's Guardian" << endl;
    cout << "\t\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t\t\t\t\t\t[2] Display Students Guardian" << endl;
    cout << "\t\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t\t\t\t\t\t[3] Return to Main Menu" << endl;
    cout << "\t\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t\t\t\t\t\tEnter your choice: ";
    cin >> choose;

    
    switch (choose)
    {

    case 1:
        system("cls");
        inputGuardian();
        break;

    case 2:
        system("cls");
        displayGuardians();
        break;

    case 3:

        cout << "Press any key to continue...";
        getch();
        main_menu();
        break;

    default:
        cout << "Your input is not in the options";
        pressAnyKey();
        break;
    }
}

void inputGuardian()
{
    int stop = 1, studentNo;
    totalGuardian++;
    GUARDIAN input[MAX_SUB];
    PARENT_CONTACT student;

    int guardianCount = 0;
    cout << "\t\t\t\t    =================================================\n";
    cout << "\t\t\t\t    ||  \t\t            \t\t   ||\n";
    cout << "\t\t\t\t    ||  \tFILL UP GUARDIAN INFORMATION \t   ||\n";
    cout << "\t\t\t\t    ||  \t\t            \t\t   ||\n";
    cout << "\t\t\t\t    =================================================\n";
    cout << "\n\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t\t\t\t\t\t  GUARDIAN INFORMATION\n";
    cout << "\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\n\t\t\t\t\t\tEnter student Student no: ";
    cin >> studentNo;

    // if the student not found this function will not execute
    if (locateStudent(studentNo) == -1)
    {
        errorMessage("Student not found try again later");
        guardian_menu();
        return;
    }

    while (1)
    {
        cout << "\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\t\t\t\t\t\t    Guardian no# " << (guardianCount + 1) << endl;
        cout << "\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\t\t\t\t\tEnter Guardian First Name: ";
        cin >> input[guardianCount].firstName;

        cout << "\n\t\t\t\t\tEnter Guardian Last Name: ";
        cin >> input[guardianCount].lastName;

        cout << "\n\t\t\t\t\tEnter Guardian Contact: ";
        cin >> input[guardianCount].contact;

        cout << "\n\t\t\t\t\tEnter Guardian Relaitionship: ";
        cin >> input[guardianCount].relationship;

        cout << "\n\t\t\t\t\tEnter Guardian Occupation: ";
        cin >> input[guardianCount].occupation;

        cout << "\n\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\t\t\t\t  Add more Guardian ? type [1] if YES and [0] if no: ";
        cin >> stop;

        if (stop != 1)
        {
            break;
        }

        guardianCount++;
    }
    student.studentNumber = studentNo;
    student.guardianCount = guardianCount;
    insertGuardian(student, input);
}

void insertGuardian(PARENT_CONTACT student, GUARDIAN *input)
{

    guardian[totalGuardian].guardianCount = student.guardianCount;
    guardian[totalGuardian].studentNumber = student.studentNumber;

    // *guardian[totalGuardian].subject = *input;

    for (int i = 0; i <= student.guardianCount; i++)
    {
        strcpy(guardian[totalGuardian].guardians[i].firstName, input[i].firstName);
        strcpy(guardian[totalGuardian].guardians[i].lastName, input[i].lastName);
        strcpy(guardian[totalGuardian].guardians[i].contact, input[i].contact);
        strcpy(guardian[totalGuardian].guardians[i].occupation, input[i].occupation);
        strcpy(guardian[totalGuardian].guardians[i].relationship, input[i].relationship);
    }

    saveFileGuardian();
    cout << "Successfully Added";
    pressAnyKey();
    guardian_menu();
}

void displayGuardians()
{
    int i, e;
    cout << "\t\t\t\t    =================================================\n";
    cout << "\t\t\t\t    ||  \t\t            \t\t   ||\n";
    cout << "\t\t\t\t    ||  \tLIST OF GUARDIAN INFORMATION \t   ||\n";
    cout << "\t\t\t\t    ||  \t\t            \t\t   ||\n";
    cout << "\t\t\t\t    =================================================\n\n";
    cout << "\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout << "\t\t\t\tFirst Name | Last Name | Contact | Relaitionship | Occupation" << endl;
    for (i = 1; i <= totalGuardian; i++)
    {
        cout << endl
             << "\t\t\t\t\tStudent Name: " << record[locateEnlist(guardian[i].studentNumber)].firstName << " " << record[locateEnlist(guardian[i].studentNumber)].lastName << " Student Number TUPM-" << guardian[i].studentNumber << endl;
        for (e = 0; e <= guardian[i].guardianCount; e++)
        {
            cout << "\t\t\t\t" <<guardian[i].guardians[e].firstName << "\t" << guardian[i].guardians[e].lastName << "\t" << guardian[i].guardians[e].contact << "\t    " << guardian[i].guardians[e].relationship << "\t\t" << guardian[i].guardians[e].occupation << endl;
        }
        cout << endl;
    }
    cout << "\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout << "\n\t\t\t\t\t\tEnd of results NOTHING FOLLOWS" << endl;
    pressAnyKey();
    guardian_menu();
}
