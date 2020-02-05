#ifndef MODEL_H
#define MODEL_H
#include "Config.h"

typedef struct student
{
    int id;
    char firstName[50], lastName[50], address[50], tel[11], course[11];
} STUDENT;

typedef struct subject
{

    char subjectCode[40];
    char venue[40];
    char time[20];
    char subjectDescription[40];

} SUBJECT;

typedef struct enlist
{

    int subCount;
    char studentNumber[40];
    SUBJECT subject[MAX_SUB];

} ENLIST;

#endif // MODEL_H
