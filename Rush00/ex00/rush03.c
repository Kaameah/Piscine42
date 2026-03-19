/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:37:46 by username          #+#    #+#             */
/*   Updated: 2026/03/07 17:37:47 by username         ###   ########.fr       */
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
				|| (ligne == y - 1 && colonne == 0))
				ft_putchar('A');
			else if ((ligne == y - 1 && colonne == x - 1)
				|| (ligne == 0 && colonne == x - 1))
				ft_putchar('C');
			else if ((ligne == 0 || ligne == y - 1)
				|| (colonne == 0 || colonne == x - 1))
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
