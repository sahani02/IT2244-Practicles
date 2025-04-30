    Step 1: Read Input
    
    read -p "Enter number a: " a
    read -p "Enter number b: " b
    read -p "Enter number c: " c
    Prompts the user to enter three numbers.
    
    Stores them in variables: a, b, and c.
    
    Step 2: Define gcd() Function
    
    gcd() {
      while [ $2 -ne 0 ]; do
        temp=$2
        set -- $2 $(( $1 % $2 ))
      done
      echo $1
    }
    This is a Bash function to compute GCD (Greatest Common Divisor) using the Euclidean Algorithm.
    
    set -- changes the positional parameters to the next pair: (b, a % b)
    
    When the second number becomes 0, the first one is the GCD.
    
    Step 3: Calculate LCM of a and b
    
    g=$(gcd $a $b)
    lcm=$(( a * b / g ))
    First calculates the GCD of a and b and stores it in g.
    
    Then uses the formula:
    LCM = (a × b) / GCD
    
    Step 4: Output LCM and GCD
    
    echo "LCM of $a and $b is: $lcm"
    echo "GCD of $b and $c is: $(gcd $b $c)"
    Displays the LCM of the first two inputs.
    
    Calculates and displays the GCD of the second and third inputs.

![Screenshot (190)](https://github.com/user-attachments/assets/fe105925-d414-4289-9a54-7479ab6fdb0e)



