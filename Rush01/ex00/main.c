/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaroy <lumaroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 17:29:04 by lumaroy           #+#    #+#             */
/*   Updated: 2026/03/15 17:26:51 by lumaroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
//"2 3 2 1 2 1 2 3 3 1 3 2 1 3 2 3"
//"1 2 3 3 3 3 1 2 1 2 2 2 4 3 1 2"
//extern void	rush(char str[]);
extern void	parse_input(char *str, int clues[16]);
extern int	verif_couple(int clues[16]);
extern void	empty_grid(int grid[4][4]);
extern void	print_grid(int grid[4][4]);
extern void	apply_col_rules(int grid[4][4], int clues[16]);
extern void	apply_row_rules(int grid[4][4], int clues[16]);
extern int	rush(int str[4][4]);

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
