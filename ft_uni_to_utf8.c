/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_to_utf8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:59:44 by valentin          #+#    #+#             */
/*   Updated: 2019/02/26 09:46:29 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_char_len(wchar_t c)
{
	int				bytes;

	bytes = 0;
	if (c < (1 << 7))
		bytes = (1 < MB_CUR_MAX ? 1 : MB_CUR_MAX);
	else if (c < (1 << 11))
		bytes = (2 < MB_CUR_MAX ? 2 : MB_CUR_MAX);
	else if (c < (1 << 16))
		bytes = (3 < MB_CUR_MAX ? 3 : MB_CUR_MAX);
	else if (c < (1 << 21))
		bytes = (4 < MB_CUR_MAX ? 4 : MB_CUR_MAX);
	return (bytes);
}

static void		char_conversion(unsigned char *b, wchar_t c, int len)
{
	if (len == 1)
		*b++ = (unsigned char)c;
	else if (len == 2)
	{
		*b++ = (unsigned char)((c >> 6) | 0xc0);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (len == 3)
	{
		*b++ = (unsigned char)((c >> 12) | 0xE0);
		*b++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (len == 4)
	{
		*b++ = (unsigned char)((c >> 18) | 0xF0);
		*b++ = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
		*b++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	*b = '\0';
}

char			*ft_uni_utf8_char(wchar_t c)
{
	int				charlen;
	unsigned char	*retptr;
	unsigned char	*retchar;

	if (!c)
		return (NULL);
	charlen = get_char_len(c);
	if (charlen == 0)
		return (NULL);
	if (!(retchar = (unsigned char *)pf_memalloc(charlen + 1)))
		return (NULL);
	retptr = retchar;
	char_conversion(retptr, c, charlen);
	return ((char*)retchar);
}

char			*ft_uni_utf8_str(wchar_t *str)
{
	char			*retstr;
	char			*tmp;
	char			*add;
	int				index;

	index = 1;
	retstr = NULL;
	if (str && str[0] == '\0')
		return (pf_strdup("\0"));
	if (!str)
		return (NULL);
	retstr = ft_uni_utf8_char(str[0]);
	while (retstr && str[index])
	{
		tmp = pf_strdup(retstr);
		pf_memdel((void**)&retstr);
		add = ft_uni_utf8_char(str[index]);
		retstr = pf_strjoin(tmp, add);
		pf_memdel((void**)&tmp);
		pf_memdel((void**)&add);
		index++;
	}
	if (!retstr)
		return (NULL);
	return (retstr);
}
