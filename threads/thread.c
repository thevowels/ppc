/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 21:07:08 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/02 21:18:11 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>


void* routine(){
	printf("Test from threadssssssssssssssssssssssssssssssssssssssssss.\n");
	sleep(1);
	printf("Process id %d\n", getpid());
	sleep(1);
	printf("Test from thread.\n");
	return NULL;
}
int main(void)
{
	pthread_t t1, t2;
	if(pthread_create(&t1, NULL, &routine,NULL) != 0)
		exit(EXIT_FAILURE);
	pthread_create(&t2, NULL, &routine,NULL);
	pthread_join(t1,NULL);
	
	return (0);
}