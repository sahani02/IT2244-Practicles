- pipe.c

    - This C program demonstrates how to use a pipe to pass messages within a single process.
    
    - It defines three fixed-length messages (msg1, msg2, msg3) of 16 bytes.
    
    - A pipe is created using pipe(p), giving two file descriptors:
    
        - p[1] for writing
            
       - p[0] for reading
        
    - All three messages are written to the pipe using write().
    
    - A loop is used to read the messages from the pipe using read(), and each message is printed with printf().
    
    - Although pipes are usually used between parent and child processes, this code demonstrates basic pipe usage within the same process.

![Screenshot 2025-06-06 141947](https://github.com/user-attachments/assets/d9073912-50c7-4c3d-a00c-fc6b1ead6f4d)

- exercise.c

![Screenshot 2025-06-06 153746](https://github.com/user-attachments/assets/366a7105-61f5-4c2d-9395-4784be506932)

- d20_HW.c

![Screenshot 2025-06-08 233033](https://github.com/user-attachments/assets/fa3a54b6-941c-419c-991f-7a8659a34b1a)
![Screenshot 2025-06-08 233045](https://github.com/user-attachments/assets/86c626c3-b197-46c1-b3e1-410e7a1087f2)
![Screenshot 2025-06-08 233054](https://github.com/user-attachments/assets/6cca150d-fefc-4756-84fb-cf1899da4c96)
