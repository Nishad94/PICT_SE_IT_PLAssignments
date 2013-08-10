#include "definitions.h"
#ifndef SEARCHING_DB
#define SEARCHING_DB

//Return the location of the searched roll number in the array of the structure, if not found return -1
int search_rollnum(int rnum, database db[])
{
    int i;
    for(i=0; i<MAX_STUDENTS; i++)
        if(db[i].roll_no == rnum)
            return i;

    if(i == MAX_STUDENTS)
        return -1;  //Roll number not found
}


#endif
