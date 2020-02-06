#include "Utils.h"
#include "Controller.h"

int locateStudent(int id)
// * Find student index and return it
{
    int i = 0;
    for (i = 0; i <= totalRecord; i++)
    {

        if (record[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

int locateEnlist(int id)
{
    int i = 0;
    for (i = 0; i <= totalEnlist; i++)
    {

        if (enlist[i].studentNumber == id)
        {
            return i;
        }
    }
    return -1;
}