#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

char vec[9][9]{};

void go(int s, int t, int x, int y, char c)
{
	int row = s + x, col = t + y;

	bool ok = 0;
	while (true)
	{
		row = row + x;
		col = col + y;
		if (row < 1 || row > 8 || col < 1 || col > 8)
			break;

		if (vec[row][col] == c)
		{
			ok = 1;
			break;
		}
		if (vec[row][col] == '+')
			break;

	}

	if (ok)
		while (true)
		{
			if (row == s && col == t)
				break;
			vec[row][col] = c;
			row = row - x;
			col = col - y;
		}
}

int main(int s, int t, int x, int y, char c)
{
	int T;
	std::cin >> T;

	while (T--)
	{
		int n;
		std::cin >> n;

		for (int i = 1; i < 9; i++)
			for (int j = 1; j < 9; j++)
				vec[i][j] = '+';

		vec[4][4] = 'O'; vec[5][5] = 'O';
		vec[4][5] = 'X'; vec[5][4] = 'X';

		int s, t;

		for (int x = 0; x < n; x++)
		{
			std::cin >> s >> t;


			if (x % 2 == 0)
			{
				vec[s][t] = 'X';

				if (vec[s - 1][t - 1] == 'O')
					go(s, t, -1, -1, 'X');
				if (vec[s - 1][t] == 'O')
					go(s, t, -1, 0, 'X');
				if (vec[s - 1][t + 1] == 'O')
					go(s, t, -1, 1, 'X');
				if (vec[s][t - 1] == 'O')
					go(s, t, 0, -1, 'X');
				if (vec[s][t + 1] == 'O')
					go(s, t, 0, 1, 'X');
				if (vec[s + 1][t - 1] == 'O')
					go(s, t, 1, -1, 'X');
				if (vec[s + 1][t] == 'O')
					go(s, t, 1, 0, 'X');
				if (vec[s + 1][t + 1] == 'O')
					go(s, t, 1, 1, 'X');
			}

			else
			{
				vec[s][t] = 'O';

				if (vec[s - 1][t - 1] == 'X')
					go(s, t, -1, -1, 'O');
				if (vec[s - 1][t] == 'X')
					go(s, t, -1, 0, 'O');
				if (vec[s - 1][t + 1] == 'X')
					go(s, t, -1, 1, 'O');
				if (vec[s][t - 1] == 'X')
					go(s, t, 0, -1, 'O');
				if (vec[s][t + 1] == 'X')
					go(s, t, 0, 1, 'O');
				if (vec[s + 1][t - 1] == 'X')
					go(s, t, 1, -1, 'O');
				if (vec[s + 1][t] == 'X')
					go(s, t, 1, 0, 'O');
				if (vec[s + 1][t + 1] == 'X')
					go(s, t, 1, 1, 'O');
			}

		}

		int cntWhite = 0, cntBlack = 0;

		for (int i = 1; i < 9; i++)
			for (int j = 1; j < 9; j++)
			{
				if (vec[i][j] == 'O')
					cntWhite++;
				if (vec[i][j] == 'X')
					cntBlack++;
			}

		std::cout << cntBlack << " " << cntWhite << "\n";

		for (int i = 1; i < 9; i++)
		{
			for (int j = 1; j < 9; j++)
			{
				std::cout << vec[i][j];
			}
			std::cout << "\n";
		}

	}
}