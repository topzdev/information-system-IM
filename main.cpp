#include "main.h"
#include <iostream>
#include "Enrollment.h"
#include "Enlistment.h"
#include "Controller.h"
#include "Guardian.h"


int main_menu();
using namespace std;

int main()
{
    retrieveFileRecord();
    retrieveFileEnlist();
    retrieveFileGuardian();
    main_menu();
    return 0;
}

int main_menu()
{
    int choose;
    system("cls");
    cout << "\t\t\t\t    =================================================\n";
    cout << "\t\t\t\t    ||  \t\t            \t\t   ||\n";
    cout << "\t\t\t\t    ||  \t  STUDENT ERS MAIN MENU \t   ||\n";
    cout << "\t\t\t\t    ||  \t\t            \t\t   ||\n";
    cout << "\t\t\t\t    =================================================\n\n";
    cout << "\t\t\t\t\t\tStudent Information System" << endl;
    cout << "\n\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t\t\t\t\t\t  [1] Enroll Student" << endl;
    cout << "\n\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t\t\t\t\t\t  [2] Enlist Student" << endl;
    cout << "\n\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t\t\t\t\t\t  [3] Add Guardians" << endl;
    cout << "\n\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t\t\t\t\t\t  [4] Exit" << endl;
    cout << "\n\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t\t\t\t\t\tSELECT SERVICE:";
    cin >> choose;

    switch (choose)
    {
    case 1:
        enroll_menu();
        break;

    case 2:
        enlist_menu();
        break;

    case 3:
        guardian_menu();
        break;

    case 4:
        break;
    }
    return 0;
}
