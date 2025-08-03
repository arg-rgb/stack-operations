#include<stdio.h>
#include<stdlib.h>

void push(int **stack, int *top, int item, int *capacity);
void pop(int *stack, int *top);
void display(int *stack, int *top);

int main(){
    int *stack = NULL, top = -1, capacity, item, ch;
    
    printf("Enter initial stack capacity: ");
    scanf("%d", &capacity);
    
    do{ 
        puts("\nMenu :\n1 for push\n2 for pop\n3 for display\n4 for exit");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        
        switch(ch){
            case 1: 
                printf("Enter item to push: ");
                scanf("%d", &item);
                push(&stack, &top, item, &capacity);
                break;
            case 2: 
                pop(stack, &top); 
                break;
            case 3: 
                display(stack, &top); 
                break;
            case 4: 
                if (stack != NULL) free(stack);
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default: 
                puts("Please Enter a valid choice...!!!");
        }
    } while(1);
    return 0;
}

void push(int **stack, int *top, int item, int *capacity){
    // Allocate memory only if not already allocated
    if (*stack == NULL) {
        *stack = (int *)malloc(sizeof(int) * (*capacity));
        if (*stack == NULL) {
            puts("Memory allocation failed...");
            return;
        }
        printf("Stack created with capacity %d\n", *capacity);
    }
    
    // Check if stack is full
    if (*top >= (*capacity - 1)) {
        char decision;
        printf("Stack overflow! Current capacity: %d\n", *capacity);
        printf("Do you want to reallocate memory? (y/n): ");
        scanf(" %c", &decision);
        
        if (decision == 'y' || decision == 'Y') {
            int newSize;
            printf("Enter new stack size (must be > %d): ", *capacity);
            scanf("%d", &newSize);
            
            if (newSize <= *capacity) {
                printf("New size must be greater than current capacity!\n");
                return;
            }
            
            int *temp = (int *)realloc(*stack, newSize * sizeof(int));
            if (temp == NULL) {
                puts("Reallocation failed!");
                return;
            }
            *stack = temp;
            printf("Stack resized from %d to %d\n", *capacity, newSize);
            *capacity = newSize;
        } else {
            puts("Push operation cancelled.");
            return;
        }
    }
    
    (*top)++;
    (*stack)[*top] = item;
    printf("Successfully pushed %d (position %d)\n", item, *top);
}

void pop(int *stack, int *top) {
    // Check if stack is empty
    if (*top == -1) {
        puts("Stack underflow! Stack is empty.");
        return;
    }
    
    int poppedItem = stack[*top];
    (*top)--;
    printf("Popped item: %d\n", poppedItem);
    printf("Current top position: %d\n", *top);
}

void display(int *stack, int *top) {
    // Check if stack is empty
    if (*top == -1) {
        puts("Stack is empty! Nothing to display.");
        return;
    }
    
    printf("\nStack contents (top to bottom):\n");
    printf("Position\tValue\n");
    printf("--------\t-----\n");
    
    for (int i = *top; i >= 0; i--) {
        printf("%d\t\t%d", i, stack[i]);
        if (i == *top) {
            printf(" <- TOP");
        }
        printf("\n");
    }
    printf("Total elements: %d\n", *top + 1);
}
