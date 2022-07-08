#include "libft.h"
#include <stdio.h>

int		main(void)
{
	int i = 0;
	char **tab;
		
	tab = ft_split("bonjour##je##m'appel##Arthur", '#');
	while (i < 4)
	{
		printf("string %d : %s\n", i, tab[i]);
		i++;
	}
	return (0);
}

// display k
// display src[k]
// display i
// display dest[i]
// display start
// display len
