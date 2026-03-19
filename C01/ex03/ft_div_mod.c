/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:52:46 by ccorbeau          #+#    #+#             */
/*   Updated: 2026/03/05 20:10:53 by ccorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int main(void)
{
	int a, b, div, mod;
	
	a = 69;
	b = 42;
	div = 0;
	mod = 0;

	ft_div_mod(a, b, &div, &mod);
	if (div != 0 && mod != 0)
	{
		write(1, "OK", 2);
	}
}
*/
