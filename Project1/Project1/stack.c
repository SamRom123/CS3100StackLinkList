#include <stdio.h>
#include "stack.h"


//Default constructor for the stack
stackT *NewStack(void) {
	
	stackT *temp = (stackT *) malloc(sizeof(stackT)); //Creates a pointer to stackT, and allocates the memory to it
	temp->head = NULL;								  //Sets the head pointer to NULL

	return temp;

}
//Pushes the value "value" to the first item in the list
void Push(stackT *stack, valueT value) {



	nodeT *temp = (nodeT *) malloc(sizeof(nodeT));	//Creates a new node to store the value in
	temp->value = value;							//Places the passed in value into the temp node

	if (stack->head == NULL) {						//Checks if the stack is empty
		stack->head = temp;							//Points the head ptr to the address of the temp node
		stack->head->next = NULL;					//This node will always be the last node, so sets "next" to point to NULL
		return;
	}
	else {											//If the stack is NOT empty, redirect temp.next
		temp->next = stack->head;					//Points the temp node's next to the current head of the stack
		stack->head = temp;							//Points head to the new front of the stack
		return;		
	}
}
//Returns and removes the first value in the stack
valueT Pop(stackT *stack) {

	if (stack->head == NULL) {							//Checks if the stack is empty
		fprintf(stderr, "Nothing in the stack \n");		//Prints an error stating the stack is empty
		return 0;
	}
	valueT returner = stack->head->value;				//Stores the value from the first node into returner
	
	stackT *temp = (stackT *)malloc(sizeof(stackT));	//Creates a temp node to store the location of the next node
	temp->head = stack->head->next;						//Points the temp ptr to the second item in the list
	
	free(stack->head);									//Frees the current node

	stack->head = temp->head;							//Points head to the new first node

	return returner;									//Returns the value in the now deleted node


}
//Deletes all items/nodes in the stack
void EmptyStack(stackT *stack) {

	stackT *temp = (stackT *)malloc(sizeof(stackT));	//Creates a stackT pointer
	while (stack->head != NULL) {						//Loops through the stack until head is null
		temp->head = stack->head->next;					//Stores the next node in the stack
		free(stack->head);								//Frees the first node
		stack->head = temp->head;						//Points head to the new first node in the stack
	}
	return;
}
//If the stack is empty, delete the node pointing to null
void FreeStack(stackT *stack) {

	if (stack->head != NULL) {							//Checks if the stack is empty
		fprintf(stderr, "The stack is not empty\n");	//Prints an error stating the stack is not empty
		return;
	}

	free(stack);										//Frees the stack
	return;
}
//Checks if the stack is empty
bool IsEmpty(stackT *stack) {

	if (stack->head == NULL) {		//If the stack head pointer is null, return true
		return true;
	}
	return false;
}