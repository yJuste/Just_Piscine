/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void	ft_sorted_list_insert_at_start(t_list **begin_list1, t_list *list2)
{
	list2->next = *begin_list1;
	*begin_list1 = list2;
}

void	ft_sorted_list_insert(t_list **begin_list1, t_list *list2, int (*cmp)())
{
	t_list		*prev;
	t_list		*cur;

	prev = NULL;
	if (!(*begin_list1))
		return ;
	cur = *begin_list1;
	if (!cur || cmp(cur->data, list2->data) > 0)
		return (ft_sorted_list_insert_at_start(begin_list1, list2));
	while (cur)
	{
		if (cmp(cur->data, list2->data) > 0)
		{
			prev->next = list2;
			list2->next = cur;
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
	prev->next = list2;
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_list		*next;

	if (!begin_list1)
		return ;
	while (begin_list2)
	{
		next = begin_list2->next;
		ft_sorted_list_insert(begin_list1, begin_list2, cmp);
		begin_list2 = next;
	}
	return ;
}
