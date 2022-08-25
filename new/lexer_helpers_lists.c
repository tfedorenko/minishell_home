/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_helpers_lists.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:46:58 by tfedoren          #+#    #+#             */
/*   Updated: 2022/08/25 18:31:32 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list_lexer	*new_node(int key, char *value)
{
	t_list_lexer	*new_node;

	new_node = (t_list_lexer *)malloc(sizeof(t_list_lexer));
	if (new_node)
		return (NULL);
	new_node->key = key;
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

int push_to_list(t_list_lexer *root, int key, char *value,	int *f)
{
	if (!root)
		return (1);
	if (*f == 1)
	{
		root = new_node(key, value);
		root->next = NULL;
		*f = 0;
	}
	else
		root->next = new_node(key, value);
	return (root->next);
}

void	print_list(t_list_lexer *head)
{
	if (!head)
		return ;
	while (head->next != NULL)
	{
		ft_printf("test1\n");
		ft_printf("Key =%i, Value =%s\n", head->key, head->value);
		head = (head->next);
	}
	if (head->key)
	{
		ft_printf("test2\n");
		ft_printf("Key =%i, Value =%s\n", head->key, head->value);
	}
	ft_printf("\n");
}
