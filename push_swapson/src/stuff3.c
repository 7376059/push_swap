/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:56:29 by dgrady            #+#    #+#             */
/*   Updated: 2019/11/04 21:00:32 by dgrady           ###   ########.fr       */
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

int		ft_atoii(const char *str)
{
	int		flag;
	int		rez;

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
