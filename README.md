## OS-Assignment

**Question1:**\
Write a multithreaded program that calculates various statistical values for a list of numbers. 
This program will be passed a series of numbers on the command line and will then create three separate worker threads. 
One thread will determine the average of the numbers, the second will determine the maximum value, and the third will determine the minimum value. 
For example, suppose your program is passed the integers:\
90 81 78 95 79 72 85\
The program will report\
The average value is 82\
The minimum value is 72\
The maximum value is 95\
The variables representing the average, minimum, and maximum values will be stored globally. 
The worker threads will set these values, and the parent thread will output the values once the workers have exited.\
**Note:**\
For compilation: `gcc Question1.c -lpthread`\
To run: `./a.out`

**Question2:**\
Design a program using concepts of inter-process communication ordinary pipes in which one process sends a string message to a second process, 
and the second process reverses the case of each character in the message and sends it back to the first process. 
For example, if the first process sends the message Hi There, the second process will return hI tHERE. 
This will require using two pipes, one for sending the original message from the first to the second process and the other for sending the modified message from the second to the first process. 
You can write this program using either UNIX or Windows pipes.\
**Note:**\
For compilation: `gcc -o Question2 Question2.c`\
To run: `./Question2`
