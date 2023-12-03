#include "libftprintf.h"
#include  <unistd.h>

int main()
{
	int test = ft_printf("hello %s, I am %i years old", "you", 29);
	return (0);
}
