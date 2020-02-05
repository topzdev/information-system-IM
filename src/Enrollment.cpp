#include <iostream>
#include <conio.h>
#include "string.h"

#include "Enrollment.h"
#include "Model.h"
#include "Controller.h"

using namespace std;

int enroll_menu()
{
    int choosen;
    system("cls");
    cout << "[1] Add Student Record\n";
    cout << "[2] Search Student Record\n";
    cout << "[3] Show All Student Record\n";
    cout << "Enter your choosen number: ";
    cin >> choosen;

    switch (choosen)
    {

    case 1:
        addRecordPrompt();
        break;

    case 2:
        findStudent();
        break;

    case 3:
        showAllRecord();
        break;
    }

    return 0;
}

int addRecordPrompt()
{
    totalRecord++;
    STUDENT input;
    cout << "ADD STUDENT RECORD\n";
    cout << "===================================\n";
    cout << "STUDENT ID:" << totalRecord << "\n";

    cout << "Enter your First Name: ";
    cin >> input.firstName;

    cout << "Enter your Last Name: ";
    cin >> input.lastName;

    cout << "Enter your address: ";
    cin >> input.address;

    cout << "Enter your Tel Number: ";
    cin >> input.tel;

    cout << "Enter your Course: ";
    cin >> input.course;

    int i = totalRecord;
    record[i].id = i;

    strcpy(record[i].firstName, input.firstName);
    strcpy(record[i].lastName, input.lastName);
    strcpy(record[i].address, input.address);
    strcpy(record[i].tel, input.tel);
    strcpy(record[i].course, input.course);

    saveFileRecord();
    cout << " \nStudent Record Successfully Added\n";
    getch();
    enroll_menu();

    return 0;
}

int findStudent()
{
    int i = 1, id, found = 0;
    cout << "FIND STUDENT RECORD\n";
    cout << "=================================\n";

    cout << "Enter student id: ";
    scanf("%d", &id);

    while (i <= totalRecord)
    {
        if (i == id)
        {
            cout << "Student ID: " << record[i].id << "\n";
            cout << "Full Name:" << record[i].firstName << " " << record[i].lastName << "\n";
            cout << "Address:" << record[i].address << "\n";
            cout << "Telephone Number:" << record[i].tel << "\n";
            cout << "Course:" << record[i].course << "\n";
            found++;
        }
        i++;
    }

    if (found == 0)
    {
        cout << "\nStudent not found...\n";
    }

    getch();
    enroll_menu();
    return 0;
}

int showAllRecord()
{
    int i = 1;

    cout << "Showing student data\n";
    cout << "=================================\n";
    while (i <= totalRecord)
    {
        cout << record[i].id << " " << record[i].firstName << " " << record[i].lastName << " " << record[i].address << " " << record[i].tel << " " << record[i].course;
        i++;
    }
    cout << "\n=================================\n";
    cout << "End of Record\n";

    getch();
    enroll_menu();
    return 0;
}

int locateStudent(int id)
// * Find student index and return it
{
    return 1;
}