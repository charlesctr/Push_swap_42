/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:52:56 by chcoutur          #+#    #+#             */
/*   Updated: 2019/09/23 16:24:40 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int		move_s(t_stack *sub)
{
	int tmp;

	tmp = sub->tab[0];
	if (sub->size > 1)
	{
		sub->tab[0] = sub->tab[1];
		sub->tab[1] = tmp;
	}
	return (1);
}

int				move_sb(t_stack *a, t_stack *b)
{
	(void)a;
	move_s(b);
	return (1);
}

int				move_sa(t_stack *a, t_stack *b)
{
	(void)b;
	move_s(a);
	return (1);
}

int				move_ss(t_stack *a, t_stack *b)
{
	move_s(a);
	move_s(b);
	return (1);
}
