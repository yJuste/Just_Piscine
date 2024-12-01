/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list		*prev;
	t_list		*cur;

	cur = *begin_list;
	prev = NULL;
	while (cur)
	{
		if ((*cmp)(cur->data, data_ref) == 0)
		{
			if (prev)
				prev->next = cur->next;
			else
				*begin_list = cur->next;
			(*free_fct)(cur->data);
			free(cur);
			if (prev)
				cur = prev->next;
			else
				cur = *begin_list;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
