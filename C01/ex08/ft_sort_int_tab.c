/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 19:49:33 by ccorbeau          #+#    #+#             */
/*   Updated: 2026/03/05 20:16:58 by ccorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
int	*ft_sort_int_tab(int size)
{
	int	i;
	int	*tab;
	tab = (int *)malloc(sizeof(int) * size);
	
	int tab2[8] = {3,0,0,2,9,0,4,2};
	i = 0;
	while (i < size)
	{
		tab[i] = tab2[i];
		i++;
	}
	
	return (tab);
}


void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		nb += '0';
		write(1, &nb, 1);
	}
}

int	main(void)
{
	int	*tab;
	
	tab = ft_sort_int_tab(8);

	int	i = 0;
	while (i < 8)
	{
		ft_putnbr(tab[i]);
		i++;
	}
}

