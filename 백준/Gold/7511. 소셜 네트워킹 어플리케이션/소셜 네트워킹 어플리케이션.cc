#include <iostream>
#include <vector>

using namespace std;

int Parent[1'000'002];
int Rank[1'000'002];

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

	int T;
	cin >> T;
	for(int j = 1; j <= T; ++j)
	{
		int n, k;
		cin >> n; //user
		cin >> k; //friend

		for (int i = 0; i <= n; ++i)
		{
			Parent[i] = i;
			Rank[i] = 0;
		}

		while (k--)
		{
			int a, b;
			cin >> a >> b;

			Union(a, b); //와 b는 친구
		}
		int m;
		cin >> m;
		cout << "Scenario " << j << ":\n";

		//m개의 정답 출력
		while (m--)
		{
			int u, v;
			cin >> u >> v;
			
			if (Find(u) == Find(v))
				cout << 1 << "\n";
			else
				cout << 0 << "\n";						
		}
		cout << "\n";
	}
}