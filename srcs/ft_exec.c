/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 10:58:04 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/31 11:49:52 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell2.h"

t_env		*get_access_exec(t_env *env)
{
	char	**tmp;
	char	*path;
	int		i;

	i = 0;
	if (env->args[0][0] == '/')
		path = ft_strdup(env->args[0]);
	else
	{
		tmp = ft_strsplit(ft_getenv("PATH"), ':');
		while (tmp[i])
		{
			path = ft_strjoin(tmp[i], "/");
			env->path = ft_strjoin(path, env->args[0]);
			env->access = access(env->path, X_OK);
			if (env->access == 0)
				return (env);
			i++;
		}
	}
	return (env);
}

int			ft_fork(t_env *env)
{
	pid_t	pid;

	pid = fork();
	if (pid > 0)
		wait(NULL);
	else
	{
		execve(env->path, env->args, 0);
		exit(0);
		return (0);
	}
	return (0);
}
