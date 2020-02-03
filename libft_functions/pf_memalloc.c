/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:59:44 by valentin          #+#    #+#             */
/*   Updated: 2018/12/04 14:08:53 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	*pf_memalloc(size_t size)
{
	unsigned char	*mem;

	if (size <= 0)
		return (NULL);
	mem = (unsigned char*)malloc(sizeof(mem) * size);
	if (!mem)
		return (NULL);
	pf_bzero(mem, size);
	return (mem);
}
