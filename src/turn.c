/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 03:50:31 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/09 22:07:19 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "field.h"
#include <stdbool.h>
#include <poll.h>
#include <time.h>
#include <unistd.h>

void	draw_screen(t_field *field);
void	move(t_field *field);
bool	is_hit_wall(t_field *field);


void	turn(t_field *field)
{
	t_target_mino	last_target;

	while (1)
	{
		draw_screen(field);
		last_target = field->target;
		move(field);
		field->target.y++;
		if (is_hit_wall(field) == true)
		{
			field->target = last_target;
			break ;
		}
	}
}