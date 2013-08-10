/* Tasks implemented:
             1. Adding data:
                    1. Add and validate name
                    2. Add and validate mobile number
                    3. Add and validate address:
                                    1. Address->Street Name
                                    2. Address->City
                                    3. Address->State
                                    4. Address->PinCode
                    4. Add and validate department
                    5. Add and validate roll number
            2. Searching:
                    1. By rollnumber


    Tasks Left:
            - Add and validate FE Marks
            - Display data
            - Searching by: 1. Name
                            2. Mobile Number
                            3. City,State,PINCODE
                            4. Department
            - Delete Data
*/

#ifndef NECESSARY_HEADERS
#define NECESSARY_HEADERS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_NAME_SIZE 30
#define PHONENUM_SIZE 11
#define IT 1
#define COMP 2
#define ENTC 3
#define MAX_STUDENTS 10


typedef struct adrs
{
    char street_name[100];
    char city[15];
    char state[15];
    char pincode[7];
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

//Menu and initialize Functions:
int display_menu(void);
void initialize_database(database db[]);

//Search functions:
int search_rollnum(int rnum,database db[]);

//Add data functions:
void add_record(int position,database db[]);
void add_name(char dest[], char parameter[]);
void add_number(char dest[]);
void add_address(ADDRESS* a);
void add_pin(char dest[]);
void add_department(int* dest);
void add_rollnum(int* dest);
void add_marks(int dest[]);

//Validation functions:
int validate_name(char name[]);
int validate_number(char num[],int num_of_digits);

#endif
