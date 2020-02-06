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
    cout << "Student Information System" << endl;
    cout << "[1] Enroll Student" << endl;
    cout << "[2] Enlist Student" << endl;
    cout << "[3] Add Guardians" << endl;
    cout << "[4] Exit" << endl;
    cout << "SELECT SERVICE:";
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
