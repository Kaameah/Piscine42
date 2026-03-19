/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorbeau <ccorbeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:16:01 by ccorbeau          #+#    #+#             */
/*   Updated: 2026/03/17 14:16:54 by ccorbeau         ###   ########.fr       */
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

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		l;
	char	*copy;

	l = ft_strlen(src) + 1;
	copy = (char *) malloc(l * sizeof(char));
	ft_strcpy(copy, src);
	return (copy);
}

/*
#include <stdio.h>

int main() {
    
    char *original = "Hello World";
 
    printf( "La copie contient : %s\n", ft_strdup(original));
    return 0;
}
*/
