/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:23:24 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/02 14:28:54 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

static t_hash	*mem_exit(t_hash *htab, int size)
{
	ft_printf("Memory alloction fail!\n");
	destroy_htab(htab, size);
	return (NULL);
}

static t_hash	*dup_exit(char *key, t_hash *htab, int size)
{
	ft_printf("Find a duplicate of key: %s.\n", key);
	destroy_htab(htab, size);
	return (NULL);
}

static t_hash	*insert_htab(t_hash *htab, char **tab, int size,
	unsigned int (*hash_f)(char*, int))
{
	unsigned int	i;
	int				j;
	int				check;

	j = 0;
	while (j < size)
	{
		i = hash_f(tab[j], size);
		if (htab[i].content == NULL)
			htab[i].content = ft_strdup(tab[j]);
		else
		{
			check = handle_collision(&htab[i], tab[j]);
			if (check == -1)
				return (dup_exit(tab[j], htab, size));
			if (check == -2)
				return (mem_exit(htab, size));
		}
		j++;
	}
	return (htab);
}

t_hash	*create_htab(int size, char *tab[], unsigned int (*hash_f)(char*, int))
{
	t_hash			*htab;

	htab = (t_hash *)malloc((size + 1) * sizeof(t_hash));
	if (htab == NULL)
		return (NULL);
	init_htab(htab, size);
	htab = insert_htab(htab, tab, size, hash_f);
	return (htab);
}
