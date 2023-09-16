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
    printf("Set Min Value for Random Data Set: ");
    scanf("%d", &rand_min);

    int rand_max = 0;
    printf("Set Max Value for Random Data Set: ");
    scanf("%d", &rand_max);


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
    printf("Search for: ");
    scanf("%d", &search_for);

    while ( (search_for < rand_min) || (search_for > rand_max) )
    {
        printf("Search for: ");
        scanf("%d", &search_for);
    }

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