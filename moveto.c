/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveto.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:59:44 by valentin          #+#    #+#             */
/*   Updated: 2019/02/28 15:17:44 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_specifier_pos(char *format)
{
	int pos;

	pos = 0;
	while (checkfor_specifier(format[pos]) != 1)
	{
		if (checkfor_all(format[pos]) == 0 || !format[pos])
		{
			return (pos * -1);
		}
		pos++;
	}
	return (pos);
}

char	*moveto_specifier(char *format)
{
	while (checkfor_specifier(*format) != 1 && *format)
	{
		if (checkfor_all(*format) == 0 && *format)
			return (format + 1);
		else if (checkfor_all(*format) == 0)
			return (format);
		format++;
	}
	if (!*format)
		return (format);
	else
		return (format + 1);
}

char	*print_moveto(char *format, int len)
{
	write(1, format, len);
	return (format + len);
}
