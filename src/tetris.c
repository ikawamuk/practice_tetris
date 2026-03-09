/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 02:04:38 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 03:55:35 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "field.h"
#include <stdio.h>
#include <string.h>


void	init(t_field *field);
void	turn(t_field *field);
void	update_terrain(t_field *field);

int	tetris(void)
{
	t_field	field;
	memset(field.terrain, 0, sizeof(field.terrain));
	printf("\033[2J");
	while (1)
	{
		init(&field);
		turn(&field);
		update_terrain(&field);
	}
	return (0);
}
