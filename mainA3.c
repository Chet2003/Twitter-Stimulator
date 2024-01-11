#include "headerA3.h" //Includes the header file

int main ()
{
    /*Declaration and initalization of userInput, userInput is an integer variable that stores the menu option selected by the user */
    int userInput;    
    userInput = 0;

    /*Declaration and intialization of tweetList and head. tweetList is a double tweet pointer that points to the head node, which is 
      initalized to the memory address of head. head is a single tweet pointer that points to the head node, which is initalized to NULL.  */
    tweet ** tweetList;
    tweet * head;
    
    head = NULL;
    tweetList = &head;

    /*Declaration and initialization of newTweet, newTweet is a pointer that stores the node produced by createTweets */
    tweet * newTweet;

    /*Declaration and initialization of matchIndicator. matchIndicator is an integer variable that store output produced by 
      searchTweetsByKeyword, which indicates if a match was found*/
    int matchIndicator;
    matchIndicator = 0;

    /*Prints the menu options with the corresponding numeric option*/
    printf ("1. Create a new tweet\n");
    printf ("2. Display tweets\n"); 
    printf ("3. Search a tweet (by keyword)\n");
    printf ("4. Find how many words are “stop words”\n");
    printf ("5. Delete the nth tweet\n");
    printf ("6. Save tweets to a file\n");
    printf ("7. Load tweets from a file\n");
    printf ("8. Sort the given linked list on userid\n"); 
    printf ("9. Exit\n");

    /*Prompts and scans an integer from the user that represents the menu option that they selected */
    printf ("Choose a menu option: ");
    scanf ("%d", &userInput);
    getchar ();

    /*if - statement: Determines if the input is invalid, lower than or equal to zero or larger than 9. If true, indicates to the user
                      that the valid is invalid and prompts for valid input. The function will keep prompting the user for valid input 
                      until valid input is provided through a do - while loop*/
    if (userInput <= 0 || userInput > 9)
    {   
        do
        {
	    printf("Invalid input. Choose a valid menu option: ");
            scanf ("%d", &userInput);
            getchar ();
        }
        while (userInput <= 0 || userInput > 9);
    }
    
    /*while - loop: Determines if the userInput is valid. If valid, executes switch statement that executes the menu options, prompts and collects
                    the user's input for the following menu option*/
    while (userInput > 0 && userInput < 9)
    {   
        /*switch - statement: Based on the value of userInput, executes the particular actions described by the menu*/
        switch (userInput)
        {
            /*Case 1: Represents menu option 1, which creates a new tweet and adds the tweet to the current linked list. Menu option is 
                      accomplished through assigning the value of createTweet to newTweet. Using newTweet, adds the node to the current linked lis
                      through addNodeToList*/
	    case 1:
                newTweet = createTweet (*(tweetList));
                addNodeToList(tweetList, newTweet);
	        break;

            /*Case 2: Represents menu option 2, which displays all of the tweets in the current linked list through the function call of 
                      display tweets */
            case 2:
                displayTweets (*(tweetList)); 
                break;

            /*Case 3: Represents menu option 3, which  updates matchIndicator through the return value of the function call of 
                      searchTweetsByKeyword that indicates if a match was found.*/
            case 3:
                matchIndicator = searchTweetsByKeyword (*(tweetList));
	        if (matchIndicator == 0)
                {
		    printf ("No tweets matched that search\n");
                }
                break;

            /*Case 4: Represents menu option 4, which indicates the number of stop words found throughout the linked list of tweets using 
                      a function call of countStopWords*/
            case 4: 
                countStopWords (*(tweetList));
                break;

            /*Case 5: Represents menu option 5, which deletes a tweet from current linked list through the function call of deleteTweet*/
            case 5:
                deleteTweet (tweetList); 
                break;

            /*Case 6: Represents menu option 6, which saves tweets in the current linked list to a file through the function call of 
                      saveTweetsToFile*/
            case 6:
                saveTweetsToFile (*(tweetList)); 
                break;

            /*Case 7: Represents menu option 7, which adds tweets to the current linked list through the function call of loadTweetsFromFile */
            case 7:
                loadTweetsFromFile (tweetList); 
                break;

            /*Case 8: Represents menu option 8, which sorts the tweets in ascending order through the function call of sortID */
            case 8: 
                sortID (tweetList);
                break;
	}
       
        /*Prints the menu options with the corresponding numeric option*/
        printf ("1. Create a new tweet\n");
        printf ("2. Display tweets\n"); 
        printf ("3. Search a tweet (by keyword)\n");
        printf ("4. Find how many words are “stop words”\n");
        printf ("5. Delete the nth tweet\n");
        printf ("6. Save tweets to a file\n");
        printf ("7. Load tweets from a file\n");
        printf ("8. Sort the given linked list on userid\n"); 
        printf ("9. Exit\n");

        /*Prompts and scans an integer from the user that represents the menu option that they selected */
        printf ("Choose a menu option: ");
        scanf ("%d", &userInput);
	getchar ();

        /*if - statement: Determines if the input is invalid, lower than or equal to zero or larger than 9. If true, indicates to the user
                          that the valid is invalid and prompts for valid input. The function will keep prompting the user for valid input 
                          until valid input is provided through a do - while loop*/
        if (userInput <= 0 || userInput > 9)
        {   
            do
            {
                printf("Invalid input. Choose a valid menu option: ");
                scanf ("%d", &userInput);
                getchar ();
            }
            while (userInput <= 0 || userInput > 9);
        }
    }
    
    /*Declaration and initialization of temp. temp is a tweet pointer that stores the current head of linked list*/
    tweet * temp; 
    temp = head; 

    /*while - loop: Determines if temp is not equal to NULL. If true, head is changed to the address stored at head -> next and temp is freed.
                    temp is updated to equal head. The loop frees the nodes of the linked list*/
    while (temp != NULL) 
    {
        head = head -> next;
        free (temp);
        temp = head;
    }

    /*Frees the temp and head pointers*/
    free (temp);
    free (head);
    
    return 0;
}
