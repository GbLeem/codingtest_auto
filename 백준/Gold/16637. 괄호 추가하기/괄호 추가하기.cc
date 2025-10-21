#include <iostream>
#include <string>
#include <climits>
using namespace std;

int n;
string str;
int answer = INT_MIN;

int Calc(int a, int b, char op)
{
	int res = 0;

	switch (op)
	{
	case '+':
		res = a + b;
		break;
	case '-':
		res = a - b;
		break;
	case '*':
		res = a * b;
		break;	
	default:
		break;
	}
	return res;
}

void Choose(int st, int cur)
{
	if (st >= n)
	{
		answer = max(answer, cur);
		return;
	}

	//순서대로 계산
	int nxt = Calc(cur, str[st + 1] - '0', str[st]);
	Choose(st + 2, nxt);

	//괄호 계산
	if (st + 2 < n)
	{
		//뒤에 먼저 계산하고 앞에 더하기
		int temp = Calc(str[st + 1] - '0', str[st + 3] - '0', str[st + 2]);
		int nxtTemp = Calc(cur, temp, str[st]);

		Choose(st + 4, nxtTemp);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> str;
	
	if (n == 1)
	{
		cout << str[0] - '0';
		return 0;
	}
	// 부호, 현재 값
	Choose(1, str[0] - '0');

	cout << answer;
}