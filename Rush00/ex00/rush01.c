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

	ligne = 0;
	while (ligne < y)
	{
		colonne = 0;
		while (colonne < x)
		{
			if ((ligne == 0 && colonne == 0) || (ligne == y - 1 && colonne == x - 1))
				ft_putchar('/');
			else if ((ligne == 0 && colonne == x - 1) || (ligne == y - 1 && colonne == 0))
				ft_putchar('\\');
			else if (ligne == 0 || ligne == y - 1 || colonne == 0 || colonne == x - 1)
				ft_putchar('*');
			else
				ft_putchar(' ');
			colonne++;
		}
		ft_putchar('\n');
		ligne++;
	}
}
