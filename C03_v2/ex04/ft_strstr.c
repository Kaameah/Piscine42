/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorbeau <ccorbeau@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:44:44 by ccorbeau          #+#    #+#             */
/*   Updated: 2026/03/09 20:44:47 by ccorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
			j++;
		if (to_find[j] == '\0')
			return (&str[i - 1]);
		i++;
	}
	return (0);
}

int	main(void)
{
	printf("%s", ft_strstr("bonjour les amis", "jour"));
	return (0);
}
