1.Script Functionality:
This script performs basic arithmetic operations (addition, subtraction, multiplication, and division) on two numbers entered by the user via the terminal.

Script Breakdown:

    Prompt user to enter the first number:
    
    echo "Enter number 1: "
    read x
    Displays the message Enter number 1:
    
    read x takes input from the user and stores it in variable x.
    
    Prompt user to enter the second number:
    
    echo "Enter number 2: "
    read y
    Displays the message Enter number 2:
    
    read y stores the input in variable y.
    
    Perform addition:
  
    addition=$(($x + $y))
    Calculates the sum of x and y and stores it in the variable addition.
    
    Perform subtraction:
    
    substraction=$(($x - $y))
    Calculates x minus y.
    
    Perform multiplication:
    
    multiplication=$(($x * $y))
    Calculates x times y.
    
    Perform division:
    
    division=$(($x / $y))
    Calculates x divided by y (integer division; decimals will be truncated).
    
    Display the results:
    
    echo "Addition: $addition"
    echo "Substraction: $substraction"
    echo "Multiplication: $multiplication"
    echo "Division: $division"
    Outputs the results of each operation.

![Screenshot 2025-04-30 151034](https://github.com/user-attachments/assets/14367ac0-2316-47e1-9a7e-7e1b100606d8)

2.Script Functionality:
This script asks for the user's name and three numbers, then calculates the sum and average of those numbers, and prints a personalized greeting.

Script Breakdown:

    Ask for the user's name:
    
    echo "Who are you?"
    read name
    Prompts the user and stores their input in the variable name.
    
    Ask for three numbers:
    
    echo "Enter Number 1"
    read x
    echo "Enter Number 2" 
    read y
    echo "Enter Number 3"
    read z
    Each prompt reads one number and stores it in x, y, and z respectively.
    
    Calculate the sum:
    
    sum=$(($x + $y + $z))
    Adds the three numbers and stores the result in sum.
    
    Calculate the average:
    
    avg=$((sum/3))
    Divides the sum by 3 (integer division) and stores it in avg.
    
    Display the results:
    
    echo "Hi" $name
    echo "Summation: $sum" 
    echo "Average: $avg"
    Greets the user by name and displays the calculated sum and average.

![Screenshot (167)](https://github.com/user-attachments/assets/e7d66c22-1060-4fb1-9108-babbd392a59a)

