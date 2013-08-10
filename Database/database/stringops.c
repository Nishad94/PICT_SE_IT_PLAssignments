/*
   Program for string manipulations including:
   1. Compare
   2. Copy
   3. Reverse
   4. Palindrome
   5. Substring
*/

#ifndef STRING_OPS
#define STRING_OPS

//String Operations
void make_heading(char s[]);
void read_string(char s1[]);
int strlength(char s[]);
int string_compare(char s1[], char s2[]);
void string_copy(char dest[], char src[]);
void string_reverse(char dest[], char src[]);
int string_palindrome(char s1[]);
int substring(char source[], char subpart[]);

//Interface(Heading)
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

    //Ignore initial \n's in input stream
    while((c = getchar()) == '\n')
        ;
    s1[i++] = c;
    //Copy string untill a newline is encountered
    while((c = getchar()) != '\n')
        s1[i++] = c;
    s1[i] = '\0';
}

//Function to calculate string length
int strlength(char s[])
{
    int i;
    for(i=0; s[i] != '\0'; i++)
    ;
    return i;
}
/*Function to compare 2 strings.
  If s1 > s2 return 1, s1 < s2 return -1.
  If s1 == s2, return 0 */
int string_compare(char s1[], char s2[])
{
    int i = 0;
    while((s1[i] == s2[i]) && (s1[i] != '\0'))
        i++;
    if(s1[i] == '\0')
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
    for(i=0; src[i] != '\0'; i++)
        dest[i] = src[i];
    //Append '\0' at the end:
    dest[i] = '\0';
}

//Function to reverse a string and store it in a new array
void string_reverse(char dest[], char src[])
{
    int i, j;
    for(i=0; src[i] != '\0'; i++)
        ;
    // i is pointing to '\0', so do i--
    i--;
    for(j=0; i >= 0; j++,i--)
        dest[j] = src[i];
    //Append '\0' at the end of dest[]
    dest[j] = '\0';
}

//Function returns 1 if string is a palindrome, else 0
int string_palindrome(char s1[])
{
    int i=0, j;
    //Compute string length
    while(s1[i] != '\0')
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
    while(source[i] != '\0')
    {
        if(source[i] == subpart[j])
        {
            //While the characters match keep on checking until we reach '\0'
            while((source[i] == subpart[j]) && (source[i] != '\0'))
            {
                i++;
                j++;
            }
        }
        else
            i++; //If characters don't match, go to the next character in source

        if(subpart[j] == '\0') //Reached end of subpart, hence subpart found in source
        {
            count++; //Substring found, increase count
            //  i++; //Go to the next character of the source
        }
        j=0; //Start checking for another instance of subpart
    }
    return count;
}

#endif
