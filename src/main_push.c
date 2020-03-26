/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:49:48 by chcoutur          #+#    #+#             */
/*   Updated: 2019/10/07 13:46:57 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_error(t_ab *arg)
{
	write(2, "Error\n", 6);
	free_ab(arg);
	return (-1);
}

int			main(int argc, char **argv)
{
	t_ab	arg;
	char	**back;

	back = argv;
	if (argc == 1)
		return (0);
	if (set(&arg, argv, get_size(argv)) == -1)
		return (0);
	if (check_a(back) == -1 || check_b(arg.a) == -1)
		return (ft_error(&arg));
	if (check_valid(arg.a, arg.b) == 1)
		return (0);
	while (arg.a->size > 1 && check_valid(arg.a, arg.b) == -1)
		sort(&arg, 0);
	while (check_valid(arg.a, arg.b) == -1)
	{
		while (check_valid(arg.a, arg.b) == -1
				&& check_tab(arg.a->tab, arg.a->size) == 1)
			sort(&arg, 1);
		while (check_tab(arg.a->tab, arg.a->size) == -1)
			sort(&arg, 2);
	}
	free_ab(&arg);
	return (0);
}
