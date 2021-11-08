#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include<math.h>

int order(int x)
{
	int n = 0;
	while (x) {
		n++;
		x = x / 10;
	}
	return n;
}

int isArmstrong(int x)
{
	// Calling order function
	int n = order(x);
	int temp = x, sum = 0;
	while (temp) {
		int r = temp % 10;
		sum += pow(r, n);
		temp = temp / 10;
	}

	// If satisfies Armstrong condition
	if (sum == x)
		return 1;
	else
		return 0;
}

int isPalindrom(int x){
	
		int n = x, reversed = 0;
	    while (n != 0) {
        int remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
		}
    // palindrome if orignal and reversed are equal
    if (x == reversed)
        printf("%d is a palindrome.", x);
    else
        printf("%d is not a palindrome.", x);

    return 0;
}