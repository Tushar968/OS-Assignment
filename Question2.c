#include<stdio.h>
#include<unistd.h>

int main()
{
	int pipe1[2], pipe2[2];
	int status1, status2;
	int pid;
	char message1[50];
	char message2[50]={'\0'};
	printf("Enter the string message:");
	fgets(message1, 50, stdin);

	char read_message[50];

	//Changing the case of characters
	int ascii=0;
	for(int i=0; i<sizeof(message1); i++)
	{
		ascii=(int)message1[i];
		if(ascii>=97 && ascii<=122)
		{
			ascii=ascii-32;
			message2[i]=(char)ascii;
		}
		else if(ascii>=65 && ascii<=90)
		{
			ascii=ascii+32;
			message2[i]=(char)ascii;
		}
		else
			message2[i]=(char)ascii;
	}

	printf("Parent process with pid = %d and ppid = %d\n\n", getpid(), getppid());

	status1 = pipe(pipe1);
	if (status1 == -1)
	{
		printf("Unable to create pipe 1\n");
		return 1;
	}

	status2 = pipe(pipe2);
	if (status2==-1)
	{
		printf("Unable to create pipe 2\n");
		return 1;
	}

	//Creating two processes
	pid = fork();

	if (pid!=0)
		{
			//Parent Process (first process)
			close(pipe1[0]);
			close(pipe2[1]);
			printf("Message sent through pipe 1 in first process (pid = %d and ppid = %d): %s\n", getpid(), getppid(), message1);
			write(pipe1[1], message1, sizeof(message1));
			read(pipe2[0], read_message, sizeof(read_message));
			printf("Message received from pipe 2 in first process (pid = %d and ppid = %d): %s\n", getpid(), getppid(), read_message);
		}
	else
		{
			//Child Process (Second process)
			close(pipe1[1]);
			close(pipe2[0]);
			read( pipe1[0], read_message, sizeof(read_message));
			printf("Message received from pipe 1 in second process (pid = %d and ppid = %d): %s\n", getpid(), getppid(), read_message);
			printf("Message sent through pipe 2 in second process (pid = %d and ppid = %d): %s\n", getpid(), getppid(), message2);
			write(pipe2[1], message2, sizeof(message2));
		}
	return 0;
}
