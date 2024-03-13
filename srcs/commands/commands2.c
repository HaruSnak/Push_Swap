/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:26:10 by shmoreno          #+#    #+#             */
/*   Updated: 2024/02/23 18:12:28 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rra_rrb(t_stack_node **stack, char c)
{
	t_stack_node	*last;
	t_stack_node	*second_to_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next != NULL)
	{
		second_to_last = last;
		last = last->next;
	}
	second_to_last->next = NULL;
	last->next = *stack;
	*stack = last;
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}

void	ft_rrr_suit(t_stack_node *last, t_stack_node *prev, t_stack_node *tmp)
{
	last = tmp;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = tmp;
}

void	ft_rrr(t_stack_node **list1, t_stack_node **list2)
{
	t_stack_node	*last;
	t_stack_node	*prev;
	t_stack_node	*tmp;
	int				i;

	last = NULL;
	prev = NULL;
	i = -1;
	while (++i < 2)
	{
		if (i == 0)
			tmp = *list1;
		else
			tmp = *list2;
		if (tmp != NULL && tmp->next != NULL)
		{
			ft_rrr_suit(last, prev, tmp);
			if (i == 0)
				*list1 = last;
			else
				*list2 = last;
		}
	}
	ft_printf("rrr\n");
}
