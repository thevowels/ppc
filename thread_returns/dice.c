/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dice.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 22:10:29 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/02 22:17:57 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *roll_dice(){
	int *result;

	result = malloc(sizeof(int));
	
	*result = (rand() % 6) + 1;

	return (result);
}

int main(void)
{
	int *res;
	pthread_t th;

	srand(time(NULL));
	pthread_create(&th,NULL,&roll_dice,NULL);
	pthread_join(th,(void **)&res);
	printf("We got %d on this roll\n", *res);
	free(res);
	return(EXIT_SUCCESS);
}