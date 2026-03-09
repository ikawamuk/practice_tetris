/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cuurent_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:00:00 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/09 22:11:51 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <stdint.h>

int64_t	get_ms(struct timespec *timespec);

int	get_cuurent_time(struct timespec *timespec)
{
	if (clock_gettime(CLOCK_MONOTONIC, timespec) == -1)
		return (-1);
	return (0);
}

int64_t	get_elapsed_time(struct timespec *base)
{
	struct timespec	cuurent;
	get_cuurent_time(&cuurent);
	int64_t	sec = (int64_t)cuurent.tv_sec - (int64_t)base->tv_sec;
	int64_t	nsec = (int64_t)cuurent.tv_nsec - (int64_t)base->tv_nsec;
	return (sec * 1000LL + nsec / 1000000LL);
}

int64_t	get_ms(struct timespec *timespec)
{
	int64_t	sec = (int64_t)timespec->tv_sec;
	int64_t	nsec = (int64_t)timespec->tv_nsec;
	return (sec * 1000LL + nsec / 1000000LL);
}
