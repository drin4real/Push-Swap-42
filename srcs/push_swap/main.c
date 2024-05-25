/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:03:28 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/22 16:57:50 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack			*a;
	t_stack			*b;
	unsigned int	a_size;

	a_size = 0;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	stack_init(&a, av, ac);
	a_size = ft_stsize(a);
	ft_index(a, a_size);
	if (a_size != 1)
		push_swap(&a, &b, a_size);
	ft_free(&a, &b, NULL, 0);
}
