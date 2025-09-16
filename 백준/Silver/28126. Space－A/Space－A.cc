#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int n;
string str;
int k;
int answer = 0;

//일단 탐색으로 지점까지 가는 동안의 경로가 
//N에 포함된다면 OK

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> str;
	cin >> k;

	int U = 0;
	int R = 0;
	int X = 0;

	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == 'U')
			U++;
		else if (str[i] == 'R')
			R++;
		else
			X++;
	}

	while (k--)
	{
		int x, y;
		cin >> x >> y;

		//움직일 거리
		x--;
		y--;

		//최소 이동 하고
		int cnt = min(min( x, y), X );
		x -= cnt;
		y -= cnt;

		//남은걸로 갈 수 있을때
		if (R >= x && U >= y)
			answer++;
	}
	cout << answer;
}