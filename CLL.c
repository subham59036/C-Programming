#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
      int data;
      struct Node *next;
      struct Node *prev;
} Node;

Node* createNode(int value) {
      Node *newNode = (Node*)malloc(sizeof(Node));
      if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
      }
      newNode->data = value;
      newNode->next = NULL;
      newNode->prev = NULL;
      return newNode;
}

void printList(Node *head) {
      if (head == NULL) {
            printf("NULL\n");
            return;
      }

      Node *current = head;
      do {
            printf("%d <-> ", current->data);
            current = current->next;
      } while (current != head);

      printf("(HEAD)\n");
}

Node* search(Node *head, int target) {
      if (head == NULL) {
            return NULL;
      }

      Node *current = head;
      do {
            if (current->data == target) {
                  return current;
            }
            current = current->next;
      } while (current != head);

      return NULL;
}

void insertAtBeginning(Node **head, int value) {
      Node *newNode = createNode(value);

      if (*head == NULL) {
            newNode->next = newNode;
            newNode->prev = newNode;
            *head = newNode;
            return;
      }

      Node *tail = (*head)->prev;

      newNode->next = *head;
      newNode->prev = tail;
      tail->next = newNode;
      (*head)->prev = newNode;
      *head = newNode;
}

void insertAtEnd(Node **head, int value) {
      Node *newNode = createNode(value);

      if (*head == NULL) {
            newNode->next = newNode;
            newNode->prev = newNode;
            *head = newNode;
            return;
      }

      Node *tail = (*head)->prev;

      newNode->next = *head;
      newNode->prev = tail;
      tail->next = newNode;
      (*head)->prev = newNode;
}

void insertAfter(Node *prevNode, int value) {
      if (prevNode == NULL) {
            printf("Previous node cannot be NULL!\n");
            return;
      }

      Node *newNode = createNode(value);

      newNode->next = prevNode->next;
      newNode->prev = prevNode;
      prevNode->next->prev = newNode;
      prevNode->next = newNode;
}

void deleteFromBeginning(Node **head) {
      if (*head == NULL) {
            printf("List is empty!\n");
            return;
      }

      Node *temp = *head;

      if ((*head)->next == *head) {
            free(temp);
            *head = NULL;
            return;
      }

      Node *tail = (*head)->prev;

      *head = (*head)->next;
      (*head)->prev = tail;
      tail->next = *head;

      free(temp);
}

void deleteFromEnd(Node **head) {
      if (*head == NULL) {
            printf("List is empty!\n");
            return;
      }

      if ((*head)->next == *head) {
            free(*head);
            *head = NULL;
            return;
      }

      Node *tail = (*head)->prev;
      Node *newTail = tail->prev;

      newTail->next = *head;
      (*head)->prev = newTail;

      free(tail);
}

void deleteByValue(Node **head, int value) {
      if (*head == NULL) {
            printf("List is empty!\n");
            return;
      }

      Node *current = *head;

      do {
            if (current->data == value) {
                  break;
            }
            current = current->next;
      } while (current != *head);

      if (current->data != value) {
            printf("%d not found in the list!\n", value);
            return;
      }

      if (current->next == current) {
            free(current);
            *head = NULL;
            return;
      }

      if (current == *head) {
            Node *tail = (*head)->prev;

            *head = current->next;
            (*head)->prev = tail;
            tail->next = *head;

            free(current);
            return;
      }

      current->prev->next = current->next;
      current->next->prev = current->prev;

      free(current);
}

void freeList(Node **head) {
      if (*head == NULL) {
            return;
      }

      Node *current = (*head)->next;

      while (current != *head) {
            Node *temp = current;
            current = current->next;
            free(temp);
      }

      free(*head);
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