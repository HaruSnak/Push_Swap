/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sortingmore.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:32:12 by shmoreno          #+#    #+#             */
/*   Updated: 2024/03/17 19:23:52 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Here you will find the functions that allow sorting the stacks
// using functions like ft_sa_sb, ft_pa_pb, ft_pre_sorting_b, ft_ra_rb,
// ft_rra_rrb, ft_size_stack, ft_ranking, ft_free_rank, ft_sorting_b,
// ft_sorting_third_b, ft_rrr, ft_sorting_one, ft_sort_c_start_low,
// ft_sort_c_end_low, ft_sorting_third_a_b, and ft_sorting_final.
// ft_sorting_one = 1 iteration of sorting c_start
// ft_sort_c_start_low = sorting c_start
// ft_sort_c_end_low = sorting c_end
void	ft_sorting_one(t_stack_node **stack_a, t_stack_node **stack_b,
	int ***rank)
{
	ft_sa_sb(stack_a, 'a');
	ft_free_rank(*rank, stack_a);
	ft_pa_pb(stack_b, stack_a, 'b');
	if (ft_size_stack(stack_b) >= 2)
		ft_pre_sorting_b(stack_b);
}

void	ft_sort_c_start_low(t_stack_node **stack_a, t_stack_node **stack_b,
	unsigned int c_start, int ***rank)
{
	while (c_start != 0)
	{
		ft_ra_rb(stack_a, 'a');
		c_start--;
	}
	ft_free_rank(*rank, stack_a);
	ft_pa_pb(stack_b, stack_a, 'b');
	if (ft_size_stack(stack_b) >= 2)
	{
		ft_pre_sorting_b(stack_b);
	}
}

void	ft_sort_c_end_low(t_stack_node **stack_a, t_stack_node **stack_b,
	unsigned int c_end, int ***rank)
{
	while (c_end != 0)
	{
		ft_rra_rrb(stack_a, 'a');
		c_end--;
	}
	ft_free_rank(*rank, stack_a);
	ft_pa_pb(stack_b, stack_a, 'b');
	if (ft_size_stack(stack_b) >= 2)
	{
		ft_pre_sorting_b(stack_b);
	}
}

void	ft_sorting_third_a_b(t_stack_node **stack_a, t_stack_node **stack_b,
	int ***rank)
{
	*rank = ft_ranking(stack_a);
	if (ft_size_stack(stack_b) == 3)
		ft_sorting_third_b(stack_b);
	ft_free_rank(*rank, stack_a);
	*rank = ft_ranking(stack_a);
}

void	ft_sorting_final(t_stack_node **stack_a, t_stack_node **stack_b,
	int ***rank)
{
	ft_free_rank(*rank, stack_a);
	if (ft_size_stack(stack_b) != 0)
		ft_sorting_b(stack_a, stack_b);
	*rank = ft_ranking(stack_a);
	ft_free_rank(*rank, stack_a);
}
