#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int primes[10] = {2,3,5,7,11,13,17,19,23,29};
void *routine(void *arg)
{
	int *sum;
	int i;
	i = 0;
	sum = malloc(sizeof(int));
	*sum = 0;
	while(i < 5)
	{
		*sum += ((int *)arg)[i];
		i++;
	}
	return sum;
}

int main(void)
{
	pthread_t th[2];
	int i;

	i = 0;
	while(i < 2)
	{
		int a;
		a = i * 5;
		if(pthread_create(&th[i], NULL, &routine,&primes[a]) != 0)
		{
			perror("Failed to create a thread");
		}
		i++;
	}
	int globalSum = 0;
	int *partialSum;
	i = 0;
	while(i < 2)
	{
		pthread_join(th[i],(void **)&partialSum);
		globalSum += *partialSum;
		i++;
	}
	printf("Total sum is %d\n", globalSum);
}
