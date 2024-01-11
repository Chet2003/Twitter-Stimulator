#include "headerA3.h" //Includes the header file

/*
    displayTweets: Displays all of the tweets currently in the memory
    In: tweet * tweetList
    Out: None 
    Post: Outputs of the tweets in the current linked list (including the id, user and text)
*/
void displayTweets(tweet * tweetList)
{
    /*Declaration and initalization of temp. temp is a tweet pointer that points to the address pointed to by 
     tweetList */
    tweet * temp;
    temp = tweetList;

    /*while - loop: Determines if temp is not equal to NULL. Accesses the nodes of the linked list*/
    while (temp != NULL)
    {
        /*Prints the id, user and text of the current node*/
        printf ("%d: Created by %s: %s\n", temp->id, temp->user, temp->text);
    
        /*Updates temp to point to the next node in the linked list through the address stored in temp -> next */
        temp = temp -> next;
    }
}
