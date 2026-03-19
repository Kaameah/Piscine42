/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorbeau <ccorbeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 19:34:26 by ccorbeau          #+#    #+#             */
/*   Updated: 2026/03/14 19:34:28 by ccorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	parse_input(char *str, int clues[16])
{
	int	i;

	i = 0;
	while (i < 16)
	{
		clues[i] = str[i * 2] - '0';
		i++;
	}
}

int	verif_couple(int clues[16])
{
	int	i;
	int	val;

	i = 0;
	while (i < 8)
	{
		val = clues[i] * 10 + clues[i + 4];
		if (!(val == 12 || val == 21
				|| val == 13 || val == 31
				|| val == 14 || val == 41
				|| val == 22
				|| val == 23 || val == 32))
			return (0);
		i++;
		if (i == 4)
			i += 4;
	}
	return (1);
}
