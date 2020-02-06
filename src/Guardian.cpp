#include "Guardian.h"
#include <iostream>
#include <string.h>
// Context
#include "Enlistment.h"
#include "Model.h"
#include "Controller.h"
#include "Config.h"
#include "Views.h"
#include "Utils.h"
#include "Enrollment.h"

using namespace std;

void guardian_menu()
{
    system("cls");
    int choose;

    cout << "Choose any options" << endl;
    cout << "[1] Add Student's Guardian" << endl;
    cout << "[2] Display Students Guardian" << endl;
    cout << "[3] Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choose;

    system("cls");
    switch (choose)
    {

    case 1:
        inputGuardian();
        break;

    case 2:
        displayGuardians();
        break;

    case 3:
        break;
        system(0);
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

    cout << "GUARDIAN INFORMATION\n";
    cout << "-------------------------------------\n";

    cout << "Enter student Student no: ";
    cin >> studentNo;

    // if the student not found this function will not execute
    if (locateStudent(studentNo) == -1)
    {
        cout << "Student not found try again later" << endl;
        pressAnyKey();
        guardian_menu();
        return;
    }

    while (1)
    {
        cout << "Guardian no# " << (guardianCount + 1) << endl;
        cout << "Enter Guardian First Name: ";
        cin >> input[guardianCount].firstName;

        cout << "Enter Guardian Last Name: ";
        cin >> input[guardianCount].lastName;

        cout << "Enter Guardian Contact: ";
        cin >> input[guardianCount].contact;

        cout << "Enter Guardian Relaitionship: ";
        cin >> input[guardianCount].relationship;

        cout << "Enter Guardian Occupation: ";
        cin >> input[guardianCount].occupation;

        cout << "Add more Guardian ? type [1] if YES and [0] if no: ";
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
    cout << "First Name | Last Name | Contact | Relaitionship | Occupation" << endl;
    for (i = 1; i <= totalGuardian; i++)
    {
        cout << endl
             << "Student Name: " << record[locateEnlist(guardian[i].studentNumber)].firstName << " " << record[locateEnlist(guardian[i].studentNumber)].lastName << " Student Number TUPM-" << guardian[i].studentNumber << endl;
        for (e = 0; e <= guardian[i].guardianCount; e++)
        {
            cout << guardian[i].guardians[e].firstName << " " << guardian[i].guardians[e].lastName << " " << guardian[i].guardians[e].contact << " " << guardian[i].guardians[e].relationship << " " << guardian[i].guardians[e].occupation << endl;
        }
        cout << endl;
    }

    cout << "\nEnd of results" << endl;
    pressAnyKey();
    guardian_menu();
}
