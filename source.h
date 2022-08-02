/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:15:24 by tfedoren          #+#    #+#             */
/*   Updated: 2022/08/02 15:00:55 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOURCE_H
# define SOURCE_H

# define EOF (-1)
# define ERRCHAR (0)
# define INIT_SRC_POS (-2)

/*	*buffer - pointer to input string;
	bufsize - size of input string;
	curpos - our current position in a string (from where we'll get the next char)
*/

typedef struct s_source
{
	char	*buffer;
	long	bufsize;
	long	curpos;
}	t_source;

char	next_char(t_source *src);
char	peek_char(t_source *src);
void	skip_white_spaces(t_source *src);

#endif