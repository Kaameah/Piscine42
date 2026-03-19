/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:37:46 by ccorbeau          #+#    #+#             */
/*   Updated: 2026/03/07 17:37:47 by ccorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	ligne;
	int	colonne;

	ligne = -1;
	while (ligne++ < y - 1 && !(x < 0 || y < 0))
	{
		colonne = -1;
		while (colonne++ < x - 1)
		{
			if ((ligne == 0 && colonne == 0)
				|| (ligne == y - 1 && colonne == x - 1)
				|| (ligne == 0 && colonne == x - 1)
				|| (ligne == y - 1 && colonne == 0))
				ft_putchar('o');
			else if (ligne == 0 || ligne == y - 1)
				ft_putchar('-');
			else if (colonne == 0 || colonne == x - 1)
				ft_putchar('|');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
