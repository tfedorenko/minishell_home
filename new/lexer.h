/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:12:15 by tfedoren          #+#    #+#             */
/*   Updated: 2022/08/25 17:50:52 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LEXER_H
# define LEXER_H
//# define EXIT_SUCCESS

# define SEP			0
# define WORD			1
# define INSIDE_SQ		2
# define INSIDE_DQ		3
# define PIPE			4
# define REDIR_APPEND	5
# define REDIR_SOURCE	6
# define REDIR_OUT		7
# define REDIR_IN		8
# define NCONST			9


typedef struct s_list_lexer
{
	void					*key;
	void					*value;
	struct s_list_element	*next;
} t_list_lexer;


int	lexer(t_list_lexer *token, const char *line);

/**********************helpers_lexer**********************/
int	find_space(char c);

/**********************helpers_lists**********************/
t_list_lexer	*push_to_list(t_list_lexer *root, void *key_word, void *value);
t_list_lexer	*new_node(void *key_word, void *value);



#endif