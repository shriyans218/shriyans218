#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the stack structure
struct stack {
    int size;
    int top;
    char *arr;
};

// Check if the stack is empty
int isEmpty(struct stack *ptr) {
    return ptr->top == -1;
}

// Check if the stack is full
int isFull(struct stack *ptr) {
    return ptr->top == ptr->size - 1;
}

// Push an element onto the stack
void push(struct stack *ptr, char val) {
    if (isFull(ptr)) {
        printf("Stack Overflow! Cannot push %c to the stack\n", val);
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

// Pop an element from the stack
char pop(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    } else {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// Function to check if the parentheses in an expression are balanced
int parenthesisMatch(char *exp) {
    // Create and initialize the stack
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push(sp, '(');
        } else if (exp[i] == ')') {
            if (isEmpty(sp)) {
                // Free allocated memory before returning
                free(sp->arr);
                free(sp);
                return 0;
            }
            pop(sp);
        }
    }

    int isBalanced = isEmpty(sp);
    // Free allocated memory
    free(sp->arr);
    free(sp);

    return isBalanced;
}

// Main function
int main() {
    char exp[100]; // Allocate memory for the expression
    printf("Enter the expression: ");
    fgets(exp, 100, stdin); // Safely read the expression
    exp[strcspn(exp, "\n")] = 0; // Remove the newline character if present

    if (parenthesisMatch(exp)) {
        printf("The parenthesis is matching\n");
    } else {
        printf("The parenthesis is not matching\n");
    }

    return 0;
}
