/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 22:25:31 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/05 00:52:57 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

int primes[10] = {2,3,5,7,11,13,17,19,23,29};

void *routine(void *arg)
{
	sleep(1);
	int value = *(int *)arg;
	printf("%d ", value);
	return (NULL);
}

int main(void)
{
	pthread_t th[10];
	int i;
	while(i < 10)
	{
		pthread_create(&th[i],NULL, &routine, &(primes[i]));
		i++;
	}
	i =0;
	while(i < 10)
	{
		pthread_join(th[i], NULL);
		i++;
	}
}