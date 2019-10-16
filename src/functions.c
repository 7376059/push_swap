#include "push_swap.h"

t_stack *pb(t_stack *stack)
{
	t_lest *temp;
	t_lest *temp2;

	if (stack->b == NULL)
	{
		stack->b = create_elem(stack->a->data);
		stack->a = stack->a->next;
		return (stack);
	}
	temp = stack->b;
	temp2 = stack->a;
	stack->a = stack->a->next;
	stack->b = temp2;
    stack->b->next = temp;
	return (stack);
}

t_stack *pa(t_stack *stack)
{
    t_lest *temp;
    t_lest *temp2;

    if (stack->a == NULL)
    {
        stack->a = create_elem(stack->b->data);
        stack->b = stack->b->next;
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

t_stack *ra(t_stack *stack)
{
	t_lest *temp;
	t_lest *temp2;

	if (stack->a == NULL || stack->a->next == NULL)
		return (stack);
	temp = stack->a;
	while(temp->next)
		temp = temp->next;

	temp2 = stack->a;
	stack->a = stack->a->next;
	temp->next = temp2;
	temp->next->next = NULL;
	return (stack);
}

t_stack *rb(t_stack *stack)
{
    t_lest *temp;
    t_lest *temp2;

    if (stack->b == NULL || stack->b->next == NULL)
        return (stack);
    temp = stack->b;
    while(temp->next)
        temp = temp->next;

    temp2 = stack->b;
    stack->b = stack->b->next;
    temp->next = temp2;
    temp->next->next = NULL;
    return (stack);
}

t_stack *rr(t_stack *stack)
{
	stack = ra(stack);
	stack = rb(stack);
    return (stack);
}


t_stack *rra(t_stack *stack)
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

t_stack *rrb(t_stack *stack)
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

t_stack *rrr(t_stack *stack)
{
	stack = rra(stack);
	stack = rrb(stack);
    return (stack);
}

