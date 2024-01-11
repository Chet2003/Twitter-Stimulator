#include "headerA3.h" //Includes the header file

/*
    createTweet: Creates a tweet struct or node and returns the struct that does not obtain an id already present in the linked list 
    In: tweet * tweetList
    Out: A tweet struct containing an id, user, and text
    Post: Produces a tweet struct  that contains an unique id 
*/
tweet * createTweet (tweet * tweetList)
{
    /*Declaration and initialization of newTweet. newTweet is a tweet struct that stores the values of tweet being composed*/
    tweet * newTweet;
    newTweet = malloc (sizeof (tweet));

    /*Declaration and initialization of sumUsername. sumUsername is an integer that stores the sum of the ASCII values of the 
      characters of the username*/
    int sumUsername;
    sumUsername = 0;

    /*Declaration and initialization of lengthOfTweet. lengthOfTweet is an integer that the length of the tweet */
    int lengthOfTweet; 
    lengthOfTweet = 0;    

    /*Declaration and initialization of id. id is an integer that stores the id of the tweet*/
    int id;
    id = 0;

    /*Declaration and initialization of username. username is a string that dynamically stores the username*/
    char * username; 
    username = malloc (sizeof(char) * 1);

    /*Declaration and initialization of text. text is a string that dynamically stores the text*/
    char * text;
    text = malloc (sizeof (char) * 1);

    /*Declaration and initialization of userChars. userChars stores the number of characters in username*/
    int userChars;
    userChars = 0;

    /*Declaration and initialization of numChars. numChars stores the number of character in text */
    int numChars;
    numChars = 0;

    /*do - while loop: Verfies that the username is a non - zero length string and not larger than 51 characters*/
    do 
    {
        /*Declaration and initialization of userChars. userChars stores the number of characters in userChars*/
        userChars = 0;

        /*Prompts and collects input from the user*/
        printf ("Enter a username: ");
        scanf ("%c", &(username [userChars]));

        /*Scans input until a newline character is encountered. If a newline character is encountered, it reassigns the character to a null character 
        representing the end of the line*/
        while (username [userChars] != '\n')
        {
            /*Increases the numChars by 1, realloc fileName to provide more space for an additional character, and scans a character, which is assigned
            to the character located at the userChars index of keyword*/
            userChars += 1;

            username = realloc (username, sizeof (char) * userChars + 1);

            scanf ("%c", &(username[userChars]));
        }

        /*Reassigns the final character to a null character, which indicates the end of the string or username*/
        username [userChars] = '\0';
    }
    while (userChars <= 0 || userChars > 51);  

    

    /*do - while loop: Verfies that the text is a non - zero length string and not larger than 141 characters*/
    do 
    {
        numChars = 0;

        /*Prompts and collects input from the user*/
        printf ("Enter the user's tweet: ");
        scanf ("%c", &(text [numChars]));

        /*Scans input until a newline character is encountered. If a newline character is encountered, it reassigns the character to a null character 
        representing the end of the line*/
        while (text [numChars] != '\n')
        {
            /*Increases the numChars by 1, realloc fileName to provide more space for an additional character, and scans a character, which is assigned
            to the character located at the numChars index of keyword*/
            numChars += 1;

            text = realloc (text, sizeof (char) * numChars + 1);

            scanf ("%c", &(text[numChars]));
        }

        /*Reassigns the final character to a null character, which indicates the end of the string or text*/
        text [numChars] = '\0';
    }
    while (numChars <= 0 || numChars > 141);  

    /*Assigns username to newTweet -> user. Assigns text to newTweet -> text. Assigns newTweet -> next to NULL.*/
    strcpy (newTweet -> user, username);
    strcpy (newTweet -> text, text);
    newTweet-> next = NULL; 

    /*Assigns the length of newTweet -> text to lengthOfTweet */
    lengthOfTweet = strlen (newTweet->text);

    int i; //Declaration of for - loop counter

    /*for - loop: Accesses the characters of newTweet -> user*/
    for (i = 0; i < strlen (newTweet->user); i++)
    {
        /*Adds the ASCII value of the character located at index i of newTweet-> user to  sumUsername */
	sumUsername += (int) (newTweet->user)[i];
    } 

    /*Assigns the value of sumUsername combined with lengthOfTweet to id*/
    id = sumUsername + lengthOfTweet;

    /*Assigns newTweet -> id to id*/
    newTweet->id = id;

    /*Declaration and initialization of temp. temp is a tweet pointer that pointer to the head node*/
    tweet * temp; 
    temp = tweetList;

    /*if statement: Determines if the temp is equal to NULL, which implies that the end of the list is reached. If false, id will be compared 
                    with the id of every node in the linked list*/
    if (temp != NULL)
    {
        /*do - while loop: Access the nodes of the linked list. Executes if temp does not equal NULL or the end of the linked list has not been reached.*/
        do
        {
            /*if - statement: Determines if the id held at temp->id and newTweet->id are equal. If equal, newTweet->id increased by a 
                              a random value in the range of 1 - 9999 and temp is reassigned to the head node. This will allow for the 
                              new value of id to be compared with the entire linked list to ensure that no id is equal. If not equal, temp 
                              is assigned to the next node in the linked list*/
            if (temp->id == newTweet->id)
            {
                newTweet->id += rand() % 1000;
                temp = tweetList;
            }
            else 
            {    
                temp = temp -> next; 
            }
        }
        while (temp != NULL);
    }   

    /*Prints the id generated for newTweet */
    printf("Your computer-generated userid is %d\n", newTweet->id);

    /*Frees the memory allocated to username and text*/
    free (username);
    free (text);

    /*Returns a tweet struct containing the input values provided by the user through the use of newTweet*/
    return newTweet;
}
