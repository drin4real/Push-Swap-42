/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:14:53 by dren              #+#    #+#             */
/*   Updated: 2024/05/22 15:26:03 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **st)
{
	t_stack	*temp;

	if ((*st)->next == NULL)
		return ;
	temp = (*st)->next;
	(*st)->next = (*st)->next->next;
	temp->next = *st;
	*st = temp;
}

void	sa(t_stack **a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}
