/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 10:45:33 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/31 11:48:36 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell2.h"

int			main(int ac, char **av, char **env)
{
	t_env	*e;

	ft_init_env(env);
	e = recup_env();
	av = av - ac + ac;
	print_shell(e);
	return (0);
}
