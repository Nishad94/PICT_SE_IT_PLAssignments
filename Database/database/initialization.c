#include "definitions.h"
#ifndef INITIALIZATION_DB
#define INITIALIZATION_DB

//Main Menu
int display_menu(void)
{
    int choice, wrong_choice=0;
    do
    {
        make_heading("STUDENT DATABASE");
        if(wrong_choice)
        {
            printf("ERROR: Wrong choice, enter correct choice!! \n\n");
            wrong_choice = 0;
        }
        printf("Choose an operation to perform:\n1.Add Student Record\n2.Search\n3.Delete Student Record\n4.Display records\n");
        scanf("%d",&choice);
        if(choice<1 || choice>4)
            wrong_choice = 1;
    }
    while(choice<1 || choice>4);
    printf("\n");
    return choice;
}


//Initialize database entries with roll numbers as -1
void initialize_database(database db[])
{
    int i;
    for(i=0; i<MAX_STUDENTS; i++)
        db[i].roll_no = -1;
}

#endif

