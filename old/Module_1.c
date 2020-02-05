#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
#define MAX_SUB 5
#define FILENAME "record"

int totalRecord = 1;

typedef struct student {
    int id, subCount;
    char firstName[50], lastName[50], address[50] ,tel[11], course[11];
    char subject[50][10];
}STUDENT;

STUDENT record[MAX];

FILE * file_rec;


int main (){
    retrieveFile();
    menu();
    return 0;
}

void menu(){
    int choosen;
    system("cls");
    printf("[1] Add Student Record\n");
    printf("[2] Search Student Record\n");
    printf("[3] Show All Student Record\n");
    printf("Enter your choosen number: ");
    scanf("%d", &choosen);

    switch(choosen){

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

}

void addRecordPrompt(){
    int id, e = 0, counter = 0;
    char subject[50][10];
    char firstName[50], lastName[50], address[50], tel[50], course[50];

    printf("ADD STUDENT RECORD\n");
    printf("===================================\n");

    printf("STUDENT ID: %d \n", totalRecord );

    printf("Enter your First Name: ");
    scanf("%s", &firstName);

    printf("Enter your Last Name: ");
    scanf("%s", &lastName);

    printf("Enter your address: ");
    scanf("%s", &address);

    printf("Enter your Tel Number: ");
    scanf("%s", &tel);

    printf("Enter your Course: ");
    scanf("%s", &course);

    printf("Type 0 if done \n");
    printf("Enter %d subject: ", (counter + 1));
    scanf("%s", subject[counter]);
    while(strcmpi(subject[counter], "0") == 1){
        counter++;
        printf("Enter %d subject: ", (counter + 1));
        scanf("%s", subject[counter]);
    };

    int i = totalRecord;
    record[i].id = i;
    record[i].subCount = counter;


    printf("List of subject you entered is\n");
    while(e != counter){
        //record[i].subject = subject[e];
        strcpy(record[i].subject[e],subject[e]);
        printf("\n%s", record[i].subject[e]);
        e++;
    }

    strcpy(record[i].firstName, firstName);
    strcpy(record[i].lastName, lastName);
    strcpy(record[i].address, address);
    strcpy(record[i].tel, tel);
    strcpy(record[i].course, course);

    totalRecord++;

    saveFile();
    printf("\nStudent Record Successfully Added\n");
    getch();
    menu();

}


void findStudent(){

}


void showAllRecord(){
    int i = 1;

    printf("Showing student data\n");
    printf("=================================\n");
    while(i <= totalRecord){
        printf("%d %s %s %s %s %s %d\n", record[i].id, record[i].firstName, record[i].lastName, record[i].address, record[i].tel, record[i].course, record[i].subCount);
        i++;
    }
    printf("=================================\n");
    printf("End of Record\n");

    getch();
    menu();

}


void retrieveFile(){

    int i = 1, e = 0;
    file_rec = fopen("record.txt", "r");

    if(file_rec != NULL){
        printf("\nRetrieving File...");
        fscanf(file_rec, "%d", &totalRecord);
        while(i <= totalRecord){
            e = 0;
            fscanf(file_rec, "%d %s %s %s %s %s %d", &record[i].id, record[i].firstName, record[i].lastName, record[i].address, record[i].tel, record[i].course, &record[i].subCount);

            while(e != record[i].subCount){

                fscanf(file_rec, "%s", record[i].subject[e]);

                e++;
            }
            i++;
        }
    }
    getch();
    fclose(file_rec);
}


void saveFile(){

    int i = 1, e = 0;
    file_rec = fopen("record.txt", "w");

    if(file_rec != NULL){
        printf("\nSaving file...");
        fprintf(file_rec, "%d\n", totalRecord);
        while(i <= totalRecord){
            e = 0;
            fprintf(file_rec, "%d %s %s %s %s %s %d\n", record[i].id, record[i].firstName, record[i].lastName, record[i].address, record[i].tel, record[i].course, record[i].subCount);


            while(e != record[i].subCount){
                fprintf(file_rec,"%s\n", record[i].subject[e]);
                e++;
            }
            i++;
        }
    }

    fclose(file_rec);

}


