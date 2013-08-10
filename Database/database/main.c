#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stringops.c"
//#include <string.h>
#define MAX_NAME_SIZE 30
#define PHONENUM_SIZE 11
#define IT 1
#define COMP 2
#define ENTC 3
#define MAX_STUDENTS 10

typedef struct adrs
{
    char society_flat_num[100];
    char street_name[40];
    char city[15];
    char state[15];
} ADDRESS;

typedef struct db
{
    char name[MAX_NAME_SIZE];
    char mobile_num[PHONENUM_SIZE];
    ADDRESS a;
    int department;
    int roll_no;
    int FE_marks[5];
} database;

void make_heading(char s[]);
int display_menu(void);
void initialize_database(database db[]);
int search_rollnum(int rnum, database db[]);
void add_record(int position, database db[]);
void add_name(char dest[]);
void add_number(char dest[]);
int validate_name(char name[]);
int validate_number(char num[]);

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

//Interface(Heading)
void make_heading(char s[])
{
    int i, j, tabs_to_center=3;
    system("clear");
    i = strlen(s);
    for(j=0; j<tabs_to_center; j++)
        putchar('\t');
    for(j=0; j<= (i+1); j++)
        putchar('#');
    putchar('\n');
    for(j=0; j<tabs_to_center; j++)
        putchar('\t');
    putchar(' ');
    for(j=0; j<i; j++)
        putchar(s[j]);
    putchar(' ');
    putchar('\n');
    for(j=0; j<tabs_to_center; j++)
        putchar('\t');
    for(j=0; j<= (i+1); j++)
        putchar('#');
    printf("\n\n");
}
//End of interface module

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

//Validate name, must consist of only alphabets(1 space accepted between first and lst name) Return 1 on success, else 0
int validate_name(char name[])
{
    int i=0, space=0;

    //Until '\0' is found,check all characters
    while(name[i])
    {
        //isalpha() returns 0 if it isnt a character
        if(!isalpha(name[i]))
        {
            //Only 1 space allowed in the name(seperating first and last name), hence increment space if found
            if((name[i] == ' ') && (space < 1))
                space++;

            //Either spaces exceeded or not an alphabet
            else
                return 0; //Failure
        }

        i++;
    }

    return 1; //Success
}

//Validate 10 digit mobile number, return 1 for success and 0 for failure
int validate_number(char num[])
{
    int i=0;

    //Until '\0' is found,check all characters
    while(num[i])
    {
        //isdigit() returns 0 if it isnt a digit
        if(!isdigit(num[i]))
        {
            return 0; //Failure
        }

        i++;
    }

    //Check whether number of digits is 10
    if(i == 10)
        return 1; //Success

    return 0; //Failure, as number of digits is not 10
}

//Add a new student record at db[position]
void add_record(int position, database db[])
{
    //Read and validate student name
    add_name(db[position].name);

    //Read and validate mobile number
    add_number(db[position].mobile_num);
}

//Function will store name in destination after validation
void add_name(char dest[])
{
    char temp[MAX_NAME_SIZE];

    //Repeatedly read name until the entered name is valid
    do
    {
        printf("Enter student name: ");
        read_string(temp);
    }
    while(!validate_name(temp));

    //Copy to destination if validation is successful
    string_copy(dest,temp);

}

void add_number(char dest[])
{
    char temp[11];

    //Repeatedly read mobile number until it is a valid 10 digit number
    do
    {
        printf("Enter 10 digit student mobile number: ");
        read_string(temp);
    }
    while(!validate_number(temp));

    //Copy to database if validation is successful
    string_copy(dest,temp);
}
