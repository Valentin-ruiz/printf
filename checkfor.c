/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:04:13 by valentin          #+#    #+#             */
/*   Updated: 2019/03/04 14:00:16 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		checkfor_specifier(char c)
{
	const char	*specifiers;
	int			count;

	count = 0;
	specifiers = "sSpdDioOuUxXcCfF%";
	while (specifiers[count])
	{
		if (specifiers[count] == c)
			return (1);
		count++;
	}
	return (0);
}

int		checkfor_flags(char c)
{
	const char	*flags;
	int			count;

	count = 0;
	flags = "hljz";
	while (flags[count])
	{
		if (flags[count] == c)
			return (1);
		count++;
	}
	return (0);
}

int		checkfor_modifiers(char c)
{
	const char	*modifiers;
	int			count;

	count = 0;
	modifiers = ".*#0-+ ";
	while (modifiers[count])
	{
		if (modifiers[count] == c)
			return (1);
		count++;
	}
	return (0);
}

int		checkfor_all(char c)
{
	const char	*all_frmat_chars;
	int			count;

	count = 0;
	all_frmat_chars = " 1234567890.*#-+ hljzsSpdDioOuUxXcCfF";
	while (all_frmat_chars[count])
	{
		if (all_frmat_chars[count] == c)
			return (1);
		count++;
	}
	return (0);
}

int		checkthrough_for(char *mods, char c)
{
	if (!mods)
		return (0);
	while (*mods)
	{
		if (*mods == c)
			return (1);
		mods++;
	}
	return (0);
}
