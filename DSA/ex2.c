#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void insertAfterNode(struct Node* prevNode, int data);
void deleteBeginning(struct Node** head);
void deleteEnd(struct Node** head);
void deleteAtPosition(struct Node** head, int position);
void searchElement(struct Node* head, int key);
void displayList(struct Node* head);
int countNodes(struct Node* head);
void reverseList(struct Node** head);
void sortList(struct Node** head);
struct Node* mergeLists(struct Node* head1, struct Node* head2);
void findMiddle(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, data, position;
    
    while (1) {
        // Display menu options
        printf("\n===== MENU =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Node\n");
        printf("4. Delete Beginning\n");
        printf("5. Delete End\n");
        printf("6. Delete at a Specific Position\n");
        printf("7. Search for an Element\n");
        printf("8. Display Linked List\n");
        printf("9. Count Nodes\n");
        printf("10. Reverse Linked List\n");
        printf("11. Sort Linked List\n");
        printf("12. Find Middle Node\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform operations based on user choice
        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                printf("Enter position after which to insert: ");
                scanf("%d", &position);
                struct Node* temp = head;
                for (int i = 0; i < position && temp != NULL; i++) temp = temp->next;
                if (temp != NULL) insertAfterNode(temp, data);
                else printf("Position not found!\n");
                break;
            case 4:
                deleteBeginning(&head);
                break;
            case 5:
                deleteEnd(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &data);
                searchElement(head, data);
                break;
            case 8:
                displayList(head);
                break;
            case 9:
                printf("Total nodes: %d\n", countNodes(head));
                break;
            case 10:
                reverseList(&head);
                break;
            case 11:
                sortList(&head);
                break;
            case 12:
                findMiddle(head);
                break;
            case 13:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

// Function implementations
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void insertAfterNode(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void deleteBeginning(struct Node** head) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}

void deleteEnd(struct Node** head) {
    if (*head == NULL) return;
    struct Node* temp = *head, * prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) *head = NULL;
    else prev->next = NULL;
    free(temp);
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) return;
    struct Node* temp = *head, * prev = NULL;
    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void searchElement(struct Node* head, int key) {
    struct Node* temp = head;
    int position = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found in the list\n", key);
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void reverseList(struct Node** head) {
    struct Node *prev = NULL, * current = *head, * next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void sortList(struct Node** head) {
    struct Node* i, * j;
    int temp;
    if (*head == NULL) return;
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void findMiddle(struct Node* head) {
    struct Node* slow = head, * fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow != NULL) printf("Middle element: %d\n", slow->data);
}