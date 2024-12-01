/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlongin <jlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:25:55 by jlongin           #+#    #+#             */
/*   Updated: 2024/12/01 12:59:09 by jlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_at(t_list *begin_list, size_t n)
{
	size_t		i;

	i = 0;
	while (begin_list && i < n)
	{
		begin_list = begin_list->next;
		i++;
	}
	if (i == n)
		return (begin_list);
	return (NULL);
}

size_t	ft_list_size(t_list *begin_list)
{
	size_t		i;

	i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

void	ft_list_swap(t_list *a, t_list *b)
{
	void		*x;

	x = a->data;
	a->data = b->data;
	b->data = x;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	size_t		size;
	size_t		i;

	i = 0;
	size = ft_list_size(begin_list);
	while (i < size / 2)
	{
		ft_list_swap(ft_list_at(begin_list, 0),
			ft_list_at(begin_list, size - i - 1));
		i++;
	}
}
