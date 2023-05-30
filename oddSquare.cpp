#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


int main()
{
	int T;
	std::cin >> T;

	while (T--)
	{
		int n;
		std::cin >> n;
		int v[49][49] = {};

		int row = 0, col = n / 2;
		int start = 1;

		while (start <= n * n)
		{
			v[row][col] = start;

			start++;

			int tempRow = row, tempCol = col;
			row--;
			col++;

			if (row == -1)
				row = n - 1;

			if (col == n)
				col = 0;

			if (v[row][col])
			{
				row = tempRow + 1;
				col = tempCol;

				if (row == n)
					row = 0;
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << v[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
}
