#include <iostream>
#include <string>
#include <vector>

#define FAST std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);

int main()
{
	FAST;

	int T;
	std::cin >> T;

	while (T--)
	{
		std::string num;
		std::cin >> num;

		char arr[101]{};
		int idx = 0;

		while (num.length() != 1)
		{
			char temp = num[num.length() - 1];
			arr[idx++] = temp;

			num.pop_back();
			if (num[num.length() - 1] >= temp)
				num[num.length() - 1] -= temp - '0';
			else
			{
				int digit = num.length() - 2;

				while (digit >= 0 && num[digit] == '0')
				{
					num[digit] = '9';
					digit--;
				}

				num[num.length() - 1] += 10 - (temp - '0');

				num[digit] -= 1;

				if (num[0] == '0')
					num.erase(num.begin());

			}


		}

		if (num == "0")
			for (int i = idx - 1; i >= 0; i--)
			{
				std::cout << arr[i];
			}
		else
			std::cout << 0;

		std::cout << "\n";

	}

	return 0;
}