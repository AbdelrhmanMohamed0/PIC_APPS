// Stack.h: Header file for stack implementation using array in C

#ifndef STACK_H // Include guard to prevent multiple inclusion
#define STACK_H

#include <stdbool.h> // For bool type
#include "STD_TYPES.h"

#define MAXSIZE 100       // Maximum size of the stack

// Define an element type union that can hold both u8 and f64
typedef union
{
    u8 u8_element;
    f64 f64_element;
} ELEMENT_TYPE;
// Structure for stack
typedef struct stack
{
    ELEMENT_TYPE array[MAXSIZE]; // Array to store elements
    u32 top;
    u32 min;
    u32 max;
} Stack;

// Function prototypes

// Initialize a stack
void stack_init(Stack *stack);

// Check if a stack is full
bool stack_full(Stack *stack);

// Check if a stack is empty
bool stack_empty(Stack *stack);

// Push an element to a stack
bool push_stack(Stack *stack, ELEMENT_TYPE element);

// Pop an element from a stack
bool pop_stack(ELEMENT_TYPE *element, Stack *stack);

// Get the top element of a stack
bool stack_top(Stack *stack, ELEMENT_TYPE *element);

// Traverse a stack and apply a function to each element
void traverse_stack(Stack *stack, void (*func)(ELEMENT_TYPE));

// Get the size of a stack
u32 size_stack(Stack *stack);

// Clear a stack
void clear_stack(Stack *stack);

//find minimum element in stack
u32 stack_min(Stack *stack);

//find maximum element in stack
u32 stack_max(Stack *stack);

#endif
