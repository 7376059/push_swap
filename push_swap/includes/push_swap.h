#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>   // убрать
# include <string.h> // убрать
# include <ctype.h>  // убрать

# include<unistd.h>
# include<stdlib.h>
# include<stdarg.h>


typedef struct s_lest
{
	int data;
	struct s_lest *next;
}		t_lest;


typedef struct s_stack
{

	t_lest *a;
	t_lest *b;

	int b_dir;
	int a_dir;
	int a_index;
	int a_spin;
	int b_spin;
	
}				t_stack ;

int g_flag;

t_lest *create_elem(int data);
t_stack *count_for_elem(int index, t_stack *stack);
t_stack *do_algo(t_stack *stack);
t_stack *count_for_all(t_stack *stack);
t_stack *all_algo(t_stack *stack);
void print_stack(t_stack *stack);


t_stack *sa(t_stack *stack);	
t_stack *pb(t_stack *stack);
t_stack *pa(t_stack *stack);
t_stack *ra(int i, t_stack *stack);
t_stack *rb(int i, t_stack *stack);
t_stack *rr(t_stack *stack);
t_stack *rra(int i, t_stack *stack);
t_stack *rrb(int i ,t_stack *stack);
t_stack *rrr(t_stack *stack);

/*
t_stack *sa(t_stack *stack);
t_stack *sb(t_stack *stack);
t_stack *ss(t_stack *stack);
t_stack *pa(t_stack *stack);
t_stack *pb(t_stack *stack);
t_stack *rrr(t_stack *stack);
t_stack *ra(int flag, t_stack *stack);
t_stack *rb(int flag, t_stack *stack);
t_stack *rr(t_stack *stack);
t_stack *rra(int flag, t_stack *stack);
t_stack *rrb(int flag, t_stack *stack);
t_stack *prepare_stacks(t_stack *stack);

t_stack *init_stacks(int ac, char **av);
t_stack *init_stacks_str(char *av);

int count_for_a(int index, t_stack *stack);
int count_for_b(int index, t_stack *stack);
int count_operations(int index, t_stack *stack);
int count_for_all(t_stack *stack);
*/


#endif
