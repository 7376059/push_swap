/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:28:42 by dgrady            #+#    #+#             */
/*   Updated: 2019/11/04 20:46:15 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/libft.h"

typedef	struct		s_inst
{
	char			*str;
	struct s_inst	*next;
}					t_inst;

typedef	struct		s_lest
{
	int				data;
	struct s_lest	*next;
}					t_lest;

typedef	struct		s_stack
{
	t_lest			*a;
	t_lest			*b;
	int				b_dir;
	int				a_dir;
	int				a_spin;
	int				b_spin;
}					t_stack;

t_lest				*create_elem(int data);
int					ft_atoii(const char *str);
void				clear_mas(char **str);
void				go_exit(char **str);
t_stack				*init_stack(void);
t_lest				*init_a(char **str);
int					check_string(t_lest *lst, char *str);
void				clear_lest(t_lest *lest);
void				clear_stack(t_stack *stack);
void				clear_inst(t_inst *lest);
t_inst				*create_inst(char *str);
int					check_if_sorted(t_stack *stack);
void				not_valid_inst(t_stack *stack, t_inst *inst);
t_lest				*fuc_norma(char **temp, t_lest *rez, int j, t_lest *start);
int					check_mass(char **temp);
t_stack				*sb(t_stack *stack);
t_stack				*sa(t_stack *stack);
t_stack				*ss(t_stack *stack);
t_stack				*pb(t_stack *stack);
t_stack				*pa(t_stack *stack);
t_stack				*ra(t_stack *stack);
t_stack				*rb(t_stack *stack);
t_stack				*rr(t_stack *stack);
t_stack				*rra(t_stack *stack);
t_stack				*rrb(t_stack *stack);
t_stack				*rrr(t_stack *stack);
#endif
