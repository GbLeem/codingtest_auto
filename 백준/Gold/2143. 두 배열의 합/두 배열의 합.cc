#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, m;
long long arrA[1002], arrB[1002];
long long dpA[1002], dpB[1002];
vector<long long> A, B;
long long answer = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arrA[i];
		dpA[i] = dpA[i - 1] + arrA[i];
	}
	cin >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> arrB[i];
		dpB[i] = dpB[i - 1] + arrB[i];
	}
	
	//정렬이 안되어있는 각 배열에서 하나 이상씩 값을 가져와서 더해서 T를 만들기
	//가져올때 idx 오름차순으로 가져와야함

	//구간합
	//dp[i] = 1~i까지 합

	//모든 부분합
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			A.push_back(dpA[i] - dpA[j]);
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			B.push_back(dpB[i] - dpB[j]);
		}
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	for (int i = 0; i < A.size(); ++i)
	{
		int temp = t - A[i];
		answer += (upper_bound(B.begin(), B.end(), temp) - lower_bound(B.begin(), B.end(), temp));
	}
	cout << answer;
}