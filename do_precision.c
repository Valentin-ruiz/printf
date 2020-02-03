/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:59:44 by valentin          #+#    #+#             */
/*   Updated: 2019/02/28 15:17:26 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*pad_copy(char *original, int sign, int pad, int totallen)
{
	char	*ret;
	int		count;

	count = 0;
	ret = (char*)pf_memalloc(totallen);
	if (!ret)
		return (NULL);
	if (sign)
	{
		ret[0] = '-';
		count++;
	}
	while (count - sign < pad)
	{
		ret[count] = '0';
		count++;
	}
	while (*original)
	{
		ret[count] = *original;
		count++;
		original++;
	}
	ret[totallen] = '\0';
	return (ret);
}

char		*do_precision(char *output, int precision)
{
	int		len;
	int		count;
	int		minussign;
	char	*retoutp;

	len = 0;
	count = 0;
	minussign = (output[0] == '-' ? 1 : 0);
	if (minussign)
		output++;
	len = pf_strlen(output);
	if (len < precision)
	{
		len = precision - len;
		precision += minussign;
		retoutp = pad_copy(output, minussign, len, precision);
	}
	if (minussign)
		output--;
	if (len >= precision)
		retoutp = pf_strdup(output);
	pf_memdel((void**)&output);
	return (retoutp);
}
