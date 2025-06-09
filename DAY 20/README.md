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

![Screenshot 2025-06-09 121218](https://github.com/user-attachments/assets/360da485-4d1a-4573-a586-986f0ab9a9af)

