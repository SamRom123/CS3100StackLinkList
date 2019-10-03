#StackLinkList
(View as "Raw" or "Blame")
This is an assignemnt from my operating systems class where I asked to create a stack based on a linked list in C.
I also had to make sure that the program to compile in linux, along with an appropriate makefile.
"Makefile" and "stack.h" were given by the professor.

stack.c
This program is stack and the assosiated functions based on a linked list. 
Functions:
NewStack(void);
  Default constructor for the stack
Push(stackT * stack, valueT value);
  Pushes the given value onto the stack
Pop(stackT * stack);
  Pops the top value off of the stack
EmptyStack(stackT * stack);
  Removes everything from the stack, but does not delete it
FreeStack(stackT * stack);
  If the stack is empty, delete empty node that still remains
IsEmpty(stackT * stack);
  Checks if the stack is empty
