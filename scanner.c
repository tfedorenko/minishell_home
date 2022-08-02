/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:56:37 by tfedoren          #+#    #+#             */
/*   Updated: 2022/08/02 21:59:45 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "shell.h"
#include "scanner.h"
#include "source.h"


t_source	*token_buf_ini(t_source *g_token)
{
	g_token->buffer = NULL;
	g_token->bufsize = 0;
	g_token->curpos = -1;
	return (g_token);
}
// char 	*token_buf = NULL;
// int		token_bufsize = 0;
// int		token_bufindex = -1;

// struct s_token eof_token =
// {
// 	eof_token.text_len = 0;
// }
t_token	*eof_token_ini(t_token *eof_token)
{
	eof_token->text_len = 0;
	return (eof_token);
}

void	add_to_buf(char c, t_source *g_token)
{
	char	*tmp;

	g_token->buffer[g_token->curpos++] = c;
	if (g_token->curpos >= g_token->bufsize)
	{
		tmp = realoc(g_token->buffer, (g_token->bufsize) * 2);
		if (!tmp)
		{
			return ;
		}
		g_token->buffer = tmp;
		g_token->bufsize *= 2;
	}
}

t_token	*create_token(char *str)
{
	t_token	*new_token;
	char	*new_str;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
	{
		return (NULL);
	}
	memset(new_token, 0, sizeof(t_token));
	new_token->text_len = strlen(str);
	new_str = malloc(sizeof(char) *(new_token->text_len + 1));
	if (!new_str)
	{
		free(new_token);
		return (NULL);
	}
	strcpy(new_str, str);
	new_token->text = new_str;
	return (new_token);
}

void	free_token(t_token *token)
{
	if (token->text)
	{
		free(token->text);
	}
	free(token);
}

