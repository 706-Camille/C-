#include <iostream>

int vec[100][100]{};
int vec2[100][100]{};

int main()
{
    int T;
    std::cin >> T;

    while (T--)
    {
        int r, s, t;
        std::cin >> r >> s >> t;


        for (int row = 0; row < r; row++)
            for (int col = 0; col < s; col++)
            {
                std::cin >> vec[row][col];
            }

        for (int row = 0; row < s; row++)
            for (int col = 0; col < t; col++)
            {
                std::cin >> vec2[row][col];
            }

        for (int row = 0; row < r; row++)
        {
            for (int col = 0; col < t; col++)
            {
                int sum = 0;
                for (int k = 0; k < s; k++)
                {
                    sum += vec[row][k] * vec2[k][col];
                }
                std::cout << sum << " ";
            }

            std::cout << "\n";
        }

    }


    return 0;
}

