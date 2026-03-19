/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaroy <lumaroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 17:29:51 by lumaroy           #+#    #+#             */
/*   Updated: 2026/03/15 14:39:10 by lumaroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	*ft_intrev(char *tab[4][4])
{
	int	i;
	int	last;
	int	tmp;
	int	size;

	i = 0;
	size = ft_strlen(tab);
	last = size - 1;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[last];
		tab[last] = tmp;
		i++;
		last--;
	}
	return (tab);
}
