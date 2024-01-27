/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferri <claferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:34:07 by cyril             #+#    #+#             */
/*   Updated: 2024/01/27 16:18:33 by claferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# define BASE_10 "0123456789"
# define BASE_16_UP "0123456789ABCDEF"
# define BASE_16_LO "0123456789abcdef"

# include <unistd.h>
# include <stdlib.h>

typedef unsigned long long	t_ull;
typedef long long			t_ll;

int		ft_printf(const char *format, ...);
ssize_t	ft_putnb_b_fd(long long number, char *base, int fd);
ssize_t	ft_putnb_u_b_fd(t_ull number, char *base, int fd);
ssize_t	ft_putptr_fd(void *ptr, int fd);
ssize_t	ft_putstr_fd_st(char *s, int fd);

#endif