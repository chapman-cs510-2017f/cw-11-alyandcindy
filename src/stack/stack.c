#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// create a new stack 
STACK new_stack() {
    STACK new = NULL; // stack is empty
    return new; // return the empty stack 
}

// add a value to the stack 
void push_stack(STACK *s, SVALUE val) { 
    STACK new = (STACK) malloc(sizeof(struct stack)); 
    if (new == NULL) {
        fprintf(stderr, "ERROR: Unable to push onto stack\n");
        return;
    }
    new->data = val; // set the value in the new stack
    new->head = *s; // set the head of the stack
    *s = new; // point to the new stack
}

// remove a value from the stack by "popping" it off
SVALUE pop_stack(STACK *s) { 
    SVALUE val;
    STACK temp;
    if (*s == NULL) {
      fprintf(stderr, "ERROR: Attempt to pop value from empty stack\n");
      val = SVALUE_ERR;
    }
    else {
      val = (*s)->data;
      temp = (*s);
      *s = (*s)->head;
      free(temp);
    }
    return val;
}

// print svalue
void print_svalue(SVALUE val) {
    printf("%d", val); // print val 
}

// print stack
void print_stack(STACK s) {
    while (s->head != NULL) { // while there is a value and not empty/null
        print_svalue(s->data); // print the data of the stack from the top 
        printf("\t"); // tab for formatting 
        s = s->head; // s is now to the head, so printing from the top to bottom in this loop

    }
    print_svalue(s->data); // exit loop and print
    printf("\n"); // print a new line 
}

