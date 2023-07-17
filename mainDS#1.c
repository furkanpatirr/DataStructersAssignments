#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//This code creates a stack data structure that contains random numbers. It then prompts the user to enter a number and searches for that number within the created stack.

#define STACKSIZE 100
#define INT     1
#define FLOAT   2
#define STRING  3

// Element type structure
struct stackelement {
    int type;
    union {
        int ival;
        float fval;
        char *pval;
    } element;
};

// Memory model
struct stack {
    int top;
    int items[STACKSIZE];   // can be replaced with element type structure
};

// Check if stack is empty
int isEmpty(struct stack *ps) {
    if (ps->top == -1)
        return 1;
    else
        return 0;
}

// Push element onto stack
void push(struct stack *ps, int x) {
    if (ps->top == STACKSIZE - 1) {
        printf("%s", "stack overflow");
        exit(1);
    } else
        ps->items[++(ps->top)] = x;

    return;
}

// Pop element from stack
int pop(struct stack *ps) {
    if (isEmpty(ps)) {
        printf("%s", "Stack underflow");
        exit(1);
    }
    return (ps->items[ps->top--]);
}

// Print elements
void print(struct stack *ps) {
    int topnew = ps->top;

    for (int i = 0; i <= topnew; i++) {
        printf("-%d--", pop(ps));
    }
    printf("\n");
}

// Fill stack with random elements
void fill(struct stack *ps) {
    srand(time(NULL));
    int number;

    for (int i = 0; i <= 98; i++) {
        push(ps, rand() % 1000);
    }
}

// Search for selected element
void search(struct stack *ps, int se) {
    int topnew = ps->top;

    for (int i = 0; i <= 98; i++) {
        if (se == ps->items[i]) {
            printf("The searched element is the %dth member from the bottom", (topnew - i));
        }
    }
}

int main() {
    struct stack stack;
    int searchedElement;

    fill(&stack);
    print(&stack);

    printf("Please enter the element you are searching for..\n");
    scanf("%d", &searchedElement);

    search(&stack, searchedElement);

    return 0;
}
