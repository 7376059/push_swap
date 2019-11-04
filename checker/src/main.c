/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:05:20 by dgrady            #+#    #+#             */
/*   Updated: 2019/11/04 20:48:08 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*functions_manager(char *str, t_stack *stack, t_inst *inst)
{
	if (ft_strcmp(str, "pa") == 0)
		stack = pa(stack);
	else if (ft_strcmp(str, "pb") == 0)
		stack = pb(stack);
	else if (ft_strcmp(str, "sb") == 0)
		stack = sb(stack);
	else if (ft_strcmp(str, "sa") == 0)
		stack = sa(stack);
	else if (ft_strcmp(str, "ra") == 0)
		stack = ra(stack);
	else if (ft_strcmp(str, "rb") == 0)
		stack = rb(stack);
	else if (ft_strcmp(str, "rr") == 0)
		stack = rr(stack);
	else if (ft_strcmp(str, "rra") == 0)
		stack = rra(stack);
	else if (ft_strcmp(str, "rrb") == 0)
		stack = rrb(stack);
	else if (ft_strcmp(str, "rrr") == 0)
		stack = rrr(stack);
	else
		not_valid_inst(stack, inst);
	return (stack);
}

void		execute_inst(t_inst *inst, t_stack *stack)
{
	t_inst *temp;

	temp = inst;
	while (temp)
	{
		stack = functions_manager(temp->str, stack, inst);
		temp = temp->next;
	}
	if (check_if_sorted(stack) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "Error\n", 6);
	if (inst)
		clear_inst(inst);
	clear_stack(stack);
}

void		read_inst(t_stack *stack)
{
	char	*line;
	t_inst	*start;
	t_inst	*rez;
	int		i;

	i = 0;
	while (get_next_line(0, &line))
	{
		if (i == 0)
		{
			rez = create_inst(line);
			start = rez;
			i++;
			continue ;
		}
		rez->next = create_inst(line);
		rez = rez->next;
	}
	if (i == 0)
		execute_inst(NULL, stack);
	execute_inst(start, stack);
}

int			main(int ac, char **av)
{
	t_stack *stack;

	if (ac == 1)
		return (0);
	stack = init_stack();
	stack->a = init_a(av);
	if (stack->a == NULL)
		clear_stack(stack);
	read_inst(stack);
	return (0);
}
