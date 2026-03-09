/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 04:14:06 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/09 18:07:53 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "field.h"
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

int		get_ch(void);

void	move(t_field *field)
{
	int	time_count = 0;
	int	input;
	while (time_count < TIME_PER_TURN)
	{
		input = get_ch();
		if (input != -1)
		{
			printf("get char %c\n", input);
		}
		usleep(10);
		time_count++;
	}
	(void)field;
}
