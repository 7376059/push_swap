/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:19:04 by dgrady            #+#    #+#             */
/*   Updated: 2019/11/04 18:25:07 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_inst	*create_inst(char *str)
{
	t_inst *rez;

	rez = (t_inst*)malloc(sizeof(t_inst));
	rez->str = str;
	rez->next = NULL;
	return (rez);
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

void	clear_mas(char **str)
{
	int i;

	i = -1;
	if (!str)
		return ;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	clear_inst(t_inst *lest)
{
	t_inst *temp;

	if (lest == NULL)
		return ;
	temp = lest;
	while (lest)
	{
		temp = lest;
		lest = lest->next;
		if (temp->str)
			free(temp->str);
		free(temp);
	}
}

void	clear_lest(t_lest *lest)
{
	t_lest *temp;

	if (lest == NULL)
		return ;
	temp = lest;
	while (lest)
	{
		temp = lest;
		lest = lest->next;
		free(temp);
	}
}
