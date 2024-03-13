/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:26:16 by shmoreno          #+#    #+#             */
/*   Updated: 2024/02/23 17:37:25 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sa_sb(struct s_stack_node **list, char c)
{
	struct s_stack_node	*temp;

	if (*list != NULL && (*list)->next != NULL)
	{
		temp = (*list)->next;
		(*list)->next = temp->next;
		temp->next = *list;
		*list = temp;
		if (c == 'a')
			ft_printf("sa\n");
		if (c == 'b')
			ft_printf("sb\n");
	}
}

void	ft_ss(struct s_stack_node **list, struct s_stack_node **list2)
{
	struct s_stack_node	*temp;
	struct s_stack_node	*temp2;

	if (*list != NULL && (*list)->next != NULL && *list2 != NULL
		&& (*list2)->next != NULL)
	{
		temp = (*list)->next;
		(*list)->next = temp->next;
		temp->next = *list;
		*list = temp;
		temp2 = (*list2)->next;
		(*list2)->next = temp2->next;
		temp2->next = *list2;
		*list2 = temp2;
		ft_printf("ss\n");
	}
}

void	ft_pa_pb(struct s_stack_node **dest, struct s_stack_node **src, char c)
{
	struct s_stack_node	*temp;

	if ((c == 'a' || c == 'b') && (*src != NULL))
	{
		temp = *src;
		*src = (*src)->next;
		temp->next = *dest;
		*dest = temp;
		ft_printf("p%c\n", c);
	}
}

void	ft_ra_rb(struct s_stack_node **list, char c)
{
	struct s_stack_node	*temp;

	if (*list != NULL && (*list)->next != NULL)
	{
		temp = *list;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = *list;
		*list = (*list)->next;
		temp->next->next = NULL;
		if (c == 'a')
			ft_printf("ra\n");
		if (c == 'b')
			ft_printf("rb\n");
	}
}

void	ft_rr(struct s_stack_node **list, struct s_stack_node **list2)
{
	struct s_stack_node	*temp;
	struct s_stack_node	*temp2;

	if (*list != NULL && (*list)->next != NULL && *list2 != NULL
		&& (*list2)->next != NULL)
	{
		temp = *list;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = *list;
		*list = (*list)->next;
		temp->next->next = NULL;
		temp2 = *list2;
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->next = *list2;
		*list2 = (*list2)->next;
		temp2->next->next = NULL;
		ft_printf("rr\n");
	}
}
