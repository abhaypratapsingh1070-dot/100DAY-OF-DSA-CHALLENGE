#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL, *merged = NULL;
    int n, value;

    printf("Enter number of elements in List 1: ");
    scanf("%d", &n);
    printf("Enter sorted elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        list1 = insertEnd(list1, value);
    }

    printf("Enter number of elements in List 2: ");
    scanf("%d", &n);
    printf("Enter sorted elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        list2 = insertEnd(list2, value);
    }

    merged = mergeLists(list1, list2);

    printf("Merged Sorted List:\n");
    display(merged);

    return 0;
}