/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:54:50 by tfedoren          #+#    #+#             */
/*   Updated: 2022/08/23 18:00:35 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_list_pipes(t_separated_by_pipe *head)
{
	if (!head)
		return ;
	while (head->next != NULL)
	{
		ft_printf("%s", head->sub);
		ft_printf("\n");
		head = head->next;
	}
	if (head->sub)
	{
		ft_printf("%s", head->sub);
		ft_printf("\n");
	}
}

void	print_list_spaces(t_separated_by_pipe *head)
{
	int i;
	int j;
	char *temp;
	
	temp = (head->sub);
	
	j = 0;
	i = 0;
	
	// while (j < 2)
	// {
		while (i <  strcount(temp, ' '))
		{
			if (!head)
				return ;
			while (head->next != NULL)
			{
				ft_printf("%s", (head->argv[i]));
				ft_printf("\n");
				head = head->next;
			}
			if (head->argv[i])
			{
				ft_printf("%s", head->argv[i]);
				ft_printf("\n");
			}
			// ft_printf("here\n");
			i++;
		// }
	}
	

}

t_separated_by_pipe	*ft_lstnew_custom(void *content, t_shell *s)
{
	t_separated_by_pipe	*new;

	new = malloc(sizeof(t_separated_by_pipe));
	if (!new)
		return (NULL);
	new->sub = content;
	new->main = s;
	new->argv = NULL;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_custom(t_separated_by_pipe **lst, \
											t_separated_by_pipe *new)
{
	t_separated_by_pipe	*current;

	current = *lst;
	if (lst)
	{
		if (*lst)
		{
			while (current->next != NULL)
				current = current->next;
			current->next = new;
		}
		else
			*lst = new;
	}
}

// int test_space_split(t_shell *s)
// {
// 	int i = 0;
// 	char **tab;

// 	tab = split_by_spaces(s);
// 	while (i < 4)
// 	{
// 		printf("string %d : %s\n", i, tab[i]);
// 		i++;
// 	}
// 	return (0);
// }
