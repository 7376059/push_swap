/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:42:59 by dgrady            #+#    #+#             */
/*   Updated: 2019/11/04 20:44:13 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*sb(t_stack *stack)
{
	int i;

	if (!stack->b || stack->b->next == 0)
		return (stack);
	i = stack->b->data;
	stack->b->data = stack->b->next->data;
	stack->b->next->data = i;
	return (stack);
}

t_stack	*sa(t_stack *stack)
{
	int i;

	if (!stack->a || stack->a->next == 0)
		return (stack);
	i = stack->a->data;
	stack->a->data = stack->a->next->data;
	stack->a->next->data = i;
	return (stack);
}

t_stack	*ss(t_stack *stack)
{
	stack = sa(stack);
	stack = sb(stack);
	return (stack);
}

t_stack	*pb(t_stack *stack)
{
	t_lest *temp;
	t_lest *temp2;
	t_lest *clear;

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
