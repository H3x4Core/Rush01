
#include <stdio.h>

int get_pos_index_cell(int pos, int n)
{
	n /= 4;
	pos += 1;
	int larray = n + 2;
	if (pos <= n)
		return (pos);
	if (n < pos && pos <= (2 * n))
		return ((pos - n) + (larray - 1) * larray);
	if ((2 * n) < pos && pos <= (3 * n))
		return ((pos - 2 * n) * larray);
	if (3 * n < pos && pos <= n * 4)
		return ((pos - 3 * n) * larray + (larray - 1));
	return (0);
}

int main(void)
{
	int n = 20;
	for (int i = 0; i < 20; i++)
	{
		printf("pos : %02d - cel : %02d\n", i, get_pos_index_cell(i, n));
	}
	
}