/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_terrain.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 03:51:20 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 03:54:10 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "field.h"
#include <stdbool.h>
#include <unistd.h>

void	update_terrain(t_field *field)
{
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			if (field->target.mino.shape[y][x])
				field->terrain[field->target.y + y][field->target.x + x] = 1;
}