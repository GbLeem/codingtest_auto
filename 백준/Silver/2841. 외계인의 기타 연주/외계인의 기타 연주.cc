#include <iostream>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;

int n, p;
unordered_map<int, priority_queue<int>> um;
int answer = 0;
vector<vector<int>> vec;

//줄을 넣었을때 몇번 프랫이 있는지
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p;

	for (int i = 0; i < n; ++i)
	{
		int L, P;
		cin >> L >> P;
		
		//한번도 안누른 줄일 때
		if (um.empty() || um.find(L) == um.end())
		{
			priority_queue<int> pq;
			pq.push(P);
			um.insert({ L, pq });
			answer++;
		}
		else
		{
			while (!um[L].empty() && um[L].top() > P)
			{
				um[L].pop();
				answer++;
			}

			//새롭게 눌러야 하는 경우
			if (um[L].empty() || um[L].top() < P)
			{
				um[L].push(P);
				answer++;
			}
		}
	}
	cout << answer;
}


//숫자가 높을수록 높은 프랫
//숫자가 높은 프랫이면 그냥 바로 연주 ㄱ


//2 10
//2 5
//2 2
//2 1