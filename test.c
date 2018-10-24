#include "libft.h"
#include <stdio.h>
#include <unistd.h>

int main ()
{
	char	*str;

	str = malloc(sizeof(char)*15);
	str[0] = 'u';
	str[1] = 'u';
	str[2] = 'u';
	str[3] = 'u';
	str[4] = '\0';

	ft_printf("BEFORE: str = %s\n", str);
	ft_printf("BEFORE: str = %p\n", str);
	
	//free(str);

	write(1, &str[0], 1);
	ft_printf("After: str = %s\n", str);
	ft_printf("After: str = %p\n", str);


	return (0);
}
