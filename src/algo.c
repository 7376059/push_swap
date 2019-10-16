#include "push_swap.h"


t_stack *count_for_b(int index, t_stack *stack)
{
	int i;
	t_lest *temp;

	temp = stack->b;
	i = 0;
	while(temp->next)
	{
		temp = temp->next;
		i++;
	}
	printf("%d\n", i);
	if (i / 2 > index)
	{
		stack->b_dir = 1;
		stack->b_spin = index;
	}
	else
	{
		stack->b_dir = -1;	
		stack->b_spin = i - index + 1;
	}
	return (stack);
}


int count_for_minimal(int data, t_stack *stack)
{
	t_lest *temp;
	int index_a;
	int minimal;
	int i;

	temp = stack->a;
	index_a = 0;
	minimal = 0;
	i = 0;

	while (temp)
	{
		:i	
	}
	
}


int  count_index_for_a(int index, t_stack *stack)
{
	t_lest *temp2;
	t_lest *temp;

	int  minimal;
	int i;
	int index_a;

	minimal = -2222222;
	
	temp2 = stack->b;
	temp = stack->a;
	i = 0;
	index_a = -1;
	while(index != 0)
	{
		temp2 = temp2->next;
		index--;
	}
	while (temp)
	{
		if (temp->data < temp2->data)
		{
			if (minimal < temp->data - temp2->data)
			{
				minimal = temp->data - temp2->data;
				index_a = i;
			}
		}
		i++;
		temp = temp->next;
	}
	//if (index_a == -1)
	//	return (count_for_minimal(temp2->data, stack));
	return(index_a);
}



int count_for_elem(int index, t_stack *stack)
{
	int i;

	i = count_index_for_a(2,stack);
	printf("index a = %d\n", i);
	//printf("%d\n\n", count_for_b(index, stack));
	
	return 1;
}
