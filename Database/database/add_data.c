#include "definitions.h"
#ifndef DATA_ADD
#define DATA_ADD

//Add a new student record at db[position]
void add_record(int position, database db[])
{
    //Read and validate student name
    add_name(db[position].name,"Enter student name: ");

    //Read and validate mobile number
    add_number(db[position].mobile_num);

    //Read and validate address
    add_address(&db[position].a);

    //Read and validate department
    add_department(&db[position].department);

    //Read and validate roll number
    add_rollnum(&db[position].roll_no);

    //Read and validate FE marks
    add_marks(db[position].FE_marks);
}

//Function will store parameter(name,city,state,etc) in destination after validation
void add_name(char dest[], char parameter[])
{
    char temp[MAX_NAME_SIZE];

    //Repeatedly read name until the entered name is valid
    do
    {
        printf("%s",parameter);
        read_string(temp);
    }
    while(!validate_name(temp));

    //Copy to destination if validation is successful
    string_copy(dest,temp);

}

//Function will store number in destination after validation
void add_number(char dest[])
{
    char temp[11];

    //Repeatedly read mobile number until it is a valid 10 digit number
    do
    {
        printf("Enter 10 digit student mobile number: ");
        read_string(temp);
    }
    while(!validate_number(temp,10));

    //Copy to database if validation is successful
    string_copy(dest,temp);
}

//Pass by reference because we need to modify actual contents!
//Function will store address in destination after validation
void add_address(ADDRESS* a)
{
    printf("Enter street name(primary address,max 100 characters): ");
    read_string(a->street_name);

    //Similar validation rules for city,state as name, so use add_name()
    add_name(a->city,"Enter city: ");
    add_name(a->state,"Enter state: ");

    add_pin(a->pincode);
}

//Read pincode and add after validation
void add_pin(char dest[])
{
    char temp[20]; //temp test array

    //Repeatedly read pin until the entered pin is valid
    do
    {
        printf("Enter 6 digit PINCODE: ");
        read_string(temp);
    }
    while(!validate_number(temp,6));

    //Copy to destination if validation is successful
    string_copy(dest,temp);
}

//Function will store the department using the defined macros
void add_department(int* dest)
{
    int temp;
    do
    {
        printf("Choose department:\n\t1.I.T\t2.Computer Engg\t3.E&TC\n");
        scanf("%d",&temp);
    }
    while((temp < 1) || (temp > 3));

    *dest = temp;
}

//Function that validates and stores 4 digit roll number
void add_rollnum(int* dest)
{
    int temp;

    do
    {
        printf("Enter 4 digit roll number: ");
        scanf("%d",&temp);
    }
    while((temp < 1000) || (temp > 4999)); //Roll numbers for: FE 1xxx SE 2xxx TE 3xxx BE 4xxx

    *dest = temp;
}

//Function to validate and store marks of 5 subjects
void add_marks(int dest[])
{
    int i=0, temp;

    printf("Enter the following F.E Marks(out of 100) :\n");

    //Read and validate:
    do
    {
        printf("Engineering Mathematics 1: ");
        scanf("%d",&temp);
    }
    while((temp < 0) || (temp>100));
    dest[(i++)] = temp;

    do
    {
        printf("Engineering Mathematics 2: ");
        scanf("%d",&temp);
    }
    while((temp < 0) || (temp>100));
    dest[(i++)] = temp;

    do
    {
        printf("FPL 1: ");
        scanf("%d",&temp);
    }
    while((temp < 0) || (temp>100));
    dest[(i++)] = temp;

    do
    {
        printf("FPL 2: ");
        scanf("%d",&temp);
    }
    while((temp < 0) || (temp>100));
    dest[(i++)] = temp;

    do
    {
        printf("Engineering Mechanics: ");
        scanf("%d",&temp);
    }
    while((temp < 0) || (temp>100));
    dest[(i++)] = temp;

}

#endif
