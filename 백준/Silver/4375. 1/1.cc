#include <iostream>
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n)
	{
		int ans = 1;
		int cnt = 1;

		while (1)
		{
			//나눠떨어짐
			if (ans % n == 0)
				break;
			else
			{
				cnt++;
				ans = ans * 10 + 1;
				ans %= n;
			}
		}
		cout << cnt << "\n";
	}
}