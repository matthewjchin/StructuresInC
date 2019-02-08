#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Complex{
    float real;
    float imag;
};

void Display(struct Complex c){
    printf("Real Number: %.2f, Imaginary Number: %.2fi\n", c.real, c.imag);
}

struct Complex Add(struct Complex c1, struct Complex c2){
    struct Complex sumNums; 
    sumNums.real = c1.real + c2.real;
    sumNums.imag = c1.imag + c2.imag;
    return sumNums;
}

struct Complex Subtract(struct Complex c1, struct Complex c2){
    struct Complex diffNums;
    diffNums.real = c1.real - c2.real;
    diffNums.imag = c1.imag - c2.imag;
    return diffNums;
}

int main(){
    struct Complex num1, num2, temp;
    printf("Enter the real and imaginary numbers:\n");
    scanf("%f %f", &num1.real, &num1.imag);
    Display(num1);

    printf("\nFor 2nd complex number \n");
    printf("Enter real and imaginary numbers:\n");
    scanf("%f %f", &num2.real, &num2.imag);
    Display(num2);

    temp = Add(num1, num2);
    Display(temp);
}
