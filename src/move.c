/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 04:14:06 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/09 22:11:39 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 199309L
#include <stdint.h>
#include <time.h>
#include "define.h"
#include "field.h"
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

int		get_cuurent_time(struct timespec *timespec);
int64_t	get_elapsed_time(struct timespec *base);
int64_t	get_ms(struct timespec *timespec);
int		get_ch(void);

void	move(t_field *field)
{
	struct timespec	start;
	int				input;

	get_cuurent_time(&start);
	while (get_elapsed_time(&start) < MS_PER_TURN)
	{
		input = get_ch();
		if (input != -1)
			printf("get char %c\n", input);
	}
	(void)field;
}
