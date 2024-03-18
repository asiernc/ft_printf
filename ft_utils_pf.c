/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_pf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:32:22 by anovio-c          #+#    #+#             */
/*   Updated: 2024/01/23 11:29:40 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr_pf(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

int	ft_strlen_pf(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_len_num_pf(unsigned long long num, char *base)
{
	unsigned long long	len_base;
	size_t				len;

	len = 1;
	len_base = ft_strlen_pf(base);
	while (num >= len_base)
	{
		num /= len_base;
		len++;
	}
	return (len);
}

int	ft_format_hex(unsigned long long num, char *base)
{
	char	*str;
	int		num_len;
	int		base_len;
	int		len_str;

	num_len = ft_len_num_pf(num, base);
	base_len = ft_strlen_pf(base);
	str = (char *)malloc((num_len + 1) * sizeof(char));
	if (!str)
		return (-1);
	str[num_len] = '\0';
	while (num_len)
	{
		num_len--;
		str[num_len] = base[num % base_len];
		num /= base_len;
	}
	len_str = ft_strlen_pf(str);
	if (ft_putstr_pf(str) == -1)
		len_str = -1;
	free(str);
	return (len_str);
}
