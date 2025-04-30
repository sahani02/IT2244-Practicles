![Screenshot (176)](https://github.com/user-attachments/assets/528d0096-132c-497a-9c7b-68a894eb1a0c)
![Screenshot (175)](https://github.com/user-attachments/assets/350e7245-35b7-48f1-9695-4e4fb31101c0)
![Screenshot (173)](https://github.com/user-attachments/assets/5139e697-ed56-4bc9-a1e6-e1b3dcc094bb)
![Screenshot (174)](https://github.com/user-attachments/assets/4a6874a3-5cd5-4853-b003-f12f329f2276)
![Screenshot (172)](https://github.com/user-attachments/assets/a41bae06-b0fd-4301-a287-9f4d6d5aac27)
![Screenshot (171)](https://github.com/user-attachments/assets/56cd2103-0909-4b09-aec8-02bf37b4c9ff)
![Screenshot (170)](https://github.com/user-attachments/assets/877b39f0-ef61-4840-a7f1-23e52031cecb)
![Screenshot (169)](https://github.com/user-attachments/assets/60e82a02-c479-4e40-a423-b5399c7cf106)
![Screenshot (168)](https://github.com/user-attachments/assets/7eefabf3-67f7-4196-91fd-cc4d49813c88)
![Screenshot (177)](https://github.com/user-attachments/assets/a5bc1a4b-ebda-4d86-a4a9-036d15bedc04)
![Screenshot 2025-04-30 213752](https://github.com/user-attachments/assets/a017375d-e4c3-454b-a86d-2f9bdf9da533)

    1–3: File Creation and Viewing
    
    1. touch datafile.csv       # Creates an empty file
    2. vi datafile.csv          # Opens the file in vi editor to input data
    3. more datafile.csv        # Displays contents page-by-page
    
    4: Search Operations
    
    4. grep "Engineering" datafile.csv  # search for "Engineering" data
    
    5–6: Line Count & End of File
    
    5. tail -3 datafile.csv     # Last 3 lines of the file
    6. wc -l datafile.csv       # Count of lines (11 total including header)
    
    7–9: Field and Column Operations
    7. awk -F, '{print NF;exit}' datafile.csv    # Number of fields (columns)
    8. awk -F, '{print $3}' datafile.csv         # Print 3rd column (Age)
    9. cut -d, -f3 datafile.csv                  # Same as above using cut
    
    10–12: Subsetting Lines
    
    10. head -n7 datafile.csv           # First 7 lines
    11. head -n7 | tail -n6             # Lines 2 to 7
    12. head -n7 | tail -n1             # Line 7 only
    
    13–15: Column Extraction
    
    13. tail -n3 datafile.csv                  # Last 3 rows
    14. awk -F, '{print $3,$3}' datafile.csv   # 3rd column printed twice
    15. awk -F, '{print $2,$3}' datafile.csv   # 2nd and 3rd column
    
    16–17: Alternate File and Salary Extraction
    
    16. more xyz.csv                           # Shows simpler version of file
    17. awk -F, '{print $4}' datafile.csv      # Prints Salary column
    
    18–23: make decending or accending order
    
    18–23: awk -F, '{print $4-desc}' datafile.csv' 
    
    24–25: Sorting Salary Values
    
    24. awk -F, '{print $4}' datafile.csv | sort     # Ascending salary sort
    25. awk -F, '{print $4}' datafile.csv | sort -r  # Descending
    
    26–33: Sorting by Salary (k4) or Age (k3)
    sort -t',' -k4,4n: Sort by Salary (numeric ascending)
    
    sort -t',' -k3,3n: Sort by Age (numeric ascending)
    
    -r: Reverse sort
    
    -n: Numeric sort
    
    -kX,Y: Sort from field X to Y
    
    Some commands are redundant or incorrectly compounded (like -r -n -r) — only one -r is needed.
    
    34–35: Sort ascending salary, then full reverse
    
    36–37: Sort descending by salary (textually or numerically)
    
    38–39: Compound Sort Keys
    
    38. sort -t',' -k2,4 -r         # Sort by Name, then by Salary in reverse
    39. sort -t',' -k2,2 -k4,4 -r   # Better: sort Name descending, Salary descending
