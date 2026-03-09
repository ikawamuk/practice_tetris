/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 02:24:20 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 04:10:33 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

static struct termios	g_old_termios;
static int				g_old_flags;
static int				g_is_initialized;

void	init_input(void)
{
	struct termios	newt;

	if (g_is_initialized)
		return ;
	if (tcgetattr(STDIN_FILENO, &g_old_termios) == -1)
		return ;
	newt = g_old_termios;
	newt.c_lflag &= ~(ICANON | ECHO);
	newt.c_cc[VMIN] = 0;
	newt.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &newt) == -1)
		return ;
	g_old_flags = fcntl(STDIN_FILENO, F_GETFL, 0);
	if (g_old_flags == -1)
		return ;
	if (fcntl(STDIN_FILENO, F_SETFL, g_old_flags | O_NONBLOCK) == -1)
		return ;
	g_is_initialized = 1;
}

void	restore_input(void)
{
	if (!g_is_initialized)
		return ;
	tcsetattr(STDIN_FILENO, TCSANOW, &g_old_termios);
	fcntl(STDIN_FILENO, F_SETFL, g_old_flags);
	g_is_initialized = 0;
}

int	get_ch(void)
{
	unsigned char	c;
	ssize_t			nread;

	if (!g_is_initialized)
		init_input();
	nread = read(STDIN_FILENO, &c, 1);
	if (nread == 1)
		return ((int)c);
	return (-1);
}
