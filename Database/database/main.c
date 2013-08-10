#include "definitions.h"

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
        add_record(i,dbase);
        printf("Name: %s\nMobile Number: %s\n",dbase[0].name,dbase[0].mobile_num);
    }


    }
    return 0;
}
