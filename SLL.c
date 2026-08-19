#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
      int data;
      struct Node *next;
} Node;

Node* createNode(int value) {
      Node *newNode = (Node*)malloc(sizeof(Node));

      if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
      }

      newNode->data = value;
      newNode->next = NULL;

      return newNode;
}

void printList(Node *head) {
      Node *current = head;

      while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
      }

      printf("NULL\n");
}

Node* search(Node *head, int target) {
      Node *current = head;

      while (current != NULL) {
            if (current->data == target) {
                  return current;
            }

            current = current->next;
      }

      return NULL;
}

void insertAtBeginning(Node **head, int value) {
      Node *newNode = createNode(value);

      newNode->next = *head;
      *head = newNode;
}

void insertAtEnd(Node **head, int value) {
      Node *newNode = createNode(value);
      if (*head == NULL) {
            *head = newNode;
            return;
      }
      Node *current = *head;
      while (current->next != NULL) {
            current = current->next;
      }
      current->next = newNode;
}

void insertAfter(Node *prevNode, int value) {
      if (prevNode == NULL) {
            printf("Previous node cannot be NULL!\n");
            return;
      }
      Node *newNode = createNode(value);
      newNode->next = prevNode->next;
      prevNode->next = newNode;
}

void deleteFromBeginning(Node **head) {
      if (*head == NULL) {
            printf("List is empty!\n");
            return;
      }
      Node *temp = *head;
      *head = (*head)->next;
      free(temp);
}


void deleteFromEnd(Node **head) {
      if (*head == NULL) {
            printf("List is empty!\n");
            return;
      }
      if ((*head)->next == NULL) {
            free(*head);
            *head = NULL;
            return;
      }

      Node *current = *head;
      while (current->next->next != NULL) {
            current = current->next;
      }

      free(current->next);
      current->next = NULL;
}

void deleteByValue(Node **head, int value) {
      if (*head == NULL) {
            printf("List is empty!\n");
            return;
      }
      if ((*head)->data == value) {
            Node *temp = *head;

            *head = (*head)->next;

            free(temp);
            return;
      }
      Node *current = *head;
      while (current->next != NULL &&
             current->next->data != value) {

            current = current->next;
      }
      if (current->next == NULL) {
            printf("%d not found in the list!\n", value);
            return;
      }
      Node *temp = current->next;
      current->next = temp->next;
      free(temp);
}

void freeList(Node **head) {
      Node *current = *head;
      while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
      }
      *head = NULL;
}

void main() {
      Node *head = NULL;
      insertAtBeginning(&head, 30);
      insertAtBeginning(&head, 20);
      insertAtBeginning(&head, 10);
      printf("After inserting at beginning:\n");
      printList(head);
      insertAtEnd(&head, 40);
      insertAtEnd(&head, 50);
      printf("\nAfter inserting at end:\n");
      printList(head);
      Node *node = search(head, 30);
      if (node != NULL) {
            insertAfter(node, 35);
      }
      printf("\nAfter inserting 35 after 30:\n");
      printList(head);
      int target = 40;
      Node *result = search(head, target);

      if (result != NULL) {
            printf("\n%d found in the list.\n", target);
      }
      else {
            printf("\n%d not found in the list.\n", target);
      }
      deleteFromBeginning(&head);
      printf("\nAfter deleting from beginning:\n");
      printList(head);
      deleteFromEnd(&head);
      printf("\nAfter deleting from end:\n");
      printList(head);
      deleteByValue(&head, 35);
      printf("\nAfter deleting 35:\n");
      printList(head);
      freeList(&head);
}