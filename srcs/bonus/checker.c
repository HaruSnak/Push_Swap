/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:08:11 by shmoreno          #+#    #+#             */
/*   Updated: 2024/02/24 22:30:02 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// ft_check_cmds permet de verifier les commandes
// ft_verification permet d'analyser ce que ft_check_cmds a verifier
void	ft_check_cmds(t_stack_node **stack_a, t_stack_node **stack_b,
	char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		ft_sa_sb(stack_a, 'a');
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		ft_sa_sb(stack_b, 'b');
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		ft_pa_pb(stack_a, stack_b, 'a');
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		ft_pa_pb(stack_b, stack_a, 'b');
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ft_ra_rb(stack_a, 'a');
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ft_ra_rb(stack_b, 'b');
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		ft_rr(stack_a, stack_b);
	else if (line[0] == 'r' && line[1] == 'r'
		&& line[2] == 'a' && line[3] == '\n')
		ft_rra_rrb(stack_a, 'a');
	else if (line[0] == 'r' && line[1] == 'r'
		&& line[2] == 'b' && line[3] == '\n')
		ft_rra_rrb(stack_b, 'b');
	else if (line[0] == 'r' && line[1] == 'r'
		&& line[2] == 'r' && line[3] == '\n')
		ft_rrr(stack_a, stack_b);
	else
		ft_free_errors(stack_a);
}

void	ft_verification(t_stack_node **stack_a, t_stack_node **stack_b,
	char *line, int **rank)
{
	while (line != NULL)
	{
		ft_check_cmds(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	if (ft_check_stack(stack_a, rank, 'a'))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	char			*line;
	int				**rank;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2 || (argc == 2 && argv[1][0] == '\0') || argc == 1)
		return (1);
	ft_init_stack_a(&stack_a, argc, argv);
	rank = ft_ranking(&stack_a);
	line = get_next_line(0);
	if (!line && !ft_check_stack(&stack_a, rank, 'a'))
		ft_printf("KO\n");
	else if (!line && ft_check_stack(&stack_a, rank, 'a'))
		ft_printf("OK\n");
	else
		ft_verification(&stack_a, &stack_b, line, rank);
	ft_free_rank(rank, &stack_a);
	ft_free_stack(&stack_a);
	return (0);
}
