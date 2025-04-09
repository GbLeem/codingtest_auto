#include <iostream>
using namespace std;

int t;
int m, n, x, y;

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}

int Check(int m, int n, int x, int y)
{
	//k*m+1번째에는 항상 x가 1이된다. 1, 11, 21
	//k*n+1번째에는 항상 y가 1이된다. 1, 13, 25

	//최소공배수까지 돌면서
	//m번째 놈을 찾기
	int answer = -1;
	int l = lcm(m, n);

	for (int xi = x; xi <= l; xi += m)
	{
		int yi = xi % n;

		if (yi == 0)
			yi = n;
		if (yi == y)
		{
			answer = xi;
			break;
		}
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		cin >> m >> n >> x >> y;

		//10 12
		//1 1 - 2 2 - 3 3 - 4 4 - 5 5 - 6 6 - 7 7 - 8 8 - 9 9 - 10 10 - 1 11 - 2 12 
		//3 1 - 4 2 - 5 3 - 6 4 - 7 5 - 8 6 - 9 7 - 10 8 - 1 9 - 2 10 - 3 11 - 4 12
		//5 1
		cout << Check(m, n, x, y) << "\n";
	
	}
}