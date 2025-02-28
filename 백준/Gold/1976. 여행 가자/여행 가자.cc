#include <iostream>
using namespace std;

int n, m;
int Parent[202];
int Rank[202];
int Ans[202];

int Find(int a)
{
	if (Parent[a] == a)
		return a;
	Parent[a] = Find(Parent[a]);

	return Parent[a];
}

void Union(int a, int b)
{
	int rootA = Find(a);
	int rootB = Find(b);

	if (rootA != rootB)
	{
		//B랭크가 더 크면
		if (Rank[rootA] < Rank[rootB])
		{
			//B쪽으로 붙이기
			Parent[rootA] = rootB;
		}
		else if (Rank[rootA] > Rank[rootB])
		{
			Parent[rootB] = rootA;
		}
		else
		{
			Parent[rootA] = rootB;
			Rank[rootB]++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; ++i)
	{
		Parent[i] = i;
		Rank[i] = 0;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int k;
			cin >> k;

			if (k == 1)
			{				
				Union(i, j);
			}
		}
	}
	int temp = -1;
	string ans = "YES";

	for (int i = 0; i < m; ++i)
	{
		int num;
		cin >> num;
		
		//처음
		if (temp == -1)
			temp = Find(num);

		if(temp != Find(num))
		{
			ans = "NO";
			break;
		}
	}
	cout << ans;	
}