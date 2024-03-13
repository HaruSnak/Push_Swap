/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:02:28 by shmoreno          #+#    #+#             */
/*   Updated: 2024/02/24 22:15:45 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// error_multi_args permet de verifier si les arguments sont bien des int.
// error_alone_arg permet de verifier si l'argument est bien un int.
// base_errors permet de verifier si il y a bien des arguments.
// Cela me permet de filtrer les erreurs de base.
#include "../includes/push_swap.h"

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

// ft_duplicate sert a verifier si il y a des doublons dans la stack.
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

//ft_free_stack permet de free la stack.
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

//ft_free_rank permet de free le rank.
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

//ft_free_errors permet de free la stack et d'afficher l'erreur.
void	ft_free_errors(t_stack_node **a)
{
	ft_free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
