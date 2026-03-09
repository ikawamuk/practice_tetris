/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 02:30:03 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/09 23:44:46 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "field.h"
#include "define.h"
#include <stdlib.h>
#include <stdio.h>

void	draw_screen(t_field *field);

void	init(t_field *field)
{
	field->target.mino = minos[rand() % 7];
	field->target.x = (FIELD_WIDTH - 4) / 2;
	field->target.y = 0;
	draw_screen(field);
	// fprintf(stderr, "mino: %d\n", field->target.mino.id);
	return ;
}
