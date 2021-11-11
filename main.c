#include <stdio.h>
#include "NumClass.h"

int main()
{
    int first, second;
    printf("Enter first number: ");
    scanf("%d", &first);
    printf("Enter second number: ");
    scanf("%d", &second);
    int temp = first;
    while(temp<=second){
        if(isPrime(temp)) {
            printf("Prime Numbers:");
            printf("%d",temp);}
        temp++;
    }
    temp=first;
        while(temp<=second){
        if(isPalindrome(temp)) {
            printf("\nPalindrome Numbers:");
            printf("%d",temp);}
        temp++;
    }
    temp=first;
    while(temp<=second){
        if(isStrong(temp)) {
            printf("\nStrong Numbers:");
            printf("%d",temp);}
        temp++;
    }
    temp=first;
    while(temp<=second){
        if(isArmstrong(temp)) {
            printf("\nArmstrong Numbers:");
            printf("%d",temp);}
        temp++;
    }

}