#include "Controller.h"
#include "Model.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

FILE *file;

int totalRecord = 0;
int totalEnlist = 0;

STUDENT record[MAX];
ENLIST enlist[MAX];

void retrieveFileRecord()
{

    int i = 1;
    file = fopen(FILENAME_RECORD, "r");

    if (file != NULL)
    {
        printf("\nRetrieving File...");
        fscanf(file, "%d", &totalRecord);
        while (i <= totalRecord)
        {

            fscanf(file, "%d %s %s %s %s %s", &record[i].id, record[i].firstName, record[i].lastName, record[i].address, record[i].tel, record[i].course);
            i++;
        }
    }
    getch();
    fclose(file);
}

void saveFileRecord()
{

    int i = 1;
    file = fopen(FILENAME_RECORD, "w");

    if (file != NULL)
    {
        printf("\nSaving file...");
        fprintf(file, "%d\n", totalRecord);
        while (i <= totalRecord)
        {

            fprintf(file, "%d %s %s %s %s %s\n", record[i].id, record[i].firstName, record[i].lastName, record[i].address, record[i].tel, record[i].course);
            i++;
        }
    }

    fclose(file);
}

void retrieveFileEnlist()
{
    int i, e;
    file = fopen(FILENAME_ENLIST, "r");

    fscanf(file, "%d", &totalEnlist);
    for (i = 0; i <= totalEnlist; i++)
    {
        fscanf(file, "%s %d", enlist[i].studentNumber, &enlist[i].subCount);

        for (e = 0; e <= enlist[i].subCount; e++)
        {
            fscanf(file, "%s %s %s %s", enlist[i].subject[e].subjectCode, enlist[i].subject[e].venue, enlist[i].subject[e].time, enlist[i].subject[e].subjectDescription);
        }
    }
    fclose(file);
}

void saveFileEnlist()
{
    int i, e;
    file = fopen(FILENAME_ENLIST, "w");

    fprintf(file, "%d\n", totalEnlist);
    for (i = 0; i <= totalEnlist; i++)
    {
        fprintf(file, "%s %d\n", enlist[i].studentNumber, enlist[i].subCount);

        for (e = 0; e <= enlist[i].subCount; e++)
        {
            fprintf(file, "%s %s %s %s\n", enlist[i].subject[e].subjectCode, enlist[i].subject[e].venue, enlist[i].subject[e].time, enlist[i].subject[e].subjectDescription);
        }
    }
    fclose(file);
}
