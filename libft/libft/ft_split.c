/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:13:53 by dbislimi          #+#    #+#             */
/*   Updated: 2024/05/20 15:39:21 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_str_with(char const *s, int start, int end)
{
	char	*fill;
	int		i;

	i = 0;
	fill = malloc(sizeof(char) * (end - start + 1));
	if (!fill)
		return (NULL);
	while (start < end)
		fill[i++] = s[start++];
	fill[i] = 0;
	return (fill);
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	int			size;
	int			i;
	int			end;
	int			start;

	i = 0;
	start = 0;
	size = count_words(s, c);
	split = malloc(sizeof(char *) * (size + 1));
	if (!split)
		return (NULL);
	while (i < size)
	{
		while (s[start] == c && s[start])
			start++;
		end = start + 1;
		while (s[end] != c && s[end])
			end++;
		split[i] = fill_str_with(s, start, end);
		start = end + 1;
		i++;
	}
	split[i] = NULL;
	return (split);
}
/*
int main(void)
{
	char *tosplit = "      bonjour a    Tous  !! . ";
	char **split = ft_split(tosplit, ' ');
	int i;

	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	free(split);
}*/