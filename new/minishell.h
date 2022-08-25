/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:51:09 by tfedoren          #+#    #+#             */
/*   Updated: 2022/08/25 18:33:00 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

// # define PIPE '|'
# define SINGLE_QOUTE '\''
# define DOUBLE_QUOTE '\"'

# include "Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <string.h>
# include </Users/tfedoren/goinfre/.brew/opt/readline/include/readline/readline.h>
# include </Users/tfedoren/goinfre/.brew/opt/readline/include/readline/history.h>

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
	int					key;
	char				*value;
	// int					size;
	// struct s_list_lexer	*head;
	struct s_list_lexer	*next;
}	t_list_lexer;

typedef struct s_minishell
{
	int					size_of_list;
	struct s_list_lexer	*head;
}

/**********************_lexer_****************************/
int	lexer(t_list_lexer *token, const char *line, int *f);

/*********************_helpers_lexer_*********************/
int special_char_handler(t_list_lexer *tokens, const char *line, int i, int t, int *f);
int word_handler(t_list_lexer *tokens, const char *line, int i, int *t, int *f);
int char_handler(t_list_lexer *tokens, const char *line, int *i, int *f);
int	quotes_handler(t_list_lexer *tokens, const char *line, int i, int *t, int *f);
int	find_space(char c);
int	find_special(char c);

/*********************_helpers_lists_*********************/
t_list_lexer	*push_to_list(t_list_lexer *root, int key, char *value, int *f);
t_list_lexer	*new_node(int key, char *value);
void	print_list(t_list_lexer *head);


typedef struct s_shell
{
	char				*input;
	char				**separated_by_pipe;
	char				***argv;

}	t_shell;

bool	errors_connected_with_qoutes_handler(char *cmd);
bool	check_for_number_of_double_quotes(char *cmd);
bool	check_for_number_of_single_quotes(char *cmd);
int		number_of_quotes_counter(char *cmd, char *quote);

/*********splitting_by_pipes*****************/
void	split_by_pipes(t_shell *s);
// t_separated_by_pipe	*ft_lstnew_custom(void *content, t_shell *s);
// void	ft_lstadd_back_custom(t_separated_by_pipe **lst, \
											t_separated_by_pipe *new);

/*********splitting_by_spaces*****************/
char	**ft_split_by_spaces(char *s, char c, t_shell *kurwa);
void	split_by_spaces(t_shell *s);
int		strcount(char *s, char c);

void	removing_quotes(t_shell *s);
int		inside_diff(char *line, int pos, char quote);
int		inside_same(char *line, int pos, char quote);


void	parsing(t_shell *s);

// void	print_list_pipes(t_separated_by_pipe *head);
// void	print_list_spaces(t_separated_by_pipe *head);


#endif
