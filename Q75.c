#include <stdio.h>

#define MAX 1000

int main() {
    int arr[MAX], n;

    // Input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0, maxLen = 0;

    
    int hash[20001];  
    for (int i = 0; i < 20001; i++) {
        hash[i] = -2;  // -2 means not visited
    }

    int offset = 10000;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum == 0) {
            maxLen = i + 1;
        }

        if (hash[prefixSum + offset] == -2) {
            hash[prefixSum + offset] = i;
        } else {
            int len = i - hash[prefixSum + offset];
            if (len > maxLen) {
                maxLen = len;
            }
        }
    }

    printf("%d\n", maxLen);

    return 0;
}