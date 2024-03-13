/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:37:49 by shmoreno          #+#    #+#             */
/*   Updated: 2024/02/24 22:24:00 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Vous trouverez ici les fonctions qui permettent de comparer les piles
// et de les classer en fonction de leur position dans la pile.
// ft_check_stack = vérification de la pile
// ft_compare_ranking = comparaison du classement
// ft_last_rank = dernier classement
bool	ft_check_stack(t_stack_node **stack_a, int **rank, char c)
{
	t_stack_node	*current;
	int				i;
	int				c_inverse;

	current = *stack_a;
	c_inverse = ft_size_stack(stack_a) - 1;
	i = 0;
	while (current != NULL)
	{
		if (c == 'a')
		{
			if (*rank[i] != current->nbr)
				return (false);
			rank++;
		}
		else if (c == 'b')
		{
			if (*rank[c_inverse] != current->nbr)
				return (false);
			c_inverse--;
		}
		current = current->next;
	}
	return (true);
}

void	ft_compare_ranking(t_stack_node **stack, int **rank)
{
	t_stack_node	*current;
	int				i;
	int				l;

	current = *stack;
	i = 0;
	l = 0;
	while (current != NULL)
	{
		if (i <= ft_size_stack(stack) && rank[i][l] == current->nbr)
		{
			current->rank = i + 1;
			current = current->next;
			i = 0;
		}
		else
			i++;
	}
}

int	ft_last_rank(t_stack_node **stack)
{
	t_stack_node	*current;

	current = *stack;
	while (current != NULL)
	{
		if (current->next == NULL)
		{
			return (current->rank);
		}
		current = current->next;
	}
	return (-1);
}
