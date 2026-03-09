/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 03:50:31 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/09 23:24:39 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "field.h"
#include "define.h"
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

void	draw_screen(t_field *field);
void	moveable(t_field *field);
bool	is_hit_ground(t_field *field);
int		get_ch(void);
void	move(t_field *field, int input);
int		get_cuurent_time(struct timespec *timespec);
int64_t	get_elapsed_time(struct timespec *base);

static bool	is_grounded(t_field *field)
{
	t_target_mino	current_target;

	current_target = field->target;
	field->target.y++;
	if (is_hit_ground(field) == true)
	{
		field->target = current_target;
		return (true);
	}
	field->target = current_target;
	return (false);
}

static void	lock_delay(t_field *field)
{
	struct timespec	start;
	int				input;

	get_cuurent_time(&start);
	while (get_elapsed_time(&start) < LOCK_DELAY_MS)
	{
		input = get_ch();
		if (input == -1)
			continue ;
		move(field, input);
		if (is_grounded(field) == false)
			return ;
	}
}

void	phase(t_field *field)
{
	while (1)
	{
		draw_screen(field);
		moveable(field);
		if (is_grounded(field) == true)
			lock_delay(field);
		if (is_grounded(field) == true)
			break ;
		field->target.y++;
	}
}
