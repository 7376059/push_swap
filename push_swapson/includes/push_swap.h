/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:36:01 by dgrady            #+#    #+#             */
/*   Updated: 2019/11/04 21:03:57 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/libft.h"

typedef struct		s_lest
{
	int				data;
	struct s_lest	*next;
}					t_lest;

typedef struct		s_stack
{
	t_lest			*a;
	t_lest			*b;
	int				b_dir;
	int				a_dir;
	int				a_spin;
	int				b_spin;
}					t_stack;

t_lest				*create_elem(int data);
t_stack				*count_for_elem(int index, t_stack *stack);
t_stack				*do_algo(t_stack *stack);
t_stack				*count_for_all(t_stack *stack);
t_stack				*all_algo(t_stack *stack);
void				*print_stack(t_stack *stack);
t_lest				*init_a(char **str);
int					check_string(t_lest *lst, char *str);
void				clear_mas(char **str);
t_stack				*init_stack(void);
void				go_exit(char **str);
int					ft_atoii(const char *str);
void				clear_lest(t_lest *lest);
void				clear_stack(t_stack *stack);
int					check_if_sorted(t_stack *stack);
t_stack				*sort_a(t_stack *stack);
t_stack				*count_for_b(int index, t_stack *stack);
t_stack				*keks_shpeks(t_stack *stack, int i, int index);
t_lest				*fuc_norma(char	**temp, t_lest *rez, int j, t_lest *start);
int					check_mass(char **temp);
int					ft_atoii(const char *str);
t_lest				*create_elem(int data);

t_stack				*sa(t_stack *stack);
t_stack				*pb(t_stack *stack);
t_stack				*pa(t_stack *stack);
t_stack				*ra(int i, t_stack *stack);
t_stack				*rb(int i, t_stack *stack);
t_stack				*rr(t_stack *stack);
t_stack				*rra(int i, t_stack *stack);
t_stack				*rrb(int i, t_stack *stack);
t_stack				*rrr(t_stack *stack);

#endif
