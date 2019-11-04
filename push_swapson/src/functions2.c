/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:00:44 by dgrady            #+#    #+#             */
/*   Updated: 2019/11/04 21:02:46 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*sa(t_stack *stack)
{
	int i;

	write(1, "sa\n", 3);
	if (!stack->a || stack->a->next == 0)
		return (stack);
	i = stack->a->data;
	stack->a->data = stack->a->next->data;
	stack->a->next->data = i;
	return (stack);
}

t_stack	*pb(t_stack *stack)
{
	t_lest *temp;
	t_lest *temp2;
	t_lest *clear;

	write(1, "pb\n", 3);
	if (stack->b == NULL)
	{
		stack->b = create_elem(stack->a->data);
		clear = stack->a;
		stack->a = stack->a->next;
		free(clear);
		return (stack);
	}
	temp = stack->b;
	temp2 = stack->a;
	stack->a = stack->a->next;
	stack->b = temp2;
	stack->b->next = temp;
	return (stack);
}

t_stack	*pa(t_stack *stack)
{
	t_lest *temp;
	t_lest *temp2;
	t_lest *clear;

	write(1, "pa\n", 3);
	if (stack->a == NULL)
	{
		stack->a = create_elem(stack->b->data);
		clear = stack->b;
		stack->b = stack->b->next;
		free(clear);
		return (stack);
	}
	if (stack->b == NULL)
		return (stack);
	temp = stack->a;
	temp2 = stack->b;
	stack->b = stack->b->next;
	stack->a = temp2;
	stack->a->next = temp;
	return (stack);
}

t_stack	*ra(int i, t_stack *stack)
{
	t_lest *temp;
	t_lest *temp2;

	if (i)
		write(1, "ra\n", 3);
	if (stack->a == NULL || stack->a->next == NULL)
		return (stack);
	temp = stack->a;
	while (temp->next)
		temp = temp->next;
	temp2 = stack->a;
	stack->a = stack->a->next;
	temp->next = temp2;
	temp->next->next = NULL;
	return (stack);
}
