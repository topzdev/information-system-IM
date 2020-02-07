#include "Views.h"
#include <conio.h>
#include <windows.h>
#include <iostream>

using namespace std;

void pressAnyKey()
{
    cout << "\n\t\t\t\t\t\t    Press any [Key] to Continue!"
         << endl;
    getch();
}

void errorMessage(char *message){
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << "\t\t\t=================================================================" << endl;
        cout << "\t\t\t=\t\t\t\t\t\t\t\t=" << endl;
        cout << "\t\t\t=\t\t"<<message<<"\t\t=\n";
        cout << "\t\t\t=\t\t\t\t\t\t\t\t=" << endl;
        cout << "\t\t\t=================================================================" << endl;
        pressAnyKey();
}
