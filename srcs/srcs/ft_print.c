/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 18:18:36 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/30 14:04:15 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell2.h"
# include <stdio.h>

void		print_prompt(void)
{
	ft_putstr("$> ");
}

void		print_env(t_env *env)
{
	int		i;

	i = 0;
	if (env->env)
	{
		while (env->env[i])
		{
			ft_putendl(env->env[i]);
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
		print_prompt();
	//	line = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	//	if ((ret = read (1, line, BUFF_SIZE)) > 0)
	//		line[ret - 1] = '\0';
		get_next_line(0, &line);
		if (ft_strlen(line) > 0 && ft_checkspace(line) > 0)
		{
			line = ft_clean(line);
			cmd = ft_strsplit(line, ';');
			i = 0;
			while (cmd[i])
			{
				env->args = ft_strsplit(cmd[i], 32);
				ft_builtins(env->args[i], env);
				i++;
			}
		}
	}
}
