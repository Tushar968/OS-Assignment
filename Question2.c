#include<stdio.h>
#include<unistd.h>

char conversion(char str_org[50])
{
	char str_final[50]={'\0'};
	int ascii_value=0;
	for (int i=0; i<strlen(str_org); i++)
	{
		ascii_value = (int)str_org[i];
		if (ascii_value>=97 && ascii_value<=122)
		{
			ascii_value = ascii_value-32;
			str_final[i] = (char)ascii_value;
		}
		else if (ascii_value>=65 && ascii_Value<=90)
		{
			ascii_value = ascii_value+32;
			str_final[i] = (char)ascii_value;
		}
		else
			str_final[i] = (char)ascii_value;
	}
	return str_final;
}
int main()
{
	int pipefds1[2], pipefds2[2];
	int returnstatus1, returnstatus2;
	int pid;
	char message1[50], message2[50];
	gets(str);

	char read_message[50];

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
}
