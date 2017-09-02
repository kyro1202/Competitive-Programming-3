#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int test,a,b,c; cin >> test;
    while(test--)
    {
        cin >> a >> b >> c;
        long long int temp;
        long long int memo[a][b][c];
        for(int i = 0 ; i < a ; i++)
            for(int j = 0 ; j < b ; j++)
                for(int k = 0 ; k < c ; k++)
                {
                    cin >> temp;
                    if(i > 0) temp += memo[i-1][j][k];
                    if(j > 0) temp += memo[i][j-1][k];
                    if(k > 0) temp += memo[i][j][k-1];
                    if(i > 0 && j > 0) temp -= memo[i-1][j-1][k];
                    if(i > 0 && k > 0) temp -= memo[i-1][j][k-1];
                    if(j > 0 && k > 0) temp -= memo[i][j-1][k-1];
                    if(i > 0 && j > 0 && k > 0) temp += memo[i-1][j-1][k-1];
                    memo[i][j][k] = temp;
                }
        long long int ans = LONG_LONG_MIN;
        for(int i = 0 ; i < a ; i++)
            for(int j = 0 ; j < b ; j++)
                for(int k = 0 ; k < c ; k++)
                    for(int x = i ; x < a ; x++)
                        for(int y = j ; y < b ; y++)
                            for(int z = k ; z < c ; z++)
                            {
                                long long int p = memo[x][y][z];
                                if(i > 0) p -= memo[i-1][y][z];
                                if(j > 0) p -= memo[x][j-1][z];
                                if(k > 0) p -= memo[x][y][k-1];
                                if(i > 0 && j > 0) p += memo[i-1][j-1][z];
                                if(i > 0 && k > 0) p += memo[i-1][y][k-1];
                                if(j > 0 && k > 0) p += memo[x][j-1][k-1];
                                if(i > 0 && j > 0 && k > 0) p -= memo[i-1][j-1][k-1];
                                ans = max(ans,p);
                            }
        cout << ans << endl;
        if(test)
        cout << endl;
    }
}