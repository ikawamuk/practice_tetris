/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 02:20:06 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/10 21:10:08 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "field.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

void	print_next(void);
void	print_hold(t_field *field);
void	print_key_config(void);

void	draw_screen(t_field *field)
{
	int	screen[FIELD_HEIGHT][FIELD_WIDTH];
	memmove(screen, field->terrain, sizeof(screen));
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			if (field->target.mino.shape[y][x])
				screen[field->target.y + y][field->target.x + x] = 1;
	printf("\033[H\n");
	print_hold(field);
	print_next();
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
	print_key_config();
	printf("\n");
	
}

void	print_key_config(void)
{
	printf("A:← D:→ S:soft drop W:hard drop Q:left rotate E:right rotate F:hold");
}

static const char mino_char_table[] = "IOSZJLT";

void	print_hold(t_field *field)
{
	printf("HOLD: ");
	if (field->hold.has_hold)
		printf("%c", mino_char_table[field->hold.mino.id]);
	printf("\n");
}

void	get_nexts(t_mino nexts[3]);
/*
enum e_mino
{
	I_MINO,
	O_MINO,
	S_MINO,
	Z_MINO,
	J_MINO,
	L_MINO,
	T_MINO
};
*/
void	print_next(void)
{
	t_mino	nexts[3];

	get_nexts(nexts);
	printf("NEXT: %c %c %c\n",
		mino_char_table[nexts[0].id],
		mino_char_table[nexts[1].id],
		mino_char_table[nexts[2].id]);
}
