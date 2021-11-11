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
            printf("%d",temp);}
        temp++;
    }
    temp=first;
    printf("\n");
        while(temp<=second){
        if(isPalindrome(temp)) {
            printf("%d",temp);}
        temp++;
    }
    temp=first;
    printf("\n");
    while(temp<=second){
        if(isStrong(temp)) {
            printf("%d",temp);}
        temp++;
    }
    temp=first;
    printf("\n");
    while(temp<=second){
        if(isArmstrong(temp)) {
            printf("%d",temp);}
        temp++;
    }

}