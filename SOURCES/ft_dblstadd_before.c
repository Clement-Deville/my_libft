/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblstadd_before.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:50:39 by cdeville          #+#    #+#             */
/*   Updated: 2024/01/27 12:14:05 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

void	ft_dblstadd_before(t_dblist *actual, t_dblist *new)
{
	if (!actual || !new)
		return ;
	new->next = actual;
	new->prev = actual->prev;
	if (actual->prev)
		actual->prev->next = new;
	actual->prev = new;
}
