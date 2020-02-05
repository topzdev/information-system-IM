#include "Database.h"
#include "Controller.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

FILE * file_rec;

void retrieveFile(){

    int i = 1;
    file_rec = fopen(FILENAME, "r");

    if(file_rec != NULL){
        printf("\nRetrieving File...");
        fscanf(file_rec, "%d", &L.totalRecord);
        while(i <= L.totalRecord){
            fscanf(file_rec, "%d %s %s %s %s %s %d", &L.record[i].id, L.record[i].firstName, L.record[i].lastName, L.record[i].address, L.record[i].tel, L.record[i].course);
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
        fprintf(file_rec, "%d\n", L.totalRecord);
        while(i <= L.totalRecord){
            fprintf(file_rec, "%d %s %s %s %s %s %d\n", L.record[i].id, L.record[i].firstName, L.record[i].lastName, L.record[i].address, L.record[i].tel, L.record[i].course);
            i++;
        }
    }

    fclose(file_rec);

}
