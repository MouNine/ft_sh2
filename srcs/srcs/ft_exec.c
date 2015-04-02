/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 10:58:04 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/27 13:38:14 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell2.h"

int        ft_fork(char *line, char **args, char **path, t_env *env)
{
    pid_t   pid;
    int     i;
    int     ret_exe;
 
    ret_exe = -1;
    i = 0;
    if ((pid = fork()) < 0)
        ft_putendl_fd("Can't fork", 2);
    else if (pid == 0)
    {
        while (ret_exe < 0 && *path[i] != 0)
        {
            if ((ret_exe = execve(ft_strjoin(path[i], line), args, env->env))
                && path[i + 1] == 0 && line[0] != '\0')
                ft_putendl_fd("Command not found", 2);
            i++;
        }
    }
    else
        wait(NULL);
    return (1);
}
