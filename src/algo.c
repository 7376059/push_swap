#include "push_swap.h"


int count_for_b(int index, t_stack *stack)
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
		return (index);
	else
		return (i - index + 1);
}


int count_for_elem(int index, t_stack *stack)
{
	printf("%d\n\n", count_for_b(index, stack));
	return 1;
}
