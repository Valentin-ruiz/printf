/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:59:44 by valentin          #+#    #+#             */
/*   Updated: 2018/12/04 14:08:37 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		add_chars(char *retstr, long n, int len)
{
	if (n < 0)
	{
		retstr[0] = '-';
		n *= -1;
		len--;
		while (len > 0 && retstr[len] != '-')
		{
			retstr[len] = n % 10 + '0';
			n = n / 10;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			len--;
			retstr[len] = n % 10 + '0';
			n = n / 10;
		}
	}
}

char			*pf_itoa(int n)
{
	int		len;
	char	*retstr;
	int		ntmp;

	len = 1;
	ntmp = n;
	if (ntmp < 0)
		len++;
	while (ntmp / 10)
	{
		len++;
		ntmp /= 10;
	}
	if (!(retstr = (char*)pf_memalloc(len + 1)))
		return (NULL);
	else
		add_chars(retstr, (long)n, len);
	retstr[len] = '\0';
	return (retstr);
}
