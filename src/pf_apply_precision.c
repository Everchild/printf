/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 15:17:38 by sbrochar          #+#    #+#             */
/*   Updated: 2017/05/13 01:35:59 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				apply_precision(t_specs *specs, char **result)
{
	char			*tmp;
	int				orig_len;
	int				len;

	orig_len = ft_strlen(*result);
	len = specs->precision;
	if ((specs->format == 'p') && specs->precision > -1)
	{
		if (!specs->precision && !ft_strcmp(*result, "0x0"))
			(*result)[2] = '\0';
		else if (len > (orig_len - 2))
		{
			tmp = (char *)ft_memalloc(sizeof(char) * (len + 1 + 2));
			ft_memset(tmp, '0', specs->precision + 2);
			ft_strncpy(tmp + (specs->precision + 2 - orig_len), *result, orig_len);
			ft_strdel(result);
			*result = tmp;
			tmp = ft_strchr(*result, 'x');
			*tmp = '0';
			(*result)[1] = 'x';
		}
	}
	else if ((specs->format == 's' || specs->format == 'S') && specs->precision > -1 && len < orig_len)
	{
		tmp = (char *)ft_memalloc(sizeof(char) * (len + 1));
		tmp = ft_strncpy(tmp, *result, len);
		ft_strdel(result);
		*result = tmp;
	}
	else if ((specs->format == 'd' || specs->format == 'D' || specs->format == 'i' || specs->format == 'o' || specs->format == 'O' || specs->format == 'U' || specs->format == 'u' || specs->format == 'x' || specs->format == 'X'))
	{
		if (!specs->precision && !ft_strcmp(*result, "0"))
			**result = '\0';
		else if (specs->precision > orig_len)
		{
			tmp = (char *)ft_memalloc(sizeof(char) * (len + 1));
			ft_memset(tmp, '0', specs->precision);
			ft_strncpy(tmp + (specs->precision - orig_len), *result, orig_len);
			ft_strdel(result);
			*result = tmp;
			if ((tmp = ft_strchr(*result, '-')) != 0)
			{
				*tmp = '0';
				*result = ft_strjoinf("-", *result, 2);
			}
		}
	}
}
