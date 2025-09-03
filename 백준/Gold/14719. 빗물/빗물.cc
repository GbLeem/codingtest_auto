#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int w, h;
vector<int> vec(502);
stack<int> st;
int answer = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	
	for (int i = 0; i < w; ++i)
	{
		cin >> vec[i];
	}

	for (int i = 0; i < w; ++i)
	{
		//더 높은 벽이 생긴 경우
		while (!st.empty() && vec[st.top()] < vec[i])
		{
			int idx = st.top();
			st.pop();

			if (st.empty())
			{
				break;
			}
			int left = st.top();
			int width = i - left - 1;
			int height = min(vec[left], vec[i]) - vec[idx];
			answer += height * width;
		}
		st.push(i);
	}

	cout << answer;
}