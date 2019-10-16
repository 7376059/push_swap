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
	rez->index = 0;
    return (rez);
}


t_stack *prepare_stack_a(t_stack *stack)
{
	int i;
	t_lest *temp;

	i = 0;
	temp = stack->a;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	if (i < 3)
		return (stack);
	while (i != 3)
	{
		stack = pb(stack);
		i--;
	}
	return (stack);
}

int main(int ac, char **av)
{
	t_stack *stack;	
	stack = init_stack(av[1]);
	stack = prepare_stack_a(stack);
	count_for_elem(0, stack);
	while (stack->a || stack->b)
	{
		if (stack->a)
		{
			printf("%d", stack->a->data);
			stack->a = stack->a->next;
		}
		if (stack->b)
		{
 			printf("\t%d", stack->b->data);
        	stack->b = stack->b->next;
		}
		printf("\n");
	}
}
