/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:49:21 by chcoutur          #+#    #+#             */
/*   Updated: 2019/09/26 13:05:27 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int		move_p(t_stack *fi, t_stack *se)
{
	int i;

	i = se->size;
	if (fi->size > 0)
	{
		se->size += 1;
		while (i > 0)
		{
			se->tab[i] = se->tab[i - 1];
			i--;
		}
		se->tab[0] = fi->tab[0];
		i = 0;
		while (i + 1 < fi->size)
		{
			fi->tab[i] = fi->tab[i + 1];
			i++;
		}
		fi->size = fi->size - 1;
	}
	return (1);
}

int				move_pb(t_stack *a, t_stack *b)
{
	move_p(a, b);
	return (1);
}

int				move_pa(t_stack *a, t_stack *b)
{
	move_p(b, a);
	return (1);
}
