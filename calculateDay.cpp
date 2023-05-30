#include <iostream>

int main()
{
	int T;
	std::cin >> T;

	while (T--)
	{
		int startDay = 5;

		int year, month, day;
		std::cin >> year >> month >> day;

		for (int i = 1582; i < year; i++)
		{
			if (i % 4 == 0)
			{
				if (i % 100 == 0 && i % 400 != 0)
					startDay++;
				else
					startDay += 2;
			}
			else
				startDay++;
		}


		for (int i = 1; i < month; i++)
		{
			switch (i)
			{
			case 2:
				if (year % 4 == 0)
				{
					if (year % 100 == 0 && year % 400 != 0)
						startDay += 28;
					else
						startDay += 29;
				}
				else
					startDay += 28;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				startDay += 30;
				break;
			default:
				startDay += 31;
			}
		}

		startDay += day - 1;

		std::cout << startDay % 7 << "\n";
	}

	return 0;
}