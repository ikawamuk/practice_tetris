/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mino.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 01:48:35 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 03:29:18 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINO_H
# define MINO_H

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

typedef struct
{
	enum e_mino	id;
	int			shape[4][4];
}	t_mino;

extern const t_mino	minos[];

typedef struct
{
	int		x;
	int		y;
	t_mino	mino;
}	t_target_mino;

#endif
