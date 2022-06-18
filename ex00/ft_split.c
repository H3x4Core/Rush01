#include "ft_atoi.c"
#include "ft.h"

int ft_word_count(char *str)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if ((!ft_isspace(str[i]) && ft_isspace(str[i + 1])) //Check for char followed with space
			|| (!ft_isspace(str[i]) && str[i + 1] == 0)) //check for word followed with end of string
			words++;
		i++;
	}
	return (words);
}

int **ft_split_int(char *str)
{
	int **tab;
	int words;
	int i;
	int j;
	int k;


	i = 0;
	j = 0;
	k = 0;
	words = ft_word_count(str);

	if (!(words % 4) && ((4 * MIN_N) < words) && (words > (4 * MAX_N))) //Check if words is multiple of 4, and it's in the correct range of 4 multiples
		tab = malloc(sizeof(int*))
	else
		return (0);
	
	
	while (str[i])
	{	
		k = ft_atoi(&str[i], &tab[j]);
		if ((*tab[j] < 1) || ((words / 4) < *tab[j])) //check for number range
			return (0);
		j++;
		i += k;
	}
	return (tab);
}

#if 1


int main(void)
{
	char *str = "1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4";
	int **tab;
	int i = 0;
	
	printf("%i", ft_word_count(str));

	tab = ft_split_int(str);

	while (tab[i])
	{
		printf("%i\n", *tab[i++]);
	}
	

	
}
#endif