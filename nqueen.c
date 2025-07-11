#include <stdlib.h>
#include <unistd.h>

void	print_solution(int *board, int n)
{
	char	buf[32];
	int		pos;
	int		i;

	pos = 0;
	i = 0;
	while (i < n)
	{
		if (i > 0)
			buf[pos++] = ' ';
		buf[pos++] = board[i] + '0';
		i++;
	}
	buf[pos++] = '\n';
	write(1, buf, pos);
}

int	is_safe(int *board, int col, int row)
{
	int	i;
	int	row_diff;
	int	col_diff;

	i = 0;
	while (i < col)
	{
		if (board[i] == row)
			return (0);
		row_diff = board[i] - row;
		col_diff = i - col;
		if ((row_diff == col_diff) || (row_diff == -col_diff))
			return (0);
		i++;
	}
	return (1);
}

void	solve(int *board, int col, int n)
{
	int	row;

	row = 0;
	if (col == n)
	{
		print_solution(board, n);
		return ;
	}
	while (row < n)
	{
		if (is_safe(board, col, row))
		{
			board[col] = row;
			solve(board, col + 1, n);
		}
		row++;
	}
}

int	main(int argc, char **argv)
{
	int	n;
	int	*board;

	if (argc != 2)
		return (1);
	n = atoi(argv[1]);
	if (n <= 0)
		return (0);
	board = malloc(n * sizeof(int));
	if (!board)
		return (1);
	solve(board, 0, n);
	free(board);
	return (0);
}
