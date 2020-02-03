/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_minwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:06:27 by valentin          #+#    #+#             */
/*   Updated: 2019/02/26 09:44:39 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*finish_pad(char *original, char *output, char pad, int minwidth)
{
	int		len;
	int		count;

	if ((output[0] == '-' || output[0] == '+' || output[0] == ' ' ||
		output[0] == '0') && output[1] != 'x' && output[1] != 'X')
		count = 1;
	else if (output[0] == '0' && (output[1] == 'x' || output[1] == 'X'))
		count = 2;
	else
		count = 0;
	len = minwidth - pf_strlen(original);
	while (count < minwidth)
	{
		if (count < len)
			output[count] = pad;
		else if (count >= len && original)
		{
			output[count] = *original;
			original++;
		}
		count++;
	}
	return (output);
}

static char	*do_justify_pad(char *original, int minwidth)
{
	char	*output;
	int		count;

	count = 0;
	output = (char*)pf_memalloc(minwidth + 1);
	if (!output)
		return (NULL);
	output[minwidth] = '\0';
	while (original && *original)
	{
		output[count] = *original;
		count++;
		original++;
	}
	while (count < minwidth)
	{
		output[count] = ' ';
		count++;
	}
	return (output);
}

static char	*pad_zero(char *original, int minwidth, char spec)
{
	char	*output;
	int		count;
	int		len;

	count = 0;
	if (!(output = (char*)pf_memalloc(minwidth + 1)))
		return (NULL);
	output[minwidth] = '\0';
	if (original && (spec == 'x' || spec == 'X' || spec == 'p'))
	{
		output[0] = original[0];
		output[1] = original[1];
		count += 2;
		original += 2;
	}
	else if (original && !(spec == 'x' || spec == 'X' || spec == 'p'))
	{
		output[count] = original[0];
		original++;
		count++;
	}
	len = minwidth - pf_strlen(original);
	output = finish_pad(original, output, '0', minwidth);
	return (output);
}

static char	*do_pad(char *original, int minwidth, char *mods, char spec)
{
	char	*output;
	char	pad;
	int		count;
	int		len;

	pad = get_pad(mods);
	count = 0;
	len = minwidth - pf_strlen(original);
	if (pad == '0' && original && (original[0] == '-' || original[0] == '+' ||
		original[0] == ' ' || checkthrough_for(mods, '#') || spec == 'p'))
		return (pad_zero(original, minwidth, spec));
	if (!(output = (char*)pf_memalloc(minwidth + 1)))
		return (NULL);
	output[minwidth] = '\0';
	output = finish_pad(original, output, pad, minwidth);
	return (output);
}

char		*do_minwidth(char *original, int minwidth, char *mods, char spec)
{
	int		len;
	char	*output;
	char	*tmp;

	if (((spec == 'x' || spec == 'X' || spec == 'o' || spec == 'O')
		&& checkthrough_for(mods, '#')) || spec == 'p')
		tmp = hexoct_sign(spec, original);
	else if (spec == 'd' || spec == 'D' || spec == 'i')
		tmp = do_sign(original, mods);
	else
		tmp = pf_strdup(original);
	len = pf_strlen(tmp);
	if (len < minwidth)
	{
		if (checkthrough_for(mods, '-'))
			output = do_justify_pad(tmp, minwidth);
		else
			output = do_pad(tmp, minwidth, mods, spec);
	}
	else
		output = pf_strdup(tmp);
	pf_memdel((void**)&tmp);
	pf_memdel((void**)&original);
	return (output);
}
