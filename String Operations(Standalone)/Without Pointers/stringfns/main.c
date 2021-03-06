/*
   Program for string manipulations including:
   1. Compare
   2. Copy
   3. Reverse
   4. Palindrome
   5. Substring
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100 //Maximum length of string

int display_menu(void);
void make_heading(char s[]);
void read_string(char s1[]);
int strlength(char s[]);
int string_compare(char s1[], char s2[]);
void string_copy(char dest[], char src[]);
void string_reverse(char dest[], char src[]);
int string_palindrome(char s1[]);
int substring(char source[], char subpart[]);

int main()
{
    char s1[MAX], s2[MAX], choice;
    int temp;
    do
    {
        switch(display_menu())
        {
        case 1: //Compare 2 strings
            read_string(s1);
            read_string(s2);
            temp = string_compare(s1,s2);
            if(temp) //Strings are not equal
            {
                if(temp == 1)
                    printf("String 1: %s\nis greater than\nString 2: %s!\n",s1,s2);
                else //temp == -1
                    printf("String 2: %s\nis greater than\nString 1: %s!\n",s2,s1);
            }
            else //temp == 0
            {
                printf("Both the strings are equal!\n");
            }
            break;

        case 2: //Copy a string
            read_string(s1);
            string_copy(s2,s1);
            printf("Original String: %s\nCopied String: %s\n",s1,s2);
            break;

        case 3: //Reverse string
            read_string(s1);
            string_reverse(s2,s1);
            printf("Original String: %s\nReversed String: %s\n",s1,s2);
            break;

        case 4: //Check whether string is a palindrome
            read_string(s1);
            temp = string_palindrome(s1);
            if(temp) //temp == 1, if palindrome
                printf("The string \" %s \" is a palindrome.\n",s1);
            else
                printf("The string \" %s \" is not a palindrome.\n",s1);
            break;

        case 5: //Check substring
            read_string(s1);
            printf("Substring:\t");
            read_string(s2);
            temp = substring(s1,s2);
            if(temp) //temp == 1 means substring present
                printf("The substring \" %s \" is a part of \" %s \" .\nIt occurs %d times.\n",s2,s1,temp);
            else //Not a substring, hence temp == 0
                printf("The substring \" %s \" is NOT a part of \" %s \" .\n",s2,s1);
            break;
        }
        printf("Do you want to run the program again? Press 'Y' or 'y' for yes. ");
        scanf("%c",&choice);
    }
    while((choice == 'Y') || (choice == 'y'));
    return 0;
}

//Display module
int display_menu(void)
{
    int choice;
    make_heading("STRING OPERATIONS");
    printf("\tEnter which operation you want to perform:\n1.Compare  2.Copy  3.Reverse  4.Palindrome Check  5.Substring Check\n");
    scanf("%d",&choice);
    if((choice < 1) || (choice > 5))
        printf("ERROR: You've entered an invalid option\n");
    else
        return(choice);
}

void make_heading(char s[])
{
    int i, j, tabs_to_center=3;
    system("clear");
    i = strlength(s);
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

//Function to read a string
void read_string(char s1[])
{
    char c;
    int i=0;
    printf("Enter string: ");
    //Ignore initial \n's in input stream
    while((c = getchar()) == '\n')
        ;
    s1[i++] = c;
    //Copy string untill a newline is encountered
    while((c = getchar()) != '\n')
        s1[i++] = c;
    s1[i] = NULL;
}

//Function to calculate string length
int strlength(char s[])
{
    int i;
    for(i=0; s[i] != NULL; i++)
    ;
    return i;
}
/*Function to compare 2 strings.
  If s1 > s2 return 1, s1 < s2 return -1.
  If s1 == s2, return 0 */
int string_compare(char s1[], char s2[])
{
    int i = 0;
    while((s1[i] == s2[i]) && (s1[i] != NULL))
        i++;
    if(s1[i] == NULL)
        return 0; //Strigns are equal
    else //Not equal
    {
        if(s1[i] > s2[i])
            return 1;
        else
            return -1;
    }
}

//Copies src array into dest array
void string_copy(char dest[], char src[])
{
    int i;
    for(i=0; src[i] != NULL; i++)
        dest[i] = src[i];
    //Append NULL at the end:
    dest[i] = NULL;
}

//Function to reverse a string and store it in a new array
void string_reverse(char dest[], char src[])
{
    int i, j;
    for(i=0; src[i] != NULL; i++)
        ;
    // i is pointing to NULL, so do i--
    i--;
    for(j=0; i >= 0; j++,i--)
        dest[j] = src[i];
    //Append NULL at the end of dest[]
    dest[j] = NULL;
}

//Function returns 1 if string is a palindrome, else 0
int string_palindrome(char s1[])
{
    int i=0, j;
    //Compute string length
    while(s1[i] != NULL)
        i++;
    for(j=0, --i; j < i; j++,i--)
        if(s1[i] != s1[j]) //Not a palindrome
            return 0;
    return 1;
}

//Check whether substring, if yes return count of substring else return 0
int substring(char source[], char subpart[])
{
    int i=0, j=0, count=0;
    //Navigate until end of the source string
    while(source[i] != NULL)
    {
        if(source[i] == subpart[j])
        {
            //While the characters match keep on checking until we reach NULL
            while((source[i] == subpart[j]) && (source[i] != NULL))
            {
                i++;
                j++;
            }
        }
        else
            i++; //If characters don't match, go to the next character in source

        if(subpart[j] == NULL) //Reached end of subpart, hence subpart found in source
        {
            count++; //Substring found, increase count
            //  i++; //Go to the next character of the source
        }
        j=0; //Start checking for another instance of subpart
    }
    return count;
}
