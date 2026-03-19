/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:58:58 by username          #+#    #+#             */
/*   Updated: 2026/03/15 15:59:11 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
extern void	fill_rules(int **rules);
extern int	**init_rules(void);
extern void	free_rules(int **rules);

int	check_rule(int line[4], int **rules, int i)
{
	if (line[rules[i][2]] != 0 && line[rules[i][2]] != rules[i][3])
		return (0);
	line[rules[i][2]] = rules[i][3];
	return (1);
}

int	apply_rules(int line[4], int left, int right)
{
	int	**rules;
	int	i;

	rules = init_rules();
	fill_rules(rules);
	i = 0;
	while (i < 16)
	{
		if (rules[i][0] == left && rules[i][1] == right)
		{
			if (!check_rule(line, rules, i))
			{
				free_rules(rules);
				return (0);
			}
		}
		i++;
	}
	free_rules(rules);
	return (1);
}

void	apply_col_rules(int grid[4][4], int clues[16])
{
	int	col;
	int	tmp[4];
	int	i;

	col = 0;
	while (col < 4)
	{
		i = 0;
		while (i < 4)
		{
			tmp[i] = grid[i][col];
			i++;
		}
		apply_rules(tmp, clues[col], clues[4 + col]);
		i = 0;
		while (i < 4)
		{
			grid[i][col] = tmp[i];
			i++;
		}
		col++;
	}
}

void	apply_row_rules(int grid[4][4], int clues[16])
{
	int	row;

	row = 0;
	while (row < 4)
	{
		apply_rules(grid[row], clues[8 + row], clues[12 + row]);
		row++;
	}
}
