#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> scores) 
{
    int answer = 1;

    int a = scores[0][0];
    int b = scores[0][1];

    sort(scores.begin(), scores.end(), [](const vector<int>& u, const vector<int>& v)
        {
            if (u[0] != v[0]) 
                return u[0] > v[0];
            return u[1] < v[1];
        });

    int tempY = -1;
    vector<int> temp;

    for (const auto& s : scores)
    {
        if (s[1] < tempY)
        {
            if (s[0] == a && s[1] == b)
                return -1;
            continue;
        }
        else
        {
            temp.push_back(s[0] + s[1]);
        }
        tempY = max(tempY, s[1]);
    }

    sort(temp.begin(), temp.end(), greater<int>());

    for (const auto& t : temp)
    {
        if (t == a + b)
            return answer;
        answer++;
    }

    return answer;
}