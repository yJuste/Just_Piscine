/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlongin <jlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:37:15 by jlongin           #+#    #+#             */
/*   Updated: 2024/12/01 11:44:33 by jlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list		*cur;
	t_list		*start;
	void		*x;

	if (!begin_list || !(*begin_list))
		return ;
	cur = *begin_list;
	start = *begin_list;
	while (cur->next)
	{
		if ((*cmp)(cur->data, cur->next->data) > 0)
		{
			x = cur->data;
			cur->data = cur->next->data;
			cur->next->data = x;
			cur = start;
		}
		else
			cur = cur->next;
	}
}
