/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:59:44 by valentin          #+#    #+#             */
/*   Updated: 2018/12/04 14:09:08 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*pf_strdup(const char *s1)
{
	int		len;
	int		count;
	char	*ret;

	if (!s1)
		return (NULL);
	len = pf_strlen((char*)s1);
	count = 0;
	ret = (char*)pf_memalloc(len + 1);
	if (!ret)
		return (NULL);
	while (*s1)
	{
		ret[count] = *s1;
		count++;
		s1++;
	}
	ret[len] = '\0';
	return (ret);
}
