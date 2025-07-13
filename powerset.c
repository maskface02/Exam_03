#include <stdio.h>
#include <stdlib.h>

int	parse_arguments(int argc, char *argv[], int *target, int **numbers)
{
	int	count;

	if (argc < 2)
		return (-1);
	*target = atoi(argv[1]);
	count = argc - 2;
	if (count > 0)
	{
		*numbers = (int *)malloc(count * sizeof(int));
		if (!*numbers)
			return (-1);
		for (int i = 0; i < count; i++)
		{
			(*numbers)[i] = atoi(argv[i + 2]);
		}
	}
	else
		*numbers = NULL;
	return (count);
}

int	calculate_subset_sum(int *numbers, int count, unsigned int n)
{
	int	sum;

	sum = 0;
	for (int i = 0; i < count; i++)
	{
		if (n & (1u << i))
			sum += numbers[i];
	}
	return (sum);
}

void	print_subset(int *numbers, int count, unsigned int n)
{
	int	first;

	first = 1;
	for (int i = 0; i < count; i++)
	{
		if (n & (1u << i))
		{
			if (first)
			{
				printf("%d", numbers[i]);
				first = 0;
			}
			else
				printf(" %d", numbers[i]);
		}
	}
	printf("\n");
}

void	find_subset_sums(int *numbers, int count, int target)
{
	unsigned int	total_subsets;
	int				sum;

	total_subsets = 1u << count;
	for (unsigned int n = 0; n < total_subsets; n++)
	{
		sum = calculate_subset_sum(numbers, count, n);
		if (sum == target)
			print_subset(numbers, count, n);
	}
}

int	main(int argc, char *argv[])
{
	int	target;
	int	*numbers;
	int	count;

	numbers = NULL;
	count = parse_arguments(argc, argv, &target, &numbers);
	if (count < 0)
		return (1);
	find_subset_sums(numbers, count, target);
	free(numbers);
	return (0);
}
