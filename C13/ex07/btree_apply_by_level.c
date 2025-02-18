/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_btree.h"

// ---------------------------------PROTOTYPE---------------------------------
void		btree_apply_by_level(t_btree *root,
				void (*applyf)(void *item, int current_level,
					int is_first_elem));
void		apply_by_level(t_btree *root, int level, int *first,
				void (*applyf)(void *, int, int));
int			btree_level_count(t_btree *root);
// ---------------------------------------------------------------------------

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level,
		int is_first_elem))
{
	int		level;
	int		first;
	int		height;

	height = btree_level_count(root);
	level = 0;
	while (level < height)
	{
		first = 1;
		apply_by_level(root, level, &first, applyf);
		level++;
	}
}

void	apply_by_level(t_btree *root, int level, int *first,
		void (*applyf)(void *, int, int))
{
	if (!root)
		return ;
	if (level == 0)
	{
		applyf(root->item, level, *first);
		*first = 0;
	}
	else
	{
		apply_by_level(root->left, level - 1, first, applyf);
		apply_by_level(root->right, level - 1, first, applyf);
	}
}

int	btree_level_count(t_btree *root)
{
	int		left;
	int		right;

	if (!root)
		return (0);
	left = btree_level_count(root->left);
	right = btree_level_count(root->right);
	if (left > right)
		return (1 + left);
	else
		return (1 + right);
}
