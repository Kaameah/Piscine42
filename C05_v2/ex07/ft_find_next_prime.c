/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorbeau <ccorbeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:17:00 by ccorbeau          #+#    #+#             */
/*   Updated: 2026/03/11 14:17:09 by ccorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_is_prime(int n)
{
	int	i;

	i = 2;
	if (n <= 1)
		return (0);
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int n)
{
	while (ft_is_prime(n) == 0)
	{
		if (n < 2)
			return (2);
		n ++;
	}
	return (n);
}
