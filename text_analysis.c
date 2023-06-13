#include<stdio.h>

/* Function to count the number of words in the the text */

int word_count(char *text)
{
    int count=0,i=0,is_word=0;
    while (text[i] != '\0')
    {
        if(text[i] == ' ' || text[i] == '\n' || text[i] == '\t') // Check if the current character is a space, newline, or tab
        {
            is_word = 0;
        }else if(is_word == 0)
        {
            is_word = 1;
            count++; //Increase word count
        }
        i++; //Move to next character in the text
    }
    return count;
}

/* Function to count the number of lines in the text*/

int line_count(char *text)
{
    int count=0, i=0;
    while (text[i]!='\0')
    {
        if(text[i]=='\n')  // Check if the current character is a newline
        {
            count++;  // Increment line count
        }
        i++;   // Move to the next character in the text
    }

    return count;
}

/* Function to count the number of characters in the text */

int char_count(char *text)
{
    int count=0,i=0;
    while (text[i] != '\0')
    {
        if (text[i] != '\n' && text[i] != '\r')
        {
            count++;// Increment character count
        }
        i++;  // Move to the next character in the text
    }
    return count;
}

int main()
{
    char text[1000]; // Initialize array for the text
    char inputline[1000];
    char endchar='$';
    printf("Enter text (end with '%c' character):\n", endchar);
    /* Read lines of input until the end character is encountered */
    while (fgets(inputline, sizeof(inputline), stdin))
    {
        if (inputline[0] == endchar)
        {
            break;  // Exit the loop if the end character is entered
        }
        strcat(text, inputline);    // Concatenate the input line to the existing text
    }
    /* Call the counting functions and store the results */
    int wordcount= word_count(text);
    int linecount= line_count(text);
    int charcount= char_count(text);
    /* Print Result */
    printf("\nAnalysis Results:\n");
    printf("Number of words: %d\n", wordcount);
    printf("Number of lines: %d\n", linecount);
    printf("Number of characters(Excluding $ and lines as character): %d\n", charcount-2);
    return 0;
}
