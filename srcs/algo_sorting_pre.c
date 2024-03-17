/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sorting_pre.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:48:52 by shmoreno          #+#    #+#             */
/*   Updated: 2024/03/17 19:21:33 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Here you will find the functions that allow pre-sorting stack B
// Simplified by this function, the prototype in the comment is more complex
// However, it is not finished and does not work correctly.
void	ft_pre_sorting_b(t_stack_node **stack_b)
{
	int		**rank;

	rank = ft_ranking(stack_b);
	ft_compare_ranking(stack_b, rank);
	if (ft_size_stack(stack_b) >= 2)
	{
		if ((*stack_b)->rank < ft_last_rank(stack_b))
		{
			ft_ra_rb(stack_b, 'b');
		}
		else if ((*stack_b)->rank < (*stack_b)->next->rank)
		{
			ft_sa_sb(stack_b, 'b');
		}
	}
	ft_free_rank(rank, stack_b);
}

/*void	ft_pre_sorting_rr(t_stack_node **stack_b, t_stack_node **stack_a,
		int *c_start, int result_start)
{
	t_stack_node	*current;
	int				c_rr;
	int				c_value;
	int				c_freeze;
	static int		c_rrb;

	current = *stack_b;
	c_rr = 0;
	c_freeze = 0;
	c_value = 0;
	if (*c_start >= 0)
	{
		printf("ICCCCCCCCCCCCCCCCCCI\n");
		while (current != NULL)
		{
			if (current->nbr < result_start)
			{
				c_rr++;
				printf("1| c_rr: %d\n", c_rr);
			}
			else if (current->nbr > result_start)
			{
				c_rr++;
				printf("2| c_rr: %d\n", c_rr);
				if (c_value == 0 || c_value > (current->nbr - result_start))
				{
					c_value = current->nbr - result_start;
					printf("value: %d | nbr: %d\n", c_value, current->nbr);
					c_freeze = c_rr - 1;
				}
				printf("ICI\n");
			}
			current = current->next;
		}
		if (c_freeze > 2)
			c_freeze = 2;
		c_rr = c_freeze;
		if (c_rr != 0)
			c_rrb = c_rr;
		printf("c_rr: %d c_rrb: %d\n", c_rr, c_rrb);
		printf("c_rr: %d | c_freeze: %d\n", c_rr, c_freeze);
		printf("result_start: %d | c_start: %d\n", result_start, *c_start);
		printf("c_rr: %d c_rrb: %d\n", c_rr, c_rrb);
		current = *stack_b;
		while (current != NULL)
		{
			printf("stack_b: %d\n", current->nbr);
			printf("stack->rank: %d\n", current->rank);
			current = current->next;
		}
		if (c_rr == 1 && c_rrb == 1)
			c_rr = 0;
		while (c_rr != 0)
		{
			if (*c_start > 0)
			{
				*c_start -= 1;
				ft_rr(stack_a, stack_b);
			}
			else if (*c_start == 0)
			{
				ft_ra_rb(stack_b, 'b');
			}
			c_rr--;
		}
		current = *stack_b;
		while (current != NULL)
		{
			printf("stack_b: %d\n", current->nbr);
			printf("stack->rank: %d\n", current->rank);
			current = current->next;
		}
	}
	else if (*c_start < 0)
	{
		if (c_rrb > 1)
		{
			while (c_rrb != 0)
			{
				ft_rra_rrb(stack_b, 'b');
				c_rrb--;
			}
			current = *stack_b;
			int i = 0;
			while (current != NULL)
			{
				printf("%d | stack_b: %d\n", i, current->nbr);
				i++;
				current = current->next;
			}
			if (result_start == 1000)
				exit(1);
			return ;
		}
		else if (c_rr == 0 && c_rrb == 1)
		{
			ft_sa_sb(stack_b, 'b');
			c_rrb--;
		}
	}
}

void	ft_pre_sorting_rrr(t_stack_node **stack_b, t_stack_node **stack_a,
		int *c_end, int result_end)
{
	t_stack_node	*current;
	unsigned int	c_rrr;
	int				c_value;
	unsigned int	c_freeze;
	static int		c_rb;

	current = *stack_b;
	c_rrr = 0;
	c_freeze = 0;
	c_value = 0;
	if (*c_end >= 0)
	{
		while (current != NULL)
		{
			if (current->nbr < result_end)
			{
				c_rrr++;
			}
			else if (current->nbr > result_end)
			{
				c_rrr++;
				if (c_value == 0 || c_value > (current->nbr - result_end))
				{
					c_value = current->nbr - result_end;
					printf("nbr: %d\n", current->nbr);
					printf("crrr: %d size: %d\n", c_rrr, ft_size_stack(stack_b));
					c_freeze = ft_size_stack(stack_b) - c_rrr;
					printf("c_freeze: %d\n", c_freeze);
				}
			}
			current = current->next;
		}
		if (c_freeze > 2)
			c_freeze = 2;
		c_rrr = c_freeze;
		if (c_rrr != 0)
			c_rb = c_rrr;
		printf("c_rrr: %d | c_freeze: %d\n", c_rrr, c_freeze);
		printf("result_end: %d | c_end: %d\n", result_end, *c_end);
		printf("c_rrr: %d c_rb: %d\n", c_rrr, c_rb);
		current = *stack_b;
		int i = 0;
		while (current != NULL)
		{
			printf("%d | stack_b: %d\n", i, current->nbr);
			//printf("%d | c_end: %d\n", i, *c_end);
			i++;
			current = current->next;
		}
		//exit(1);
		while (c_rrr != 0) 
		{
			if (*c_end >= 1)
			{
				ft_rrr(stack_a, stack_b);
				*c_end -= 1;
			}
			else if (*c_end == 0)
			{
				ft_rra_rrb(stack_b, 'b');
			}
			c_rrr--;
			printf("result_end: %d | c_end: %d\n", result_end, *c_end);
			printf("c_rrr: %d c_rb: %d\n", c_rrr, c_rb);
		}
	}
	else if (*c_end < 0)
	{
		printf("ICIIII\n");
		if (c_rb > 1)
		{
			while (c_rb != 0)
			{
				ft_ra_rb(stack_b, 'b');
				c_rb--;
			}
			current = *stack_b;
			int i = 0;
			while (current != NULL)
			{
				printf("%d | stack_b: %d\n", i, current->nbr);
				i++;
				current = current->next;
			}
			if (result_end == 17)
				exit(1);
			return ;
		}
		else if (c_rb == 1 && c_rrr == 0)
		{
			ft_sa_sb(stack_b, 'b');
			c_rb--;
			if (result_end == 17)
				exit(1);
		}
	}
}*/
