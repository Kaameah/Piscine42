/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorbeau <ccorbeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 20:55:51 by ccorbeau          #+#    #+#             */
/*   Updated: 2026/03/15 20:55:53 by ccorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	**init_rules(void)
{
	int	**rules;
	int	i;

	rules = malloc(16 * sizeof(int *));
	i = 0;
	while (i < 16)
	{
		rules[i] = malloc(4 * sizeof(int));
		i++;
	}
	return (rules);
}

void	free_rules(int **rules)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		free(rules[i]);
		i++;
	}
	free(rules);
}
