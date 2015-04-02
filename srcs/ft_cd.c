/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 15:03:59 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/30 15:34:46 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell2.h"

char		*ft_copy(char *s)
{
	int		i;
	int		save;
	char	*ret;

	i = -1;
	save = -1;
	while (s[++i])
	{
		if (s[i] == '/')
			save = i;
	}
	ret = ft_strdup(s);
	ret[save] = '\0';
	return (ret);
}

char		*ft_red(char *p, char *e)
{
	char	*s;

	if (!(s = (char *)malloc((ft_strlen(e) + ft_strlen(p) + 3) * sizeof(char))))
		return (s);
	s = ft_strcpy(s, "/");
	if (e && ft_strcmp(e, "\0") != 0)
	{
		s = ft_strcat(s, e);
		if (p && ft_strcmp(p, "\0") != 0)
			s = ft_strcat(s, "/");
	}
	s = ft_strcat(s, p);
	s = ft_trim(s);
	return (s);
}

void		ft_checkaccess(char *s, t_env *env, int ip)
{
	char	*buf;

	buf = NULL;
	if (access(s, F_OK) == -1)
		ft_putendl("cd: no such a file or directory\n");
	else if (access(s, X_OK) == -1)
		ft_putendl("cd: permission denied\n");
	else
	{
		env = set_env("OLDPWD", env->env[ip] + 4, 1, env);
		chdir(s);
		env = set_env("PWD", getwd(buf), 1, env);
		if (buf)
			free(buf);
	}
}

t_env		*ft_docd(char *path, t_env *env, int ih, int ip)
{
	char	*tmp;
	char	*s;

	tmp = ft_copy(env->env[ih] + 6);
	if (path[0] == '~' && path[1] == '/')
		s = ft_red(path + 2, env->env[ih] + 6);
	else if (path[0] == '~')
		s = ft_red(path + 1, tmp);
	else if (path[0] == '/')
		s = ft_red(path + 1, NULL);
	else if (ft_strcmp(path, "-") == 0)
		s = ft_strdup(&(env->env[ft_found("OLDPWD", env)][7]));
	else
		s = ft_red(path, env->env[ip] + 5);
	ft_checkaccess(s, env, ip);
	free(s);
	free(tmp);
	return (env);
}

t_env		*ft_cd(char *path, t_env *env)
{
	int		i_home;
	int		i_pwd;

	i_home = ft_found("HOME", env);
	i_pwd = ft_found("PWD", env);
	if (!path || ft_strcmp(path, "~") == 0)
	{
		if (ft_strncmp(env->env[i_home], "HOME", 4) == 0)
		{
			env = set_env("OLDPWD", env->env[i_pwd] + 4, 1, env);
			chdir((env->env[i_home] + 5));
			env = set_env("PWD", env->env[i_home] + 5, 1, env);
		}
		return (env);
	}
	if (ft_strncmp(path, "..", 2) != 0 \
			|| ft_strcmp(env->env[i_pwd], "PWD=/") != 0)
		env = ft_docd(path, env, i_home, i_pwd);
	return (env);
}
