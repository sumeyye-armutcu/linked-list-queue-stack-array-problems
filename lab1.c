#include<stdio.h>
#include<stdlib.h>

//queue
struct Node{
    int current;
    struct Node *next;
};
//linked list
struct LinkedList{
    struct Node *head;
};
//reverses the linked list
void reverseLinkedList(struct LinkedList *llist) {
    struct Node *prev = NULL;
    struct Node *current = llist->head;
    struct Node *next = NULL;

    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    llist->head = prev;
}
//implements linked list to queue
void enqueue(struct LinkedList *llist, int value) {
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->current = value;
    new_node->next = llist->head;
    llist->head = new_node;
}
//prints the queue
void printQueue(struct LinkedList *llist) {
    if(llist->head == NULL) {
        printf("Queue is empty\n");
    } else {
        struct Node *node = llist->head;
        
        while(node != NULL) {
            printf("%d ", node->current);
            node = node->next;
        }
        printf("\n");
    }
}
//adds queue to stack
void push(struct Node **stack, int value) {
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->current = value;
    new_node->next = *stack;
    *stack = new_node;
}
//prints stack
void printStack(struct Node *stack) {
    if(stack == NULL) {
        printf("Stack is empty\n");
    } else {
        struct Node *node = stack;
        printf("Stack: ");
        while(node != NULL) {
            printf("%d ", node->current);
            node = node->next;
        }
        printf("\n");
    }
}
//main 
int main(){
	
    int i, num_values, data[5] = {1, 2, 3, 4, 5};
    int even_stack_sum = 0, odd_queue_sum = 0;
    struct LinkedList *llist = malloc(sizeof(struct LinkedList));
    struct Node *stack = NULL;

    llist->head = NULL;

    for(i = 4;i>=0;i--){
        enqueue(llist, data[i]);
    }
    //printing array
    printf("Array: ");
    
     for( i = 0; i < 5; i++)
      printf("%d ", data[i]);
    //printing linked list
    printf("\nLinked list: ");
    printQueue(llist);
    

   reverseLinkedList(llist);
    //printing queue
    printf("Queue: ");
    printQueue(llist);

    
    printf("Enter the number of values to extract from the end of the queue: ");
    scanf("%d", &num_values);

    reverseLinkedList(llist);

    for(i = 0; i < num_values; i++) {
        if(llist->head == NULL) {
            printf("Queue is empty\n");
            break;
        } else {
            struct Node *node = llist->head;
            push(&stack, node->current);
            llist->head = llist->head->next;
            free(node);
        }
    }

    //prints stack
    printStack(stack);
    //prints remaining queue
    printf("Remaining Queue after extraction: ");
    reverseLinkedList(llist);
    printQueue(llist);
    
    struct Node *stack_node = stack;
    struct Node *queue_node = llist->head;
    // Calculate the number of even numbers in the stack
    while (stack_node != NULL) {
    if (stack_node->current % 2 == 0) {
        even_stack_sum ++;
    }
    stack_node = stack_node->next;
}

// Calculate the number of odd numbers in the queue
while (queue_node != NULL) {
    if (queue_node->current % 2 == 1) {
        odd_queue_sum ++;
    }
    queue_node = queue_node->next;
}

if (even_stack_sum > odd_queue_sum) {
    printf("The even numbers in the stack are bigger than the odd numbers in the queue\n");
} else if (even_stack_sum < odd_queue_sum) {
    printf("The even numbers in the stack are smaller than the odd numbers in the queue\n");
} else {
    printf("The even numbers in the stack is equal to  odd numbers in the queue\n");
    return 0;
}}
