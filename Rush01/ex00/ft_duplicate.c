/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorbeau <ccorbeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 19:25:44 by ccorbeau          #+#    #+#             */
/*   Updated: 2026/03/15 19:25:45 by ccorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	checkligne(int y, int already_seen[4], int tab[4][4])
{
	int	j;

	j = 0;
	while (j < 4)
	{
		if (tab[y][j] != 0)
		{
			if (already_seen[tab[y][j] - 1] == 0)
				already_seen[tab[y][j] - 1] = 1;
			else
				return (0);
		}
		j++;
	}
	return (j);
}

int	checkrow(int x, int already_seen[4], int tab[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (tab[i][x] != 0)
		{
			if (already_seen[tab[i][x] - 1] == 0)
				already_seen[tab[i][x] - 1] = 1;
			else
				return (0);
		}
		i++;
	}
	return (i);
}

int	ft_duplicate(int x, int y, int tab[4][4])
{
	int	already_seen[4];
	int	i;
	int	j;

	already_seen[0] = 0;
	already_seen[1] = 0;
	already_seen[2] = 0;
	already_seen[3] = 0;
	i = 0;
	j = checkligne(y, already_seen, tab);
	if (j == 4)
	{
		while (i < 4)
		{
			already_seen[i] = 0;
			i++;
		}
		i = 0;
		i = checkrow(x, already_seen, tab);
		if (i == 4)
			return (1);
	}
	return (0);
}
