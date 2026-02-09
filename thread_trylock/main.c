/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 01:37:22 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/05 02:15:46 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

pthread_mutex_t	stoveMutex;
int				gas = 100;

void	*routine(void *arg)
{
	pthread_mutex_lock(&stoveMutex);
	usleep(500000);
	int fuelNeeded = (rand()%50);
	if(gas - fuelNeeded < 0)
	{
		printf("no more gas\n");
	}
	else
	{
		gas -= fuelNeeded;
		printf("Gas left %d\n", gas);
	}
	pthread_mutex_unlock(&stoveMutex);
	return (NULL);
}

int	main(void)
{
	srand(time(NULL));
	pthread_t th[10];
	
	pthread_mutex_init(&stoveMutex, NULL);

	int i = 0;
	while(i < 10)
	{
		if(pthread_create(&(th[i]),NULL,&routine,NULL) != 0)
			perror("Failed to create thread\n");
		i++;
	}
	i = 0;
	while(i < 10)
	{
		pthread_detach(th[i]);
		i++;
	}
	pthread_mutex_destroy(&stoveMutex);
	pthread_exit(NULL);
}