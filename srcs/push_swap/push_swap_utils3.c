/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:46:17 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/17 18:26:25 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_negative(int n, ...)
{
	va_list	ap;
	int		*nbr;

	va_start(ap, n);
	while (n--)
	{
		nbr = va_arg(ap, int *);
		*nbr = -(va_arg(ap, int) - *nbr);
	}
	va_end(ap);
}
