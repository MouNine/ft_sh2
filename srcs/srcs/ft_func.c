/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 10:14:51 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/27 11:36:08 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell2.h"

int			ft_checkspace(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] != 32 && s[i] != 9)
			return (1);
		else
			i++;
	}
	return (0);
}

char		*ft_clean(char *cmd)
{
	int		i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == 9)
			cmd[i] = 32;
		i++;
	}
	return (cmd);
}

char			*ft_glue(char **tmp)
{
	char		*s;
	int			len;
	int			i;

	if (!tmp)
		return (NULL);
	len = 1;
	i = -1;
	while (tmp[++i])
		len = len + ft_strlen(tmp[i]) + 1;
	if (!(s = (char *)malloc(len * sizeof(char))))
		return (s);
	i = 1;
	s = ft_strcpy(s, "/");
	s = ft_strcat(s, tmp[0]);
	while (tmp[i])
	{
		s = ft_strcat(s, "/");
		s = ft_strcat(s, tmp[i]);
		i++;
	}
	return (s);
}

char			*ft_news(char **tmp)
{
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	return (ft_strdup("/"));
}

char			*ft_trim(char *s)
{
	char		**tmp;
	int			i;

	tmp = ft_strsplit(s, '/');
	if ((i = 0) == 0 && tmp[1] && ft_strcmp(tmp[1], "..") == 0 && !tmp[2])
		return (ft_news(tmp));
	while (tmp[i] && ft_strcmp(tmp[i], "..") != 0)
		i++;
	if (i != 0 && tmp[i])
	{
		while (tmp[i + 1])
		{
			free(tmp[i - 1]);
			tmp[i - 1] = ft_strdup(tmp[i + 1]);
			i++;
		}
		free(tmp[i - 1]);
		tmp[i - 1] = NULL;
		free(tmp[i]);
		free (s);
		s = ft_glue(tmp);
		s = ft_trim(s);
	}
	ft_destroy(tmp);
	return (s);
}
