#include <stdio.h>
#include "NumClass.h"
#include <math.h>

int checkSize(int num){
    if(num>0){
        return checkSize(num/10)+1;
    }
    else {
        return 0;
    }
}

int pali(int num){
    if(num<10)
        return 1;
    int size = checkSize(num);
    if (num / (int)pow(10, size-1) == num % 10)
        return pali((num % (int)pow(10, size-1)) / 10);
    else
        return 0;

}

/*int reversed(int num){
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
*/

int isPalindrome(int num){
    if(pali(num))
    {
        return 1;
    }
    return 0;
}

int armstrongNumber(int num, int power){  
    if(num>0){
        return (pow(num%10,power) +armstrongNumber(num/10, power));
     }else {
         return 0;
     }
}

int isArmstrong(int num){
    if (armstrongNumber(num, checkSize(num))==num)
        return 1;
        else return 0;
}
