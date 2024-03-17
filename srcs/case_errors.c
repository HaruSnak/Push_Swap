/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:02:28 by shmoreno          #+#    #+#             */
/*   Updated: 2024/03/17 19:25:05 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// error_multi_args checks if the arguments are indeed integers.
// error_alone_arg checks if the argument is indeed an integer.
// base_errors checks if there are any arguments at all.
// This allows me to filter basic errors.
int	ft_error_multi_args(char **argv)
{
	size_t	i;

	argv++;
	while (*argv != NULL)
	{
		i = 0;
		while ((*argv)[i] != '\0')
		{
			if (!(((*argv)[i] == '+' || (*argv)[i] == '-') || ((*argv)[i] >= '0'
						&& (*argv)[i] <= '9')))
				return (1);
			if (((*argv)[i] == '+' || (*argv)[i] == '-')
				&& !((*argv)[i + 1] >= '0' && (*argv)[i + 1] <= '9'))
				return (1);
			i++;
		}
		argv++;
	}
	return (0);
}

// ft_duplicate is used to check if there are any duplicates in the stack.
int	ft_duplicate(struct s_stack_node **stack_a)
{
	struct s_stack_node	*base;
	struct s_stack_node	*compare;

	base = *stack_a;
	while (base != NULL && base->next != NULL)
	{
		compare = base->next;
		while (compare != NULL)
		{
			if (base->nbr == compare->nbr)
				return (1);
			compare = compare->next;
		}
		base = base->next;
	}
	return (0);
}

// ft_free_stack is used to free the stack.
void	ft_free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*next;

	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

// ft_free_rank is used to free the rank.
void	ft_free_rank(int **rank, t_stack_node **stack)
{
	int	i;

	i = 0;
	while (i != ft_size_stack(stack))
	{
		free(rank[i]);
		i++;
	}
	free(rank);
}

// ft_free_errors is used to free the stack and display the error.
void	ft_free_errors(t_stack_node **a)
{
	ft_free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
