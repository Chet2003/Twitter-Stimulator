#include "headerA3.h" //Includes the header file

/*
    deleteTweet: Deletes a tweet from the linked list
    In: tweet ** tweetList
    Out: None
    Post: Removes a node frmm tweetList, prints a statement that indicates the id of the tweet that was deleted and number of the tweets remaining 
*/
void deleteTweet (tweet ** tweetList)
{

    /*Declaration and initialization of temp. temp is a tweet pointer that stores the memory address pointed to by the node that the tweetList points to */
    tweet * temp;
    temp = *(tweetList);

    /*Declaration and initialization of numOfTweets. numOfTweets is an integer variable that stores the number of tweets present in the current linked list */
    int numOfTweets;
    numOfTweets = 0;

    /*Declaration and initialization of deletedTweet. deletedTweet is an integer variable that stores the number of the tweet that the user wants to be delete*/
    int deletedTweet;
    deletedTweet = 0;

    /*Declaration and intialization of id, id is an integer variable that stores the id of the deleted tweet*/
    int id;
    id = 0;

    /*while - loop: Determines if temp is equal to NULL, implying that the end of the linked list has been reached. If false, increases the value of 
                    numOfTweet by 1 and assigns temp to point to the next node in the linked list through the use of temp -> next. Determines the 
                    number of tweets located in the current linked list*/
    while (temp != NULL)
    {
        numOfTweets += 1;
	temp = temp -> next;
    }

    /*Reassigns temp to the head node*/
    temp = *(tweetList);

    /*if - statement: Determines the number of tweets located in the linked list. If larger than 0, the user will be able to delete a tweet, otherwise,
                      the user will unable to.*/
    if (numOfTweets == 0)
    {
        /*Prints a statement implying that there is currently zero tweets in the linked list*/
	printf("Currently there are %d tweets\n", numOfTweets);
    }
    else if (numOfTweets == 1)
    {
        /*There is only one tweet in the linked list, which is indicated by the user*/
	printf ("Currently there is %d tweet\n", numOfTweets);

        /*Prompts and collects the number of the tweet they would like to deleted, which can only be only */
        printf ("Which tweet do you wish to delete - enter a value between 1 and %d: ", numOfTweets);
        scanf ("%d", &deletedTweet);
        getchar ();

        /*while - loop: Utilized to validate the input*/ 
        while (deletedTweet != 1)
        {
	    printf ("Invalid input. Choose a valid tweet to delete: ");
            scanf ("%d", &deletedTweet);
            getchar ();
        }

        /*Reassigns temp to the head node*/ 
        temp = *(tweetList);

        /*Stores the id of the deleted tweet in id*/
        id = temp -> id;

        /*Reassigns the head node of the linked list to NULL*/
        *(tweetList) = NULL;

        /*Decreases the number of tweets by 1*/
	numOfTweets -= 1;
        
        /*Frees temp, which frees the memory attached to the initial node in the list*/
        free (temp);

        /*Prints a statement that indicate the tweet deleted by its id and the number of tweet remaining */
	printf("Tweet %d deleted. There are %d tweets left\n", id, numOfTweets);
    }
    else 
    {
        /*If the number of tweets inside of the node is larger than 1, then the user is informed about the number of tweets through a print statement*/
	printf ("Currently there are %d tweets\n", numOfTweets);

        /*Prompts and collects an integer from the user presenting the number of the tweet they would like to deleted*/
        printf ("Which tweet do you wish to delete - enter a value between 1 and %d: ", numOfTweets);
        scanf ("%d", &deletedTweet);
	getchar ();

        /*while - loop: Validates that the inputted value is between 1 and the number of tweets*/
        while (deletedTweet < 1 || deletedTweet > numOfTweets)
        {
            printf ("Invalid input. Choose a valid tweet to delete: ");
            scanf ("%d", &deletedTweet);
	    getchar ();
        }

        /*if statement: Determines the number of the desired tweet to be deleted.*/
        if (deletedTweet == 1)
        {
            /*If the value of deletedTweet is 1, temp is assigned to the head of the linked list. The id of the head node is stored in id*/
	    temp = *(tweetList);
            id = temp -> id;
  
            /*The head node is reassigned to the second node in the initial list, which represent the new head node*/
            *(tweetList) = (*(tweetList))-> next;

            /*Temp is freed, which frees the memory allocated to the tweet removed from the linked list*/
            free (temp);

            /*Decreases the numOfTweets by 1*/
	    numOfTweets -= 1;

            /*Prints a statement that indicate the tweet deleted by its id and the number of tweet remaining*/
            if (numOfTweets == 1)
            {    
                printf("Tweet %d deleted. There is %d tweet left\n", id, numOfTweets);
            }
            else 
            {
		printf("Tweet %d deleted. There are %d tweets left\n", id, numOfTweets);
            }
        }
        else if (deletedTweet == numOfTweets)
        {
            /* If deletedTweet is equal to numOfTweets, it implies that the last node in the linked list is being deleted*/
            /*Declaration of lastNode. lastNode is a tweet pointer that stores the lastNode or the node being deleted */
            tweet * lastNode;
	    
            int i; //Declaration of for - loop counter

            /*for - loop: Assigns temp to the second last node in the linked list*/
	    for (i = 1; i < numOfTweets - 1; i++)
            {
		temp = temp -> next;	
            }

            /*Assigns the node pointed to by temp to  lastNode, which represents the last node in the initial list*/
	    lastNode = temp -> next;

            /*Stores the id of the last node of the linked list in id*/
            id = temp -> next -> id;

            /*Assigns the second last node to point to NULL, which will allow for the node to become the last node in the list*/
            temp -> next = NULL;

            /*Frees the lastNode, which frees the memory assigned to the last node in the initial linked list*/
            free (lastNode);
	    
            /*Decreases the number of tweets by 1*/
	    numOfTweets -= 1;

            /*Prints a statement that indicate the tweet deleted by its id and the number of tweet remaining*/ 
	    if (numOfTweets == 1)
            {    
                printf("Tweet %d deleted. There is %d tweet left\n", id, numOfTweets);
            }
            else 
            {
                printf("Tweet %d deleted. There are %d tweets left\n", id, numOfTweets);
            }

        }
        else 
        {
            /*Declaration of node. node is a tweet pointer that holds the memory address of the tweet being deleted*/
	    tweet * node;

            int i;//Declaration of for - loop counter

            /*for - loop: Assigns temp to the node prior to the desired node to be deleted in the linked list*/
            for (i = 1; i < deletedTweet - 1; i++)
            {
                temp = temp -> next;    
            }

            /*Assigns node to point to the desired deleted node*/
            node = temp -> next;

            /*Stores the id of the deleted node in id*/
            id = temp -> next -> id;

            /*Assigns the node prior to the node being deleted to point to the node following the deleted node to maintain the list*/
            temp -> next = node -> next;

            /*Frees node, which frees the memory space assigned to the deleted node*/
            free (node);

            /*Decreases the number of tweets by 1*/
            numOfTweets -= 1;
	
	    /*Prints a statement that indicate the tweet deleted by its id and the number of tweet remaining*/
            if (numOfTweets == 1)
            {    
                printf("Tweet %d deleted. There is %d tweet left\n", id, numOfTweets);
            }
            else 
            {
                printf("Tweet %d deleted. There are %d tweets left\n", id, numOfTweets);
            }
        }
    }
}
