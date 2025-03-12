#include <iostream>
using namespace std;

int n, s;
int board[22];
int isused[22];
int temp = 0;
int answer = 0;

void Choose(int cur)
{
	if (cur == n)
	{
		temp = 0;
		for (int i = 0; i < n; ++i)
		{
			//사용된 경우
			if (isused[i])
			{
				temp += board[i];
				//cout << i << " ";
			}
		}

		if (temp == s)
			answer++;		
		//cout << "\n";
		return;
	}

	Choose(cur + 1);

	isused[cur] = 1;
	Choose(cur + 1);
	isused[cur] = 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;

	for (int i = 0; i < n; ++i)
	{
		cin >> board[i];
	}

	Choose(0);
	//공집합
	if (s == 0)
		answer--;
	cout << answer;
}