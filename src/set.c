/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:43:05 by chcoutur          #+#    #+#             */
/*   Updated: 2019/10/07 13:48:19 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	t_stack		*set_stack_b(int size)
{
	t_stack *b;
	int		i;

	i = 0;
	if (!(b = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	if (!(b->tab = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	b->size = 0;
	return (b);
}

static	t_stack		*set_stack_a(char **argv, int size, int i)
{
	int			j;
	int			k;
	t_stack		*a;
	char		**new_av;

	j = -1;
	k = -1;
	if (!(a = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	if (!(a->tab = (int*)malloc(sizeof(int) * get_size(argv))))
		return (NULL);
	while (argv[++i])
	{
		if (!(new_av = ft_strsplit(argv[i], ' ')))
			return (NULL);
		while (new_av[++j])
		{
			a->tab[++k] = ft_atoi(new_av[j]);
			size++;
		}
		j = -1;
		ft_strdel_d(new_av);
	}
	a->size = size;
	return (a);
}

int					set(t_ab *arg, char **argv, int size)
{
	int i;

	i = 0;
	if (!(arg->a = set_stack_a(argv, 0, i)))
		return (-1);
	if (!(arg->b = set_stack_b(size)))
		return (-1);
	if (!(arg->sa = set_stack_b(size)))
		return (-1);
	if (!(arg->sb = set_stack_b(size)))
		return (-1);
	arg->size = size;
	return (1);
}
