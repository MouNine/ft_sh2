/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 11:09:25 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/30 14:59:31 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell2.h"
# include <stdio.h>

void		ft_builtins(char *line, t_env *env)
{
	if (!ft_strcmp(env->args[0], "exit"))
		exit(0);
	else if (!ft_strcmp(env->args[0], "env"))
		print_env(env);
    else if (!ft_strcmp(env->args[0], "setenv"))
    {
        if (env->args[1] && env->args[2] && env->args[3])
            env = set_env(env->args[1], env->args[2],
                ft_atoi(env->args[3]), env);
        else
            ft_putendl("USAGE : name value ow (0 or 1)");
    }
    else if (!ft_strcmp(env->args[0], "unsetenv"))
    {
        if (env->args[1] && !env->args[2] && !env->args[3])
        	env = ft_unsetenv(env->args[1], env);
        else
            ft_putendl("USAGE : unsetenv name");
    }
    else if (!ft_strcmp(env->args[0], "cd"))
    	env = ft_cd(env->args[1], env);
    else
        ft_fork(line, env->args, env->path, env);
}
