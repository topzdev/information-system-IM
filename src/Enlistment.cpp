#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

// Context
#include "Enlistment.h"
#include "Model.h"
#include "Controller.h"
#include "Config.h"
#include "Views.h"
#include "Utils.h"
#include "Enrollment.h"
#include "main.h"

int concat(int a, int b);

using namespace std;

void enlist_menu()
{
    system("cls");
    int choose;
                                                                             //*
    cout << "\t\t\t=================================================================" << endl;
    cout << "\t\t\t=\t\t\t\t\t\t\t\t=" << endl;
    cout << "\t\t\t=\t\t\tChoose any options\t\t\t=" << endl;
    cout << "\t\t\t=\t\t\t\t\t\t\t\t=" << endl;
    cout << "\t\t\t=\t\t\t[1] Enlist Subject\t\t\t=" << endl;
    cout << "\t\t\t=\t\t\t[2] Display Subject Enlisted\t\t=" << endl;
    cout << "\t\t\t=\t\t\t[3] Student COR\t\t\t\t=" << endl;
    cout << "\t\t\t=\t\t\t[4] Return to Main Menu\t\t\t\t=" << endl;
    cout << "\t\t\t=\t\t\t\t\t\t\t\t=" << endl;
    cout << "\t\t\t=\t\t\t\t\t\t\t\t=" << endl;
    cout << "\t\t\t=================================================================" << endl;
    cout << endl << endl <<"\t\t\t\tEnter your choice: ";
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

void inputSubject()
{
    int stop = 1, studentNo;
    SUBJECT input[MAX_SUB];
    ENLIST student;
    int num = 0;

    int sub_count = 0;

    cout << "\t\t\t=================================================================" << endl;
    cout << "\t\t\t=\t\t\t\t\t\t\t\t=" << endl;
    cout << "\t\t\t=\t\t\tSUBJECT ENLISTMENT\t\t\t=\n";
    cout << "\t\t\t=\t\t\t\t\t\t\t\t=" << endl;
    cout << "\t\t\t=================================================================" << endl;

    cout << endl << "\t\t\t\tEnter student Student no: ";
    cin >> studentNo;

    // if the student not found this function will not execute
    if(locateStudent(studentNo) == -1){

        errorMessage("Student not found try again later");
        enlist_menu();
        return;
    }

    // if the student is already enlisted the process will not continue
    if(locateEnlist(studentNo) >= 0){

        errorMessage("Student already enlisted");
        enlist_menu();
        return;
    }

     totalEnlist++;

    while (1)
     {
        cout << endl << "Subject no# "<<(sub_count + 1)<<endl;
        cout << "Enter Subject Code: ";
        cin >> input[sub_count].subjectCode;

        cout << "Enter Venue: ";
        cin >> input[sub_count].venue;

        cout << "Enter Time: ";
        cin >> input[sub_count].time;

        cout << "Enter Subject Description: ";
        cin >> input[sub_count].subjectDescription;

        cout << endl << "Add more subject? Press [1] if yes, otherwise [0]";
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

    for(int i = 0; i <= student.subCount; i++){
        strcpy(enlist[totalEnlist].subject[i].subjectCode, input[i].subjectCode);
        strcpy(enlist[totalEnlist].subject[i].venue, input[i].venue);
        strcpy(enlist[totalEnlist].subject[i].time, input[i].time);
        strcpy(enlist[totalEnlist].subject[i].subjectDescription, input[i].subjectDescription);
    }

    saveFileEnlist();
    cout<<"Successfully Added";
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
    if(indx== -1){
        cout<<"Student not found try again later"<<endl;
        pressAnyKey();
        enlist_menu();
        return;
    }
    else{


    printf("\n\n\t\t\tCERTIFICATE OF REGISTRATION\n\n");
    printf("\tStudent ID: TUPM-0%d\tSURNAME: %s  FIRST NAME: %s",enlist[indx].studentNumber,record[indx].lastName,record[indx].firstName);
    printf("\n\tADDRESS: %s   Contact No.: %s",record[indx].address,record[indx].tel);
    printf("\n\n\tSUBJECT CODE\tSUBJECT TITLE\tTIME\tVENUE\n");

    for(int i=0;i<=enlist[indx].subCount;i++)
    {
        printf("\t%s\t\t%s\t\t%s\t%s\n",enlist[indx].subject[i].subjectCode,enlist[indx].subject[i].subjectDescription,enlist[indx].subject[i].time,enlist[indx].subject[i].venue);
    }

    printf("\n\n\t ENROLLED ");
    printf("\n\t ______________________");
    printf("\n\n\t   Student's Signature");
    }
}

void displaySubjects()
{
    int i, e;

    for (i = 1; i <= totalEnlist; i++)
    {
        cout << endl
             << "\t\t\t\t\tStudent Name: " << record[locateEnlist(enlist[i].studentNumber)].firstName << " " << record[locateEnlist(enlist[i].studentNumber)].lastName << " Student Number TUPM-" << enlist[i].studentNumber << endl;

        cout << "=========================================================================================================" << endl;
        cout << "=\t\t\t\t\t\t\t\t\t\t\t\t\t=" << endl;
        cout << "=\t\tSubject Code\t|\tVenue\t|\tTime\t|\tSubject Description\t\t=\n";
        cout << "=\t\t\t\t\t\t\t\t\t\t\t\t\t=" << endl;
        cout << "=========================================================================================================" << endl;
        for (e = 0; e <= enlist[i].subCount; e++)
        {
            cout << "=\t\t" << enlist[i].subject[e].subjectCode << "\t" << "\t\t" <<  enlist[i].subject[e].venue << "\t" << "\t" << enlist[i].subject[e].time << "\t\t" << "\t" << enlist[i].subject[e].subjectDescription << "\t\t\t=" << endl;
        }
        cout << "=\t\t\t\t\t\t\t\t\t\t\t\t\t=" << endl;
        cout << "=========================================================================================================" << endl;
    }

    cout<<"\nEnd of results"<<endl;
    pressAnyKey();
    enlist_menu();
}
