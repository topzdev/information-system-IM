#include "Controller.h"
#include "Model.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

FILE *file;

int totalRecord = 0;
int totalEnlist = 0;
int totalGuardian = 0;

STUDENT record[MAX];
ENLIST enlist[MAX];
PARENT_CONTACT guardian[MAX];

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

    if (file != NULL)
    {

        fscanf(file, "%d", &totalEnlist);

        for (i = 1; i <= totalEnlist; i++)
        {
            fscanf(file, "%d %d", &enlist[i].studentNumber, &enlist[i].subCount);

            for (e = 0; e <= enlist[i].subCount; e++)
            {
                fscanf(file, "%s %s %s %s", enlist[i].subject[e].subjectCode, enlist[i].subject[e].venue, enlist[i].subject[e].time, enlist[i].subject[e].subjectDescription);
            }
        }
    }

    fclose(file);
}

void saveFileEnlist()
{
    int i, e;
    file = fopen(FILENAME_ENLIST, "w");

    if (file != NULL)
    {

        fprintf(file, "%d\n", totalEnlist);

        for (i = 1; i <= totalEnlist; i++)
        {
            fprintf(file, "%d %d\n", enlist[i].studentNumber, enlist[i].subCount);

            for (e = 0; e <= enlist[i].subCount; e++)
            {
                fprintf(file, "%s %s %s %s\n", enlist[i].subject[e].subjectCode, enlist[i].subject[e].venue, enlist[i].subject[e].time, enlist[i].subject[e].subjectDescription);
            }
        }
    }
    fclose(file);
}

void retrieveFileGuardian()
{
    int i, e;
    file = fopen(FILENAME_GUARDIAN, "r");

    if (file != NULL)
    {

        fscanf(file, "%d", &totalGuardian);

        for (i = 1; i <= totalGuardian; i++)
        {
            fscanf(file, "%d %d", &guardian[i].studentNumber, &guardian[i].guardianCount);

            for (e = 0; e <= guardian[i].guardianCount; e++)
            {
                fscanf(file, "%s %s %s %s %s", guardian[i].guardians[e].firstName, guardian[i].guardians[e].lastName, guardian[i].guardians[e].contact, guardian[i].guardians[e].relationship, guardian[i].guardians[e].occupation);
            }
        }
    }

    fclose(file);
}

void saveFileGuardian()
{
    int i, e;
    file = fopen(FILENAME_GUARDIAN, "w");

    if (file != NULL)
    {

        fprintf(file, "%d\n", totalGuardian);

        for (i = 1; i <= totalGuardian; i++)
        {
            fprintf(file, "%d %d\n", guardian[i].studentNumber, guardian[i].guardianCount);

            for (e = 0; e <= guardian[i].guardianCount; e++)
            {
                fprintf(file, "%s %s %s %s %s\n", guardian[i].guardians[e].firstName, guardian[i].guardians[e].lastName, guardian[i].guardians[e].contact, guardian[i].guardians[e].relationship, guardian[i].guardians[e].occupation);
            }
        }
    }
    fclose(file);
}
