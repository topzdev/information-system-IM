#include "Controller.h"
#include "Model.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int totalRecord = 0;

STUDENT record[MAX];

FILE * file_rec;

void retrieveFile(){

    int i = 1;
    file_rec = fopen(FILENAME, "r");

    if(file_rec != NULL){
        printf("\nRetrieving File...");
        fscanf(file_rec, "%d", &totalRecord);
        while(i <= totalRecord){

            fscanf(file_rec, "%d %s %s %s %s %s", &record[i].id, record[i].firstName, record[i].lastName, record[i].address, record[i].tel, record[i].course);
            i++;
        }
    }
    getch();
    fclose(file_rec);
}


void saveFile(){

    int i = 1;
    file_rec = fopen(FILENAME, "w");

    if(file_rec != NULL){
        printf("\nSaving file...");
        fprintf(file_rec, "%d\n", totalRecord);
        while(i <= totalRecord){

            fprintf(file_rec, "%d %s %s %s %s %s\n", record[i].id, record[i].firstName, record[i].lastName, record[i].address, record[i].tel, record[i].course);
            i++;
        }
    }

    fclose(file_rec);

}
