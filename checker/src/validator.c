/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrady <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:04:32 by dgrady            #+#    #+#             */
/*   Updated: 2019/11/04 20:45:38 by dgrady           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lest	*init_a(char **str)
{
	int		i;
	int		j;
	char	**temp;
	t_lest	*start;
	t_lest	*rez;

	i = 0;
	start = NULL;
	while (str[++i])
	{
		temp = ft_strsplit(str[i], ' ');
		if (check_mass(temp) == 1)
			continue ;
		j = -1;
		if (start == NULL)
		{
			j++;
			if (check_string(NULL, temp[0]) == 0)
				go_exit(temp);
			rez = create_elem(atoi(temp[0]));
			start = rez;
		}
		rez = fuc_norma(temp, rez, j, start);
	}
	return (start);
}

int		check_if_long(char *str)
{
	int i;

	i = ft_atoii(str);
	if (i == 0)
	{
		if (str[0] == '0' && ft_strlen(str) == 1)
			return (1);
		else
			return (0);
	}
	return (1);
}

int		check_for_minus(char *str)
{
	int count;
	int i;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] == '-')
			count++;
	if (count > 1)
		return (0);
	if (count == 1)
		if (str[0] != '-')
			return (0);
	return (check_if_long(str));
}

int		check_if_contains(t_lest *lst, int data)
{
	t_lest *temp;

	temp = lst;
	if (!lst)
		return (1);
	while (temp)
	{
		if (temp->data == data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int		check_string(t_lest *lst, char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (ft_isdigit(str[i]) || str[i] == '-')
			;
		else
			return (0);
	if (check_for_minus(str) == 0)
		return (0);
	return (check_if_contains(lst, ft_atoi(str)));
}
