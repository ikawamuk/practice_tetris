/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 02:30:03 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/10 00:03:10 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "field.h"
#include "define.h"
#include <stdlib.h>
#include <stdio.h>

void	draw_screen(t_field *field);

static void	refill_pool(t_mino *pool, int *pool_size)
{
	t_mino	tmp;
	int		j;

	for (int i = 0; i < 7; i++)
		pool[i] = minos[i];
	for (int i = 6; i > 0; i--)
	{
		j = rand() % (i + 1);
		tmp = pool[i];
		pool[i] = pool[j];
		pool[j] = tmp;
	}
	*pool_size = 7;
}

void	init(t_field *field)
{
	static t_mino	pool[7];
	static int		pool_size = 0;

	if (pool_size == 0)
		refill_pool(pool, &pool_size);
	field->target.mino = pool[--pool_size];
	field->target.x = (FIELD_WIDTH - 4) / 2;
	field->target.y = 0;
	draw_screen(field);
}
