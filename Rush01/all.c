#include <stdlib.h>
#include <unistd.h>

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

void	fill_rules4(int r[16][4])
{
	r[14][0] = 2;
	r[14][1] = 3;
	r[14][2] = 1;
	r[14][3] = 4;
	r[15][0] = 3;
	r[15][1] = 2;
	r[15][2] = 2;
	r[15][3] = 4;
}

void	fill_rules3(int r[16][4])
{
	r[9][0] = 1;
	r[9][1] = 2;
	r[9][2] = 3;
	r[9][3] = 3;
	r[10][0] = 2;
	r[10][1] = 1;
	r[10][2] = 0;
	r[10][3] = 3;
	r[11][0] = 2;
	r[11][1] = 1;
	r[11][2] = 3;
	r[11][3] = 4;
	r[12][0] = 1;
	r[12][1] = 3;
	r[12][2] = 0;
	r[12][3] = 4;
	r[13][0] = 3;
	r[13][1] = 1;
	r[13][2] = 3;
	r[13][3] = 4;
	fill_rules4(r);
}

void	fill_rules2(int r[16][4])
{
	r[3][0] = 1;
	r[3][1] = 4;
	r[3][2] = 3;
	r[3][3] = 1;
	r[4][0] = 4;
	r[4][1] = 1;
	r[4][2] = 0;
	r[4][3] = 1;
	r[5][0] = 4;
	r[5][1] = 1;
	r[5][2] = 1;
	r[5][3] = 2;
	r[6][0] = 4;
	r[6][1] = 1;
	r[6][2] = 2;
	r[6][3] = 3;
	r[7][0] = 4;
	r[7][1] = 1;
	r[7][2] = 3;
	r[7][3] = 4;
	r[8][0] = 1;
	r[8][1] = 2;
	r[8][2] = 0;
	r[8][3] = 4;
	fill_rules3(r);
}

void	fill_rules(int **rules)
{
	int	r[16][4];
	int	i;

	r[0][0] = 1;
	r[0][1] = 4;
	r[0][2] = 0;
	r[0][3] = 4;
	r[1][0] = 1;
	r[1][1] = 4;
	r[1][2] = 1;
	r[1][3] = 3;
	r[2][0] = 1;
	r[2][1] = 4;
	r[2][2] = 2;
	r[2][3] = 2;
	fill_rules2(r);
	i = 0;
	while (i < 16)
	{
		rules[i][0] = r[i][0];
		rules[i][1] = r[i][1];
		rules[i][2] = r[i][2];
		rules[i][3] = r[i][3];
		i++;
	}
}

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

void	empty_grid(int grid[4][4])
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	print_grid(int grid[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (grid[i][j] == 0)
				c = '.';
			else
				c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	checkligne(int y, int already_seen[4], int tab[4][4])
{
	int	j;

	j = 0;
	while (j < 4)
	{
		if (tab[y][j] != 0)
		{
			if (already_seen[tab[y][j] - 1] == 0)
				already_seen[tab[y][j] - 1] = 1;
			else
				return (0);
		}
		j++;
	}
	return (j);
}

int	checkrow(int x, int already_seen[4], int tab[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (tab[i][x] != 0)
		{
			if (already_seen[tab[i][x] - 1] == 0)
				already_seen[tab[i][x] - 1] = 1;
			else
				return (0);
		}
		i++;
	}
	return (i);
}

int	ft_duplicate(int x, int y, int tab[4][4])
{
	int	already_seen[4];
	int	i;
	int	j;

	already_seen[0] = 0;
	already_seen[1] = 0;
	already_seen[2] = 0;
	already_seen[3] = 0;
	i = 0;
	j = checkligne(y, already_seen, tab);
	if (j == 4)
	{
		while (i < 4)
		{
			already_seen[i] = 0;
			i++;
		}
		i = 0;
		i = checkrow(x, already_seen, tab);
		if (i == 4)
			return (1);
	}
	return (0);
}

int	rush(int str[4][4])
{
	int	y;
	int	x;
	int	dup;

	y = 0;
	while (y <= 3)
	{
		x = 0;
		while (x <= 3)
		{
			dup = ft_duplicate(x, y, str);
			if (dup == 0)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

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

int	ft_match(int *grid, int pattern[3][4], int size)
{
	int	tempgrid[4];
	int	possibilities;
	int	i;
	int	j;

	possibilities = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 4 && (grid[j] == 0 || grid[j] == pattern[i][j]))
			j++;
		if (j == 4)
		{
			j = 0;
			while (j < 4)
			{
				tempgrid[j] = pattern[i][j];
				j++;
			}
			possibilities++;
		}
		i++;
	}
	if (possibilities == 1)
	{
		j = 0;
		while (j < 4)
		{
			grid[j] = tempgrid[j];
			j++;
		}
	}
	return (possibilities);
}

int	ft_pattern(int *grid, int couple)
{
	int	pattern2[2][4];
	int	pattern3[3][4];

	if (couple == 12)
	{
		fill_pattern12(pattern2);
		return (ft_match(grid, pattern2, 2));
	}
	if (couple == 13)
	{
		fill_pattern13(pattern3);
		return (ft_match(grid, pattern3, 3));
	}
	if (couple == 22)
	{
		fill_pattern22(pattern3);
		return (ft_match(grid, pattern3, 3));
	}
	if (couple == 23)
	{
		fill_pattern23(pattern3);
		return (ft_match(grid, pattern3, 3));
	}
	return (0);
}


int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	clues[16];

	if (argc != 2)
	{
		write(1, "Error\n", 7);
		return (1);
	}
	parse_input(argv[1], clues);
	if (!verif_couple(clues))
	{
		write(1, "Error\n", 7);
		return (1);
	}
	empty_grid(grid);
	apply_row_rules(grid, clues);
	apply_col_rules(grid, clues);
	if (!rush(grid))
	{
		write(1, "Error\n", 7);
		return (1);
	}
	print_grid(grid);
	return (0);
}
