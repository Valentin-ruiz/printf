/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_up_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:59:44 by valentin          #+#    #+#             */
/*   Updated: 2019/02/26 09:48:57 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	special_print(char *output)
{
	int	len;

	len = pf_strlen(output);
	write(1, output, len);
	write(1, "\0", 1);
	if (output)
		pf_memdel((void**)&output);
	return (len);
}

static int	givennull(char *output, int minwidth, char *mods)
{
	int retlen;

	retlen = 0;
	output = do_minwidth(output, minwidth, mods, 'c');
	retlen = special_print(output);
	return (retlen);
}

int			spec_up_c(char *mods, va_list arglist)
{
	int		precision;
	int		minwidth;
	int		retlen;
	char	*output;

	minwidth = get_minwidth(mods, arglist);
	precision = get_precision(mods, arglist);
	precision = 0;
	if (checkthrough_for(mods, '.'))
		mods[get_indexof(mods, '.')] = '_';
	output = ft_uni_utf8_char(va_arg(arglist, wchar_t));
	if (!output || output[0] == '\0')
		retlen = givennull(output, minwidth - 1, mods);
	else
	{
		output = do_minwidth(output, minwidth, mods, 'C');
		if (!output)
			return (0);
		retlen = printf_free(output);
	}
	return (retlen);
}
