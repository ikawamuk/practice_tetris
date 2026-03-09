/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 03:29:32 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 03:30:42 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIELD_H
# define FIELD_H

# include "define.h"
# include "mino.h"

typedef struct
{
	int				terrain[FIELD_HEIGHT][FIELD_WIDTH];
	t_target_mino	target;
}	t_field;

#endif
