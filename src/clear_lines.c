/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 23:00:00 by codex             #+#    #+#             */
/*   Updated: 2026/03/09 23:00:00 by codex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "field.h"
#include <stdbool.h>

void	clear_lines(t_field *field)
{
	bool	is_full;

	for (int y = FIELD_HEIGHT - 1; y >= 0; y--)
	{
		is_full = true;
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			if (field->terrain[y][x] == 0)
			{
				is_full = false;
				break ;
			}
		}
		if (is_full == false)
			continue ;
		for (int row = y; row > 0; row--)
			for (int x = 0; x < FIELD_WIDTH; x++)
				field->terrain[row][x] = field->terrain[row - 1][x];
		for (int x = 0; x < FIELD_WIDTH; x++)
			field->terrain[0][x] = 0;
		y++;
	}
}
