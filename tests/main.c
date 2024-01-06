/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferri <claferri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:42:20 by cyril             #+#    #+#             */
/*   Updated: 2024/01/06 09:13:24 by claferri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>


int main()
{
char *strs[] = {"", "Testing", "ZKJHFJFJHFJS", "srgbskru%gsk",
				"JGeq%%eHyg"};
char chars[] = {'\0', 'a', '%'};
int ints[] = {0, 2147483647, -2147483648,  11, -11};
unsigned int uints[] = {0, 4294967295u, 56,  11}; 
void *ptrs[] = {(void *)NULL, (void *)"test", (void *)&ints[2], 
				(void *)&chars[0], (void *)&uints[0]};

int ret_std, ret_ft;

// Test with %s
for (int i = 0; i < 5; i++) {
	ret_std = printf("Standard printf: %s\n", strs[i]);
	ret_ft = ft_printf("  Custom printf: %s\n", strs[i]);
	printf("Return values - std: %i, ft: %i\n", ret_std, ret_ft);
}

// Test with %c
for (int i = 0; i < 3; i++) {
	ret_std = printf("Standard printf: %c\n", chars[i]);
	ret_ft = ft_printf("  Custom printf: %c\n", chars[i]);
	printf("Return values - std: %i, ft: %i\n", ret_std, ret_ft);
}

// Test with %i and %d
for (int i = 0; i < 5; i++) {
	ret_std = printf("Standard printf: %i, %d\n", ints[i], ints[i]);
	ret_ft = ft_printf("  Custom printf: %i, %d\n", ints[i], ints[i]);
	printf("Return values - std: %i, ft: %i\n", ret_std, ret_ft);
}

// Test with %u, %x and %X
for (int i = 0; i < 4; i++) {
	ret_std = printf("Standard printf: %u, %x, %X\n", 
				uints[i], uints[i], uints[i]);
	ret_ft = ft_printf("  Custom printf: %u, %x, %X\n", 
				uints[i], uints[i], uints[i]);
	printf("Return values - std: %i, ft: %i\n", ret_std, ret_ft);
}

// Test with %p
for (int i = 0; i < 5; i++) {
	ret_std = printf("Standard printf: %p\n", ptrs[i]);
	ret_ft = ft_printf("  Custom printf: %p\n", ptrs[i]);
	printf("Return values - std: %i, ft: %i\n", ret_std, ret_ft);
}
}

