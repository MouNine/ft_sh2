/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 10:45:33 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/30 14:03:04 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell2.h"

int			main(int ac, char **av, char **env)
{
	t_env	*e;
	char	*tmp;
	int		i;

	i = 0;
	ft_init_env(env);
	e = recup_env();
	e->path = ft_strsplit(ft_getenv("PATH"), ':');
	while (e->path[i])
	{
		tmp = ft_strjoin(e->path[i], "/");
		free(e->path[i]);
		e->path[i++] = tmp;
	}
	av = av - ac + ac;
	print_shell(e);
	return (0);
}
