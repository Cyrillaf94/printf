/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:34:07 by cyril             #+#    #+#             */
/*   Updated: 2023/12/15 09:46:37 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

# define BASE_10 "0123456789"
# define BASE_16_UP "0123456789ABCDEF"
# define BASE_16_LO "0123456789abcdef"

# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
ssize_t ft_putptr_fd(void *ptr, int fd);
ssize_t	ft_putptr_fd(void *addr, int fd);
ssize_t	ft_putnb_b_fd(unsigned int number, char *base, int fd);

#endif