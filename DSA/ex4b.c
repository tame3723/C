#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    struct Node* temp = top;
    printf("Popped element: %d\n", top->data);
    top = top->next;
    free(temp);
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element: %d\n", top->data);
}

void isEmpty() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }
}

void display() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeMemory() {
    while (top != NULL) {
        struct Node* temp = top;
        top = top->next;
        free(temp);
    }
    printf("Memory freed successfully!\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n===== LINKED LIST STACK MENU =====\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Check Empty\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: printf("Enter value to push: "); scanf("%d", &value); push(value); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: isEmpty(); break;
            case 5: display(); break;
            case 6: freeMemory(); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}