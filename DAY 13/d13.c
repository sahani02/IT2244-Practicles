//if else 
if(condition){
  //body of if statment;
}
else{
  //body of else statment;
}

Example: Enter your age and verify your eligible or not for election voting 
using if else condition .

#include <stdio.h>

int main() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);

    if (age >= 18) {
        printf("You are eligible to vote.\n");
    } else {
        printf("You are not eligible to vote.\n");
    }

    return 0;
}



//Ternary operator
test_condition ? expression1 : expression2;

Enter your age and verify your eligible or not for election voting 
using ternary operator .

#include <stdio.h>

int main() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);

    (age >= 18) ? printf("Eligible to vote\n") : printf("Not eligible to vote\n");

    return 0;
}


//switch operator
switch(variable/expression){
   case 1:
     //body of case 1
     break;
   case 2:
     //body of case 2
     break;

   case n:
     //body of case n
     break;

  default:
    // body of default
   }

Example 1: Enter the value between 1 to 7 and create a program for following output:
Enter the number between 1 to 7 : 1
Today is Sunday!

#include <stdio.h>

int main() {
    int day;
    printf("Enter number between 1 to 7: ");
    scanf("%d", &day);

    switch(day) {
        case 1: 
		printf("Today is Sunday!\n"); 
		break;
		
        case 2: 
		printf("Today is Monday!\n"); 
		break;
		
        case 3: 
		printf("Today is Tuesday!\n"); 
		break;
		
        case 4: 
		printf("Today is Wednesday!\n"); 
		break;
		
        case 5: 
		printf("Today is Thursday!\n"); 
		break;
		
        case 6: 
		printf("Today is Friday!\n"); 
		break;
		
        case 7: 
		printf("Today is Saturday!\n"); 
		break;
		
        default: 
		printf("Invalid input!\n");
    }

    return 0;
}


Example 2:
write a code for small astrology based on your life path number for that  get date of birth 
from user then calculate life path number.(use switch case)
output:
     case 1-Date: 23
	 case 2-Date: 29

     calculation for life path number:                    
			  a=date%10     3                                
			  b=date/10     2
			  c=a+b         5
	  if life path number :
			  1:Lucky
			  2:Carefuly do your work
			  3:Storger
			  4:Happy
			  5:Can get help
			  6:Doubt
			  7:Sad 
			  8:Like
			  9:Courage
			  
#include <stdio.h>

int main() {
    int date, a, b, c;
    printf("Enter your birth date (1-31): ");
    scanf("%d", &date);

    a = date % 10;
    b = date / 10;
    c = a + b;

    if (c > 9) c = (c % 10) + (c / 10);  // Reduce to single digit if needed

    switch (c) {
        case 1: 
		printf("Lucky\n"); 
		break;
		
        case 2: 
		printf("Carefully do your work\n"); 
		break;
		
        case 3: 
		printf("Stronger\n"); 
		break;
		
        case 4: 
		printf("Happy\n"); 
		break;
		
        case 5: 
		printf("Can get help\n"); 
		break;
		
        case 6: 
		printf("Doubt\n"); 
		break;
		
        case 7: 
		printf("Sad\n"); 
		break;
		
        case 8: 
		printf("Like\n"); 
		break;
		
        case 9: 
		printf("Courage\n"); 
		break;
		
        default: 
		printf("Invalid life path number\n");
    }

    return 0;
}


Example 3:
Give list of numbers then calculate the summation and multiplication using for loop.
 Example:-
    1 2 3 4 5                             
	summation = 15                         
    multiplication =120
	
#include <stdio.h>

int main() {
    int n, num, sum = 0, product = 1;

    printf("Enter how many numbers you want to input: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%d", &num);
        sum += num;
        product *= num;
    }

    printf("Summation = %d\n", sum);
    printf("Multiplication = %d\n", product);

    return 0;
}
	

Example 4:
Print the integers from 1  to 10 using while loop.

#include <stdio.h>

int main() {
    int i = 1;
    while (i <= 10) {
        printf("%d ", i);
        i++;
    }
    return 0;
}


EXAMPLE 5:
Write a C program to generate and print the Fibonacci series up to a specified 
number of terms. The program should take the number of terms as input from the 
user and then display the corresponding Fibonacci sequence.

#include <stdio.h>

int main() {
    int n, a = 0, b = 1, next;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    for (int i = 1; i <= n; ++i) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }

    return 0;
}


EXAMPLE 6:
Write a C program to calculate the factorial of a given non-negative integer.

#include <stdio.h>

int main() {
    int n;
    unsigned long long factorial = 1;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        factorial *= i;

    printf("Factorial of %d = %llu\n", n, factorial);
    return 0;
}


Example 7:
Write a C program that:
Accepts two strings as input from the user.
Concatenates the two strings Displays the concatenated result.

#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];

    // Get input from user
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';  // Remove newline character

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';  // Remove newline character

    // Concatenate the strings
    strcat(str1, str2);

    // Display the result
    printf("Concatenated string: %s\n", str1);

    return 0;
}


Example 8:
Write a C program that takes a binary number (as an integer) as input and 
converts it to its decimal equivalent.

#include <stdio.h>

int main() {
    int binary, decimal = 0, base = 1, rem;

    printf("Enter a binary number: ");
    scanf("%d", &binary);

    while (binary > 0) {
        rem = binary % 10;
        decimal += rem * base;
        base *= 2;
        binary /= 10;
    }

    printf("Decimal equivalent: %d\n", decimal);
    return 0;
}


Example 9:
Write a C program that:
Accepts an array of integers from the user.
Finds and displays the maximum and minimum values in the array.

#include <stdio.h>

int main() {
    int n, num, min, max;

    printf("Enter how many numbers you want to input: ");
    scanf("%d", &n);

    printf("Enter number 1: ");
    scanf("%d", &num);
    min = max = num;

    for (int i = 2; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%d", &num);
        if (num < min) min = num;
        if (num > max) max = num;
    }

    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);

    return 0;
}


Example 10:
C program to generate Pascal's Triangle.

Output:
no of rows =5
          1
        1   1
      1   2   1
    1   3   3   1
  1   4   6   4   1
  
#include <stdio.h>

int main() {
    int n;

    // Ask the user for the number of rows
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    // Generate Pascal's Triangle
    for (int i = 0; i < n; i++) {
        int num = 1;  // First element in each row is always 1

        // Print leading spaces for formatting
        for (int space = 0; space < n - i - 1; space++) {
            printf(" ");
        }

        // Calculate and print each number in the row
        for (int j = 0; j <= i; j++) {
            if (j > 0) {
                num = num * (i - j + 1) / j;  // Calculate next number in the row
            }
            printf("%d ", num);
        }

        printf("\n");
    }

    return 0;
}

