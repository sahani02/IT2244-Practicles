Q1.
![Screenshot (206)](https://github.com/user-attachments/assets/5fb8a2ff-7103-4ecd-ba3d-48e4d737d14f)
![Screenshot (205)](https://github.com/user-attachments/assets/4214d653-c0bd-4398-b0f2-3e1ae5c67c41)
![Screenshot (204)](https://github.com/user-attachments/assets/8d55b81f-e99e-4cdf-8dc6-ecf1182fc026)

Q2.
1. Display rows with GPA > 3.5
2. Calculate average GPA
![Screenshot 2025-05-23 211145](https://github.com/user-attachments/assets/10e55f41-4845-4ea6-9069-85cc68ee5d43)

Q3.

✅read -p "Enter String1: " String_1
  Prompts the user to input the first string.
  Stores the input in a variable called String_1.

✅ read -p "Enter String2: " String_2
  Prompts the user to input the second string.
  Stores it in String_2.

✅ len1=${#String_1}
   Calculates the length (number of characters) in String_1.
   Stores it in len1.

✅ len2=${#String_2}
   Calculates the length of String_2.
   Stores it in len2.

✅ if (( len1 > len2 )); then
   Checks if len1 (length of String_1) is greater than len2.

✅ echo $String_1 "is larger than " $String_2
   If the first string is longer, it prints that String_1 is larger.

✅ else
   If len1 is not greater than len2, it assumes String_2 is larger.

✅ echo $String_2  "is larger than" $String_1
   Prints that String_2 is larger.

✅ fi
   Ends the if condition.
   
   ![Screenshot 2025-05-23 210929](https://github.com/user-attachments/assets/9d0513fd-082b-42fb-846b-30f2dbd83c60)


