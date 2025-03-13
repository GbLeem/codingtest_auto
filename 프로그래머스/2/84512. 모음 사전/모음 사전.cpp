#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int amount[5] = {781, 156, 31, 6, 1};
unordered_map<char, int> um;
int solution(string word) 
{
    int answer = 0;
    
    um.insert({'A', 0});
    um.insert({'E', 1});
    um.insert({'I', 2});
    um.insert({'O', 3});
    um.insert({'U', 4});
    
    for(int i = 0; i < word.size(); ++i)
    {
        answer += um[word[i]] * amount[i] + 1;        
    }
    return answer;
}