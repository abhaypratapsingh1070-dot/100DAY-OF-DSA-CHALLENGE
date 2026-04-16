#include <stdio.h>

#define EMPTY -1

int table[100];  
int m;            


int hashFunction(int key) {
    return key % m;
}


void insert(int key) {
    for (int i = 0; i < m; i++) {
        int index = (hashFunction(key) + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
    }
    printf("Hash Table is Full\n");
}

void search(int key) {
    for (int i = 0; i < m; i++) {
        int index = (hashFunction(key) + i * i) % m;

        if (table[index] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }

        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }
    }
    printf("NOT FOUND\n");
}

int main() {
    int q;
    scanf("%d", &m); 
    scanf("%d", &q);  

    // Initialize table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (op[0] == 'I') {   
            insert(key);
        } else if (op[0] == 'S') {  
            search(key);
        }
    }

    return 0;
}