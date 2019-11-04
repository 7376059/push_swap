/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:02:00 by dgrady            #+#    #+#             */
/*   Updated: 2019/11/04 20:53:47 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*prepare_stack_a(t_stack *stack)
{
	int		i;
	t_lest	*temp;
	int		min;

	i = 0;
	temp = stack->a;
	min = temp->data;
	while (temp)
	{
		min = (min > temp->data ? temp->data : min);
		temp = temp->next;
		i++;
	}
	if (i < 3)
		return (stack);
	while (i != 3)
	{
		if (stack->a->data != min)
		{
			stack = pb(stack);
			i--;
		}
		stack = (stack->a->data == min ? ra(1, stack) : stack);
	}
	return (stack);
}

t_lest	*fuc_norma2(t_lest *temp, int *min, int *min_index, int *i)
{
	if (*min < temp->data)
	{
		*min = temp->data;
		*min_index = *i;
	}
	temp = temp->next;
	*i = *i + 1;
	return (temp);
}

t_stack	*rotate_to_min(t_stack *stack)
{
	t_lest	*temp;
	int		min;
	int		min_index;
	int		i;

	temp = stack->a;
	i = 0;
	min = temp->data;
	min_index = 0;
	while (temp)
		temp = fuc_norma2(temp, &min, &min_index, &i);
	if (i / 2 > min_index)
	{
		i = min_index + 1;
		while (i-- > 0)
			stack = ra(1, stack);
	}
	else
	{
		i = i - min_index - 1;
		while (i-- > 0)
			stack = rra(1, stack);
	}
	return (stack);
}

void	check_if_two(t_stack *stack)
{
	int		i;
	t_lest	*temp;

	i = 0;
	temp = stack->a;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	if (i == 2)
	{
		if (check_if_sorted(stack) == 0)
		{
			write(1, "sa\n", 3);
			clear_stack(stack);
		}
	}
}

int		main(int ac, char **av)
{
	t_stack *stack;

	stack = init_stack();
	stack->a = init_a(av);
	if (stack->a == NULL)
		clear_stack(stack);
	check_if_two(stack);
	if (check_if_sorted(stack))
		clear_stack(stack);
	stack = prepare_stack_a(stack);
	stack = sort_a(stack);
	stack = all_algo(stack);
	stack = rotate_to_min(stack);
	clear_stack(stack);
	return (0);
}
