/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:31:26 by shmoreno          #+#    #+#             */
/*   Updated: 2024/03/17 19:26:22 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Here you will find the functions that allow ranking the numbers
// in the stack based on their position in the stack.
// ft_size_stack = stack size
// ft_ranking_maxint = the largest number in the stack
// ft_rank_process = ranking process
// ft_ranking_init = ranking initialization
// ft_ranking = ranking
int	ft_size_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	int				i;

	i = 0;
	current = *stack;
	if (current == NULL)
		return (0);
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

int	ft_ranking_maxint(t_stack_node **stack)
{
	t_stack_node	*search;
	int				count;

	count = 0;
	search = *stack;
	if (search == NULL)
		return (-1);
	count = search->nbr;
	while (search != NULL)
	{
		if (count < search->nbr)
			count = search->nbr;
		search = search->next;
	}
	return (count);
}

void	ft_rank_process(t_stack_node *current, int **rank, int i, int l)
{
	int		j;
	bool	above_median;

	if (current != NULL)
	{
		if (rank[i][l] > current->nbr)
		{
			j = 0;
			above_median = false;
			while (j != i)
			{
				if (rank[j][l] == current->nbr)
					above_median = true;
				j++;
			}
			if (!above_median)
				rank[i][l] = current->nbr;
		}
		ft_rank_process(current->next, rank, i, l);
	}
}

void	ft_ranking_init(t_stack_node **stack, int **rank, int i, int l)
{
	t_stack_node	*current;

	if (i != ft_size_stack(stack))
	{
		current = *stack;
		rank[i][l] = ft_ranking_maxint(stack);
		ft_rank_process(current, rank, i, l);
		i++;
		ft_ranking_init(stack, rank, i, l);
	}
}

int	**ft_ranking(t_stack_node **stack)
{
	int	**rank;
	int	i;
	int	l;

	i = 0;
	l = 0;
	rank = (int **)malloc(sizeof(int *) * ft_size_stack(stack));
	if (rank == NULL)
	{
		ft_free_stack(stack);
		return (NULL);
	}
	while (i != ft_size_stack(stack))
	{
		rank[i] = (int *)malloc(sizeof(int));
		if (rank[i] == NULL)
		{
			ft_free_rank(rank, stack);
			return (NULL);
		}
		i++;
	}
	i = 0;
	ft_ranking_init(stack, rank, i, l);
	return (rank);
}
