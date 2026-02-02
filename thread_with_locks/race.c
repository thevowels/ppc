/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   race.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 21:22:56 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/02 21:42:53 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <pthread.h>


int mails = 0;
pthread_mutex_t lock;

void *routine(){
	for(int i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock(&lock);
		mails++;
		pthread_mutex_unlock(&lock);
	}
	return (NULL);
}

int main(void)
{
	pthread_t t1, t2;
	pthread_mutex_init(&lock, NULL);
	pthread_create(&t1,NULL,&routine,NULL);
	pthread_create(&t2,NULL,&routine, NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("Mail: %d\n", mails);
	return (0);
}