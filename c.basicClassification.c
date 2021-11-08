// C program to find Armstrong number

#include <stdio.h>

/* Function to calculate x raised to the power y */
int power(int x, unsigned int y)
{
	if (y == 0)
		return 1;
	if (y % 2 == 0)
		return power(x, y / 2) * power(x, y / 2);
	return x * power(x, y / 2) * power(x, y / 2);
}

/* Function to calculate order of the number */
int order(int x)
{
	int n = 0;
	while (x) {
		n++;
		x = x / 10;
	}
	return n;
}

// Function to check whether the given number is
// Armstrong number or not
int isArmstrong(int x)
{
	// Calling order function
	int n = order(x);
	int temp = x, sum = 0;
	while (temp) {
		int r = temp % 10;
		sum += power(r, n);
		temp = temp / 10;
	}

	// If satisfies Armstrong condition
	if (sum == x)
		return 1;
	else
		return 0;
}

// A function that returns true only
// if num contains one
// digit
int oneDigit(int num)
{
	
	// Comparison operation is faster
	// than division
	// operation. So using following
	// instead of "return num
	// / 10 == 0;"
	return (num >= 0 && num < 10);
}

// A recursive function to find
// out whether num is
// palindrome or not. Initially, dupNum
// contains address of
// a copy of num.
bool isPalUtil(int num, int* dupNum)
{
	
	// Base case (needed for recursion
	// termination): This
	// statement mainly compares the
	// first digit with the
	// last digit
	if (oneDigit(num))
		return (num == (*dupNum) % 10);

	// This is the key line in this
	// method. Note that all
	// recursive calls have a separate
	// copy of num, but they
	// all share same copy of *dupNum.
	// We divide num while
	// moving up the recursion tree
	if (!isPalUtil(num / 10, dupNum))
		return false;

	// The following statements are
	// executed when we move up
	// the recursion call tree
	*dupNum /= 10;

	// At this point, if num%10 contains
	// i'th digit from
	// beginning, then (*dupNum)%10
	// contains i'th digit
	// from end
	return (num % 10 == (*dupNum) % 10);
}

// The main function that uses
// recursive function
// isPalUtil() to find out whether
// num is palindrome or not
int isPal(int num)
{
	
	// Check if num is negative,
	// make it positive
	if (num < 0)
		num = -num;

	// Create a separate copy of num,
	// so that modifications
	// made to address dupNum don't
	// change the input number.
	// *dupNum = num
	int* dupNum = new int(num);

	return isPalUtil(num, dupNum);
}
int factorial(int r) {
   int fact = 1;
   while(r>1) {
      fact = fact * r;
      r--;
   }
   return fact;
}
int isStrong(int n) {
   int temp, rem, result = 0;
   temp = n;
   while(temp) {
      rem = temp % 10;
      result = result + factorial(rem);
      temp = temp/10;
   }
   if (result == n)
      return 1;
   else
      return 0;
}

int is_prime(int num)
{
     if (num <= 1) return 0;
     if (num % 2 == 0 && num > 2) return 0;
     for(int i = 3; i < num / 2; i+= 2)
     {
         if (num % i == 0)
             return 0;
     }
     return 1;
}