/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 02:20:06 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 03:36:50 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "field.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

void	draw_screen(t_field *field)
{
	int	screen[FIELD_HEIGHT][FIELD_WIDTH];
	memmove(screen, field->terrain, sizeof(screen));
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			if (field->target.mino.shape[y][x])
				screen[field->target.y + y][field->target.x + x] = 1;
	printf("\033[H\n");
	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		printf(WALL_LITERAL);
		for (int x = 0; x < FIELD_WIDTH; x++)
			printf(screen[y][x] ? BLOCK_LITERAL : SPACE_LITERAL);
		printf(WALL_LITERAL);
		printf("\n");
	}
	for (int x = 0; x < FIELD_WIDTH + 2; x++)
		printf(WALL_LITERAL);
	printf("\n");
}
