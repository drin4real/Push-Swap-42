/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:40:35 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/22 18:19:08 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	manage_commands2(t_stack **a, t_stack **b, char *current_line)
{
	if (!ft_strcmp(current_line, "ss\n"))
	{
		ft_swap(a);
		ft_swap(b);
	}
	else if (!ft_strcmp(current_line, "rr\n"))
	{
		ft_rotate(a);
		ft_rotate(b);
	}
	else if (!ft_strcmp(current_line, "rrr\n"))
	{
		ft_reverse(a);
		ft_reverse(b);
	}
}

static char	*manage_commands(t_stack **a, t_stack **b, char *current_line)
{
	if (!ft_strcmp(current_line, "sa\n"))
		ft_swap(a);
	else if (!ft_strcmp(current_line, "sb\n"))
		ft_swap(b);
	else if (!ft_strcmp(current_line, "ss\n"))
		manage_commands2(a, b, current_line);
	else if (!ft_strcmp(current_line, "ra\n"))
		ft_rotate(a);
	else if (!ft_strcmp(current_line, "rb\n"))
		ft_rotate(b);
	else if (!ft_strcmp(current_line, "rr\n"))
		manage_commands2(a, b, current_line);
	else if (!ft_strcmp(current_line, "rra\n"))
		ft_reverse(a);
	else if (!ft_strcmp(current_line, "rrb\n"))
		ft_reverse(b);
	else if (!ft_strcmp(current_line, "rrr\n"))
		manage_commands2(a, b, current_line);
	else if (!ft_strcmp(current_line, "pa\n"))
		ft_push(b, a);
	else if (!ft_strcmp(current_line, "pb\n"))
		ft_push(a, b);
	else
		return (ft_strdup("!"));
	return (get_next_line(0));
}

static void	checker(t_stack **a, t_stack **b, char *line)
{
	char	*temp;

	while (line && line[0] != '!')
	{
		temp = line;
		line = manage_commands(a, b, line);
		free(temp);
	}
	if (line && line[0] == '!')
	{
		free(line);
		ft_free(a, b, NULL, 1);
	}
	else if (*b || !check_order(*a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int ac, char **av)
{
	char	*line;
	t_stack	*a;
	t_stack	*b;

	line = NULL;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	stack_init(&a, av, ac);
	line = get_next_line(0);
	checker(&a, &b, line);
	ft_free(&a, &b, NULL, 0);
}
