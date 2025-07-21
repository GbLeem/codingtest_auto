#include <iostream>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map<string, int> um;
int answer = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		string name;
		cin >> name;
		um[name]++;
	}

	for (int i = 0; i < M; ++i)
	{
		string name;
		cin >> name;
		if (um[name])
			answer++;
	}
	cout << answer;
}