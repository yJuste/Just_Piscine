/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated: 2024/11/29 10:56:18 by jlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

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
