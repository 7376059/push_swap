/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:14:06 by dgrady            #+#    #+#             */
/*   Updated: 2019/11/04 20:44:57 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*rb(t_stack *stack)
{
	t_lest *temp;
	t_lest *temp2;

	if (stack->b == NULL || stack->b->next == NULL)
		return (stack);
	temp = stack->b;
	while (temp->next)
		temp = temp->next;
	temp2 = stack->b;
	stack->b = stack->b->next;
	temp->next = temp2;
	temp->next->next = NULL;
	return (stack);
}

t_stack	*rr(t_stack *stack)
{
	stack = ra(stack);
	stack = rb(stack);
	return (stack);
}

t_stack	*rra(t_stack *stack)
{
	t_lest *temp;
	t_lest *temp2;
	t_lest *temp3;

	if (stack->a == NULL || stack->a->next == NULL)
		return (stack);
	temp3 = stack->a;
	while (temp3->next->next)
		temp3 = temp3->next;
	temp = temp3->next;
	temp2 = stack->a;
	stack->a = temp;
	stack->a->next = temp2;
	temp3->next = NULL;
	return (stack);
}

t_stack	*rrb(t_stack *stack)
{
	t_lest *temp;
	t_lest *temp2;
	t_lest *temp3;

	if (stack->b == NULL || stack->b->next == NULL)
		return (stack);
	temp3 = stack->b;
	while (temp3->next->next)
		temp3 = temp3->next;
	temp = temp3->next;
	temp2 = stack->b;
	stack->b = temp;
	stack->b->next = temp2;
	temp3->next = NULL;
	return (stack);
}

t_stack	*rrr(t_stack *stack)
{
	stack = rra(stack);
	stack = rrb(stack);
	return (stack);
}
