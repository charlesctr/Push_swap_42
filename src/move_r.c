/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:51:54 by chcoutur          #+#    #+#             */
/*   Updated: 2019/09/26 13:05:47 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int		move_r(t_stack *sub)
{
	int i;
	int tmp;

	i = 0;
	tmp = sub->tab[0];
	while (i + 1 < sub->size)
	{
		sub->tab[i] = sub->tab[i + 1];
		i++;
	}
	sub->tab[i] = tmp;
	return (1);
}

int				move_rr(t_stack *a, t_stack *b)
{
	move_r(a);
	move_r(b);
	return (1);
}

int				move_rb(t_stack *a, t_stack *b)
{
	(void)a;
	move_r(b);
	return (1);
}

int				move_ra(t_stack *a, t_stack *b)
{
	(void)b;
	move_r(a);
	return (1);
}
