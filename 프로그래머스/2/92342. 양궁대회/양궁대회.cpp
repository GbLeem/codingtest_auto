#include <vector>
#include <algorithm>

using namespace std;

int max_diff = 0;
vector<int> answer(11, 0);

bool isBetter(const vector<int>& ryan_info) 
{
    for (int i = 10; i >= 0; --i) {
        if (ryan_info[i] > answer[i]) {
            return true;
        }
        if (ryan_info[i] < answer[i]) {
            return false;
        }
    }
    return false;
}

void dfs(int index, int arrows_left, vector<int>& ryan_info, const vector<int>& apeach_info) 
{
    if (index == 11) 
    {

        if (arrows_left > 0) 
        {
            ryan_info[10] = arrows_left;
        }

        int ryan_score = 0;
        int apeach_score = 0;
        for (int i = 0; i < 11; ++i) 
        {
            if (ryan_info[i] == 0 && apeach_info[i] == 0) 
                continue;

            if (ryan_info[i] > apeach_info[i]) 
            {
                ryan_score += (10 - i);
            } else 
            {
                apeach_score += (10 - i);
            }
        }
        
        if (ryan_score > apeach_score) 
        {
            int diff = ryan_score - apeach_score;
            if (diff > max_diff) 
            {
                max_diff = diff;
                answer = ryan_info;
            } else if (diff == max_diff && isBetter(ryan_info)) 
            {
                answer = ryan_info;
            }
        }
        
        if (arrows_left > 0) 
        {
            ryan_info[10] = 0;
        }
        return;
    }

    int arrows_to_win = apeach_info[index] + 1;
    if (arrows_left >= arrows_to_win) 
    {
        ryan_info[index] = arrows_to_win;
        dfs(index + 1, arrows_left - arrows_to_win, ryan_info, apeach_info);
        ryan_info[index] = 0;
    }

    dfs(index + 1, arrows_left, ryan_info, apeach_info);
}

vector<int> solution(int n, vector<int> info) 
{
    vector<int> ryan_info(11, 0);
    dfs(0, n, ryan_info, info);

    if (max_diff == 0) 
    {
        return {-1};
    }
    
    return answer;
}