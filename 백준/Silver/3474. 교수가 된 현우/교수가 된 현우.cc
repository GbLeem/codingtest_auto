#include <iostream>
using namespace std;

int T;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	
	while (T--)
	{
		int num;
		int answer1 = 0;
		int answer2 = 0;
		cin >> num;
		
		int temp1 = 2;
		while (temp1 <= num)
		{
			answer1 += num / temp1;
			temp1 *= 2;
		}

		int temp2 = 5;
		while (temp2 <= num)
		{
			answer2 += num / temp2;
			temp2 *= 5;
		}

		cout << min(answer1, answer2) << "\n";
	}
}