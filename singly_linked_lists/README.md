Building upon and creating ideas based upon the topics learned in lecture :

These programs work on singly-linked lists


--


create_and_delete_a_linked_list.c :
    * to run the program in the terminal, go to the folder location and enter $./create_a_linked_list

    - Ask user how many elements they want in the linked list
    - Ask user to define the Minimum range for the upcoming randomized data set (linked list values will be between X and Y)
    - Ask user to define the Maximum range for the upcoming randomized data set (linked list values will be between X and Y)

    - Program will create the linked list and assign each value a random value within the range set by the user

    - Free memory at the end of the program
    - Delete list at the end of the program
    
    - Args for delete_linked_list function :
        - Node pointer to linked list


--


delete_element_from_linked_list.c :
    * to run the program in the terminal, go to the folder location and enter $./delete_element_from_linked_list

    - Ask user how many elements they want in the linked list
    - Ask user to define the Minimum range for the upcoming randomized data set (linked list values will be between X and Y)
    - Ask user to define the Maximum range for the upcoming randomized data set (linked list values will be between X and Y)

    - Program will create the linked list and assign each value a random value within the range set by the user

    - Delete the element of the linked list whose .value equals the search_for variable input by the user

    - Free memory at the end of the program
    - Delete list at the end of the program

    - Args for delete_element_from_linked_list function :
        - Node pointer to linked list, int search_for
    - Args for delete_linked_list function :
        - Node pointer to linked list


--


insert_new_node_into_linked_list.c :
    * to run the program in the terminal, go to the folder location and enter $./insert_new_node_into_linked_list

    - Ask user how many elements they want in the linked list
    - Ask user to define the Minimum range for the upcoming randomized data set (linked list values will be between X and Y)
    - Ask user to define the Maximum range for the upcoming randomized data set (linked list values will be between X and Y)

    - Program will create the linked list and assign each value a random value within the range set by the user

    - Insert a new element at the beginning of the list. The value of the element will equal the insert variable entered by the user

    - Free memory at the end of the program
    - Delete list at the end of the program

    - Args for insert_node function :
        - Node pointer to linked list, int insert
    - Args for delete_linked_list function :
        - Node pointer to linked list


--


search_linked_list_for_value.c :
    * to run the program in the terminal, go to the folder location and enter $./search_linked_list_for_value

    - Ask user how many elements they want in the linked list
    - Ask user to define the Minimum range for the upcoming randomized data set (linked list values will be between X and Y)
    - Ask user to define the Maximum range for the upcoming randomized data set (linked list values will be between X and Y)

    - Program will create the linked list and assign each value a random value within the range set by the user

    - Search the element for a number given by the user. Let the user know if the number was found in the list or not

    - Free memory at the end of the program
    - Delete list at the end of the program

    - Create a singly-linked list like above
    - User inputs a number in the list they'd like to search for. Program returns a message if found or not