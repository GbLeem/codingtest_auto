#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const vector<string>& v1, const vector<string>& v2)
{
    return v1.size() < v2.size();
}

vector<int> solution(string s)
{
    vector<string> answer;

    vector<vector<string>> vec;
    vector<string> tempVec;

    for (int i = 1; i < s.size() - 1; ++i)
    {
        if (s[i] != '{' && s[i - 1] == '{')
        {
            if (!tempVec.empty())
            {
                vec.push_back(tempVec);
                tempVec.clear();
            }

            string temp;
            temp += s[i];

            int idx = i;
            while (1)
            {
                idx++;
                if (s[idx] == ',' || s[idx] == '}')
                {
                    tempVec.push_back(temp);
                    break;
                }
                temp += s[idx];
            }
        }
        if (s[i] != '{' && s[i - 1] == ',')
        {
            string temp;
            temp += s[i];

            int idx = i;
            while (1)
            {
                idx++;
                if (s[idx] == ',' || s[idx] == '}')
                {
                    tempVec.push_back(temp);
                    break;
                }
                temp += s[idx];
            }
        }
    }
    if (!tempVec.empty())
        vec.push_back(tempVec);

    sort(vec.begin(), vec.end(), cmp);

    for (auto v : vec)
    {
        for (auto vi : v)
        {
            //answer에 없는 것 순서로 넣기
            if (answer.empty())
                answer.push_back(vi);

            else
            {
                auto it = find(answer.begin(), answer.end(), vi);
                if(it == answer.end())
                    answer.push_back(vi);
            }
        }
    }

    vector<int>ans;
    for (auto a : answer)
    {
        ans.push_back(stoi(a));
    }
    return ans;
}