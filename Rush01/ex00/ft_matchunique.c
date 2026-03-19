/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matchunique.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdupon <anthony.dupont89@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 19:44:35 by antdupon          #+#    #+#             */
/*   Updated: 2026/03/15 21:19:56 by antdupon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

extern void	fill_pattern12(int pattern[2][4]);
extern void	fill_pattern13(int pattern[3][4]);
extern void	fill_pattern22(int pattern[3][4]);
extern void	fill_pattern23(int pattern[3][4]);

int	ft_match(int *grid, int pattern[3][4], int size)
{
	int	tempgrid[4];
	int	possibilities;
	int	i;
	int	j;

	possibilities = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 4 && (grid[j] == 0 || grid[j] == pattern[i][j]))
			j++;
		if (j == 4)
		{
			j = 0;
			while (j < 4)
			{
				tempgrid[j] = pattern[i][j];
				j++;
			}
			possibilities++;
		}
		i++;
	}
	if (possibilities == 1)
	{
		j = 0;
		while (j < 4)
		{
			grid[j] = tempgrid[j];
			j++;
		}
	}
	return (possibilities);
}

int	ft_pattern(int *grid, int couple)
{
	int	pattern2[2][4];
	int	pattern3[3][4];

	if (couple == 12)
	{
		fill_pattern12(pattern2);
		return (ft_match(grid, pattern2, 2));
	}
	if (couple == 13)
	{
		fill_pattern13(pattern3);
		return (ft_match(grid, pattern3, 3));
	}
	if (couple == 22)
	{
		fill_pattern22(pattern3);
		return (ft_match(grid, pattern3, 3));
	}
	if (couple == 23)
	{
		fill_pattern23(pattern3);
		return (ft_match(grid, pattern3, 3));
	}
	return (0);
}
