// Score: 200/200

#include <iostream>

using namespace std;

constexpr int MAX_N = 3000;

int main()
{
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int count = 0;
    for (auto r = 0u; r <= MAX_N / R; ++r)
    {
        auto rc = R * r;
        for (auto g = 0u; g <= (MAX_N - rc) / G; ++g)
        {
            auto rest = N - rc - G * g;
            if (rest / B <= MAX_N && rest % B == 0)
            {
                ++count;
            }
        }
    }
    cout << count;
}
