/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removing_qoutes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:08:41 by tfedoren          #+#    #+#             */
/*   Updated: 2022/08/23 18:34:34 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "minishell.h"


int	delete_quote(char *str, int i, char quote)
{
	if (inside_diff(str, i, quote) && !inside_same(str, i, quote))
		return (0);
	else
		return (1);
}

int	quote_we_count(char *str, int i, char search)
{
	if (str[i] == search)
	{
		if (!inside_diff(str, i, str[i]) && !inside_same(str, i, str[i]))
			return (1);
	}
	return (0);
}

int	inside_same(char *line, int pos, char quote)
{
	int	qq_num;
	int	i;

	i = 0;
	qq_num = 0;
	while (i < pos)
	{
		if (quote_we_count(line, i, quote))
			qq_num++;
		i++;
	}
	if (qq_num % 2 == 1)
		return (1);
	return (0);
}

int	inside_diff(char *line, int pos, char quote)
{
	int		num;
	int		i;
	char	diff_quote;

	if (quote == SINGLE_QOUTE)
		diff_quote = DOUBLE_QUOTE;
	else if (quote == DOUBLE_QUOTE)
		diff_quote = SINGLE_QOUTE;
	else
		return (0);
	i = 0;
	num = 0;
	while (i < pos)
	{
		if (quote_we_count(line, i, diff_quote))
			num++;
		i++;
	}
	if (num % 2 == 1)
		return (1);
	return (0);
}

void	copystuff(char *temp, char *src, int *i, int *y)
{
	temp[*y] = src[*i];
	(*y)++;
	(*i)++;
}

char *strcpywithout(char *src, int len, int i, int y)
{
	char *temp2;
	int quote;

	quote = 0;
	temp2 = ft_calloc(1, len+1);
	while (src[i])
	{
		if (src[i] == SINGLE_QOUTE || src[i] == DOUBLE_QUOTE)
		{
			quote = src[i];
			if (delete_quote(src, i, quote))
				i++;
			else
				copystuff(temp2, src, &i, &y);
		}
		else
			copystuff(temp2, src, &i, &y);
	}
	temp2[y] = '\0';
	return (temp2);
}

int get_len(char *str, int quote, int len, int i)
{
	while (str[i])
	{
		if (str[i] == SINGLE_QOUTE || str[i] == DOUBLE_QUOTE)
		{
			quote = str[i];
			if (delete_quote(str, i, quote))
				i++;
			else
			{
				i++;
				len++;
			}
		}
	}
	return (len);
}

// void	removing_quotes(t_shell *s)
// {
// 	t_separated_by_pipe	*temp;
// 	int					i;
// 	char				*temp2;
// 	int					len;

// 	temp = s->s_p;
// 	len = 0;
// 	while (temp->argv[i])
// 	{
// 		len = get_len(temp->argv[i], 0, 0, 0);
// 		temp2 = strcpywithout(temp->argv[i], len, 0, 0);
// 		free(temp->argv[i]);
// 		temp->argv[i] = temp2;
// 		i++;
// 	}
// 	temp = temp->next;
// }
