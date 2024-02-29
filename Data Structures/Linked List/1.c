#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;                           //data for the Node
    struct Node* next;                  //pointer to the next node
};

// Function to create and insert a node at the beginning of the linked list
//struct Node* head is the pointer for the staring of the linked list it is the place from where we can start accessing the linked list
//int data is the data we are storing in the Node;
struct Node* insert(struct Node* head, int data){                       
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    //new_node points to the place where the memory has been allocated
    new_node->data = data;              //Acceingin the value
    new_node->next = NULL;              //we dont now the next Nide yet so we make it NULL
    if (head == NULL) {                 //Checking if we have started the linked list if not 
        head = new_node;                // we start by assigning the starting point the node that we have created 
    }
    else {
        // Traverse the list to find the last node       //we have created the linked list now we have to got to the end of the list
        struct Node* current = head;                      //the only location that we know in the linked list is the head so we start from it
        while (current->next != NULL) {                   //we check wether the next node is empty or not 
            current = current->next;                        //if it is not empty we go to the next node in the list we do this until the last node is reached
        }

        // Insert the new node at the end
        current->next = new_node;                           //After finding the last node we set the last nodes next as the new_Node and make it the last node off the updtaed list
    }                   

    return head;                                             //Now we return the starting point of the linked list to the main()
}

// Function to display the linked list
void display(struct Node* head) {                             //Only the starting point is given
    struct Node* current = head;                              //we get the address of it to a pointer and go forward 
    while (current != NULL) {                                 //checking the current is empty or not
        printf("%d -> ", current->data);                       //if not printing the value 
        current = current->next;                              //going to the next node in linked list
    }
    printf("NULL\n");       
}

// Main function
int main() {
    struct Node* my_linked_list = NULL;                         //the starting point of the linked list we use to access it
    // Inserting elements
    my_linked_list = insert(my_linked_list, 3);
    my_linked_list = insert(my_linked_list, 7);
    my_linked_list = insert(my_linked_list, 12);

    // Displaying the linked list
    display(my_linked_list);

    return 0;
}
