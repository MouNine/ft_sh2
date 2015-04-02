/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 11:09:25 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/31 11:47:53 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell2.h"

void	ft_builtins(t_env *env)
{
	if (!ft_strcmp(env->args[0], "exit"))
		exit(0);
	else if (!ft_strcmp(env->args[0], "env"))
		print_env(env->env);
	else if (!ft_strcmp(env->args[0], "setenv"))
	{
		if (env->args[1] && env->args[2] && env->args[3])
			env = set_env(env->args[1], env->args[2], \
					ft_atoi(env->args[3]), env);
		else
			ft_putendl("USAGE : name value ow (0 or 1)");
	}
	else if (!ft_strcmp(env->args[0], "unsetenv"))
	{
		if (env->args[1])
			env = ft_unsetenv(env->args[1], env);
		else
			ft_putendl("USAGE : unsetenv name");
	}
	else if (!ft_strcmp(env->args[0], "cd"))
		env = ft_cd(env->args[1], env);
	else
	{
		env = get_access_exec(env);
		if (env->access == -1)
		{
			ft_putstr_fd("minishell : command not found: ", 2);
			ft_putendl_fd(env->args[0], 2);
		}
		else if (env->args[0])
			ft_fork(env);
	}
}
