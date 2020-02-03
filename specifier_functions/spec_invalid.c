/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_invalid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:59:44 by valentin          #+#    #+#             */
/*   Updated: 2019/02/26 09:48:20 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_output(char *mods, int minwidth, char output)
{
	char	pad;

	pad = get_pad(mods);
	minwidth -= 1;
	if (checkthrough_for(mods, '-'))
	{
		pad = ' ';
		write(1, &output, 1);
	}
	while (minwidth > 0)
	{
		write(1, &pad, 1);
		minwidth--;
	}
	if (!checkthrough_for(mods, '-'))
		write(1, &output, 1);
}

int			spec_invalid(char *mods, int minwidth, char output)
{
	int		ret;

	if (output == '\0')
		return (0);
	if (minwidth == 0)
	{
		write(1, &output, 1);
		return (1);
	}
	ret = minwidth;
	if (checkthrough_for(mods, '.'))
		mods[get_indexof(mods, '.')] = '_';
	ft_output(mods, minwidth, output);
	return (ret);
}
