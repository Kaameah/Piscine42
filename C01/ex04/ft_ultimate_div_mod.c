/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 18:02:53 by username          #+#    #+#             */
/*   Updated: 2026/03/05 18:12:57 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp_result;
	int	tmp_remainder;

	tmp_result = *a / *b;
	tmp_remainder = *a % *b;
	*a = tmp_result;
	*b = tmp_remainder;
}
/*
int main(void)
{
	int a, b;

	a = 69;
	b = 42;

	ft_ultimate_div_mod(&a, &b);

	if (a != 69 && b != 42)
	{
		write(1, "OK", 2);
	}
}
*/
