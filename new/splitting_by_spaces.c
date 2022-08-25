/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitting_by_spaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:08:21 by tfedoren          #+#    #+#             */
/*   Updated: 2022/08/23 18:02:45 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "minishell.h"

void	split_by_spaces(t_shell *s)
{
	t_separated_by_pipe	*temp;
	temp = s->s_p;

	while (temp)
	{
		s->s_p->argv =ft_split_by_spaces(temp->sub, ' ', s);
		temp = temp->next;
	}
}

int	out_q(char *line, int pos)
{
	int	q_num;
	int	qq_num;
	int	i;

	q_num = 0;
	qq_num = 0;
	i = 0;
	while (i < pos)
	{
		if (q_num % 2 == 0)
		{
			if (line[i] == DOUBLE_QUOTE)
				qq_num++;
		}
		if (qq_num % 2 == 0)
		{
			if (line[i] == SINGLE_QOUTE)
				q_num++;
		}
		i++;
	}
	if (q_num % 2 == 1 || qq_num % 2 == 1)
		return (0);
	return (1);
}

int	strcount(char *s, char c)
{
	int	counter;
	int	j;
	int	string_flag;

	counter = 0;
	j = 0;
	string_flag = 0;
	while (s[j] != '\0')
	{
		if (s[j] != c && string_flag == 0 && out_q(s, j))
		{
			string_flag = 1;
			counter++;
		}
		else if (s[j] == c && out_q(s, j))
			string_flag = 0;
		j++;
	}
	return (counter);
}

char	**ft_split_by_spaces(char *s, char c,t_shell *kurwa )
{
	char	**array;
	int		flag;
	size_t	i;
	size_t	j;
 
	array = ft_calloc( (strcount(s, c) + 122),sizeof(char *));
	// printf("Content %s and lenght %zu", temp->sub, ft_strlen(temp->sub));
	printf("%s String and lenght %zu" ,s, ft_strlen(s));
	kurwa->s_p->arr_lenght = strcount(s, c) + 1;
	i = 0;
	j = 0;
	flag = -1;
	printf("Chuj");
	if (!array || !s)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		printf("Pomocy");
		if (flag < 0 && s[i] != c && out_q(s, i))
			flag = i;
		else if ((s[i] == c || i == ft_strlen(s)) && 0 <= flag && out_q(s, i))
		{
			array[j] = ft_substr(s, flag, i - flag);
			flag = -1;
			j++;
		}
		i++;
	}
	array[j] = 0;
	int a = 1;
	while(a <  kurwa->s_p->arr_lenght)
	{
		printf("%s\n", array[a]);
		a++;
	}

	return (array);
}
// 