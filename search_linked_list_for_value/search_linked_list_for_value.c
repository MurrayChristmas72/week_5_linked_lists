#include <stdio.h>  // printf()
#include <stdlib.h>  // rand() ; srandom() ; free()
#include <time.h>  // time()
#include <stdbool.h>


typedef struct node
{
    int value;
    struct node *next;
}
node;

#define NODE_COUNT 7


bool search_linked_list(node *node, int number);


int main(void)
{
    // Create & populate a linked list so we can search thru it :

    // create linked list
    node *list = NULL;

    // populate linked list w/ nodes w/ random values - range set by the user
    int rand_min = 0;
    char *rand_min_buffer = NULL;
    size_t rand_min_buffer_size_bytes = 0;
	
    do
    {
        printf("Please set the Minimum value for the randomized data set range?: ");
        if (getline(&rand_min_buffer, &rand_min_buffer_size_bytes, stdin) == -1)
        {
            free(rand_min_buffer);
            printf("Error: Invalid input. Closing program\n");
            return 1;
        }
        if (rand_min_buffer == NULL)
        {
            free(rand_min_buffer);
            printf("Error: NULL, not enough space for input. Closing program\n");
            return 1;
        }
        // if we get to this point, input is valid - convert it to an int
        if (*rand_min_buffer == '0')
        {
            rand_min = 0;  // if user inputs 0, that's valid. break out to avoid atoi's issue of returning 0 for both 0 input and errors
            break;
        }
		rand_min = atoi(rand_min_buffer);
    }
    while (rand_min == 0);  // try again if user input is not an integer

    printf("\n");

	int rand_max = 0;
    char *rand_max_buffer = NULL;
    size_t rand_max_buffer_size_bytes = 0;

    do
    {
        printf("Please set the Maximum value for the randomized data set range: ");
        if (getline(&rand_max_buffer, &rand_max_buffer_size_bytes, stdin) == -1)
        {
            free(rand_max_buffer);
            printf("Error: Invalid input. Closing program\n");
            return 1;
        }
        if (rand_max_buffer == NULL)
        {
            free(rand_max_buffer);
            printf("Error: NULL, not enough space for input. Closing program\n");
            return 1;
        }
        // if we get to this point, input is valid - convert it to an int
        if (*rand_max_buffer == '0')
        {
            rand_max = 0;  // if user inputs 0, that's valid. break out to avoid atoi's issue of returning 0 for both 0 input and errors
            break;
        }
		rand_max = atoi(rand_max_buffer);
    }
    while (rand_max == 0);  // try again if user input is not an integer

    if (rand_min > rand_max)
    {
        printf("Error: Minimum value must be smaller than the maximum value. Closing program\n");
        return 1;
    }


    srand(time(NULL));  // seed new random set so we can generate a random number each iteration
    for (int i = 0; i < NODE_COUNT; i++)
    {
        node *new_node = malloc(sizeof(node));  // create new node pointer
        if (new_node == NULL)  // make sure space is available
        {
            return 1;
        }
        new_node->value = rand() % ((rand_max + 1) - rand_min);  // populate .value with random number within random range set by the user
        new_node->next = NULL;  // populate .next NULL to remove garbage value
        new_node->next = list;
        list = new_node;  // return pointer to the front
    }


    // Search thru linked list for an integer :
    // prompt user for an integer that we'll try and find in the linked list
    printf("\n");
    int search_for = 0;
    char *search_for_buffer = NULL;
    size_t search_for_buffer_size_bytes = 0;

    do
    {
        repeat_if_search_for_is_not_within_random_range:
        printf("Search for: ");
        if (getline(&search_for_buffer, &search_for_buffer_size_bytes, stdin) == -1)
        {
            free(search_for_buffer);
            printf("Error: Invalid input. Closing program\n");
            return 1;
        }
        if (search_for_buffer == NULL)
        {
            free(search_for_buffer);
            printf("Error: NULL, not enough space for input. Closing program\n");
            return 1;
        }
        // if we get to this point, input is valid - convert it to an int
        if (*search_for_buffer == '0')
        {
            search_for = 0;  // if user inputs 0, that's valid. break out to avoid atoi's issue of returning 0 for both 0 input and errors
            break;
        }
        search_for = atoi(search_for_buffer);
        if ( (search_for < rand_min) || (search_for > rand_max) )
        {
            printf("Your number is not within the random data set range. Try again.\n\n");
            goto repeat_if_search_for_is_not_within_random_range;
        }
    }
    while (search_for == 0);  // try again if user input is not an integer

    node *trav = list;
    if ( search_linked_list(trav, search_for) )
    {
        printf("Success: Your number appears in the linked list\n");
        return 0;
    }
    else
    {
        printf("Failure: Your number does not appear in the linked list\n");
        return 0;
    }

free(search_for_buffer);
return 0;
}


bool search_linked_list(node *node, int number)
{
    while (node != NULL)
    {
        if (node->value == number)
        {
            return true;
        }
        node = node->next;
    }
    return false;
}