#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

pair<double, double> board[10'002];
int n;
double answer = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> board[i].first >> board[i].second;
	}

	for (int i = 0; i < n; ++i)
	{
		int j = (i + 1) % n;
		answer += (board[i].first * board[j].second) - (board[i].second * board[j].first);
	}
	
	answer = abs(answer);
	answer /= 2;
	
	cout << fixed;
	cout.precision(1);
	cout << answer;
}