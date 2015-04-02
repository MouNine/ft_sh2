/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 15:39:38 by eboeuf            #+#    #+#             */
/*   Updated: 2015/04/01 15:57:42 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell2.h"

t_sym		is_op(char *str)
{
	if (str[0] == '|' && str[1] != '|')
		return (pipes);
	if (str[0] == '<' && str[1] == '<')
		return (append);
	if (str[0] == '<')
		return (redir_in);
	if (str[0] == '>')
		return (redir_out);
	if (str[0] == ';')
		return (colon);
	if (str[0] == '>' && str[1] == '>')
		return (redir_dest);
	return (unknown);
}
