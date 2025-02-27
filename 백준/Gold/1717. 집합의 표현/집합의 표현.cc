#include <iostream>
using namespace std;

int m, n;
int Parent[1'000'002];
int Rank[1'000'002];

//부모 찾기
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
		
	cin >> n >> m;
	
	for (int i = 0; i <= n; ++i)
	{
		Parent[i] = i;
		Rank[i] = 0;
	}
	while (m--)
	{
		int k, a, b;

		cin >> k >> a >> b;

		if(k == 1)
		{ 
			if (Find(a) == Find(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else
		{
			Union(a, b);			
		}
	}
}