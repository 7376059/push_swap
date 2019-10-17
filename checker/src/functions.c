#include "push_swap.h"

t_stack *sa(t_stack *stack)
{
	int i;

	if (g_flag)
		write(1, "sa\n", 3);
	if (!stack->a || stack->a->next == 0)
		return stack;
	i = stack->a->data;
	stack->a->data = stack->a->next->data;
	stack->a->next->data = i;
	return (stack);	
}


t_stack *pb(t_stack *stack)
{
	t_lest *temp;
	t_lest *temp2;
	
	if (g_flag)
		write(1, "pb\n", 3);
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

	if (g_flag)
		write(1, "pa\n", 3);
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

t_stack *ra(int i, t_stack *stack)
{
	t_lest *temp;
	t_lest *temp2;

	if (i && g_flag)
		write(1, "ra\n", 3);
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

t_stack *rb(int i, t_stack *stack)
{
    t_lest *temp;
    t_lest *temp2;
	

	if (i && g_flag)
        write(1, "rb\n", 3);
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
	if (g_flag)
		write(1, "rr\n", 3);
	stack = ra(0, stack);
	stack = rb(0, stack);
    return (stack);
}


t_stack *rra(int i, t_stack *stack)
{
	t_lest *temp;
	t_lest *temp2;
	t_lest *temp3;
	
	if (i && g_flag)
		write(1, "rra\n", 4);
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

t_stack *rrb(int i, t_stack *stack)
{
    t_lest *temp;
    t_lest *temp2;
    t_lest *temp3;
	
	if (i && g_flag)
		write(1, "rrb\n", 4);
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
	 if (g_flag)
        write(1, "rrr\n", 4);
	stack = rra(0, stack);
	stack = rrb(0, stack);
    return (stack);
}

