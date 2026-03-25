/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:16:01 by username          #+#    #+#             */
/*   Updated: 2026/03/17 14:16:54 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *copy, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strdup(char *src)
{
	char	*copy;

	copy = malloc((ft_strlen(src) + 1));
	ft_strcpy(copy, src);
	return (copy);
}


#include <stdio.h>

int main() {
    
    char *original = "Hello World";
 
    printf( "La copie contient : %s\n", ft_strdup(original));
    return 0;
}

