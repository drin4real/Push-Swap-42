/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:32:03 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/22 15:06:16 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"

typedef struct s_stack
{
	int					content;
	int					index;
	char				stack;
	struct s_stack		*next;
}		t_stack;

typedef struct targetlocation
{
	int	arrow;
	int	target;
	int	moves;
}	t_targets;

int			ft_abs(int nb);
int			ft_min(int a, int b);
int			ft_max(int a, int b);
void		ft_negative(int n, ...);
int			is_extremum(int index, t_stack *b);
void		ft_stclear(t_stack **st);
t_stack		*ft_stlast(t_stack *st);
void		ft_stadd_back(t_stack **st, t_stack *new);
void		ft_stadd_front(t_stack **st, t_stack *new);
void		ft_stprint(t_stack *s);
int			ft_stsize(t_stack *st);
t_stack		*ft_stnew(int content);
void		stack_init(t_stack **a, char **argv, int argc);
int			check_order(t_stack	*st);
void		ft_free(t_stack **a, t_stack **b, char **tab, int flag);
void		ft_swap(t_stack **st);
void		ft_rotate(t_stack **st);
void		ft_reverse(t_stack **st);
void		ft_push(t_stack **src, t_stack **dest);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		pa(t_stack **b, t_stack **a);
void		pb(t_stack **a, t_stack **b);
void		px(t_stack **from, t_stack **to);
void		ra(t_stack **a, int *a_pos);
void		rb(t_stack **b, int *b_pos);
void		rr(t_stack **a, t_stack **b, int *a_pos, int *b_pos);
void		rx(t_stack	**st, int *x_pos);
void		rra(t_stack **a, int *a_pos);
void		rrb(t_stack **b, int *b_pos);
void		rrx(t_stack	**st, int *x_pos);
void		rrr(t_stack **a, t_stack **b, int *a_pos, int *b_pos);
void		ft_index(t_stack *st, int size);
int			max_index(t_stack *st);
int			min_index(t_stack *st);
int			best_index(t_stack *st);
int			find_index(t_stack *st, int index);
int			find_target(int index, t_stack *b);
int			is_extremum(int index, t_stack *b);
void		push_swap(t_stack **a, t_stack **b, int size);
void		small_sort(t_stack **a);
void		big_sort(t_stack **a, t_stack **b, int a_size);

#endif