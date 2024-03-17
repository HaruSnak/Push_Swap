/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sorting_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:28:01 by shmoreno          #+#    #+#             */
/*   Updated: 2024/03/17 19:23:24 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Here you will find the functions that allow sorting the stacks
// using functions like ft_sa_sb, ft_pa_pb, ft_ra_rb...
// ft_sorting_third_b = sorting stack b
// ft_sorting_third_a = sorting stack a
void	ft_sorting_third_a(t_stack_node **stack_a, int **rank)
{
	while (!ft_check_stack(stack_a, rank, 'a'))
	{
		ft_compare_ranking(stack_a, rank);
		if ((*stack_a)->rank == 3 && (*stack_a)->next->rank == 1)
			ft_ra_rb(stack_a, 'a');
		else if ((*stack_a)->rank == 2 && (*stack_a)->next->rank == 1)
			ft_sa_sb(stack_a, 'a');
		else if ((*stack_a)->rank == 3 && (*stack_a)->next->rank == 2)
		{
			ft_sa_sb(stack_a, 'a');
			ft_rra_rrb(stack_a, 'a');
		}
		else if ((*stack_a)->rank == 1 && (*stack_a)->next->rank == 3)
		{
			ft_sa_sb(stack_a, 'a');
			ft_ra_rb(stack_a, 'a');
		}
		else if ((*stack_a)->rank == 2 && (*stack_a)->next->rank == 3)
			ft_rra_rrb(stack_a, 'a');
	}
}

void	ft_sorting_third_b(t_stack_node **stack_b)
{
	int		**rank;

	rank = ft_ranking(stack_b);
	ft_compare_ranking(stack_b, rank);
	while (!(ft_check_stack(stack_b, rank, 'b')))
	{
		if ((*stack_b)->rank == 1 && (*stack_b)->next->rank == 3)
			ft_ra_rb(stack_b, 'b');
		else if ((*stack_b)->rank == 2 && (*stack_b)->next->rank == 3)
			ft_sa_sb(stack_b, 'b');
		else if ((*stack_b)->rank == 2 && (*stack_b)->next->rank == 1)
			ft_rra_rrb(stack_b, 'b');
		else if (((*stack_b)->rank == 1 || (*stack_b)->rank == 3)
			&& ((*stack_b)->next->rank == 2 || (*stack_b)->next->rank == 1))
		{
			ft_rra_rrb(stack_b, 'b');
			ft_sa_sb(stack_b, 'b');
		}
		else if ((*stack_b)->rank == 1 && (*stack_b)->next->rank == 2)
		{
			ft_sa_sb(stack_b, 'b');
			ft_rra_rrb(stack_b, 'b');
		}
	}
	ft_free_rank(rank, stack_b);
}
