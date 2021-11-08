#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include<math.h>

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