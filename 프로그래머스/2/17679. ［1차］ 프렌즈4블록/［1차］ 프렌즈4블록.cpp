#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer = 0;
int row;
int col;

void Print(vector<string>& board)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}
void Reset(vector<string>& board)
{
    vector<string> temp(row);
    for (int i = 0; i < row; ++i)
    {
        temp[i].resize(col, ' ');
    }

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (board[i][j] == '0')
            {
                if (board[i + 1][j] != '0')
                {
                    board[i + 1][j] = '1';
                }
                if (board[i][j + 1] != '0')
                {
                    board[i][j + 1] = '1';
                }
                if (board[i + 1][j + 1] != '0')
                {
                    board[i + 1][j + 1] = '1';
                }
            }
        }
    }

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (board[i][j] == '1' || board[i][j] == '0')
                answer++;
        }
    }


    int tempRow = row - 1;
    for (int i = 0; i < col; ++i)
    {
        for (int j = row - 1; j >= 0; --j)
        {
            if (isalpha(board[j][i]))
            {
                temp[tempRow][i] = board[j][i];
                tempRow--;
            }
        }
        tempRow = row - 1;
    }
    board.clear();
    board = temp;
}

bool Check(int x, int y, vector<string>& board)
{
    char cmp = board[x][y];
    if (!isalpha(cmp))
        return false;
    if (x + 1 >= row || y + 1 >= col)
        return false;
    if (board[x + 1][y] == cmp && board[x][y + 1] == cmp && board[x + 1][y + 1] == cmp)
        return true;
    else
        return false;
}

int solution(int m, int n, vector<string> board)
{
    row = m;
    col = n;

    //가로-1 세로 -1 모든 경우의 수를 돌면서
    //x+1 y+1 x+1 y+1 체크후 조건 만족하면, 시작점에만 체크
    //다 돌면, 내려주기

    while (1)
    {
        bool bomb = false;

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (Check(i, j, board))
                {
                    board[i][j] = '0';
                    bomb = true;
                }
            }
        }
        //한번도 안터진 경우는 끝
        if (!bomb)
            break;
        //board 내려주기
        Reset(board);

        /*Print(board);
        cout << answer << "\n";*/
    }

    return answer;
}