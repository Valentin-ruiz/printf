/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:59:44 by valentin          #+#    #+#             */
/*   Updated: 2018/12/04 14:09:37 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*pf_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	count;

	count = 0;
	if (len == 0 || !s)
		return (NULL);
	if (!(substr = (char*)pf_memalloc(len + 1)))
		return (NULL);
	while (count < len)
	{
		substr[count] = s[count + start];
		count++;
	}
	substr[count] = '\0';
	return (substr);
}
