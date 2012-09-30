#include <iostream>
#include <cstdlib>

using namespace std;

const int MAXN = 8;
int line[MAXN];

int dfs(int row)
{
    if(row >= MAXN) {
        for(int k = 0; k < MAXN; ++k)
          cout << line[k] << " ";
        cout << endl;
        return 1;
    }
    int i, j;
    int cnt = 0;
    for(i = 0; i < MAXN; i++)
    {
        // 判断是否与先前放置的皇后冲突
        for(j = 0; j < row; j++)
        {
            if(line[j] == i || abs(line[j] - i) == row - j)
                break;
        }
        if(j == row)
        {
            line[row] = i;
            cnt += dfs(row + 1);
        }
    }
    return cnt;
}

int main( int c, char ** v ) 
{
    cout << dfs(0) << endl;
}

