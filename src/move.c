/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 04:14:06 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/10 20:21:20 by ikawamuk         ###   ########.fr       */
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
;static void	hard_drop(t_field *field);

static void	rotate_left(t_field *field)
{
	int	new_shape[4][4];

	// TODO かべにりんせつしているときに、壁キックを入れる必要がある！
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			new_shape[y][x] = field->target.mino.shape[x][3 - y];
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			field->target.mino.shape[y][x] = new_shape[y][x];
}

static void	rotate_right(t_field *field)
{
	int	new_shape[4][4];

	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			new_shape[y][x] = field->target.mino.shape[3 - x][y];
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			field->target.mino.shape[y][x] = new_shape[y][x];
}

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
	if (input == 'a') field->target.x--;
	else if (input == 'd') field->target.x++;
	else if (input == 's') field->target.y++;
	else if (input == 'q') rotate_left(field);
	else if (input == 'e') rotate_right(field);
	else if (input == 'w') hard_drop(field);
	else if (input == 'f') {} // hold;
	if (is_hit_wall(field) == true)
	{
		field->target = last_target;
		return ;
	}
	draw_screen(field);
}

static void	hard_drop(t_field *field)
{
	t_target_mino	last_target;
	while (is_hit_wall(field) == false)
	{
		last_target = field->target;
		field->target.y++;
	}
	field->target = last_target;
	return ;
}

