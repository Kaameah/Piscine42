/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <marvin@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 16:18:15 by username          #+#    #+#             */
/*   Updated: 2026/03/18 16:18:17 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

typedef int	t_bool;
# define TRUE	1
# define FALSE	0

# define EVEN(nbr) (nbr % 2 == 0) 

# define EVEN_MSG "I have an even number of argument."
# define ODD_MSG "I have an odd number of arguments."
# define SUCCESS 0

#endif
