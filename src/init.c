/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 02:30:03 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 03:38:30 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "field.h"
#include "define.h"
#include <stdlib.h>
#include <stdio.h>

void	draw_screen(t_field *field);

void	init(t_field *field)
{
	field->target.mino = minos[rand() % 8];
	field->target.x = (FIELD_WIDTH - 4) / 2;
	field->target.y = 0;
	draw_screen(field);
	return ;
}
