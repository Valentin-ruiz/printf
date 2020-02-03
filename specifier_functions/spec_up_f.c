/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_up_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:59:44 by valentin          #+#    #+#             */
/*   Updated: 2019/03/13 16:11:58 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*add_decimal(char *ret, int precision, long decimal)
{
	int		len;
	int		i;
	char	*str;

	len = pf_strlen(ret) + 1 + precision;
	i = 0;
	if (!(str = (char*)pf_memalloc(len + 2)))
		return (NULL);
	while (ret[i])
	{
		str[i] = ret[i];
		i++;
	}
	str[i] = '.';
	while (precision > 0)
	{
		precision--;
		str[precision + i + 1] = decimal % 10 + '0';
		decimal = decimal / 10;
	}
	str[precision + len + 2] = 0;
	return (str);
}

static char		*get_output(va_list arglist, int precision)
{
	double		n;
	double		decimal;
	long		value;
	char		*ret;

	n = va_arg(arglist, double);
	if (precision == -1)
		precision = 6;
	decimal = ((n < 0.0f) ? -n : n);
	decimal = (decimal - (long)(((n < 0.0f) ? -n : n))) *
	ft_pow(10, precision + 1);
	decimal = ((long)decimal % 10 > 4) ? (decimal) / 10 + 1 : decimal / 10;
	value = (long)decimal;
	ret = pf_lltoa(n);
	ret = add_decimal(ret, precision, decimal);
	return (ret);
}

int				spec_up_f(char *mods, va_list arglist)
{
	int		precision;
	int		minwidth;
	int		retlen;
	char	*output;

	minwidth = get_minwidth(mods, arglist);
	precision = get_precision(mods, arglist);
	output = get_output(arglist, precision);
	if (!output)
		return (0);
	retlen = 0;
	retlen = printf_free(output);
	return (retlen);
}
