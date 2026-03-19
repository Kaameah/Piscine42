/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pattern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 22:38:05 by username          #+#    #+#             */
/*   Updated: 2026/03/15 22:38:06 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_pattern12(int pattern[2][4])
{
	pattern[0][0] = 4;
	pattern[0][1] = 1;
	pattern[0][2] = 2;
	pattern[0][3] = 3;
	pattern[1][0] = 4;
	pattern[1][1] = 2;
	pattern[1][2] = 1;
	pattern[1][3] = 3;
}

void	fill_pattern13(int pattern[3][4])
{
	pattern[0][0] = 4;
	pattern[0][1] = 2;
	pattern[0][2] = 3;
	pattern[0][3] = 1;
	pattern[1][0] = 4;
	pattern[1][1] = 1;
	pattern[1][2] = 3;
	pattern[1][3] = 2;
	pattern[2][0] = 4;
	pattern[2][1] = 3;
	pattern[2][2] = 1;
	pattern[2][3] = 2;
}

void	fill_pattern22(int pattern[3][4])
{
	pattern[0][0] = 1;
	pattern[0][1] = 4;
	pattern[0][2] = 2;
	pattern[0][3] = 3;
	pattern[1][0] = 2;
	pattern[1][1] = 4;
	pattern[1][2] = 1;
	pattern[1][3] = 3;
	pattern[2][0] = 3;
	pattern[2][1] = 4;
	pattern[2][2] = 1;
	pattern[2][3] = 2;
}

void	fill_pattern23(int pattern[3][4])
{
	pattern[0][0] = 1;
	pattern[0][1] = 4;
	pattern[0][2] = 3;
	pattern[0][3] = 2;
	pattern[1][0] = 2;
	pattern[1][1] = 4;
	pattern[1][2] = 3;
	pattern[1][3] = 1;
	pattern[2][0] = 3;
	pattern[2][1] = 4;
	pattern[2][2] = 2;
	pattern[2][3] = 1;
}
