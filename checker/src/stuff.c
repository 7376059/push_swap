/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:07:38 by dgrady            #+#    #+#             */
/*   Updated: 2019/11/04 20:33:14 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_atoii(const char *str)
{
	int	flag;
	int	rez;

	rez = 0;
	flag = 1;
	while (*str == 32 || (8 < *str && *str < 14))
		str++;
	flag = ((*str == '-') ? -1 : 1);
	if (flag == -1 || *str == '+')
		(str++);
	while (*str > 47 && *str < 58)
		if ((rez = rez * 10 + (*(str++)) - 48) < 0)
			return (0);
	return ((int)(rez * flag));
}

t_lest	*create_elem(int data)
{
	t_lest *rez;

	rez = (t_lest*)malloc(sizeof(t_lest));
	rez->data = data;
	rez->next = NULL;
	return (rez);
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
	write(1, "Error\n", 6);
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
