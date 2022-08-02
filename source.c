/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:15:16 by tfedoren          #+#    #+#             */
/*   Updated: 2022/08/02 15:00:48 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source.h"

/*
 * char	next_char(t_source *src)
 * Returns the next char from input and updates the pointer in src.
 *
 * EOF (defined as -1 in source.h) when we reach the last char of input)
*/

char	next_char(t_source *src)
{
	char	c1;

	if (!src || !src->buffer)
	{
		return (ERRCHAR);
	}
	c1 = 0;
	if (src->curpos == INIT_SRC_POS)
		src->curpos = -1;
	else
		c1 = src->buffer[src->curpos];
	if (++src->curpos >= src->bufsize)
	{
		src->curpos = src->bufsize;
		return (EOF);
	}
	return (src->buffer[src->curpos]);
}

/*
 * char	peek_char(t_source *src)
 * Returns the next char from input and does not update the pointer in src.
 *
 * EOF (defined as -1 in source.h) when we reach the last char of input)
*/

char	peek_char(t_source *src)
{
	long	pos;

	if (!src || !src->buffer)
	{
		return (ERRCHAR);
	}
	pos = src->curpos;
	if (pos >= INIT_SRC_POS)
		pos++;
	pos++;
	if (pos >= src->bufsize)
		return (EOF);
	return (src->buffer[pos]);
}

/*
 * void	skip_white_spaces(t_source *src)
 *
 * Suppose to skip white spaces
*/

void	skip_white_spaces(t_source *src)
{
	char	c;

	if (!src || !src->buffer)
		return ;
	c = peek_char(src);
	while ((c != EOF) && (c == ' ' || c == '\t'))
		next_char(src);
}
