#include <bits/stdc++.h>
using namespace std;

int m,n;

int main()
{
    cin >> m >> n; int count = 0; bool started = false;
    while(m+n != 0)
    {
        if(started)
        cout << endl;
        started = true;
        count++;
        char board[m+2][n+2]; memset(board,'0',(m+2)*(n+2)); char c; c = getchar();
        for(int i = 1 ; i < m+1 ; i++)
        {
            for(int j = 1 ; j < n+1 ; j++)
            {
                cin >> c;
                if(c == '*')
                {
                    board[i][j] = '*';
                    for(int k = i - 1 ; k < i + 2 ; k++ )
                    {
                        for(int l = j - 1 ; l < j + 2 ; l++ )
                        {
                            if(board[k][l] != '*')
                            {
                                board[k][l]++;
                            }
                        }
                    }
                }
            }
        }
        
        
                        
        cout << "Field #" << count << ":" << endl;
        for(int i = 1 ; i < m+1 ; i++)
        {
            for(int j = 1 ; j < n+1 ; j++)
            {
                cout << board[i][j];
            }
            cout << endl;
        }
        cin >> m >> n;
    }
}