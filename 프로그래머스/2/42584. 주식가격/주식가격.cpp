#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size());

    for (int i = 0; i < prices.size(); ++i)
    {
        int temp = 0;
        for (int j = i + 1; j < prices.size(); ++j)
        {   
            temp++;
            if (prices[i] > prices[j])            
                break;                       
        }
        answer[i] = temp;
    }
    return answer;
}