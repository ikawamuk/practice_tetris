/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 02:30:03 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/10 22:04:03 by ikawamuk         ###   ########.fr       */
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

t_mino	push_pool(void);
t_mino	*get_pool(void);


void	init(t_field *field)
{
	field->target.mino = push_pool();
	field->target.x = (FIELD_WIDTH - 4) / 2;
	field->target.y = 0;
	draw_screen(field);
}

typedef struct s_pool
{
	t_mino	pool[7];
	int		pool_size;
}t_pool;

static t_pool	active_pool = {0};
static t_pool	backup_pool = {0};

static void	switch_pool(void)
{
	t_pool	tmp_pool;

	tmp_pool = active_pool;
	active_pool = backup_pool;
	backup_pool = tmp_pool;
}

static void	ensure_backup_filled(void)
{
	if (backup_pool.pool_size == 0)
		refill_pool(backup_pool.pool, &backup_pool.pool_size);
}

t_mino	push_pool(void)
{
	if (active_pool.pool_size == 0)
	{
		ensure_backup_filled();
		switch_pool();
	}
	return (active_pool.pool[--active_pool.pool_size]);
}

void	get_nexts(t_mino nexts[3])
{
	int	idx;
	int	i;

	idx = 0;
	for (i = active_pool.pool_size - 1; i >= 0 && idx < 3; i--)
		nexts[idx++] = active_pool.pool[i];
	if (idx < 3)
	{
		ensure_backup_filled();
		for (i = backup_pool.pool_size - 1; i >= 0 && idx < 3; i--)
			nexts[idx++] = backup_pool.pool[i];
	}
}

t_mino	*get_pool(void)
{
	return (active_pool.pool);
}
