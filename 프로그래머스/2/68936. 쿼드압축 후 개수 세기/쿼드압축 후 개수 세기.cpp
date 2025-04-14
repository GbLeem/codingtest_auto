#include <string>
#include <vector>

using namespace std;

int one = 0;
int zero = 0;
vector<vector<int>> arr2;

bool check(int x, int y, int size)
{
    int temp = arr2[x][y];
    
    for(int i = x; i < x+ size; ++i)
    {
        for(int j = y; j < y + size; ++j)
        {
            if(temp != arr2[i][j])
                return false;
        }
    }
    if(temp == 1)
        one++;
    if(temp == 0)
        zero++;
    
    return true;
}

void compress(int x, int y, int size)
{
    if(!check(x, y, size))
    {
        compress(x, y, size/2);
        compress(x, y + size/2, size/2);
        compress(x+size/2, y, size/2);
        compress(x+size/2, y + size/2, size/2);        
    }
}

vector<int> solution(vector<vector<int>> arr) 
{
    vector<int> answer;
    arr2 = arr;
    
    compress(0, 0, arr.size());
    
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}