#ifndef CONTROLLER_H
#define CONTROLLER_H
#define FILENAME "record.txt"
#include "Model.h"
#define MAX 50


void retrieveFile();
void saveFile();

extern int totalRecord;
extern STUDENT record[MAX];


#endif // CONTROLLER_H
