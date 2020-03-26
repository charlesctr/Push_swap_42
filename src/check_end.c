/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <chcoutur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 12:16:33 by chcoutur          #+#    #+#             */
/*   Updated: 2019/10/08 09:22:10 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		check_pivot_tab_dn(t_stack *a, int pvt)
{
	int i;

	i = 0;
	while (i + 1 < a->size)
	{
		if (a->tab[i] > pvt)
			return (-1);
		i++;
	}
	return (1);
}

int		check_pivot_tab_up(t_stack *a, int pvt)
{
	int i;

	i = 0;
	while (i + 1 < a->size)
	{
		if (a->tab[i] < pvt)
			return (-1);
		i++;
	}
	return (1);
}

int		check_tab(int *tab, int size)
{
	int i;

	i = 0;
	while (i + 1 < size)
	{
		if (tab[i] > tab[i + 1])
			return (-1);
		i++;
	}
	return (1);
}

int		check_valid(t_stack *a, t_stack *b)
{
	int i;

	i = 0;
	if (b->size > 0)
		return (-1);
	while (i + 1 < a->size)
	{
		if (a->tab[i] > a->tab[i + 1])
			return (-1);
		i++;
	}
	return (1);
}
