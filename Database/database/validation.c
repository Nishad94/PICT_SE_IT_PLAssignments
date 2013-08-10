#include "definitions.h"
#ifndef VALIDATIONS_DB
#define VALIDATIONS_DB

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

//Validate 'num_of_digits' digit number, return 1 for success and 0 for failure
int validate_number(char num[], int num_of_digits)
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
    if(i == num_of_digits)
        return 1; //Success

    return 0; //Failure, as number of digits is not 10
}

#endif
