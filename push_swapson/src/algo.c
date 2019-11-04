/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:54:48 by dgrady            #+#    #+#             */
/*   Updated: 2019/11/04 19:56:42 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*spin_stack(t_stack *stack)
{
	stack->a_spin--;
	stack->b_spin--;
	return (stack);
}

t_stack	*do_algo(t_stack *stack)
{
	if (stack->a_dir == stack->b_dir)
	{
		if (stack->a_dir == -1)
		{
			while (stack->a_spin > 0 && stack->b_spin > 0)
			{
				stack = rrr(stack);
				stack = spin_stack(stack);
			}
		}
		if (stack->a_dir == 1)
		{
			while (stack->a_spin && stack->b_spin)
			{
				stack = rr(stack);
				stack = spin_stack(stack);
			}
		}
	}
	while (stack->a_spin-- > 0)
		stack = (stack->a_dir == 1 ? ra(1, stack) : rra(1, stack));
	while (stack->b_spin-- > 0)
		stack = (stack->b_dir == 1 ? rb(1, stack) : rrb(1, stack));
	stack = pa(stack);
	return (stack);
}

t_stack	*all_algo(t_stack *stack)
{
	while (stack->b != NULL)
	{
		stack = count_for_all(stack);
		stack = do_algo(stack);
	}
	return (stack);
}
