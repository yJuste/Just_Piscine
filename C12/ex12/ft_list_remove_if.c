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

void	ft_list_remove_if(t_list **begin_list,
		void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list		*cur;
	t_list		*tmp;

	cur = *begin_list;
	while (cur && cur->next)
	{
		if (cmp(cur->next->data, data_ref) == 0)
		{
			tmp = cur->next;
			cur->next = cur->next->next;
			free_fct(tmp->data);
			free(tmp);
		}
		cur = cur->next;
	}
	cur = *begin_list;
	if (cur && cmp(cur->data, data_ref) == 0)
	{
		*begin_list = cur->next;
		free_fct(cur->data);
		free(cur);
	}
}

/*	2 en 1 :

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list		*prev;
	t_list		*cur;

	cur = *begin_list;
	prev = NULL;
	while (cur)
	{
		if (cmp(cur->data, data_ref) == 0)
		{
			if (prev)
				prev->next = cur->next;
			else
				*begin_list = cur->next;
			free_fct(cur->data);
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
*/
