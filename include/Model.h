#ifndef MODEL_H
#define MODEL_H
#include "Config.h"

/* Student record */
typedef struct student
{
    int id;
    char firstName[50], lastName[50], address[50], tel[11], course[11];
} STUDENT;

/*Enlistment Structures*/
typedef struct subject
{

    char subjectCode[40];
    char venue[40];
    char time[20];
    char subjectDescription[40];

} SUBJECT;

typedef struct enlistStruct
{

    int subCount;
    int studentNumber;
    SUBJECT subject[MAX_SUB];

} ENLIST;

/*Guardian Structures*/
typedef struct guardianStruct
{
    char firstName[40];
    char lastName[40];
    char contact[20];
    char relationship[40];
    char occupation[40];
} GUARDIAN;

typedef struct parentContactStruct
{
    int guardianCount;
    int studentNumber;
    GUARDIAN guardians[MAX_GUARDIAN];

} PARENT_CONTACT;

#endif // MODEL_H
