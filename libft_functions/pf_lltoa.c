/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:59:44 by valentin          #+#    #+#             */
/*   Updated: 2019/03/13 15:15:05 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		add_chars(char *retstr, long long int n, int len)
{
	unsigned long long int n2;

	if (n < 0)
	{
		retstr[0] = '-';
		n2 = (unsigned long long)(n * -1);
		len--;
		while (len > 0 && retstr[len] != '-')
		{
			retstr[len] = n2 % 10 + '0';
			n2 = n2 / 10;
			len--;
		}
	}
	else
	{
		n2 = (unsigned long long)n;
		while (len > 0)
		{
			len--;
			retstr[len] = n % 10 + '0';
			n = n / 10;
		}
	}
}

char			*pf_lltoa(long long int n)
{
	int					len;
	char				*retstr;
	long long int		ntmp;

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
		add_chars(retstr, n, len);
	retstr[len] = '\0';
	return (retstr);
}
