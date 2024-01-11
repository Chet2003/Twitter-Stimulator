#include "headerA3.h" //Includes the header file

/*
    addNodeToList: Adds a node to the current linked list 
    In: tweet ** tweetList, tweet * node
    Out: None 
    Post: Adds a node to the current linked list
*/
void addNodeToList (tweet**tweetList, tweet * node)
{
    /*Declaration and initialization of temp. temp is a tweet pointer that points to the head node that is pointed to by tweetList */
    tweet * temp;
    temp = *(tweetList);

    /*if - statement: Determines if temp is equal to NULL, implying that temp is the beginning of the linked list */
    if (temp ==  NULL)
    {
        /*If temp is NULL, then the head node will be assigned node to begin the linked list */
        *(tweetList) = node;
    }
    else 
    {
        /*while - loop: Assigns temp to the last node in the linked list*/
        while (temp -> next != NULL) 
        {
            temp = temp -> next;
        }

        /*Assigns temp -> next to point to node, which will add another link to the linked list */
        temp -> next = node;    
    }   

}
