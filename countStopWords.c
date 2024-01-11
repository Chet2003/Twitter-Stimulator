#include "headerA3.h" //Includes the header file

/*
    countStopWords: Determines the number of stop words found in tweets from the current linked list
    In: tweet * tweetList
    Out: None
    Post: Prints a statements indicating the number of stop tweets found  and the number of tweets present
*/
void countStopWords (tweet * tweetList)
{
    /*Declaration and initialization of countStopWords. countStopWords is an integer variable that stores the number of stop words present in the 
      linked list */
    int countStopWords; 
    countStopWords = 0;

    /*Declaration and initialization of numTweets. numTweets is an integer variable that stores the number of tweets in the linked list */
    int numTweets;
    numTweets = 0;

    /*Declaration and initialization of temp. temp is a tweet pointer that points to the head of the linked list*/
    tweet * temp;
    temp = tweetList;

    /*Declaration of tweet. tweet is a string that stores the current tweet that is being checked*/
    char tweet [141];
    
    /*Declaration of word. word is char pointer that stores the tokens produced by strtok representing the different words in a sentence */
    char * word;

    /*Declaration  and initialization of stopWords. stopWords is a 2 dimensional string array that stores 25 stop words*/
    char stopWords [25][4] = {"a","an","and","are","as","at","be","by","for","from","has","he","in","is","it","its","of","on","that","the","to","was","were","will","with"};

    /*while - loop: Accesses the nodes of the list through determining if the temp pointer is NULL, which indicates the end of the list has been accessed. If false, the body of the loop 
                    executes. */
    while (temp != NULL)
    {
        /*Increments numTweets by 1 to represent the node in the list*/
        numTweets += 1;

        /*Assigns the text stored at the memory address of temp to tweet*/
        strcpy (tweet, temp -> text);

        /*if - statement: Detemines if the text held at temp is not NULL or has a length of 0. If true, the string is searched for stop words */
        if (temp -> text != NULL && strlen(temp -> text) != 0)
        {
            /*Assigns the first token of tweet to word*/
            word = strtok (tweet, " ");
      
            int i; //Declaration of for - loop counter

            /*for - loop: Accesses the elements of stopWords*/
            for (i = 0; i < 25; i++)
            {
                /*if - statement: Determines if the stop word located at index i of stopWords is equal to word. If true, the 
                                  count of stopwords is increased by 1.*/
	        if (strcmp (stopWords [i], word) == 0)
                {
		    countStopWords += 1;
                }
            }
        
            /*while - loop: Determines if word is equal to NULL, implying that the end of the tweet has been reached. If false, 
                            the tweet will be further searched*/
            while (word != NULL)
            { 
                /*Assigns the following token or word from tweet to word*/
	        word = strtok (NULL, " ");

                /*if - statement: Determines if word is equal to NULL, implying that the end of the tweet has been reached. If false, compares
                                  word with the elements of stopWords*/
                if (word != NULL)
                {
                    
                    int j; //Declaration and initialization of for - loop counter

                    /*for - loop: Accesses the elements of stopWords*/
                    for (j = 0; j < 25; j++)
                    {
	                /*if - statement: Determines if the stop word located at index i of stopWords is equal to word. If true, the 
                                          count of stopwords is increased by 1.*/
                        if (strcmp (stopWords [j], word) == 0)
                        {
		            countStopWords += 1;
                        }
                    } 
                }
	    }
        } 

        /*Assigns temp to point to the next node in the linked list through temp -> next*/      
        temp = temp -> next;
    }

    /*Prints a statement that indicates the number of tweets present and the number of stop words that were found*/
    printf ("Across %d tweets, %d stop words were found.\n", numTweets, countStopWords); 
}
