/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:12:52 by tfedoren          #+#    #+#             */
/*   Updated: 2022/08/25 18:21:52 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int special_char_handler(t_list_lexer *tokens, const char *line, int i, int *t);
// int word_handler(t_list_lexer *tokens, const char *line, int i, int *t);
// int char_handler(t_list_lexer *tokens, const char *line, int *i);
// int	quotes_handler(t_list_lexer *tokens, const char *line, int i, int *t);
// int	find_special(char c);

int	lexer(t_list_lexer *tokens, const char *line, int *f)
{
	int	i;

	i = 0;

	while (line && line[i])
	{

		ft_printf("test3\n");
		printf("%d Zium\n", *f);
		if (line[i] && find_space(line[i]) && push_to_list(tokens, SEP, NULL, f))
		{
			// push_to_list(tokens, SEP, NULL, f);
			write (1, "error1\n", 7);
			return (1);
		}
		while (line[i] && find_space(line[i]))
			i++;
		if (char_handler(tokens, line, &i, f))
			return (1);
	}
	return (0);
}

int char_handler(t_list_lexer *tokens, const char *line, int *i, int *f)
{
	int t;
	if (line[*i] == '\'' || line[*i] == '\"')
	{
		if (quotes_handler(tokens, line, *i, &t, f))
		{
			write(1, "error2\n", 7);
			return (1);			
		}
		if (t == 0)
		{
			write(1, "error: unclosed quotes\n", 23);
			return (1);			
		}

		*i += t + 1;
	}
	else if (line[*i] && find_special(line[*i]))
	{
		if (special_char_handler(tokens, line, *i, t, f))
		{
			return(1);
		}
		*i += t + 1;
	}
	else if (line[*i])
	{
		if (word_handler(tokens, line, *i, &t, f))
		{
			write(1, "error3\n", 7);
			return (1);
		}
		*i +=t;
	}
	printf("Halp god\n");
	printf("Halp god%d\n",tokens->key);


	return (0);
}

int	get_type(const char *line, int i)
{
	if (line[i] == '|')
		return (PIPE);
	if (line[i] == '>' && line[i + 1] && line[i + 1] == '>')
		return (REDIR_APPEND);
	if (line[i] == '>')
		return (REDIR_OUT);
	if (line[i] == '<' && line[i + 1] && line[i + 1] == '<')
		return (REDIR_SOURCE);
	if (line[i] == '<')
		return (REDIR_IN);
	return (NCONST);
}

/**returns i if qoutes finded and 0 if not**/

int	find_quote(const char *line, char quote)
{
	int	i;

	i = 1;
	while (line[i])
	{
		if (line[i] == quote)
			return (i);
		i++;
	}
	return (0);
}

int	find_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\r' \
					|| c == '\v' || c == '\f')
		return (c);
	return(c);
}

int	find_special(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (c);
	return(c);
}

int	quotes_handler(t_list_lexer *tokens, const char *line, int i, int *t, int *f)
{
	char	*substring;
	int		key_word;

	*t = find_quote(line + i, line[i]);
	if (*t == 0)
		return (*t);
	substring = ft_substr(line, i + 1, *t - 1);
	if (substring == NULL)
		return (1);
	if (line[i] == '\'')
		key_word = INSIDE_SQ;
	if (line[i] == '\"')
		key_word = INSIDE_DQ;
	if ( push_to_list(tokens, key_word, substring, f))
	{
		free(substring);
		return (1);
	}
	return (0);
}

int word_handler(t_list_lexer *tokens, const char *line, int i, int *t, int *f)
{
	char	*substring;

	*t = 0;
	while (line[i + *t] && !find_space(line[i + *t]) \
			&& !find_special(line[i + *t]) && \
			line[i + *t] != '\'' && line[i + *t] != '\"')
		++(*t);
	substring = ft_substr(line, i, *t);
	if (substring == NULL)
		return (1);
	if (push_to_list(tokens, WORD, substring, f))
		return (1);
	return (0);
}

int special_char_handler(t_list_lexer *tokens, const char *line, int i, int t, int *f)
{
	t = get_type(line, i);
	if (t == NCONST)
	{
		write (1, "error: wrong input\n", 19);
		return (1);
	}
	if (push_to_list(tokens, (t), NULL, f))
	{
		write(1, "error4\n", 7);
		return (1);
	}
	t = (t == REDIR_APPEND || t == REDIR_SOURCE);
	return (0);
}
