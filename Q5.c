/* Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)*/

#include<stdio.h>
int main () {
    int p , q;
    printf("Enter size and elements of first log;\n");
    scanf("%d",&p);
    int log1[p];
     
     for (int i=0; i<p; i++)
     scanf("%d",&log1[i]);

    printf("Enter size and elements of second log4 15 \n");
    scanf("%d",&q);
    int log2[q];
     
     for (int i=0; i<q; i++)
     scanf("%d",&log2[i]);

    int merged[p + q];
    int i = 0, j = 0, k = 0;

    // Merge both logs
    while(i < p && j < q) {
        if(log1[i] <= log2[j])
            merged[k++] = log1[i++];
        else
            merged[k++] = log2[j++];
    }

    // Copy remaining elements
    while(i < p)
        merged[k++] = log1[i++];

    while(j < q)
        merged[k++] = log2[j++];

    // Output merged chronological log
    for(int x = 0; x < p + q; x++)
        printf("%d ", merged[x]);

    return 0;
}
