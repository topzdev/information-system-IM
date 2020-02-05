#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Config.h"
#include "Model.h"


/* Student Record */
void retrieveFileRecord();
void saveFileRecord();

extern int totalRecord;
extern STUDENT record[MAX];


/* Student Enlistment */
void retrieveFileEnlist();
void saveFileEnlist();

extern ENLIST enlist[MAX];
extern int totalEnlist;




#endif // CONTROLLER_H
