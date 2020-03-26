/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:03:47 by chcoutur          #+#    #+#             */
/*   Updated: 2019/09/30 11:46:05 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static const	t_move	g_move[] = {
	{"pa", move_pa},
	{"pb", move_pb},
	{"ra", move_ra},
	{"rb", move_rb},
	{"rr", move_rr},
	{"rra", move_rra},
	{"rrb", move_rrb},
	{"rrr", move_rrr},
	{"sa", move_sa},
	{"sb", move_sb},
	{"ss", move_ss},
	{NULL, NULL},
};

int				move_check(t_ab *arg, char *move, int v)
{
	int i;

	i = 0;
	while (g_move[i].type)
	{
		if (ft_strcmp(move, (const char*)g_move[i].type) == 0)
		{
			g_move[i].move(arg->a, arg->b);
			if (v == 1)
				ft_printf("%s\n", move);
			return (1);
		}
		i++;
	}
	return (-1);
}
