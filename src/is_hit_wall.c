/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hit_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 03:44:27 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 04:19:56 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "field.h"
#include <stdbool.h>

bool	is_hit_wall(t_field *field)
{
	int	fx;
	int	fy;

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (field->target.mino.shape[y][x] == 0)
				continue ;
			fx = field->target.x + x;
			fy = field->target.y + y;
			if (fx < 0 || fx >= FIELD_WIDTH || fy >= FIELD_HEIGHT)
				return (true);
			if (fy >= 0 && field->terrain[fy][fx])
				return (true);
		}
	}
	return (false);
}
