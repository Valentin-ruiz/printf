/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_global.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:56:15 by valentin          #+#    #+#             */
/*   Updated: 2019/02/26 09:43:34 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**format_getptr(void)
{
	static char	*ptr = NULL;

	return (&ptr);
}

char	*format_get(void)
{
	return (*(format_getptr()));
}

void	format_set(char *format)
{
	char	**ptr;

	ptr = format_getptr();
	*ptr = format;
}

char	*format_get_pos_ptr(int pos)
{
	return (format_get() + (pos));
}

char	format_get_pos(int pos)
{
	return (*(format_get() + (pos)));
}
