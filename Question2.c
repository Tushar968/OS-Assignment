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
	char str[50], final[50];
	gets(str);
	final=conversion(str);

	
}
