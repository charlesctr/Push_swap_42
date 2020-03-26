/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:43:17 by chcoutur          #+#    #+#             */
/*   Updated: 2019/10/07 13:52:35 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int			ft_error(t_ab *arg)
{
	write(2, "Error\n", 6);
	free_ab(arg);
	return (-1);
}

static int			check_general(t_ab *arg, int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (set(arg, argv, get_size(argv)) == -1)
		return (0);
	if (check_a(argv) == -1 || check_b(arg->a) == -1)
		return (ft_error(arg));
	else
		return (1);
}

int					main(int argc, char **argv)
{
	t_ab	arg;
	int		i;
	char	*move;

	i = 0;
	move = NULL;
	if (check_general(&arg, argc, argv) != 1)
		return (-1);
	while ((move = ft_get_fd(0)) != NULL)
	{
		if (move_check(&arg, move, 0) == -1)
		{
			ft_strdel(&move);
			return (ft_error(&arg));
		}
		ft_strdel(&move);
	}
	ft_strdel(&move);
	check_valid(arg.a, arg.b) == 1 ? ft_printf("OK\n") : ft_printf("KO\n");
	free_ab(&arg);
	return (0);
}
