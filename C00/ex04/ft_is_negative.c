/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:29:49 by username          #+#    #+#             */
/*   Updated: 2026/03/05 16:02:42 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	if (n < 0)
	{
		write (1, "N", 1);
	}
	else
	{
		write(1, "P", 1);
	}
}

/* 
int main(void)
{
	ft_is_negative(0);
	ft_is_negative(-66);
	ft_is_negative(10);
	ft_is_negative(-5);
}
*/
