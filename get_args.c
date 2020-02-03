/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:59:44 by valentin          #+#    #+#             */
/*   Updated: 2019/02/26 09:46:38 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_len(char *mods)
{
	if (!mods)
		return (NONE);
	while (*mods)
	{
		if (*mods == 'h' && mods[1] == 'h')
			return (HH);
		if (*mods == 'h')
			return (H);
		if (*mods == 'l' && mods[1] == 'l')
			return (LL);
		if (*mods == 'l')
			return (L);
		if (*mods == 'j')
			return (J);
		if (*mods == 'z')
			return (Z);
		mods++;
	}
	return (NONE);
}
