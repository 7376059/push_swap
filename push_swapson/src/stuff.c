/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:07:38 by dgrady            #+#    #+#             */
/*   Updated: 2019/11/04 20:58:25 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	clear_stack(t_stack *stack)
{
	clear_lest(stack->a);
	clear_lest(stack->b);
	free(stack);
	exit(0);
}

void	go_exit(char **str)
{
	clear_mas(str);
	exit(0);
}

t_stack	*init_stack(void)
{
	t_stack *rez;

	rez = (t_stack*)malloc(sizeof(t_stack));
	rez->a = NULL;
	rez->b = NULL;
	rez->b_dir = 0;
	rez->a_dir = 0;
	rez->a_spin = 0;
	rez->b_spin = 0;
	return (rez);
}
