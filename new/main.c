/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:39:06 by tfedoren          #+#    #+#             */
/*   Updated: 2022/08/25 18:19:57 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_prompt(char *text)
{
	ft_printf(text);
}

char	*read_next_command(t_shell *s)
{

	s->input = readline("minishell$ ");
	return (s->input);
}

static void	sigint_handler(int sig)
{
	if (sig)
	{
		// rl_replace_line("", 0);
		// rl_on_new_line();
		ft_putchar_fd('\n', STDOUT_FILENO);
		print_prompt("minishell$ ");
		// rl_redisplay();
	}
}

static void	signals_function(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sigint_handler);
}

void init(t_list_lexer *tokens)
{
	tokens->key = 0;
	tokens->value = NULL; 
	tokens->next = NULL;
}


int	main(int argc, char const *argv[], char *const *env)
{
	char	*cmd;
	t_shell	s;
	t_list_lexer *tokens;

	signals_function();
	
	// tokens = new_node(tokens, cmd);
	// cmd = read_next_command(&s);
	// cmd = readline("minishell$ ");
	// tokens = (t_list_lexer *)malloc(sizeof(t_list_lexer));
	// init (tokens);
	int f = 1;
	while (1)
	{
		cmd = readline("minishell$ ");
		// s.input = read_next_command(&s);
		if (!cmd)
			break ;
		if (cmd[0] == 0 || ft_strncmp(cmd, "\n", 1) == 0)
		{
			free(cmd);
			continue ;
		}
		if (ft_strncmp(cmd, "exit", 4) == 0)
		{
			free(s.input);
			break ;
		}
		// ft_printf("test1\n");
		lexer(tokens, cmd, &f);
	// 
		print_list(tokens);
		
		// parsing(&s);
		
		t_list_lexer *tokenss;
		tokens = tokenss;
		f = 1;
	}
	// env_variables(env);
	free(tokens);
	return (0);
}
