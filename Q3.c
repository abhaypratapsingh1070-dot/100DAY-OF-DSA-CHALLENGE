/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)*/

#include <stdio.h>
int main() {
    int n, k, i;
    
    scanf("%d", &n);
    
    int arr[n];
    
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);
    
    int comparisons = 0;
    int found = -1;

    for(i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == k) {
            found = i;
            break;
        }
    }
    
    if(found != -1)
        printf("Found at index %d\n", found);
    else
        printf("Not Found\n");
    
    printf("Comparisons = %d", comparisons);

    return 0;
}