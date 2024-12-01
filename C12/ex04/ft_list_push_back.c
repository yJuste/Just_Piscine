/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	if (!begin_list)
		return (NULL);
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list		*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return ;
	elem->next = *begin_list;
	*begin_list = elem;
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list		*elem;
	t_list		*tmp;

	elem = ft_create_elem(data);
	if (!elem)
		return ;
	if (!(*begin_list))
		ft_list_push_front(begin_list, data);
	else
	{
		tmp = ft_list_last(*begin_list);
		tmp->next = elem;
	}
}
