#include "definitions.h"
#include "stringops.c"
#include "add_data.c"
#include "validation.c"
#include "initialization.c"
#include "searching.c"

int main()
{
    database dbase[MAX_STUDENTS];
    initialize_database(dbase);
    switch(display_menu())
    {
    case 1: //Add student record
    {
        int i;
        //Search fror next free position in the structure array
        i = search_rollnum(-1,dbase);
        //Add record at this position
        add_record(i,dbase);
    }
    break;

    case 2: //Search
    {

    }
    break;

    case 3: //Display Data
    {

    }
    break;

    case 4: //Delete record
    {

    }
    break;

    default:
    printf("Wrong choice entered\n");
    }
    return 0;
}
