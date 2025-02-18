/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void		*data;

	if (!root)
		return (NULL);
	data = NULL;
	data = btree_search_item(root->left, data_ref, cmpf);
	if (data)
		return (data);
	if (cmpf(root->item, data_ref) == 0)
		return (root);
	return (btree_search_item(root->right, data_ref, cmpf));
}
