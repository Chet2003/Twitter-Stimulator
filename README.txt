Student Name: Chetram Sanichar 
Username: csanicha
Student ID: 1183223
Assignment Name: Tweet Manager
Due Date: April 3rd, 2022 
Date of Last Revision: April 3rd, 2022

Compiling the program: 
The program should be complied using a makefile with the flags (-std=c99 -Wall) as follows:
make 

Running the program would be done as follows: 
./sanicharChetramA3

Explanation of Each Completed Component: 
makefile - Complies all of the different source codes using the -std=c99 and -Wall flag to 
           produce a executable, ./sanicharChetramA3 .
headerA3.h - Contains all of the function prototypes, structure definition of tweet, inclusion 
             of the standard input - output library, standard library, string library. 
createTweet.c - A source code that contains the function of createTweet, which produces tweet 
                nodes using user input for the id, user, and text components. 
displayTweets.c - A source code that contains the function displayTweets, which prints the id, user 
                  and text of the nodes located in the linked text
searchTweetsByKeyword.c - A source code that contains the function searchTweetsByKeyword, which identifies
                          nodes containing the keyword inputted by the user
countStopWords.c - A source code that contains the function countStopWords, which determines the amount  
                   stop words located in the linked list through an output statement
deleteTweet.c - A source code that contains the function deleteTweet, which based on an integer inputted by the user
                representing a tweet removes a node from the linked list
saveTweetsToFile.c - A source code that contains the function saveTweetsToFile, which saves the tweets or the linked list
                     to a file inputted by the user 
loadTweetsFromFile.c - A source code that contain the function loadTweetsFromFile, which add nodes to the linked list 
                       through using a file, which is inputted by the user.
sortID.c - A source code that contains the function sortID, which sorts the nodes in ascending order, according to their 
           id
