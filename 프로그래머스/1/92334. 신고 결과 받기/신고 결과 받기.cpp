#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer(id_list.size());
    unordered_map<string, set<string>> um;
    unordered_map<string, int> temp;

    for (int i = 0; i < report.size(); ++i)
    {
        size_t pos = report[i].find(' ');
        string temp1 = report[i].substr(0, pos);
        string temp2 = report[i].substr(pos + 1);

        um[temp2].insert(temp1);
    }

    for (auto it = um.begin(); it != um.end(); ++it)
    {
        if (it->second.size() >= k)
        {
            for (auto u : um[it->first])
            {
                temp[u]++;                   
            }
        }
    }
    for (int i = 0; i < id_list.size(); ++i)
    {
        if (temp[id_list[i]])
            answer[i] = temp[id_list[i]];
        else
            answer[i] = 0;
    }


    return answer;
}