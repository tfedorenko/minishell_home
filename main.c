/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 00:43:31 by tfedoren          #+#    #+#             */
/*   Updated: 2022/08/02 00:43:31 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "shell.h"

char *read_cmd(char *buf)
{
    int buflen;
    char *tmp;

    buf = get_next_line(0);
    buflen = strlen(buf);
}

int main(int argc, char **argv)
{
    char *cmd;

    while(1)
    {
        print_prompt1();
        cmd = read_cmd(cmd);
        if(!cmd)
            exit(EXIT_SUCCESS);
        if(cmd[0] == '\0' || strcmp(cmd, "\n") == 0)
        {
            free(cmd);
            continue;
        }
        if(strcmp(cmd, "exit") == 0)
        {
            free(cmd);
            break;
        }
        write(1, cmd, ft_strlen(cmd));
        write(1, "\n". 1);
        free(cmd);
    }
    exit(EXIT_SUCCESS);
}