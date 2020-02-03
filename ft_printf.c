/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:59:44 by valentin          #+#    #+#             */
/*   Updated: 2019/02/28 15:08:27 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_free(char *output)
{
	int	len;

	len = pf_strlen(output);
	write(1, output, len);
	pf_memdel((void**)&output);
	return (len);
}

int		parse_format(char *format, va_list arglist)
{
	int		ret;
	int		specpos;
	char	*mods;
	int		(*specifier_funciton)(char *, va_list);

	ret = 0;
	specpos = find_specifier_pos(format);
	if ((specpos <= -1 || !checkfor_all(format[specpos])))
	{
		specpos *= (specpos < 0 ? -1 : 1);
		if ((checkfor_all(format[specpos]) == 0 && format[specpos] != '\0'))
		{
			mods = (!format[specpos] ? NULL : pf_strsub(format, 0, specpos));
			return (spec_invalid(mods, get_minwidth(mods, arglist),
				format[specpos]));
		}
	}
	if (!format[specpos])
		return (0);
	mods = (specpos == 0 ? NULL : pf_strsub(format, 0, specpos));
	specifier_funciton = g_dispatcher(format, specpos);
	ret += specifier_funciton(mods, arglist);
	if (mods)
		pf_memdel((void**)&mods);
	return (ret);
}

int		read_format(va_list arglist)
{
	int		totallen;
	int		count;
	char	*format;

	count = 0;
	totallen = 0;
	format = format_get();
	while (format[count])
	{
		if (format[count] == '%')
		{
			format = print_moveto(format, count);
			format++;
			totallen += count;
			count = 0;
			totallen += parse_format(format, arglist);
			format = moveto_specifier(format);
		}
		if (*format && *format != '%')
			count++;
	}
	totallen += count;
	format = print_moveto(format, count);
	return (totallen);
}

int		check_char_nulls(va_list copy)
{
	int			ret;
	char		c;
	char		*format;

	ret = 0;
	c = 'x';
	format = format_get();
	while (*format)
	{
		while (*format && *format != '%')
			format++;
		(*format ? format++ : format);
		while (checkfor_specifier(*format) != 1 && checkfor_all(*format) == 1)
			format++;
		if (*format && (*format == 'c' || *format == 'C'))
		{
			c = va_arg(copy, int);
			if (c == 0 || !c)
				ret++;
		}
		else if (checkfor_specifier(*format) == 1 && *format != '%')
			(void)va_arg(copy, long long int);
	}
	return (ret);
}

int		ft_printf(char *format, ...)
{
	va_list		arglist;
	va_list		copy;
	int			len;

	va_start(arglist, format);
	va_copy(copy, arglist);
	format_set(format);
	len = 0;
	if (format)
	{
		len = read_format(arglist);
		len += check_char_nulls(copy);
	}
	va_end(arglist);
	va_end(copy);
	return (len);
}
