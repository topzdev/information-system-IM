#include <iostream>
#include <windows.h>
#include <stdio.h>

// Context
#include "Enlistment.h"
#include "Model.h"
#include "Controller.h"
#include "Config.h"
#include "Views.h"
#include "Utils.h"
#include "Enrollment.h"

using namespace std;

void enlist_menu()
{
    system("cls");
    int choose;

    cout << "Choose any options" << endl;
    cout << "[1] Enlist Subject" << endl;
    cout << "[2] Display Subject Enlisted" << endl;
    cout << "[3] Student COR" << endl;
    cout << "[4] Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choose;

    system("cls");
    switch (choose)
    {

    case 1:
        inputSubject();
        break;

    case 2:
        displaySubjects();
        break;

    case 3:
        printCOR();
        break;

    case 4:
        break;
        system(0);
    default:
        cout << "Your input is not in the options";
        pressAnyKey();
        break;
    }
}

void inputSubject()
{
    int stop = 1, studentNo;
    totalEnlist++;
    SUBJECT input[MAX_SUB];
    ENLIST student;

    int sub_count = 0;

    cout << "SUBJECT ENLISTMENT\n";
    cout << "-------------------------------------\n";

    cout << "Enter student Student no: ";
    cin >> studentNo;

    // if the student not found this function will not execute
    if (locateStudent(studentNo) == -1)
    {
        cout << "Student not found try again later" << endl;
        pressAnyKey();
        enlist_menu();
        return;
    }

    while (1)
    {
        cout << "Subject no# " << (sub_count + 1) << endl;
        cout << "Enter Subject Code: ";
        cin >> input[sub_count].subjectCode;

        cout << "Enter Venue: ";
        cin >> input[sub_count].venue;

        cout << "Enter Time: ";
        cin >> input[sub_count].time;

        cout << "Enter Subject Description: ";
        cin >> input[sub_count].subjectDescription;

        cout << "Add more subjects type [1] if YES and [0] if no: ";
        cin >> stop;

        if (stop != 1)
        {
            break;
        }

        sub_count++;
    }
    student.studentNumber = studentNo;
    student.subCount = sub_count;
    insertEnlist(student, input);
}

void insertEnlist(ENLIST student, SUBJECT *input)
{
    totalEnlist;
    enlist[totalEnlist].subCount = student.subCount;
    enlist[totalEnlist].studentNumber = student.studentNumber;

    // *enlist[totalEnlist].subject = *input;

    for (int i = 0; i <= student.subCount; i++)
    {
        strcpy(enlist[totalEnlist].subject[i].subjectCode, input[i].subjectCode);
        strcpy(enlist[totalEnlist].subject[i].venue, input[i].venue);
        strcpy(enlist[totalEnlist].subject[i].time, input[i].time);
        strcpy(enlist[totalEnlist].subject[i].subjectDescription, input[i].subjectDescription);
    }

    saveFileEnlist();
    cout << "Successfully Added";
    pressAnyKey();
    enlist_menu();
}

void printCOR()
{
    int search, studentNo, indx;

    cout << "Enter student Student no: ";
    cin >> studentNo;

    // if the student not found this function will not execute
    indx = locateStudent(studentNo);
    if (indx == -1)
    {
        cout << "Student not found try again later" << endl;
        pressAnyKey();
        enlist_menu();
        return;
    }
    else
    {

        printf("\n\n\t\t\tCERTIFICATE OF REGISTRATION\n\n");
        printf("\tStudent ID: TUPM-0%d\tSURNAME: %s  FIRST NAME: %s", enlist[indx].studentNumber, record[indx].lastName, record[indx].firstName);
        printf("\n\tADDRESS: %s   Contact No.: %s", record[indx].address, record[indx].tel);
        printf("\n\n\tSUBJECT CODE\tSUBJECT TITLE\tTIME\tVENUE\n");

        for (int i = 0; i <= enlist[indx].subCount; i++)
        {
            printf("\t%s\t\t%s\t\t%s\t%s\n", enlist[indx].subject[i].subjectCode, enlist[indx].subject[i].subjectDescription, enlist[indx].subject[i].time, enlist[indx].subject[i].venue);
        }

        printf("\n\n\t ENROLLED ");
        printf("\n\t ______________________");
        printf("\n\n\t   Student's Signature");
    }
}

void displaySubjects()
{
    int i, e;
    cout << "Subject Code | Venue | Time | Subject Description" << endl;
    for (i = 1; i <= totalEnlist; i++)
    {
        cout << "STUDENT ID: " << enlist[i].studentNumber << "  NUMBER OF SUBJECTS: " << enlist[i].subCount + 1 << endl;

        for (e = 0; e <= enlist[i].subCount; e++)
        {
            cout << enlist[i].subject[e].subjectCode << " " << enlist[i].subject[e].venue << " " << enlist[i].subject[e].time << " " << enlist[i].subject[e].subjectDescription << endl;
        }
    }

    cout << "\nEnd of results" << endl;
    pressAnyKey();
    enlist_menu();
}
