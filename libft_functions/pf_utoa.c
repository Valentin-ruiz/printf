/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:59:44 by valentin          #+#    #+#             */
/*   Updated: 2018/12/04 14:09:41 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*pf_utoa(uintmax_t num)
{
	int			len;
	uintmax_t	ntmp;
	char		*retstr;

	ntmp = num;
	len = 0;
	while (ntmp / 10)
	{
		len++;
		ntmp /= 10;
	}
	len++;
	retstr = (char*)pf_memalloc(len + 1);
	if (!retstr)
		return (NULL);
	retstr[len] = '\0';
	while (--len >= 0)
	{
		retstr[len] = num % 10 + '0';
		num /= 10;
	}
	return (retstr);
}
