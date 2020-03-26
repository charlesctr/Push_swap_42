/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:54:06 by chcoutur          #+#    #+#             */
/*   Updated: 2019/09/26 13:08:23 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int		move_rrev(t_stack *sub)
{
	int i;
	int tmp;

	i = sub->size - 1;
	if (i < 0)
		return (1);
	tmp = sub->tab[sub->size - 1];
	while (i > 0)
	{
		sub->tab[i] = sub->tab[i - 1];
		i--;
	}
	sub->tab[0] = tmp;
	return (1);
}

int				move_rrb(t_stack *a, t_stack *b)
{
	(void)a;
	move_rrev(b);
	return (1);
}

int				move_rra(t_stack *a, t_stack *b)
{
	(void)b;
	move_rrev(a);
	return (1);
}

int				move_rrr(t_stack *a, t_stack *b)
{
	move_rrev(a);
	move_rrev(b);
	return (1);
}
