/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 14:32:13 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/30 11:41:25 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell2.h"

t_env				*recup_env(void)
{
	static t_env	*env = NULL;

	if (env == NULL)
	{
		env = (t_env *)malloc(sizeof(t_env));
		env->env = NULL;
		env->env_orig = NULL;
		env->path = NULL;
		env->args = NULL;
		env->ret = 0;
	}
	return (env);
}

void				ft_init_env(char **env)
{
	t_env			*e;
	int				i;

	i = 0;
	e = recup_env();
	if (!env || env[0] == NULL)
	{
		ft_putendl_fd("Unable to retrieve environment", 2);
		exit(-1);
	}
	else
		e->env_orig = env;
	while (e->env_orig[i])
		i++;
	e->env = (char **)malloc(sizeof(char *) * (i + 1));
	e->env[i] = NULL;
	while (--i >= 0)
		e->env[i] = ft_strdup(e->env_orig[i]);
}

char				*ft_getenv(char *s)
{
	t_env			*env;
	int				i;

	env = recup_env();
	i = 0;
	if (env->env)
	{
		while (env->env[i])
		{
			if (!ft_strncmp(env->env[i], s, ft_strlen(s)))
				break ;
			i++;
		}
		if (env->env[i] == NULL)
			return (NULL);
	}
	else
		return (NULL);
	return (env->env[i] + ft_strlen(s) + 1);
}
