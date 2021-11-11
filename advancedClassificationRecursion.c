#include <stdio.h>
#include "NumClass.h"
#include<math.h>

int isPalindrome(int num){
    if(num == reversed(num))
    {
        return 1;
    }
    return 0;
}

int reversed(int num){
    int remain;
    int sum=0;
    if(num!=0){
            remain=num%10;
            sum=sum*10+remain;
            reversed(num/10);
    }
        else
            return sum;
    return sum;
}

int isArmstrong(int num){
    if (armstrongNumber(num, checkSize(num))==num)
        return 1;
        else return 0;
}

int checkSize(int num){
    if(num>0){
        return checkSize(num/10)+1;
    }
    else {
        return 0;
    }
}

int armstrongNumber(int num, int power){  
    if(num>0){
        return (pow(num%10,power) +armstrongNumber(num/10, power));
     }else {
         return 0;
     }
}