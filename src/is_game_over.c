/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_game_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:40:07 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/10 21:02:47 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "field.h"
#include <stdbool.h>
#include <stdio.h>
bool	is_game_over(t_field *field)
{
	for (int x = 0; x < FIELD_WIDTH; x++)
	{
		if (field->terrain[0][x])
			return (true);
	}
	return (false);
}
