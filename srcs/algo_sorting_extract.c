/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sorting_extract.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:53:32 by shmoreno          #+#    #+#             */
/*   Updated: 2024/03/17 19:22:59 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// ft_c_end_stronger_c_start sorts stack b and pushes it onto stack a.
// ft_sorting_b = sorting stack b, it is the basis of the sorting algorithm.
// ft_find_occurrence finds the number of occurrences of the value.
// ft_c_start_stronger_c_end = c_end
// ft_c_end_stronger_c_start = c_start
void	ft_c_end_stronger_c_start(t_stack_node **stack_a,
	t_stack_node **stack_b, int c_start, int ***rank)
{
	while (c_start != 0)
	{
		ft_ra_rb(stack_b, 'b');
		c_start--;
	}
	ft_free_rank(*rank, stack_b);
	ft_pa_pb(stack_a, stack_b, 'a');
	*rank = ft_ranking(stack_b);
}

void	ft_c_start_stronger_c_end(t_stack_node **stack_a,
	t_stack_node **stack_b, int c_end, int ***rank)
{
	while (c_end != 0)
	{
		ft_rra_rrb(stack_b, 'b');
		c_end--;
	}
	ft_free_rank(*rank, stack_b);
	ft_pa_pb(stack_a, stack_b, 'a');
	*rank = ft_ranking(stack_b);
}

void	ft_find_occurrence(t_stack_node **stack_b, int i,
	unsigned int *c_start, unsigned int *c_end)
{
	t_stack_node	*current;
	bool			check;
	int				**rank;

	current = *stack_b;
	check = false;
	rank = ft_ranking(stack_b);
	*c_start = 0;
	*c_end = 0;
	while (current->next != NULL)
	{
		if (current->nbr == rank[i][0])
			check = true;
		if (current->nbr != rank[i][0] && check == false)
			(*c_start)++;
		current = current->next;
	}
	*c_end = ft_size_stack(stack_b) - *c_start;
	ft_free_rank(rank, stack_b);
}

void	ft_sorting_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int				**rank;
	int				i;
	unsigned int	c_start;
	unsigned int	c_end;

	while (ft_size_stack(stack_b) >= 0)
	{
		rank = ft_ranking(stack_b);
		i = ft_size_stack(stack_b) - 1;
		ft_find_occurrence(stack_b, i, &c_start, &c_end);
		if (c_start == 1 && c_start <= c_end
			&& (*stack_b)->next->nbr == rank[i][0])
			ft_sa_sb(stack_b, 'b');
		else if (c_start <= c_end)
			ft_c_end_stronger_c_start(stack_a, stack_b, c_start, &rank);
		else if (c_start > c_end)
			ft_c_start_stronger_c_end(stack_a, stack_b, c_end, &rank);
		if (rank != NULL)
			ft_free_rank(rank, stack_b);
		if (ft_size_stack(stack_b) == 0)
			break ;
	}
}

//The system I had attempted in order to optimize the sorting algorithm.
/*void	ft_sorting_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	**rank;
	int	i;
	unsigned int	c_start;
	unsigned int	c_end;
	bool check;
	t_stack_node	*current;

	rank = ft_ranking(stack_b);
	i = ft_size_stack(stack_b) - 1;
	current = *stack_b;
	check = false;
	while (ft_size_stack(stack_b) >= 0)
	{
		i = ft_size_stack(stack_b) - 1;
		current = *stack_b;
		check = false;
		c_start = 0;
		c_end = 0;
		while (current->next != NULL)
		{
			if (current->nbr == rank[i][0])
				check = true;
			if (current->nbr != rank[i][0] && check == false)
				c_start++;
			current = current->next;
		}
		c_end = ft_size_stack(stack_b) - c_start;
		if (c_start == 1 && c_start <= c_end
			&& (*stack_b)->next->nbr == rank[i][0])
			ft_sa_sb(stack_b, 'b');
		else if (c_start == 2 && c_start <= c_end
			&& (*stack_b)->nbr == rank[i][0]
			&& ((*stack_b)->next->nbr == rank[i -1][0]
			|| (*stack_b)->next->nbr == rank[i -2][0])
			&& ((*stack_b)->next->next->nbr == rank[i -1][0]
			|| (*stack_b)->next->next->nbr == rank[i -2][0]))
		{
			ft_free_rank(rank, stack_b);
			ft_pa_pb(stack_a, stack_b, 'a');
			rank = ft_ranking(stack_b);
			if ((*stack_b)->nbr == rank[i -2][0])
				ft_sa_sb(stack_b, 'b');
		}
		else if (c_start == 2 && c_start <= c_end
			&& ((*stack_b)->nbr == rank[i -1][0]
			|| (*stack_b)->nbr == rank[i -2][0])
		&& ((*stack_b)->next->nbr == rank[i][0]
		|| (*stack_b)->next->nbr == rank[i -2][0]
		|| (*stack_b)->next->nbr == rank[i -1][0])
		&& ((*stack_b)->next->next->nbr == rank[i][0]
		|| (*stack_b)->next->next->nbr == rank[i -2][0]
		|| (*stack_b)->next->next->nbr == rank[i -1][0]))
		{
			ft_ra_rb(stack_b, 'b');
			if ((*stack_b)->nbr == rank[i][0])
			{
				ft_free_rank(rank, stack_b);
				ft_pa_pb(stack_a, stack_b, 'a');
				rank = ft_ranking(stack_b);
			}
			else if ((*stack_b)->nbr == rank[i -1][0]
			|| (*stack_b)->nbr == rank[i -2][0])
			{
				ft_sa_sb(stack_b, 'b');
				ft_free_rank(rank, stack_b);
				ft_pa_pb(stack_a, stack_b, 'a');
				rank = ft_ranking(stack_b);
			}
			ft_rra_rrb(stack_b, 'b');
		}
		else if (c_start <= c_end)
		{
			while (c_start != 0)
			{
				ft_ra_rb(stack_b, 'b');
				c_start--;
			}
			ft_free_rank(rank, stack_b);
			ft_pa_pb(stack_a, stack_b, 'a');
			rank = ft_ranking(stack_b);
		}
		else if (c_start > c_end)
		{
			while (c_end != 0)
			{
				ft_rra_rrb(stack_b, 'b');
				c_end--;
			}
			ft_free_rank(rank, stack_b);
			ft_pa_pb(stack_a, stack_b, 'a');
			rank = ft_ranking(stack_b);
		}
		if (rank != NULL)
			ft_free_rank(rank, stack_b);
		rank = ft_ranking(stack_b);
		if (ft_size_stack(stack_b) == 0)
			break ;
	}
	ft_free_rank(rank, stack_b);
}*/