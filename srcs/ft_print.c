/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 18:18:36 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/31 10:58:11 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell2.h"

void		print_env(char **env)
{
	int		i;

	i = 0;
	if (env)
	{
		while (env[i])
		{
			ft_putendl(env[i]);
			i++;
		}
	}
}

void		print_shell(t_env *env)
{
	int		i;
	char	*line;
	char	**cmd;

	while (42)
	{
		ft_putstr("$> ");
		get_next_line(0, &line);
		if (ft_strlen(line) > 0 && ft_checkspace(line) > 0)
		{
			line = ft_clean(line);
			cmd = ft_strsplit(line, ';');
			i = 0;
			while (cmd[i])
			{
				env->args = ft_strsplit(cmd[i], 32);
				ft_builtins(env);
				i++;
			}
		}
	}
}
