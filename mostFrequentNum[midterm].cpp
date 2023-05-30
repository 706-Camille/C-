#include <iostream>
#include <vector>
#include <string>
#include <algorithm>



int main()
{
	int T;
	std::cin >> T;

	while (T--)
	{
		int iInput;
		int nums[101]{};

		while (true)
		{
			std::cin >> iInput;

			if (iInput == 0)
				break;

			if (1 <= iInput && iInput <= 100)
				nums[iInput]++;
		}

		int max = 0;

		for (int i = 1; i <= 100; i++)
		{
			if (nums[i] > max)
				max = nums[i];
		}

		if (max == 0)
		{
			std::cout << 0 << "\n";
			continue;
		}

		int ans[101]{};
		int idx = 0;

		for (int i = 1; i <= 100; i++)
		{
			if (nums[i] == max)
				ans[idx++] = i;
		}

		std::cout << ans[idx - 1] << "\n";

	}

	return 0;
}