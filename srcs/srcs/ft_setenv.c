/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 12:20:29 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/26 13:44:10 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell2.h"

char			**create_blank_env(t_env *env, int i)
{
	char		**new_env;
	int			size;

	size = ft_strstrlen(env->env);
	if (!(new_env = (char **)malloc(sizeof(char *) \
					* (size + i + 1))))
		return (NULL);
	return (new_env);
}

int				ft_destroy(char **env)
{
	int	i;

	if (env)
	{
		i = 0;
		while (env[i])
			ft_strdel(&env[i]);
		free(env);
	}
	return (1);
}

int				ft_found(char *s, t_env *env)
{
	int			len;
	int			i;

	i = 0;
	len = ft_strlen(s);
	while (env->env[i] != NULL && (ft_strncmp(s, env->env[i], len) != 0
	 		|| env->env[i][len] != '='))
		i++;
	if (ft_strncmp(s, env->env[i], len) == 0)
		return (i);
	return (0);
}

t_env			*set_env(const char *n, const char *v, int ow, t_env *e)
{
	int			i;
	char		**new_env;

	i = -1;
	while (e->env && e->env[++i])
		if (((int)ft_strlen(n) == ft_strchr(e->env[i], '=') - e->env[i]) \
			&& !ft_strncmp(n, e->env[i], ft_strlen(n)))
		{
			if (ow == 1)
			{
				free(e->env[i]);
				e->env[i] = ft_joinfree(ft_strjoin(n, "="), (char *)v, 1);
			}
			return (e);
		}
	if (!(new_env = create_blank_env(e, 1)))
		return (NULL);
	i = (e->env) ? (-1) : 0;
	while (e->env && e->env[++i])
		new_env[i] = ft_strdup(e->env[i]);
	new_env[i] = ft_joinfree(ft_strjoin(n, "="), (char *)v, 1);
	ft_destroy(e->env);
	e->env = new_env;
	return (e);
}

t_env			*ft_unsetenv(const char *n, t_env *env)
{
	int			i;

	if ((i = ft_found((char *)n, env)) != 0)
	{
		free(env->env[i]);
		while (env->env[i] != '\0')
		{
			env->env[i] = env->env[i + 1];
			i++;
		}
	}
	return (env);
}
