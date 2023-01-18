/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:02:42 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/01/12 13:29:40 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The strnstr() function locates the first occurrence of the null-terminated string needle in the
     string haystack, where not more than len characters are searched.  Characters that appear after a
     `\0' character are not searched.  Since the strnstr() function is a FreeBSD specific API, it should
     only be used when portability is not a concern.
 */

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (needle[0] == '\0')
		return ((char *)&haystack[0]);
	while (haystack[i] && needle[j] && i < len && len > 0)
	{
		while (haystack[i] == needle [j] && haystack && i < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i - j]);
			i++;
			j++;
		}
		i -= j;
		j = 0;
		i++;
	}
	return (NULL);
}
