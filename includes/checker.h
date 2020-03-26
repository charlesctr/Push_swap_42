/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:43:24 by chcoutur          #+#    #+#             */
/*   Updated: 2019/10/11 18:02:02 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/libft.h"

typedef struct	s_stack
{
	int			*tab;
	int			size;
}				t_stack;

typedef struct	s_ab
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*sa;
	t_stack		*sb;
	int			size;
}				t_ab;

typedef struct	s_move
{
	char		*type;
	int			(*move)(t_stack *, t_stack*);
}				t_move;

int				get_size(char **argv);
int				set(t_ab *arg, char **argv, int argc);
int				check_a(char **argv);
int				check_b(t_stack *a);
char			**check_space(char **argv);
int				check_valid(t_stack *a, t_stack *b);
void			free_ab(t_ab *arg);
void			free_stack(t_stack *stack);

int				move_check(t_ab *arg, char *move, int v);
int				move_pa(t_stack *a, t_stack *b);
int				move_pb(t_stack *a, t_stack *b);
int				move_ra(t_stack *a, t_stack *b);
int				move_rb(t_stack *a, t_stack *b);
int				move_rr(t_stack *a, t_stack *b);
int				move_rrr(t_stack *a, t_stack *b);
int				move_rra(t_stack *a, t_stack *b);
int				move_rrb(t_stack *a, t_stack *b);
int				move_sa(t_stack *a, t_stack *b);
int				move_sb(t_stack *a, t_stack *b);
int				move_ss(t_stack *a, t_stack *b);
#endif
