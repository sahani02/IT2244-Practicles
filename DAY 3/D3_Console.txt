:: Disable command showing in the result
@echo off  

:: Display the full current system date  
echo %date%  

:: Extract and display the month from the system date (starting at position 4 with a length of 2)  
echo Month: %date:~4,2%  

:: Extract and display the day from the system date (starting at position 7 with a length of 2)  
echo Day: %date:~7,2%  

:: Extract and display the year from the system date (starting at position 10 with a length of 4)  
echo Year: %date:~10,4%  

:: Extract and display the weekday from the system date (starting at position 0 with a length of 3)  
echo Weekday: %date:~0,3%  

:: Pause execution until the user presses a key  
pause  
