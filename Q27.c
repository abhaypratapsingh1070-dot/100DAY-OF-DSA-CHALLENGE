//Q27.Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* append(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            head1 = head1->next;
    } else {
        for (int i = 0; i < diff; i++)
            head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {

    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    struct Node* common = createNode(50);
    common->next = createNode(60);

    head1 = append(head1, 10);
    head1 = append(head1, 20);
    head1 = append(head1, 30);

    struct Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = common;
    head2 = append(head2, 40);
    head2->next = common;
    struct Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL)
        printf("Intersection Point: %d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}