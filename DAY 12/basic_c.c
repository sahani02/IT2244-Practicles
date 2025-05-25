//Print Hello world
#include<stdio.h>
int main(){
printf("Hello world!\n");
return 0;
}

//Identify the variables
#include<stdio.h>
int main(){
int age;
age=25;
int num =25;
}

//print variable value as output
#include<stdio.h>
int main(){
int age=25;
printf("%d",age);
age=31;
printf("\nNew age:%d",age);
return 0;
}

#include<stdio.h>
int main(){
int firstNumber=25;
printf("First number:%d",firstNumber);
int secondNumber=firstNumber;
printf("second number:%d",secondNumber);
return 0;
}

//give firstnumber is random number and second number is 25
#include<stdio.h>
int main(){
int firstNumber,secondNumber=25;
printf("First number:%d\n",firstNumber);
printf("second number:%d\n",secondNumber);
return 0;
}

//give size of number
#include<stdio.h>
int main(){
int age=25;
printf("%d\n",age);
printf("size:%zu",sizeof(age));
return 0;
}

//data types
#include<stdio.h>
int main(){
double number=12.45;
printf("%lf\n",number); //12.450000
printf("%.2lf\n",number); //12.45

float number1=10.9f;
printf("%f\n",number1); //10.900000
printf("%.1f\n",number1); //10.9

char character='z';
printf("%c\n",character);
printf("%d\n",character);
return 0;
}

//user input
#include<stdio.h>
int main(){
int age;
printf("Enter ytour age:");
scanf("%d", &age);
printf("Age=%d\n",age);

double number;
char alpha;
printf("enter double input: ");
scanf("%lf", &number);
printf("your double input is:%lf\n",number);

printf("enter char input: ");
scanf(" %c", &alpha);
printf("your char input is: %c\n",alpha);
return 0;
}

//simple calculator- Arithmatic operations
#include<stdio.h>
int main(){

double number1;
double number2;

int n1;
int n2;

printf("enter number1: ");
scanf("%lf", &number1);

printf("enter number2: ");
scanf("%lf", &number2);

printf("\nAddition:%.2lf",number1+number2);
printf("\nSubtraction:%.2lf",number1-number2);
printf("\nmultiplication:%.2lf",number1*number2);
printf("\nDivision:%.2lf",number1/number2);

printf("\nenter n1: ");
scanf("%d", &n1);

printf("\nenter n2: ");
scanf("%d", &n2);

printf("\nReminder:%d",n1/n2);
return 0;
}
