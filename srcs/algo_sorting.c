/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:54:19 by shmoreno          #+#    #+#             */
/*   Updated: 2024/03/17 19:23:37 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// ft_sorting_base is a function that sorts stack a and stack b
// using functions ft_compare_ranking, ft_loop_iteration,
// ft_sorting_one, ft_sort_c_start_low, ft_sort_c_end_low,
// ft_sorting_third_a_b, ft_sorting_third_a, and ft_sorting_final.
// Which are in the files algo_utils.c, algo_sorting_iteration.c,
// algo_sortingmore.c, and algo_sorting_final.c.
void	ft_sorting_base(t_stack_node **stack_a, t_stack_node **stack_b,
	int **rank)
{
	unsigned int	c_start;
	unsigned int	c_end;

	while (!ft_check_stack(stack_a, rank, 'a') || ft_size_stack(stack_b) != 0)
	{
		ft_compare_ranking(stack_a, rank);
		if (ft_size_stack(stack_a) > 3)
		{
			ft_loop_iteration(stack_a, &c_start, &c_end, rank);
			c_end = ft_size_stack(stack_a) - c_end;
			if (c_start == 1 && (c_start < c_end || c_end == 0))
				ft_sorting_one(stack_a, stack_b, &rank);
			else if (c_start <= c_end)
				ft_sort_c_start_low(stack_a, stack_b, c_start, &rank);
			else if (c_start > c_end)
				ft_sort_c_end_low(stack_a, stack_b, c_end, &rank);
			ft_sorting_third_a_b(stack_a, stack_b, &rank);
			if (ft_size_stack(stack_a) == 3)
			{
				ft_sorting_third_a(stack_a, rank);
				break ;
			}
		}
	}
	ft_sorting_final(stack_a, stack_b, &rank);
}
