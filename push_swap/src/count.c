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
	if (index == 0)
	{
		stack->b_dir = 0;
		stack->b_spin = 0;
		return (stack);
	}
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

t_stack *count_for_avg(int index_a, t_stack *stack)
{
	int i;
	t_lest *temp;

	temp = stack->a;
	i = 0;
	while(temp->next)
	{
		temp = temp->next;
        i++;
    }
	stack->a_index = index_a;	
	if (i / 2 >= index_a)
    {
        stack->a_dir = 1;
        stack->a_spin = index_a + 1;
    }
    else
    {
		//printf("here\n");
        stack->a_dir = -1;
        stack->a_spin = i - index_a;
    }
    return (stack);

}

t_stack  *count_index_for_a(int index, t_stack *stack)
{
	t_lest *temp2;
	t_lest *temp;

	int  minimal;
	int i;
	int index_a;

	minimal = -222222;
	
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
			if (minimal < (temp->data - temp2->data))
			{
				minimal = (temp->data - temp2->data);
				index_a = i;
			}
		}
		i++;
		temp = temp->next;
	}
//	printf("minimal = %d index_a = %d data = %d\n", minimal, index_a, temp2->data);
	//if (index_a == -1)
	//	return (count_for_minimal(temp2->data, stack));
	return(count_for_avg(index_a, stack));
}



t_stack *count_for_elem(int index, t_stack *stack)
{
	int i;
	
	stack = count_index_for_a(index,stack);
	stack = count_for_b(index, stack);
	
//	printf("a dir %d\n", stack->a_dir);
//	printf("a spin %d\n", stack->a_spin);
//	printf("a index %d\n", stack->a_index);
//	printf("b dir %d\n", stack->b_dir);
//	printf("b spin %d\n", stack->b_spin);
		
	return (stack);
}

int count_ops(t_stack *stack)
{
	int ops;
	int a;
	int b;
	
	a = stack->a_spin;
	b = stack->b_spin;
	ops = 0;
	if (a == b)
		while (a > 0  && b > 0)
		{
			//printf("a = %d b =  %d\n", a, b);
			ops++;
			a--;
			b--;
		}

	return (ops + a + b);
}

t_stack *count_for_all(t_stack *stack)
{
	int i;
	int min_ops;
	int min_index;
	int now;
	t_lest *temp;

	i = 0;
	min_ops = 100000;
	temp = stack->b;
	while (temp)
	{
	//	printf ("lol\n");
		stack = count_for_elem(i, stack);
	//	printf ("lol1\n");
		now = count_ops(stack);
		//printf("now now %d\n", now);
	//	printf ("lol2\n");
		if (now < min_ops)
		{
			min_ops = now;
			//printf("now %d, ops = %d\n", now, min_ops);
			min_index = i;
		}
		temp = temp->next;
		i++;
	}
	//printf("min_index = %d\n", min_index);
	stack = count_for_elem(min_index, stack);
	/*
	printf("stack->a_d %d\n", stack->a_dir);
	printf("stack->a_s %d\n", stack->a_spin);
	printf("stack->b_d %d\n", stack->b_dir);
    printf("stack->b_s %d\n", stack->b_spin);
	*/
	return (stack);
}



























