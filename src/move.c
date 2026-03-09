/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 04:14:06 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 04:20:21 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "field.h"
#include <stdbool.h>

int		get_ch(void);
bool	is_hit_wall(t_field *field);

static void	rotate_clockwise(t_mino *mino)
{
	int	tmp[4][4];

	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			tmp[x][3 - y] = mino->shape[y][x];
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			mino->shape[y][x] = tmp[y][x];
}

void	move(t_field *field)
{
	t_target_mino last;
	int key;

	key = get_ch();
	if (key == -1)
		return ;
	last = field->target;
	if (key == 'a') field->target.x--;
	else if (key == 'd') field->target.x++;
	else if (key == 's') field->target.y++;
	else if (key == 'w') rotate_clockwise(&field->target.mino);

	if (is_hit_wall(field))
		field->target = last;
}
