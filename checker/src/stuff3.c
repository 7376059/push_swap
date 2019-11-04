/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:28:23 by dgrady            #+#    #+#             */
/*   Updated: 2019/11/04 20:46:33 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lest	*fuc_norma(char **temp, t_lest *rez, int j, t_lest *start)
{
	while (temp[++j])
	{
		if (check_string(start, temp[j]) == 0)
			go_exit(temp);
		rez->next = create_elem(ft_atoi(temp[j]));
		rez = rez->next;
	}
	clear_mas(temp);
	return (rez);
}

int		check_mass(char **temp)
{
	if (!temp || !temp[0])
	{
		clear_mas(temp);
		return (1);
	}
	return (0);
}

t_stack	*ra(t_stack *stack)
{
	t_lest *temp;
	t_lest *temp2;

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

void	not_valid_inst(t_stack *stack, t_inst *inst)
{
	if (inst)
		clear_inst(inst);
	write(1, "Error\n", 6);
	clear_stack(stack);
}
