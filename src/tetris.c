/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 02:04:38 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/09 17:48:52 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "field.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void	init(t_field *field);
void	turn(t_field *field);
void	update_terrain(t_field *field);
bool	is_game_over(t_field *field);
void	init_input(void);
void	restore_input(void);

int	tetris(void)
{
	t_field	field;

	init_input();
	memset(field.terrain, 0, sizeof(field.terrain));
	printf("\033[2J");
	while (1)
	{
		init(&field);
		turn(&field);
		update_terrain(&field);
		if (is_game_over(&field))
			break ;
	}
	printf("GAME OVER\n");
	restore_input();
	return (0);
}
