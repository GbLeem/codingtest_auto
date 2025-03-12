#include <iostream>
using namespace std;

int n, m;
long long state[10];

//x가 가지는 1의 갯수를 반환하는 함수
int bitcount(long long x)
{
	int ret = 0;
	for (int i = 0; i < m; ++i)
	{
		ret += (x >> i) & 1;
		//ret += 1 & (i << x);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		string name, temp;
		cin >> name >> temp;

		for (int j = m - 1; j >= 0; --j)
		{
			state[i] = (state[i] << 1) | (temp[j] == 'Y');
		}
	}

	pair<int, int> ans = { 0, -1 };//곡의 수, 기타 수
	for (int tmp = 0; tmp < (1 << n); ++tmp)
	{
		long long comb = 0; //조합 결과
		for (int i = 0; i < m; ++i)
		{
			if (!(tmp & (1LL << i)))
				continue;
			comb |= state[i];
		}

		int song = bitcount(comb);
		int guitar = bitcount(tmp);

		//곡의 수가 더 많은 경우
		if (ans.first < song)
			ans = { song, guitar };
		//곡의 수는 같은데 기타가 적은 경우
		else if (ans.first == song && ans.second > guitar)
			ans = { song, guitar };
	}
	cout << ans.second;
}