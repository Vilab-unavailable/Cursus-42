/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:16:24 by vilabard          #+#    #+#             */
/*   Updated: 2024/11/05 11:16:28 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_ullhexalen(unsigned long long n);
int		ft_printptr(void *ptr);
int		ft_printnbr(int n);
int		ft_printunbr(int n);
int		ft_hexalen(unsigned int n);
int		ft_printhexa(unsigned int nb, char c);
int		ft_printchar(char c);
int		ft_printstr(char *s);
int		ft_type(va_list args, const char *str, int i, int len);
int		ft_printf(const char *str, ...);
size_t	ft_uintlen(unsigned int n);
size_t	ft_intlen(int n);
void	ft_putnbr(int n);
void	ft_putunbr(unsigned int n);
void	ft_puthexa(unsigned int nb);
void	ft_puthexabig(unsigned int nb);
void	ft_putullhexa(unsigned long long nb);

#endif
