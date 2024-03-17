/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sorting_iteration.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:52:14 by shmoreno          #+#    #+#             */
/*   Updated: 2024/03/17 20:59:39 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// ft_suits loops over the stack to find the c_end.
void	ft_suits(unsigned int *c_end, unsigned int *c_check,
	int *c_iteration, int low)
{
	(*c_iteration)++;
	if (*c_iteration < low)
		(*c_end)++;
	(*c_check) = (*c_end);
}

// ft_condition_exit allows exiting the loop if the stack is less than 13
// (BETA) MAXIMUM RANGE ERROR.
void	ft_condition_exit(t_stack_node **stack_a,
	unsigned int *c_end, unsigned int *c_check)
{
	if (ft_size_stack(stack_a) <= 13
		&& (*c_end) >= (unsigned int)ft_size_stack(stack_a) - 1)
	{
		(*c_end) = *c_check;
		return ;
	}
}

// ft_iteration_cend loops over the stack to find the c_end.
void	ft_iteration_cend(t_stack_node **stack_a, int **rank,
	unsigned int *c_end, int low)
{
	t_stack_node	*current;
	int				c_iteration;
	unsigned int	c_check;
	int				i;

	current = *stack_a;
	c_iteration = 0;
	i = ft_size_stack(stack_a) - 1;
	c_check = 0;
	while (current != NULL && ft_size_stack(stack_a) > 3)
	{
		if (current->nbr == rank[i][0] || current->nbr == rank[i -1][0]
			|| current->nbr == rank[i -2][0])
			(*c_end)++;
		else if (current->rank > low)
			(*c_end)++;
		else if (current->rank <= low)
			ft_suits(c_end, &c_check, &c_iteration, low);
		ft_condition_exit(stack_a, c_end, &c_check);
		if (c_iteration == low)
			break ;
		current = current->next;
	}
}

// ft_iteration_cstart loops over the stack to find the c_start.
void	ft_iteration_cstart(t_stack_node **stack_a, unsigned int *c_start,
			int low)
{
	t_stack_node	*current;
	bool			check_start;
	int				i;
	int				**rank;

	current = *stack_a;
	check_start = false;
	rank = ft_ranking(stack_a);
	i = ft_size_stack(stack_a) - 1;
	while (current != NULL && ft_size_stack(stack_a) > 3)
	{
		if ((current->nbr == rank[i][0] || current->nbr == rank[i -1][0]
			|| current->nbr == rank[i -2][0]) && !check_start)
			(*c_start)++;
		else if (current->rank > low && !check_start)
			(*c_start)++;
		else if (current->rank <= low && !check_start)
		{
			check_start = true;
		}
		current = current->next;
	}
	ft_free_rank(rank, stack_a);
}

// ft_loop_iteration loops over the stack to find the c_start and c_end.
void	ft_loop_iteration(t_stack_node **stack_a, unsigned int *c_start,
	unsigned int *c_end, int **rank)
{
	int	low;

	if (ft_size_stack(stack_a) <= 100)
		low = 10;
	else
		low = 30;
	if (ft_size_stack(stack_a) < low)
		low = ft_size_stack(stack_a) - 3;
	*c_start = 0;
	*c_end = 0;
	ft_iteration_cstart(stack_a, c_start, low);
	ft_iteration_cend(stack_a, rank, c_end, low);
}

//The complete function which does the same thing as the functions above.
/*void	ft_sorting(t_stack_node **stack_a,
	t_stack_node **stack_b, int **rank)
{
	int				low;
	int				i;
	int				result_start;
	int				result_end;
	t_stack_node	*current;
	int				c_start;
	int				c_end;
	int				c_iteration;
	int				c_check;
	bool			check_start;

	low = 30;
	if (ft_size_stack(stack_a) < low)
		low = ft_size_stack(stack_a) - 2;
	while (!ft_check_stack(stack_a, rank, 'a') || ft_size_stack(stack_b) != 0)
	{
		ft_compare_ranking(stack_a, rank);
		i = ft_size_stack(stack_a) - 1;
		if (ft_size_stack(stack_a) > 3)
		{
			current = *stack_a;
			check_start = false;
			result_start = 0;
			result_end = 0;
			c_iteration = 0;
			c_check = 0;
			c_start = 0;
			c_end = 0;
			if (ft_size_stack(stack_a) < (low + 3))
				low -= 1;
			while (current != NULL && ft_size_stack(stack_a) > 3)
			{
				if ((current->nbr == rank[i][0] || current->nbr == rank[i -1][0]
					|| current->nbr == rank[i -2][0]) && check_start == false)
				{
					c_start++;
				}
				else if (current->rank > low && check_start == false)
				{
					c_start++;
				}
				else if (current->rank <= low && !check_start)
				{
					result_start = current->nbr;
					check_start = true;
				}
				if (current->nbr == rank[i][0] || current->nbr == rank[i -1][0]
					|| current->nbr == rank[i -2][0])
				{
					c_end++;
				}
				else if (current->rank > low)
				{
					c_end++;
				}
				else if (current->rank <= low)
				{
					c_iteration++;
					if (c_iteration < low)
						c_end++;
					c_check = c_end;
					result_end = current->nbr;
				}
				if (ft_size_stack(stack_a) <= 13
					&& c_end >= ft_size_stack(stack_a) - 1)
				{
					c_end = c_check;
					break ;
				}
				if (c_iteration == low)
				{
					break ;
				}
				current = current->next;
			}
			if (c_start == c_end && result_start > result_end)
				c_start += 1;
			else if (c_start == c_end && result_start < result_end)
				c_end += 1;
			c_end = ft_size_stack(stack_a) - c_end;
			if (c_start == 1 && (c_start < c_end || c_end == 0))
			{
				c_end = 0;
				ft_sa_sb(stack_a, 'a');
				ft_free_rank(rank, stack_a);
				ft_pa_pb(stack_b, stack_a, 'b');
				c_start = -1;
				if (ft_size_stack(stack_b) >= 2)
					ft_pre_sorting_b(stack_b);
			}
			else if (c_start <= c_end)
			{
				while (c_start != 0)
				{
					ft_ra_rb(stack_a, 'a');
					c_start--;
				}
				c_end = 0;
				ft_free_rank(rank, stack_a);
				ft_pa_pb(stack_b, stack_a, 'b');
				if (ft_size_stack(stack_b) >= 2)
				{
					ft_pre_sorting_b(stack_b);
				}
			}
			else if (c_start > c_end)
			{
				while (c_end != 0)
				{
					ft_rra_rrb(stack_a, 'a');
					c_end--;
				}
				c_start = 0;
				ft_free_rank(rank, stack_a);
				ft_pa_pb(stack_b, stack_a, 'b');
				if (ft_size_stack(stack_b) > 3)
				{
					ft_pre_sorting_b(stack_b);
				}
			}
			rank = ft_ranking(stack_a);
			if (ft_size_stack(stack_a) == 3)
			{
				ft_sorting_third_a(stack_a, rank);
				break ;
			}
			if (ft_size_stack(stack_b) == 3)
			{
				ft_sorting_third_b(stack_b);
			}
			ft_free_rank(rank, stack_a);
			rank = ft_ranking(stack_a);
		}
	}
	ft_free_rank(rank, stack_a);
	if (ft_size_stack(stack_b) != 0)
	{
		ft_sorting_b(stack_a, stack_b);
	}
	rank = ft_ranking(stack_a);
	ft_free_rank(rank, stack_a);
}*/