/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorbeau <ccorbeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:18:49 by ccorbeau          #+#    #+#             */
/*   Updated: 2026/03/17 14:19:21 by ccorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strmalloc(int size, char **strs, char *sep)
{
	int		i;
	int		total;
	char	*result;

	if (size == 0)
		return (malloc(1));
	i = 0;
	total = 0;
	while (i < size)
		total += ft_strlen(strs[i++]);
	total += ft_strlen(sep) * (size - 1);
	result = malloc((total + 1) * sizeof(char));
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*result;

	result = ft_strmalloc(size, strs, sep);
	i = -1;
	k = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
			result[k++] = strs[i][j++];
		if (i != size - 1)
		{
			j = 0;
			while (sep[j])
				result[k++] = sep[j++];
		}
	}
	result[k] = '\0';
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	
	char	*strs[] = {"Hello", "World", "Comment ca va"};
	int	size =  3;
	printf("%s", ft_strjoin(size, strs, " - "));
}
*/
