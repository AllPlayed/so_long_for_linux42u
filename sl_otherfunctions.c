/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_otherfunctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:05:25 by ullorent          #+#    #+#             */
/*   Updated: 2021/11/08 11:45:42 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin_sl(char const *s1, char const *s2)
{
	size_t	c;
	size_t	i;
	char	*mem;

	c = 0;
	i = 0;
	if (!s1)
		return (0);
	if (!s2)
		return ((char *)s1);
	mem = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!mem)
		return (NULL);
	while (s1[c] != '\0')
		*mem++ = s1[c++];
	while (s2[i] != '\0')
		*mem++ = s2[i++];
	*mem = '\0';
	return (mem - c - i);
}
