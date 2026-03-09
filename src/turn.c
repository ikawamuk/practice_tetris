/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 03:50:31 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 04:24:22 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "field.h"
#include <stdbool.h>
#include <poll.h>
#include <time.h>
#include <unistd.h>

void	draw_screen(t_field *field);
bool	is_hit_wall(t_field *field);
void	move(t_field *field);

static long long	now_ms(void)
{
	struct timespec	ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	return ((long long)ts.tv_sec * 1000LL + (long long)ts.tv_nsec / 1000000LL);
}

void	turn(t_field *field)
{
	t_target_mino	last_target;
	long long		next_drop_ms;
	long long		current_ms;
	int				wait_ms;
	struct pollfd	input_fds[1];

	input_fds[0].fd = STDIN_FILENO;
	input_fds[0].events = POLLIN;
	next_drop_ms = now_ms() + 500;
	while (1)
	{
		draw_screen(field);
		current_ms = now_ms();
		wait_ms = (int)(next_drop_ms - current_ms);
		if (wait_ms < 0)
			wait_ms = 0;
		if (poll(input_fds, 1, wait_ms) > 0)
			move(field);
		current_ms = now_ms();
		if (current_ms < next_drop_ms)
			continue ;
		last_target = field->target;
		field->target.y++;
		if (is_hit_wall(field) == true)
		{
			field->target = last_target;
			break ;
		}
		next_drop_ms = current_ms + 500;
	}
}
