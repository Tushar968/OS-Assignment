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
	int *a=&minimum;
	pthread_exit(a);
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
	int *b=&maximum;
	pthread_exit(b);
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
	int *c = &average;
	pthread_exit(c);
}
int main()
{
	pthread_t th1;
	pthread_t th2;
	pthread_t th3;
	void *ptr1_return;
	void *ptr2_return;
	void *ptr3_return;
	int buffer[50];
	int num;
	int min,max,avg;
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

	pthread_join(th1,&ptr1_return);
	min= *((int*)ptr1_return);

	pthread_join(th2,&ptr2_return);
	max= *((int*)ptr2_return);

	pthread_join(th3,&ptr3_return);
	avg= *((int*)ptr3_return);

	printf("Minimum number is: %d\n", min);
	printf("Maximum number is: %d\n", max);
	printf("Average value is: %d\n", avg);
}
