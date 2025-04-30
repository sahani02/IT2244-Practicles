

    Q1.Print multiplication table of 2
      num=2: Fixed number for which table is generated.
      Loop from 1 to 12.
      mul=$(($num*$i)): Computes the product of num and current value of i.
      echo: Prints in the format i x num = result.
![Screenshot (185)](https://github.com/user-attachments/assets/a418e1c0-b085-4a26-b92d-61b7fbc0282b)

    Q2.Print diamond star pattern
      rows=5: Controls the height of top and bottom triangles.
      Top half:
      Spaces decrease.
      Stars increase by odd numbers (1, 3, 5...).
      Bottom half:
      Reverse of top.
      echo -n is used to avoid newlines within each row.
![Screenshot (186)](https://github.com/user-attachments/assets/fde0e540-a537-48e6-815a-466ff3502a86)

    Q3.Print Hollow squre star pattern
      Outer border (i == 1, i == rows, j == 1, or j == cols) is filled with *.
      Inside is filled with spaces.
      Forms a hollow square.
![Screenshot (187)](https://github.com/user-attachments/assets/5591ac7c-3729-4f5d-8757-68bb30cf0fcd)

    Q4.Fibonacci series and sum of first 10 terms
![Screenshot (188)](https://github.com/user-attachments/assets/cb8228df-20e2-4877-ad0d-835a166c4e78)

    Q5.Sum of Prime Numbers Between 1 and 100
      Iterates through numbers 2 to 100.
      Checks if each is prime by testing for divisibility up to √num.
      If prime, adds to sum.
      Final sum is printed.
![Screenshot (189)](https://github.com/user-attachments/assets/0322dfc1-5804-4828-9037-742d3315aefe)
