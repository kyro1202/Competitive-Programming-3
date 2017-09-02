#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int test; cin >> test;
    while(test--)
    {
        int n; cin >> n;
        int arr[n*2][n*2];
        for(int i = 0 ; i < 2*n ; i++)
            for(int j = 0 ; j < 2*n ; j++)
            {
                if(i < n && j < n)
                {
                    cin >> arr[i][j];
                    arr[i+n][j] = arr[i][j+n] = arr[i+n][j+n] = arr[i][j];
                }
                if(i > 0) arr[i][j] += arr[i-1][j];
                if(j > 0) arr[i][j] += arr[i][j-1];
                if(i > 0 && j > 0) arr[i][j] -= arr[i-1][j-1];
            }
        int anx = -100*75*75;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                for(int a = i ; a < i+n ; a++)
                    for(int b = j ; b < j+n ; b++)
                    {
                        int s = arr[a][b];
                        if(i > 0) s -= arr[i-1][b];
                        if(j > 0) s -= arr[a][j-1];
                        if(i > 0 && j > 0) s += arr[i-1][j-1];
                        anx = max(anx,s);
                    }
        cout << anx << endl;
    }    
}