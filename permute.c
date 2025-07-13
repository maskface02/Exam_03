#include <stdio.h>
#include <string.h>

void	sort(char *str)
{
	char	tmp;

	for (int i = 0; str[i]; i++)
	{
		for (int j = i + 1; str[j]; j++)
		{
			if (str[i] > str[j])
			{
				tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
		}
	}
}

void	swap(char *x, char *y)
{
	char	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	permute(char *a, int l, int r)
{
	if (l == r)
		puts(a);
	else
	{
		for (int i = l; i <= r; i++)
		{
			swap(a + l, a + i);
			permute(a, l + 1, r);
			swap(a + l, a + i);
		}
	}
}

int	main(int ac, char **av)
{
	int	n;

	if (ac == 1)
		return (puts(av[1]), 0);
	sort(av[1]);
	n = strlen(av[1]);
	permute(av[1], 0, n - 1);
	return (0);
}
