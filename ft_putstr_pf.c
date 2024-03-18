/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:17:43 by anovio-c          #+#    #+#             */
/*   Updated: 2024/01/22 11:57:26 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_pf(char *str)
{
	char	*ptr;

	ptr = str;
	if (!str)
		return (ft_putstr_pf("(null)"));
	while (*ptr)
	{
		if (ft_putchar_pf(*ptr) == -1)
			return (-1);
		ptr++;
	}
	return (ft_strlen_pf(str));
}
