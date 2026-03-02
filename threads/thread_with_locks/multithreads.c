/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithreads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 21:46:55 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/02 22:02:03 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int sum;
pthread_mutex_t lock;

void *routine()
{
	int i;

	i =0;
	while(i< 10000)
	{
		pthread_mutex_lock(&lock);
		sum++;
		pthread_mutex_unlock(&lock);
		i++;
	}
	return (NULL);
}

int main(void)
{
	pthread_t th[8];
	int i;

	i =0;
	while(i < 8)
	{
		pthread_create(&(th[i]), NULL, &routine, NULL);
		printf("Thread %d started. \n", i);
		i++;
	}
	i = 0;
	while(i < 8)
	{
		if(pthread_join(th[i],NULL) != 0)
			return (i);
		printf("Thread %d finish execution\n", i);
		i++;
	}
	// pthread_mutex_destroy(&lock);
	printf("Sum is %d\n", sum);
	return (0);
}