#include <iostream>
#include <queue>
using namespace std;

int N;
int answer = 0;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		pq.push(num);
	}

	while (pq.size() > 1)
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();

		int sum = a + b;
		pq.push(sum);
		answer += sum;
	}
	cout << answer;
}