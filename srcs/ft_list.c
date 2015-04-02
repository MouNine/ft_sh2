/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 16:03:45 by eboeuf            #+#    #+#             */
/*   Updated: 2015/04/01 16:08:43 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell2.h"

t_token			*init_token(void)
{
	t_token		*n;

	if (!(n = (t_token *)malloc(sizeof(t_token))))
		return (NULL);
	n->token = unknown;
	n->str = NULL;
	n->next = NULL;
	n->prev = NULL;

	return (n);
}
