/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list		*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	ft_sorted_list_insert_at_start(t_list **begin_list, t_list *new)
{
	new->next = *begin_list;
	*begin_list = new;
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list		*prev;
	t_list		*cur;
	t_list		*new;

	prev = NULL;
	if (!(*begin_list))
		return ;
	cur = *begin_list;
	new = ft_create_elem(data);
	if (!new)
		return ;
	if (!cur || cmp(cur->data, new->data) > 0)
		return (ft_sorted_list_insert_at_start(begin_list, new));
	while (cur)
	{
		if (cmp(cur->data, new->data) > 0)
		{
			prev->next = new;
			new->next = cur;
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
	prev->next = new;
}
