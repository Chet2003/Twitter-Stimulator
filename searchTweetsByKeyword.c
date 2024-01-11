#include "headerA3.h" //Includes the header file
#include <ctype.h> //Includes the character library

/*
    searchTweetByKeyword: Collects a keyword from the user and locates tweets within the linked list that contains the keyword
    In: tweet * tweetList
    Out: An integer indicating whether a tweet with the keyword is located (0, - not located, 1 - located)
    Post: Prints the tweets containing the keyword and returns an integer indicating whether the search was successful or not
*/
int searchTweetsByKeyword (tweet * tweetList)
{
    /*Declaration and initialization of head. head is a tweet pointer that stores the address pointed to by tweetList */
    tweet * head;
    head = tweetList;

    /*Stores the number of characters in keyword*/
    int numChars;
    numChars = 0;

    /*Declaration and initalization of keyword and tweet. keyword is a char pointer that stores keyword inputted by the user. tweet
     is a string that temporarily stores the current tweet being searched */
    char * keyword ;
    keyword = malloc (sizeof(char) * numChars + 1);
    
    char tweet [141];

    /*Initialization and declaration of matchIndicator. matchIndicator is an integer that indicate whether the search was 
      successful or unsuccessful*/
    int matchIndicator;
    matchIndicator = 0;

    /*Prompts and scans a keyword fron the user, which is stored in keyword*/
    printf ("Enter a keyword to search: ");

    scanf ("%c", &(keyword[numChars]));

    /*Scans input until a newline character is encountered. If a newline character is encountered, it reassigns the character to a null character 
      representing the end of the line*/
    while (keyword [numChars] != '\n')
    {
        numChars += 1;

        keyword = realloc (keyword, sizeof (char) * numChars + 1);

        scanf ("%c", &(keyword[numChars]));
    }

    keyword [numChars] = '\0';

    int i; //Declaration of the for - loop counter

    /*for - loop accesses the characters of keyword*/ 
    for ( i = 0; i < strlen (keyword); i++)
    {
        /*Sets the character located at index i in keyword to lowercase */
	keyword [i] = tolower(keyword[i]);
    }

    /*while - loop: Accesses the nodes in the linked list by determining if head is not equal to NULL implying.the end of the linked list was 
                    not accessed. If true, executes the body of the loop.*/
    while (head != NULL)
    {
        /*Copies the text held at the current node to tweet*/
        strcpy (tweet, head -> text);
        tweet [strlen (head -> text)] = '\0';

        /*Declaration and initialization of matchTweet. matchTweet is a integer variable that indicates whether a match was found in 
          the current node*/
        int matchTweet;
        matchTweet = 0; 

        int j; //Declaration of for - loop

        /*for - loop: Accesses the characters of tweet*/
        for ( j = 0; j < strlen (tweet); j++)
        {
            /*Sets the character located at index j in tweet to lowercase */
            tweet[j] = tolower(tweet[j]);
        } 
        
        int k; //Declaration of for - loop counter

        /*if - statement: Determines if the length of tweet and keyword are equal. If true, tweet is compared with keyword through 
                          strcmp. If false, compares keyword to all of the segements of tweet that are same length as keyword  */
        if (strlen (tweet) == strlen (keyword))
        {
            /*if - statments: Determines if tweet and keyword are equal through strcmp. If true, updates matchTweet to 1, indicating
                              a match was found*/
	    if (strcmp (tweet, keyword) == 0)
            {
                matchTweet = 1;
            }
        }
        else if (strlen (tweet) > strlen(keyword))  
        {
            /*for - loop: Accesses the characters of tweet */
            for (k = 0; k <= strlen (tweet) - strlen(keyword); k++)
            {
                /*Declaration of tempWord. tempWord is a string of the length of keyword, which stores
                  the word produced by the tweets starting at each character */
                char tempWord [strlen (keyword)];

                /*Declaration of charIndex. charIndex stores the index accessing characters of tempWord */
                int charIndex;
                charIndex = 0;          

                int l; //Declaration of for - loop counter
 
                /*for - loop: Accesses the characters of tweet */
                for (l = k; l < k + strlen (keyword); l++)
                {
		   /*Assigns the character located at index l of tweet to the character of tempWord located at charIndex*/
                   tempWord [charIndex] = tweet[l];
                   /*Increments charIndex*/
                   charIndex++; 
                }
           
                /*if - statments: Determines if tweet and keyword are equal through strcmp. If true, updates matchTweet to 1, indicating
                              a match was found*/
                if (strcmp (keyword, tempWord) == 0)
                {
                    matchTweet = 1;
                }          
            } 
        }

        /*if - statement: Determines if matchTweet is equal to 1, implying that a match was found. If true, matchIndicator is updated and 
                          and the tweet is printed*/
        if (matchTweet == 1)
        {
            printf ("Match found for '%s': %s wrote: \"%s\"\n", keyword, head->user, head->text);
	    matchIndicator = 1;
        }

        /*Assigns head to point to the next node in the linked list through the address held by head -> next */
        head = head -> next;
    }

    free (keyword);

    /*Returns an integer indicating whether a match was found through the use of matchIndicator*/
    return matchIndicator;
}

