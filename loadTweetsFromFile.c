#include "headerA3.h" //Includes the header file

/*
    loadTweetsFromFIle: Using a file name provided by the user, stores the tweets located in the file in the current linked list
    In: tweet ** tweetList 
    Out: None 
    Post: Stores tweets from the file in the linked list and indicates whether the process was succesdful or unsuccessful
*/

void loadTweetsFromFile (tweet ** tweetList)
{
    /*Declaration of a file pointer named filePointer*/
    FILE * filePointer;    

    /*Declaraton and initialization of temp. temp is a tweet pointer that is initially assigned to the head node of the linked list or the node
      pointed to by tweetList*/
    tweet * temp;
    temp = *(tweetList);

    /*Declaration and initialization of numChars. numChars is an integer variables that  stores the number of characters in fileName*/
    int numChars;
    numChars = 0; 

    /*Declaration and initialization of fileName. fileName is a char pointer that will store the name of the filePointer. Initially, given the 
      memory space of the size for 1 character*/
    char * fileName;
    fileName = malloc (sizeof(char) * numChars + 1);

    /*Prompts and collects a file name from the user to load the tweets from*/
    printf ("Enter a filename to load from: ");
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

    /*Assigns the pointer produced by fopen when opening the file for reading*/
    filePointer = fopen (fileName, "r");

    /*if - statement: Determines if filePointer is NULL, which implies that filePointer did not open and indicates an error had occurred and 
                      returns to the main menu*/
    if (filePointer == NULL)
    {
        printf ("Tweets failed to be imported!\n");
	return; 
    }

    /*If - statement: Determines if temp is equal to NULL. If false, it implies that the file opened successfully. */
    if (temp != NULL)
    {
        /*while - loop: Assigns temp to the last node*/
        while (temp -> next != NULL)
        {
	    temp = temp -> next;
        }
    }

    /*while - loop: Determines if the end of file has been reached. If false, add nodes to the existing list*/
    while (!feof (filePointer))
    {
       /*if - statement: Determines if temp is equal to NULL. If temp is equal to NULL, adds tweets as the head node. If temp is not equal to NULL, 
                         adds tweets to the end of the linked list*/
       if (temp == NULL)
       {
           /*Declaration of headNode. headNode stores values of the initial node in the linked list*/
           tweet * headNode;
           headNode = malloc (sizeof (tweet));

           /*Scans id and user from the file through fscanf*/
           fscanf (filePointer, "%d,%[^,],", &(headNode -> id), headNode -> user);

           /*Scans text from the file through fgets*/
           fgets (headNode -> text, 141, filePointer);

           /*Assigns the last character in the text of headNode to a null character to end the text*/
           if (headNode -> text [strlen (headNode -> text) - 1] == '\n')
           {
               headNode -> text [strlen (headNode -> text) - 1] = '\0';
	   }

           /*Assigns headNode -> next to point to NULL*/
	   headNode -> next = NULL;

           /*Assigns tweetList to point to headNode and temp to headNode*/
           addNodeToList (tweetList, headNode);
           temp = headNode;
        }
        else 
        {
           /*If temp is not equal to NULL, it implies that the linked list is not empty. Declaration of node. node is a tweet 
             pointer that stores the values of the current node being read from a file*/
	   tweet * node; 
           node = malloc (sizeof (tweet));

           /*Scans id and user from the file through fscanf*/
	   fscanf (filePointer, "%d,%[^,],", &(node -> id), node -> user);

           /*Scans text from the file through fgets*/
           fgets (node -> text, 141, filePointer);

           /*Assigns the last character in the text of headNode to a null character to end the text*/
           if (node -> text [strlen (node -> text) - 1] == '\n' || node -> text [strlen (node -> text) - 1] == ',')
           {
               node -> text [strlen (node -> text) - 1] = '\0';
           }
	
           /*Assigns headNode -> next to point to NULL*/
           node -> next = NULL; 

           /*Assigns temp to point to node*/
           addNodeToList (tweetList, node);

           /*Assigns node to the next node in the linked list*/
	   temp = temp -> next;
	}
    }
   
    /*Outputs a message implying that importing the tweets was successful*/
    printf ("Tweets imported!\n");    

    /*Closes the file pointer*/
    fclose (filePointer);

    /*Frees the fileName*/
    free (fileName);
}
