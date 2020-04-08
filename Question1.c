#include<stdio.h>
#include<pthread.h>

int size=0;
int average=0;
int maximum=0;
int minimum=0;

void *thread1(void *arg)
{
	int *arr=(int*)arg;
	int min_num=arr[0];
	for(int i=0; i<size; i++)
	{
		if(min_num>arr[i])
		{
			min_num=arr[i];
		}
	}
	minimum=min_num;
	pthread_exit(NULL);
}
void *thread2(void *arg)
{
	int *arr=(int *)arg;
	int max_num=arr[0];
	for(int i=0; i<size; i++)
	{
		if(max_num<arr[i])
		{
			max_num=arr[i];
		}
	}
	maximum=max_num;
	pthread_exit(NULL);
}
void *thread3(void *arg)
{
	int *arr=(int *)arg;
	int sum=0;
	for(int i=0; i<size; i++)
	{
		sum=sum+arr[i];
	}
	average=sum/size;
	pthread_exit(NULL);
}
int main()
{
	pthread_t th1;
	pthread_t th2;
	pthread_t th3;
	int buffer[50];
	int num;
	printf("Enter total count of numbers:");
	scanf("%d",&num);
	size=num;
	printf("Enter numbers:\n");
	for( int i=0; i<num; i++)
	{
		scanf("%d",&buffer[i]);
	}

	pthread_create(&th1,NULL,thread1,(void*)&buffer);
	pthread_create(&th2,NULL,thread2,(void*)&buffer);
	pthread_create(&th3,NULL,thread3,(void*)&buffer);

	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	pthread_join(th3,NULL);

	printf("Minimum number is: %d\n", minimum);
	printf("Maximum number is: %d\n", maximum);
	printf("Average value is: %d\n", average);
}
