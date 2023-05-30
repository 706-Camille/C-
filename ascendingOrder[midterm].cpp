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
		int N;
		std::cin >> N;


		bool flag = 0;
		int temp, iInput, ans = 0, cnt = 0;

		std::cin >> temp;
		for (int i = 1; i < N; i++)
		{
			std::cin >> iInput;

			if (temp <= iInput && flag == 0)
			{
				ans += temp;
				ans += iInput;
				flag = 1;
				cnt++;
			}
			else if (temp <= iInput && flag == 1)
			{
				ans += iInput;
			}
			else if (temp > iInput)
				flag = 0;

			temp = iInput;
		}

		std::cout << cnt << " " << ans << "\n";
	}


	return 0;
}