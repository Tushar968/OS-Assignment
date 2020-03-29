#include<stdio.h>
#include<unistd.h>

int main()
{
	int pipefds1[2], pipefds2[2];
	int returnstatus1, returnstatus2;
	int pid;
	char message1[50];
	char message2[50]={'\0'};
	fgets(message1, 50, stdin);

	char read_message[50];

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


	returnstatus1= pipe(pipefds1);

	if (returnstatus1==-1)
	{
		printf("Unable to create pipe 1\n");
		return 1;
	}

	returnstatus2 = pipe(pipefds2);

	if (returnstatus2==-1)
	{
		printf("Unable to create pipe 2");
		return 1;
	}

	pid = fork();
	if (pid!=0)
		{
			close(pipefds1[0]);
			close(pipefds2[1]);
			printf("In parent: Writing to pipe 1 - Message is %s\n", message1);
			write(pipefds1[1], message1, sizeof(message1));
			read(pipefds2[0], read_message, sizeof(read_message));
			printf("In parent: Reading from pipe 2 - Message is %s\n", read_message);
		}
	else
		{
			close(pipefds1[1]);
			close(pipefds2[0]);
			read( pipefds1[0], read_message, sizeof(read_message));
			printf("In child: Reading from pipe 1 - Message is %s\n", read_message);
			printf("In child: Writing to pipe 2 - Message is %s\n", message2);
			write(pipefds2[1], message2, sizeof(message2));
		}
	return 0;
}
