#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<string>> ticket;
vector<string> answer;
bool vis[10002];
bool isAnswer;

void DFS(string cur, int cnt)
{
	answer.push_back(cur);

	//모든 티켓을 다 쓴 상황
	if (cnt == ticket.size())
	{
		isAnswer = true;
	}

	for (int i = 0; i < ticket.size(); ++i)
	{
		if (vis[i])
			continue;
		if (ticket[i][0] == cur)
		{
			vis[i] = true;
			DFS(ticket[i][1], cnt + 1);

			if (!isAnswer)
			{
				answer.pop_back();
				vis[i] = false;
			}
		}
	}

}

vector<string>solution(vector<vector<string>>tickets)
{
	sort(tickets.begin(), tickets.end());
	ticket = tickets;
	DFS("ICN", 0);

	return answer;
}