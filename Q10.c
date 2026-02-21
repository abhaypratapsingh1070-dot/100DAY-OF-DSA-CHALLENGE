/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int start, end, isPalindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    start = 0;
    end = strlen(str) - 1;

    while(start < end) {
        if(str[start] != str[end]) {
            isPalindrome = 0;
            break;
        }
        start++;
        end--;
    }

    if(isPalindrome)
        printf("Palindrome");
    else
        printf("Not a Palindrome");

    return 0;
}
