/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   race.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 21:22:56 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/02 21:30:22 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <pthread.h>


int mails = 0;

void *routine(){
	for(int i = 0; i < 10000; i++)
	{
		mails++;
	}
	return (NULL);
}

int main(void)
{
	pthread_t t1, t2;
	pthread_create(&t1,NULL,&routine,NULL);
	pthread_create(&t2,NULL,&routine, NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("Mail: %d\n", mails);
	return (0);
}