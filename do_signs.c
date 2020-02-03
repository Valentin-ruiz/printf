/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_signs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:59:44 by valentin          #+#    #+#             */
/*   Updated: 2019/02/26 09:45:40 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_sign(char *original, char *mods)
{
	if (original[0] == '-')
		return ('-');
	else
	{
		if (checkthrough_for(mods, '+'))
			return ('+');
		else if (checkthrough_for(mods, ' '))
			return (' ');
	}
	return ('\0');
}

char	*hexoct_sign(char spec, char *original)
{
	char *ret;

	if (spec == 'X')
		ret = pf_strjoin("0X", original);
	else if (spec == 'x' || spec == 'p')
		ret = pf_strjoin("0x", original);
	else if ((spec == 'o' || spec == 'O') &&
		!(original[0] == '0' && original[1] == '\0'))
		ret = pf_strjoin("0", original);
	else
		ret = pf_strdup(original);
	return (ret);
}

char	*do_sign(char *original, char *mods)
{
	char	sign;
	char	*ret;
	char	*s;

	sign = get_sign(original, mods);
	if (sign != '-')
		s = (sign == '+' ? "+" : " ");
	else
		s = "-";
	if (sign && sign != '-')
		ret = pf_strjoin(s, original);
	else
		ret = pf_strdup(original);
	return (ret);
}
