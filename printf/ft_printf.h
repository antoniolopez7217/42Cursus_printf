/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antlopez <antlopez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:59:00 by antlopez          #+#    #+#             */
/*   Updated: 2022/12/11 17:59:01 by antlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>

# define HEX_L "0123456789abcdef"
# define HEX_U "0123456789ABCDEF"

int		ft_printf(char const *f, ...);
void	ft_itoa(long int n, int *len);
int		ft_putchar(char c);
int		ft_putstr(char *s);
void	ft_check_format(va_list arg, char format, int *len);
void	ft_putnbr_base(unsigned long int nbr, char *base, int *len);
void	ft_pconvert(unsigned long int nbr, int *len);

#endif