/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitting_by_pipes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:50:16 by tfedoren          #+#    #+#             */
/*   Updated: 2022/08/23 20:48:45 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "minishell.h"

void	split_by_pipes(t_shell *s)
{
	int	i;
	int	quote_flag;
	int	start;
	char *token;
	char *temp;
	int sub_command_counter;
	int j;
	int actual_pipe_number;
	int k;
	int l;

	l=0;

	j = 0;
	
	k = 0;
	i = 0;
	quote_flag = 0;
	start = 0;
	sub_command_counter = 1;
	actual_pipe_number = 0;
	while(s->input[k])
	{
		if (s->input[k] == PIPE && !quote_flag || s->input[k] == '\0')
			sub_command_counter++;
		k++;
	}
	while(s->input[l])
	{
		if (s->input[l] != PIPE && s->input[l] != '\0')
			l++;
		else{
			break;
		}
		// printf("here\n");
	}
	s->separated_by_pipe = malloc(sizeof(char*)*sub_command_counter);
	if (!s->separated_by_pipe)
		return ;
	
	while (s->input[i])
	{	
		if (s->input[i] == PIPE)
		{
			actual_pipe_number++;
			// printf("actual_pipe_number = %d\n", actual_pipe_number);
			// printf("here\n");
		}
		// printf("actual_pipe_number = %d\n", actual_pipe_number);
			

		if (s->input[i] != PIPE && s->input[i] != '\0' && actual_pipe_number == 0)
		{
			
			token = ft_strtrim(ft_substr(s->input, start, l), " ");
			s->separated_by_pipe[j] = token;
			free(token);
			start = l + 1;
			i = l;
			printf("token = %s\n", token);
			printf("s->separated_by_pipe[%i]= %s\n", j, s->separated_by_pipe[j]);
			if (s->input[i] == '\0')
				break ;
			j++;
		}
		if (s->input[i] == PIPE && !quote_flag || s->input[i] == '\0')
		{	
			token = ft_strtrim(ft_substr(s->input, start, i - start), " ");
			token[ft_strlen(token) + 1] = '\0';
			s->separated_by_pipe[j] = token;
			start = i + 1;
			// printf("i = %d\n", i);
			// printf("token2 = %s\n", token);
			// printf("s->separated_by_pipe2[%i]= %s\n", j, s->separated_by_pipe[j]);
			if (s->input[i] == '\0')
				break ;
			j++;
		}
		else if ((s->input[i] == SINGLE_QOUTE || \
								s->input[i] == DOUBLE_QUOTE) && !quote_flag)
			quote_flag = s->input[i];
		else if (quote_flag && (!(s->input[i]) || s->input[i] == quote_flag))
			quote_flag = 0;
		// if (s->input[i] == '\0')
		// 	break;
		i++;
	}	
}
