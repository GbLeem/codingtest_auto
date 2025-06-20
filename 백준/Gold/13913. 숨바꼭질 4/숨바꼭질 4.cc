#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int arr[100'002];
int vis[100'002];
vector<int> ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	queue<int> q;
	q.push(n);
	arr[n] = 1;

	while (arr[k] == 0)
	{
		int cur = q.front();
		q.pop();
		
		for (int nxt : {cur - 1, cur + 1, cur * 2})
		{
			if (nxt < 0 || nxt > 100'000)
				continue;
			if (arr[nxt])
				continue;
			q.push(nxt);
			arr[nxt] = arr[cur] + 1;
			vis[nxt] = cur;
		}
	}	

	int val = k;
	for(int i =0 ; i < arr[k] - 1; ++i)
	{		
		ans.push_back(val);
		val = vis[val];
	}
	ans.push_back(n);
	reverse(ans.begin(), ans.end());

	cout << arr[k] - 1 << "\n";
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}
}