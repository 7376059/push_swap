/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:32:55 by dgrady            #+#    #+#             */
/*   Updated: 2019/11/04 20:52:51 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*count_for_avg(int index_a, t_stack *stack)
{
	int		i;
	t_lest	*temp;

	temp = stack->a;
	i = 0;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	if (i / 2 >= index_a)
	{
		stack->a_dir = 1;
		stack->a_spin = index_a + 1;
	}
	else
	{
		stack->a_dir = -1;
		stack->a_spin = i - index_a;
	}
	return (stack);
}

t_stack	*count_index_for_a(int index, t_stack *stack)
{
	t_lest	*temp2;
	t_lest	*temp;
	int		minimal;
	int		i;
	int		index_a;

	minimal = -2147483648;
	temp2 = stack->b;
	temp = stack->a;
	i = 0;
	index_a = -1;
	while (index-- != 0)
		temp2 = temp2->next;
	while (temp)
	{
		if (temp->data < temp2->data)
			if (minimal < (temp->data - temp2->data))
			{
				minimal = (temp->data - temp2->data);
				index_a = i;
			}
		i++;
		temp = temp->next;
	}
	return (count_for_avg(index_a, stack));
}

t_stack	*count_for_elem(int index, t_stack *stack)
{
	int i;

	stack = count_index_for_a(index, stack);
	stack = count_for_b(index, stack);
	return (stack);
}

int		count_ops(t_stack *stack)
{
	int ops;
	int a;
	int b;

	a = stack->a_spin;
	b = stack->b_spin;
	ops = 0;
	if (a == b)
		while (a > 0 && b > 0)
		{
			ops++;
			a--;
			b--;
		}
	return (ops + a + b);
}

t_stack	*count_for_all(t_stack *stack)
{
	int		i;
	int		min_ops;
	int		min_index;
	int		now;
	t_lest	*temp;

	i = 0;
	min_ops = 100000;
	temp = stack->b;
	while (temp)
	{
		stack = count_for_elem(i, stack);
		now = count_ops(stack);
		if (now < min_ops)
		{
			min_ops = now;
			min_index = i;
		}
		temp = temp->next;
		i++;
	}
	stack = count_for_elem(min_index, stack);
	return (stack);
}
