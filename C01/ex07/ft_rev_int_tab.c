/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 18:58:02 by username          #+#    #+#             */
/*   Updated: 2026/03/05 20:16:08 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_rev_int_tab(int *tab, int size)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i -1] = tmp;
		i ++;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	int	tab[8] = {3,0,0,2,9,0,4,2};
	
	ft_rev_int_tab(tab, 8);
	
	printf("%c", tab);

	int	i = 0;
	while (i < 8)
	{
		printf("%d", tab[i]);
		i++;
	}

}
*/
