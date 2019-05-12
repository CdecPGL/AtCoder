// Score: 300/300

#include <string>
#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int count = 0;
	int la_count = 0;
	int fb_count = 0;
	int ba_count = 0;
	for (auto n = 0u; n < N; ++n)
	{
		string s;
		cin >> s;
		size_t pos = 0;
		while (true)
		{
			pos = s.find("AB", pos);
			if (pos == string::npos)
			{
				break;
			}
			else
			{
				++count;
				pos += 2;
			}
		}

		auto first_c = s[0];
		auto last_c = s[s.size() - 1];
		if (last_c == 'A')
		{
			if (first_c == 'B')
			{
				++ba_count;
			}
			else
			{
				++la_count;
			}
		}
		else if (first_c == 'B')
		{
			++fb_count;
		}
	}

	bool is_last_a = false;
	while (true)
	{
		if (!is_last_a)
		{
			if (la_count)
			{
				--la_count;
				is_last_a = true;
			}
			else if (ba_count)
			{
				--ba_count;
				is_last_a = true;
			}
			else
			{
				break;
			}
		}

		if (ba_count)
		{
			--ba_count;
			++count;
			is_last_a = true;
		}
		else if (fb_count)
		{
			--fb_count;
			++count;
			is_last_a = false;
		}
		else
		{
			break;
		}
	}

	cout << count;
}
