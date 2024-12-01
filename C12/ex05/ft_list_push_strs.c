/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated: 2024/11/29 11:04:24 by jlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

t_list	*ft_list_push_strs(size_t size, char **strs)
{
	t_list		*begin_list;
	size_t		i;

	i = 0;
	begin_list = NULL;
	while (i < size)
	{
		ft_list_push_front(&begin_list, strs[i]);
		i++;
	}
	return (begin_list);
}
