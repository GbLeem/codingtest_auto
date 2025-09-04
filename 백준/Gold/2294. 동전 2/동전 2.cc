#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int coin[102];
int dp[10'002]; //현재 값이 i일 때의 최소 동전의 개수

//동전 갯수가 최소로 딱 k원 만들기
//배낭문제 dp

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	fill(dp + 1, dp + k + 1, 10'002);
	
	for (int i = 1; i <= n; ++i)
	{
		cin >> coin[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = coin[i]; j <= k; ++j)
		{
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
	if (dp[k] == 10'002)
		cout << -1;
	else
		cout << dp[k];
}