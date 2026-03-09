/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 04:14:06 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/09 22:50:02 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include <time.h>
#include "define.h"
#include "field.h"
#include <stdbool.h>
#include <stdio.h>


int		get_cuurent_time(struct timespec *timespec);
int64_t	get_elapsed_time(struct timespec *base);
int		get_ch(void);
void	move(t_field *field, int input);
bool	is_hit_wall(t_field *field);
void	draw_screen(t_field *field);

void	moveable(t_field *field)
{
	struct timespec	start;
	int				input;

	get_cuurent_time(&start);
	while (get_elapsed_time(&start) < MS_PER_TURN)
	{
		input = get_ch();
		if (input != -1)
			move(field, input);
	}
}

void	move(t_field *field, int input)
{
	t_target_mino	last_target = field->target;
	if (input == 'a')
		field->target.x--;
	else if (input == 'd')
		field->target.x++;
	else if (input == 's')
		field->target.y < FIELD_HEIGHT ? field->target.y++ : last_target.y;
	if (is_hit_wall(field) == true)
	{
		field->target = last_target;
		return ;
	}
	draw_screen(field);
}
