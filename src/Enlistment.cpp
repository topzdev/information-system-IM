#include <iostream>
#include "Enlistment.h"
#include "Model.h"
#include "Controller.h"
#include "Config.h"
#include "Views.h"
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
        break;
        printCOR();

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
    int stop = 1;
    totalEnlist++;
    SUBJECT input[MAX_SUB];
    ENLIST student;

    int sub_count = 0;

    cout << "SUBJECT ENLISTMENT\n";
    cout << "-------------------------------------\n";

    cout << "Enter student Student no: ";
    cin >> student.studentNumber;

    cout << "Enter the student's subjects %d \n", sub_count;

    while (1)
    {
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

    student.subCount = sub_count;
    insertEnlist(student, input);
}

void insertEnlist(ENLIST student, SUBJECT *input)
{
    int i;
    enlist[totalEnlist].subCount = student.subCount;
    *enlist[totalEnlist].subject = *input;

    /*for(i = 0; i < student.subCount; i++){
        strcpy(L[count].subject[i].studentNumber, input.studentNumber);
        strcpy(L[count].subjectCode, input.subjectCode);
        strcpy(L[count].venue, input.venue);
        strcpy(L[count].time, input.time);
        strcpy(L[count].subjectDescription, input.subjectDescription);

    }*/

    saveFileEnlist();
    printf("Successfully Added");
    pressAnyKey();
}

void printCOR()
{
    int search;

    printf("Enter student number ID: ");
    scanf("%s", &search);

    int indx = locateStudent(search);

    if (indx == -1)
    {
        printf("Student not found...");
        return;
    }

    printf("The student number is: %d", enlist[indx].studentNumber);
}

void displaySubjects()
{
    int i = 0, e;
    printf("Subject Code | Venue | Time | Subject Description\n");
    for (i = 0; i <= totalEnlist; i++)
    {
        printf("%s %d\n", enlist[i].studentNumber, enlist[i].subCount);

        for (e = 0; e <= enlist[i].subCount; e++)
        {
            printf("%s %s %s %s\n", enlist[i].subject[e].subjectCode, enlist[i].subject[e].venue, enlist[i].subject[e].time, enlist[i].subject[e].subjectDescription);
        }
    }

    printf("\nEnd of results");
    pressAnyKey();
}
