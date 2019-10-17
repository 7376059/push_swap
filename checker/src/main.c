#include "push_swap.h"

t_lest *create_elem(int data)
{
	t_lest *rez;
	
	rez = (t_lest*)malloc(sizeof(t_lest));
	rez->data = data;
	rez->next = NULL;
	return (rez);
}

t_lest *init_a(char *str)
{
	t_lest *rez;
	t_lest *start;
	int data;
	int i;
	
	i = 0;
	while (str[i])
	{
		data = atoi(&str[i]);
		if (i == 0)
		{
			rez = create_elem(data);
			start = rez;
		}
		else
		{
			rez->next = create_elem(data);
			rez = rez->next;
		}
		if (str[i] == '-')
			i++;
		while(isdigit(str[i]))
			i++;
		while(isspace(str[i]))
            i++;
	}
	return (start);
}

t_stack *init_stack(char *str)
{
    t_stack *rez;

    rez = (t_stack*)malloc(sizeof(t_stack));
    rez->a = init_a(str);
    rez->b = NULL;
    rez->b_dir = 0;
    rez->a_dir = 0;
    rez->a_spin = 0;
    rez->b_spin = 0;
	rez->a_index = 0;
    return (rez);
}

t_stack *rotate_to_min(t_stack *stack)
{
	t_lest *temp;
	int min;
	int min_index;
	int i;

	temp = stack->a;
	i = 0;
	min = temp->data;
	min_index = 0;
	while(temp)
	{
		if (min < temp->data)
		{
			min = temp->data;
			min_index = i;
		}
		temp = temp->next;
		i++;
	}

	if (i / 2 > min_index)
	{
		i = min_index + 1;
		while (i-- > 0)
			stack = ra(1, stack);
	}
	else
	{
		i = i - min_index - 1 ;
		while (i-- > 0)
			stack = rra(1, stack);
	}
	return (stack);
}


int main(int ac, char **av)
{
	g_flag = 0;
	t_stack *stack;	
	stack = init_stack(av[1]);
	if (!g_flag)
		print_stack(stack);
}
