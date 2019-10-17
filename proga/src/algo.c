#include "push_swap.h"

t_stack  *do_algo(t_stack *stack)
{
	if (stack->a_dir == stack->b_dir)
	{
		if (stack->a_dir == -1)
		{
			while (stack->a_spin > 0 && stack->b_spin > 0)
			{
				stack = rrr(stack);
				stack->a_spin--;
				stack->b_spin--;
			}
		}
		if (stack->a_dir == 1)
		{
            while (stack->a_spin && stack->b_spin)
			{
                stack = rr(stack);
				stack->a_spin--;
 				stack->b_spin--;
			}
		}
	}
	while (stack->a_spin > 0)
	{
		stack = (stack->a_dir == 1 ? ra(1, stack) : rra(1, stack));
		stack->a_spin--;
	}
	while (stack->b_spin-- > 0)
	{
		stack = (stack->b_dir == 1 ? rb(1, stack) : rrb(1, stack));
	}
	stack = pa(stack);
	return (stack);
}

void print_stack(t_stack *stack)
{
	t_lest *a;
	t_lest *b;

	a = stack->a;
	b = stack->b;

	while (a || b)
    {
        if (a)
        {
            printf("%d", a->data);
            a = a->next;
        }
        if (b)
        {
            printf("\t%d", b->data);
            b = b->next;
        }
        printf("\n");
    }
	printf("#######################\n");
}


t_stack *all_algo(t_stack *stack)
{
	while (stack->b != NULL)
	{
	//	printf("lol\n");
		stack = count_for_all(stack);
	//	printf("kek\n");
		/*
		printf("@@@@@@@@@@@@@@@@\n");
	    printf("stack->a_d %d\n", stack->a_dir);
	    printf("stack->a_s %d\n", stack->a_spin);
	    printf("stack->b_d %d\n", stack->b_dir);
	    printf("stack->b_s %d\n", stack->b_spin);
		*/
		
		//if (g_flag == 0)
		//	print_stack(stack);
    	stack = do_algo(stack);
	//	printf("chikipow\n");
		//print_stack(stack);
		//printf("#######################\n");
	}
	return (stack);
}
