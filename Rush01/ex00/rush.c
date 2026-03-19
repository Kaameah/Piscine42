/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaroy <lumaroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 17:29:25 by lumaroy           #+#    #+#             */
/*   Updated: 2026/03/15 18:01:26 by lumaroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

extern int	*ft_intrev(int *tab[4][4]);
extern int	ft_duplicate(int x, int y, int tab[4][4]);

int	rush(int str[4][4])
{
	int	y;
	int	x;
	int	dup;

	y = 0;
	while (y <= 3)
	{
		x = 0;
		while (x <= 3)
		{
			dup = ft_duplicate(x, y, str);
			if (dup == 0)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
