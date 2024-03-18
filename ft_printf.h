/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:56:13 by anovio-c          #+#    #+#             */
/*   Updated: 2024/01/26 11:08:51 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(char const *fmt, ...);
char	*ft_strchr_pf(const char *str, int c);
int		ft_strlen_pf(char *str);
int		ft_format_hex(unsigned long long num, char *base);
size_t	ft_len_num_pf(unsigned long long num, char *base);

int		ft_putchar_pf(char c);
int		ft_putstr_pf(char *str);
int		ft_putnbr_pf(int nb);
int		ft_putadress_pf(void *ptr);
int		ft_puthex_pf(unsigned int num, const char fmt);
int		ft_putunsigned_pf(unsigned int num);

#endif
