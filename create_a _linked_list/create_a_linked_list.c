#include <stdio.h>  // printf()
#include <stdlib.h>  // rand() ; srandom() ; free() ; strtol()
#include <time.h>  // time()
#include <ctype.h>  // isdigit()


// create node data structure
typedef struct node
{
    int value;
    struct node *next;
}
node;


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
            printf("Error: Invalid input. Closing program\n");
            return 1;
        }
        if (element_count_buffer == NULL)
        {
            free(element_count_buffer);
            printf("Error: NULL, not enough space for input. Closing program\n");
            return 1;
        }
        // if we get to this point, input is valid - convert it to an int
        if (*element_count_buffer == '0')
        {
            printf("Node pointer has been created for you. None of the values will be populated. Closing program.\n");
            free(element_count_buffer);
            return 0;
        }
        element_count = atoi(element_count_buffer);
    }
    while (element_count <= 0);  // try again if user input is not a positive integer
    free(element_count_buffer);

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
            rand_min = 0;
            break;
        }
		rand_min = atoi(rand_min_buffer);
    }
    while (rand_min == 0);

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
            rand_max = 0;
            break;
        }
		rand_max = atoi(rand_max_buffer);

    }
    while (rand_max == 0);

    printf("\n");

    if (rand_min > rand_max)
    {
        printf("Error: Minimum value must be smaller than the maximum value. Closing program\n");
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
    free(rand_min_buffer);
    free(rand_max_buffer);


    // iterate over a linked list :
    node *ptr = list; // create a 2nd pointer that points at the beginning of the list
    while (ptr != NULL) // keep iterating until you reach the end of the linked list
    {
        printf("%i\n", ptr->value); // print .number value of current element the temp pointer is pointing to
        ptr = ptr->next; // set the pointer to point to the next element
    }

free(new_node);
return 0;
}