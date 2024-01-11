#include "headerA3.h" //Includes the header file

/*
    sortID: Sorts the tweets in the linked list in ascending order based on the id 
    In: tweet ** head
    Out: None 
    Post: Reorders the tweets in ascending order based on the id 
*/
void sortID (tweet ** head)
{
    /*Declaration and initialization of temp. temp is a tweet pointer that points to the memory space of the node pointed to by head*/
    tweet * temp;
    temp = *(head);

    /*Declaration and initialization of current and after. current is a tweet pointer that points to memory space of the current node 
      of focus. after is a tweet pointer that points to the memory space of the next node in the list */
    tweet * current;
    tweet * after;

    current = NULL; 
    after = NULL;

    /*Declaration and initialization of numTweets. numTweets is an integer variable that stores number of tweets in the linked list*/
    int numTweets;
    numTweets = 0;

    /*while - loop: Determines if temp is equal to NULL. If false, increases the numTweets by 1 and assign temp to the next node*/
    while (temp != NULL)
    {
	numTweets += 1;
	temp = temp -> next;
    }

    /*Reassigns temp to the memory space pointed to by the node that head points to*/
    temp = *(head);
   
    int i; //Declaration of for - loop counter

    /*for - loop: Accesses the different node of the linked list using the bubble sort method. In each iteration of the outer 
                  for - loop, sorts the largest unsorted node to its sorted position*/
    for (i = 0; i < numTweets - 1; i++)
    {
        /*Reassigns temp to the memory space pointed to by the node that head points to*/
        temp = *(head);

	int j; //Declaration of inner for - loop counter

        /*for - loop: Accesses the different node of the linked list and does not visit nodes that are sorted*/
	for (j = 0; j < numTweets - i - 1; j++)
        {
            /*if - statement: Determines if temp and temp -> next is NULL, which if true, implies that the either node represents in the 
                              end of the list*/
	    if (temp != NULL && temp -> next != NULL)
            {
                /*current is assigned to temp. after is assigned to temp -> next */
	        current = temp;
	        after = temp -> next;

               /*if statement: Determines if the id stored in the current node  is larger than the id stored in the  after node. If true, 
                               switches the values held by the nodes*/
                if (current -> id > after -> id)
                {
                    /*Declaration and initialization of node. node is a tweet pointer that stores the values held at the current node*/
                    tweet * node;
		    node = malloc (sizeof (tweet));

		    node -> id = current -> id;
		    strcpy (node -> user, current -> user);
		    strcpy (node -> text, current -> text);

                    /*Reassigns the values held at the current node to the values of the after node*/		
		    current -> id = after -> id;
		    strcpy (current -> user, after -> user);
		    strcpy (current -> text, after -> text);
		
                    /*Reassigns the values held at the current node to the values of the node (the initial values held at the current node)*/
		    after -> id = node -> id;
		    strcpy (after -> user, node -> user);
		    strcpy (after -> text, node -> text);
		 
		    /*Frees the memory spaces assigned to node*/ 
		    free (node);
                 }
            /*Assigns temp to the next node in the linked list */
            temp = temp -> next;
	    }
           
	}
    }
}
