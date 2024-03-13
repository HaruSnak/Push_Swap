/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:40:06 by shmoreno          #+#    #+#             */
/*   Updated: 2024/02/24 22:13:34 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				**rank;

	if (argc == 1 || (argc == 1 && argv[1][0] == '\0'))
		return (1);
	a = NULL;
	b = NULL;
	ft_init_stack_a(&a, argc, argv);
	rank = ft_ranking(&a);
	if (ft_size_stack(&a) == 2 && (!ft_check_stack(&a, rank, 'a')))
		ft_sa_sb(&a, 'a');
	else if (ft_size_stack(&a) == 3)
		ft_sorting_third_a(&a, rank);
	else if (ft_size_stack(&a) > 3)
	{
		ft_sorting_base(&a, &b, rank);
		rank = ft_ranking(&a);
	}
	/*t_stack_node *tmp = a;
	while (tmp != NULL)
	{
		printf("stack_a: %d\n", tmp->nbr);
		tmp = tmp->next;
	}*/
	ft_free_rank(rank, &a);
	ft_free_stack(&a);
	return (0);
}
