#include "headerA3.h" //Includes header file

/*
    saveTweetsToFile: Saves the tweets in the current linked list to a file provided by the user
    In: tweet * tweetList
    Out: None 
    Post: Stores the values held by the nodes in a file
*/
void saveTweetsToFile (tweet * tweetList)
{
    /*Declaration of a file pointer named filePointer*/
    FILE* filePointer;
    filePointer = NULL;

    /*Declaration and initialization of temp. temp is a tweet pointer that initially points to the memory address shared by the head node*/
    tweet * temp;
    temp = tweetList;    

    /*Declaration and initialization of numChars. numChars is an integer variables that  stores the number of characters in fileName*/
    int numChars;
    numChars = 0; 

    /*Declaration and initialization of fileName. fileName is a char pointer that will store the name of the filePointer. Initially, given the 
      memory space of the size for 1 character*/
    char * fileName;
    fileName = malloc (sizeof(char) * numChars + 1);

    /*Prompts and collects input from the user*/
    printf ("Enter the filename where you would like to store your tweet: ");
    scanf ("%c", &(fileName [numChars]));

    /*Scans input until a newline character is encountered. If a newline character is encountered, it reassigns the character to a null character 
    representing the end of the line*/
    while (fileName [numChars] != '\n')
    {
        /*Increases the numChars by 1, realloc fileName to provide more space for an additional character, and scans a character, which is assigned
          to the character located at the numChars index of keyword*/
        numChars += 1;

        fileName = realloc (fileName, sizeof (char) * numChars + 1);

        scanf ("%c", &(fileName[numChars]));
    }

    /*Reassigns the final character to a null character, which indicates the end of the string or fileName*/
    fileName [numChars] = '\0';

    /*Opens the file indicated by fileName for writing and assign the pointer to filePointer */
    filePointer = fopen (fileName, "w"); 

    /*if - statement: Determines if the filePointer is NULL, which implies that the file did not open. If false, it implies that the file was opened 
                      and available for scanning.*/
    if (filePointer != NULL)
    {
        /*while - loop: Determines if the temp pointer is NULL, implying that the end of the linked list has been reached. If false, it implies that 
                        the end has not been reached.*/
        while (temp != NULL)
        {
	    /*Writes the id, user and text stored at the node pointed to by temp in the file. Updates temp to the next node through temp -> next*/
	    fprintf (filePointer, "%d,%s,%s\n", temp -> id, temp -> user, temp -> text);
            temp = temp -> next;
        }

        /*Prints an output that indicates that the output was successful */
	printf ("Output successful!\n");
    }

    /*Closes the file pointer and frees fileName */
    fclose (filePointer);
    free (fileName);
}
