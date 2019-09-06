
#include "Operation.h"


int sumOperation(int num1, int num2){
    int res;
        res = num1 + num2;
    return res;
}

int subtractionOperation(int num1, int num2){
    int res;
        res = num1 - num2;
    return res;
}

float divideOperation(int num1, int num2){
    float res;
        res = (float) num1/num2;
    return res;
}

int multipliOperation(int num1, int num2){
    int res;
        res = num1 * num2;
    return res;
}

int factorial(long num1)
{
    long b;
    long fact=1;
    for (b = num1; b > 1; b--)
    {
        fact = fact * b;
    }
    return fact;
}
