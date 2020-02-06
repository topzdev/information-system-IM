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

/* Guardian Contacts */
void retrieveFileGuardian();
void saveFileGuardian();

extern PARENT_CONTACT guardian[MAX];
extern int totalGuardian;

#endif // CONTROLLER_H
