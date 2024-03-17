/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:44:11 by shmoreno          #+#    #+#             */
/*   Updated: 2024/03/17 19:25:48 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// ft_init initializes the stack from the arguments.
// It's the basis of filling if there are multiple args or just one.
void	ft_init(char **temp_or_argv, t_stack_node **stack_a)
{
	t_stack_node	*temp;
	t_stack_node	*last;

	temp = NULL;
	last = NULL;
	while (*temp_or_argv != NULL)
	{
		temp = (t_stack_node *)malloc(sizeof(t_stack_node));
		if (temp == NULL)
			ft_free_errors(stack_a);
		temp->nbr = ft_atoi(*temp_or_argv);
		if (temp->nbr < MININT || temp->nbr > MAXINT)
			ft_free_errors(stack_a);
		temp->next = NULL;
		temp->prev = last;
		if (last != NULL)
			last->next = temp;
		else
			*stack_a = temp;
		last = temp;
		temp_or_argv++;
	}
}


// ft_init_stack_alone_arg initializes the stack if there is
//only one argument.
void	ft_init_stack_alone_arg(t_stack_node **stack_a, char **argv)
{
	char	**temp_str;
	int		i;

	if (ft_error_multi_args(argv))
		temp_str = ft_split(argv[1], ' ');
	else
	{
		temp_str = malloc(sizeof(char *) * 2);
		if (!temp_str)
			ft_free_errors(stack_a);
		temp_str[0] = ft_strdup(argv[1]);
	}
	if (ft_error_multi_args(temp_str))
		ft_free_errors(stack_a);
	ft_init(temp_str, stack_a);
	if (ft_duplicate(stack_a))
		ft_free_errors(stack_a);
	i = 0;
	while (temp_str[i])
	{
		free(temp_str[i]);
		i++;
	}
	free(temp_str);
}

// ft_init_stack_a initializes the stack from the arguments.
void	ft_init_stack_a(t_stack_node **stack_a, int argc, char **argv)
{
	if (argc == 2)
	{
		ft_init_stack_alone_arg(stack_a, argv);
		return ;
	}
	if (ft_error_multi_args(argv))
	{
		ft_free_errors(stack_a);
	}
	argv++;
	ft_init(argv, stack_a);
	if (ft_duplicate(stack_a))
	{
		ft_free_errors(stack_a);
	}
}
