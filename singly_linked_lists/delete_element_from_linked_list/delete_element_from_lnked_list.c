#include <stdio.h>  // printf()
#include <stdlib.h>  // rand() ; srandom() ; free() ; strtol()
#include <time.h>  // time()
#include <ctype.h>  // isdigit()
#include <stdbool.h>


// create node data structure
typedef struct node
{
    int value;
    struct node *next;
}
node;


node* delete_element_from_linked_list(node *list, int number);
void delete_linked_list(node *node);


int main(void)
{

    // create linked list pointer and set it to NULL
    node *list = NULL;

    // populate linked list w/ nodes w/ random values - range set by the user
    // user input must be an integer > 0
    int element_count = 0;
    char *element_count_buffer = NULL;
    size_t element_count_buffer_size_bytes = 0;

    do
    {
        printf("How many elements would you like to have in your linked list?: ");
        if (getline(&element_count_buffer, &element_count_buffer_size_bytes, stdin) == -1)
        {
            free(element_count_buffer);
            element_count_buffer = NULL;
            printf("Error: Invalid input. Closing program\n");
            return 1;
        }
        if (element_count_buffer == NULL)
        {
            free(element_count_buffer);
            element_count_buffer = NULL;
            printf("Error: NULL, not enough space for input. Closing program\n");
            return 1;
        }
        // if we get to this point, input is valid - convert it to an int
        if (*element_count_buffer == '0')
        {
            printf("Node pointer has been created for you. None of the values will be populated. Closing program.\n");
            free(element_count_buffer);
            element_count_buffer = NULL;
            return 0;
        }
        element_count = atoi(element_count_buffer);
    }
    while (element_count <= 0);  // try again if user input is not a positive integer
    free(element_count_buffer);
    element_count_buffer = NULL;

    printf("\n");

    int rand_min = 0;
    char *rand_min_buffer = NULL;
    size_t rand_min_buffer_size_bytes = 0;
	
    do
    {
        printf("Please set the Minimum value for the randomized data set range?: ");
        if (getline(&rand_min_buffer, &rand_min_buffer_size_bytes, stdin) == -1)
        {
            free(rand_min_buffer);
            rand_min_buffer = NULL;
            printf("Error: Invalid input. Closing program\n");
            return 1;
        }
        if (rand_min_buffer == NULL)
        {
            free(rand_min_buffer);
            rand_min_buffer = NULL;
            printf("Error: NULL, not enough space for input. Closing program\n");
            return 1;
        }
        // if we get to this point, input is valid - convert it to an int
        if (*rand_min_buffer == '0')
        {
            rand_min = 0;
            break;
        }
		rand_min = atoi(rand_min_buffer);
    }
    while (rand_min == 0);
    free(rand_min_buffer);
    rand_min_buffer = NULL;

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
            rand_max_buffer = NULL;
            printf("Error: Invalid input. Closing program\n");
            return 1;
        }
        if (rand_max_buffer == NULL)
        {
            free(rand_max_buffer);
            rand_max_buffer = NULL;
            printf("Error: NULL, not enough space for input. Closing program\n");
            return 1;
        }
        // if we get to this point, input is valid - convert it to an int
        if (*rand_max_buffer == '0')
        {
            rand_max = 0;
            break;
        }
		rand_max = atoi(rand_max_buffer);

    }
    while (rand_max == 0);
    free(rand_max_buffer);
    rand_max_buffer = NULL;


    if (rand_min > rand_max)
    {
        printf("Minimum value must be smaller than the maximum value. Closing program\n\n");
        return 1;
    }

    node * new_node = NULL;
    srand(time(NULL));  // seed new random set so we can generate a random number each iteration
    for (int i = 0; i < element_count; i++)
    {
        new_node = malloc(sizeof(node));  // create new node pointer
        if (new_node == NULL)  // make sure space is available
        {
            return 1;
        }
        // range finder math :
        // find range by subtracting the max and the min. add 1 so that both values are included 
        // (ie min == 3, max == 8. 8 - 3 == 5, but range has 6 values so add 1)
        // rand() defaults to setting 0 as the rand_min & a user defined number as the rand_max
        // we can get around this by running rand() with the range as the rand_max (between 0 and range - 1)
        // then adding the rand_min at the end to shift the data set up to fit within the min & max constraints
        int range = rand_max - rand_min + 1;
        new_node->value = rand() % range + rand_min;  // populate .value with random number within random range set by the user
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
            search_for_buffer = NULL;
            printf("Error: Invalid input. Closing program\n");
            return 1;
        }
        if (search_for_buffer == NULL)
        {
            free(search_for_buffer);
            search_for_buffer = NULL;
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
    free(search_for_buffer);
    search_for_buffer = NULL;


    delete_element_from_linked_list(list, search_for);


    /*
    * after program is run
    * free memory
    */

   delete_linked_list(list);
    
list = NULL;
new_node = NULL;
return 0;
}


node* delete_element_from_linked_list(node *list, int number)
{
    bool in_list = false;

    node *trav = NULL;
    trav = list;
    node *tail = NULL;
    tail = list;

    // trav finds the desired element (where .value == number)
    // tail finds the element before trav
    // so that tail.next can point to trav.next; so when trav is free'd, the link chain remain intact

    while (trav != NULL)
    {
        if (trav->value == number)
        {
            in_list = true;
            while (tail != NULL)
            {
                if (tail == trav)  // if number is found at the 1st element
                {
                    tail = trav->next;
                    free(trav);
                    trav = NULL;
                    trav = tail;
                    list = trav;
                    break;
                }
                else if (tail->next == trav)  // if number is found anywhere after the 1st element
                {
                    tail->next = trav->next;
                    free(trav);
                    trav = NULL;
                    trav = tail->next;
                    break;
                }
                else  // if number is found at the current element
                {
                    tail = tail->next;
                }
            }
        }
        else
        {
            trav = trav->next;
        }
    }
    return list;
}


void delete_linked_list(node *node)
{
// starts with separate traversal pointer pointing to the beginning of the linked list
    // Base Case :
    // if you reach a null pointer, stop
    if (node == NULL)
    {
        return;
    }

    // Recursive Case :
    // delete the rest of the list
    delete_linked_list(node->next);

    // free the current node
    free(node);
    node = NULL;
}