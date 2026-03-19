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

void 	main(void)
{
	grid[4]
	ft_pattern(
