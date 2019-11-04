/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:49:22 by dgrady            #+#    #+#             */
/*   Updated: 2019/11/04 20:56:11 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*sort_a(t_stack *stack)
{
	int temp1;
	int temp2;
	int temp3;

	temp1 = stack->a->data;
	temp2 = stack->a->next->data;
	temp3 = stack->a->next->next->data;
	if (temp1 < temp2 && temp1 < temp3 && temp3 > temp2)
		return (stack);
	if (temp1 > temp2 && temp1 > temp3 && temp2 < temp3)
		return (stack);
	if (temp1 < temp2 && temp1 > temp3 && temp2 > temp3)
		return (stack);
	stack = sa(stack);
	return (stack);
}

int		check_if_sorted(t_stack *stack)
{
	t_lest	*slow;
	t_lest	*fast;
	int		i;
	int		flag;

	flag = 1;
	if (stack->b != NULL)
		return (0);
	if (stack->a->next == NULL)
		return (1);
	slow = stack->a;
	fast = stack->a->next;
	while (fast)
	{
		if (slow->data > fast->data)
			return (0);
		slow = slow->next;
		fast = fast->next;
	}
	return (1);
}

t_stack	*keks_shpeks(t_stack *stack, int i, int index)
{
	stack->b_dir = -1;
	stack->b_spin = i - index + 1;
	return (stack);
}

t_stack	*count_for_b(int index, t_stack *stack)
{
	int		i;
	t_lest	*temp;

	temp = stack->b;
	i = 0;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	if (index == 0)
	{
		stack->b_dir = 0;
		stack->b_spin = 0;
		return (stack);
	}
	if (i / 2 > index)
	{
		stack->b_dir = 1;
		stack->b_spin = index;
	}
	else
		stack = keks_shpeks(stack, i, index);
	return (stack);
}
