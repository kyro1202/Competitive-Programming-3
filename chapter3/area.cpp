#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int test; cin >> test;
    for(int ti = 1 ; ti <= test ; ti++)
    {
        int n,m; long long int k;
        cin >> n >> m >> k;
        long long int arr[n][m],temp;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
            {
                cin >> temp;
                if(i > 0) temp += arr[i-1][j];
                arr[i][j] = temp;
            }
        long long int anp = 0,anx = 0;
        for(int i = 0 ; i < n ; i++)
            for(int j = i ; j < n ; j++)
            {
                int col = 0;
                long long int cost = 0;
                for(int a = 0 ; a < m ; a++)
                {
                    int col_sum = arr[j][a];
                    if(i > 0) col_sum -= arr[i-1][a];
                    cost += col_sum;
                    if(cost > k)
                    {
                        while(cost > k)
                        {
                            cost -= arr[j][col];
                            if(i > 0) cost += arr[i-1][col];
                            col++;
                        }
                    }
                    int area = (a - col + 1)*(j - i + 1);
                    if(area == anx)
                    {
                        anp = min(anp,cost);
                    }
                    else if(area > anx)
                    {
                        anx = area;
                        anp = cost;
                    }
                }
            }
                    
        cout << "Case #" << ti << ": " << anx << " " << anp << endl;
    }
}