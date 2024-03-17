/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:24:46 by shmoreno          #+#    #+#             */
/*   Updated: 2024/03/17 19:19:39 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "libft/includes/libft.h"
# include "printf/ft_printf.h"

# define MAXINT 2147483647
# define MININT -2147483647

typedef struct s_stack_node
{
	int					nbr;
	int					rank;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// SPLIT			split.c
char					**ft_split(char const *s, char c);

// CASE ERRORS		case_errors.c
int						ft_error_multi_args(char **argv);
int						ft_duplicate(struct s_stack_node **stack_a);
void					ft_free_errors(t_stack_node **a);
void					ft_free_rank(int **rank, t_stack_node **stack);
void					ft_free_stack(t_stack_node **stack);

// COMMANDS			commands.c
void					ft_sa_sb(struct s_stack_node **list, char c);
void					ft_ss(struct s_stack_node **list,
							struct s_stack_node **list2);
void					ft_pa_pb(struct s_stack_node **dest,
							struct s_stack_node **src,
							char c);
void					ft_ra_rb(struct s_stack_node **list, char c);
void					ft_rr(struct s_stack_node **list,
							struct s_stack_node **list2);
void					ft_rra_rrb(struct s_stack_node **list, char c);
void					ft_rrr(struct s_stack_node **list1,
							struct s_stack_node **list2);

// PARSING			parsing.c
void					ft_init_stack_a(t_stack_node **stack_a,
							int argc,
							char **argv);
int						ft_atoi(const char *str);
char					*ft_strdup(const char *src);

// RANKING			ranking.c
int						**ft_ranking(t_stack_node **stack);
int						ft_size_stack(t_stack_node **stack);

// ALGO SORTING 	algo_sorting.c
void					ft_sorting_third_a(t_stack_node **stack_a, int **rank);
void					ft_sorting_third_b(t_stack_node **stack_b);
void					ft_sorting_b(t_stack_node **stack_a,
							t_stack_node **stack_b);
void					ft_pre_sorting_b(t_stack_node **stack_b);
void					ft_sorting_base(t_stack_node **stack_a,
							t_stack_node **stack_b, int **rank);

// ALGO ITERATION LOOP algo_sorting_iteration.c
void					ft_loop_iteration(t_stack_node **stack_a,
							unsigned int *c_start, unsigned int *c_end,
							int **rank);
void					ft_iteration_cstart(t_stack_node **stack_a,
							unsigned int *c_start, int low);
void					ft_iteration_cend(t_stack_node **stack_a, int **rank,
							unsigned int *c_end, int low);
void					ft_condition_exit(t_stack_node **stack_a,
							unsigned int *c_end, unsigned int *c_check);
void					ft_suits(unsigned int *c_end, unsigned int *c_check,
							int *c_iteration, int low);

// ALGO UTILS		algo_utils.c
int						ft_last_rank(t_stack_node **stack);
void					ft_compare_ranking(t_stack_node **stack_a, int **rank);
bool					ft_check_stack(t_stack_node **stack_a, int **rank,
							char c);

// ALGO SORTINGMORE	 algo_sortingmore.c
void					ft_sorting_one(t_stack_node **stack_a,
							t_stack_node **stack_b, int ***rank);
void					ft_sort_c_start_low(t_stack_node **stack_a,
							t_stack_node **stack_b,
							unsigned int c_start, int ***rank);
void					ft_sort_c_end_low(t_stack_node **stack_a,
							t_stack_node **stack_b, unsigned int c_end,
							int ***rank);
void					ft_sorting_third_a_b(t_stack_node **stack_a,
							t_stack_node **stack_b, int ***rank);
void					ft_sorting_final(t_stack_node **stack_a,
							t_stack_node **stack_b, int ***rank);

#endif
