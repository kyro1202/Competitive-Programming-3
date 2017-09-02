#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d", &n) == 1)
    {
        int arr[n][n],temp;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
            {
                cin >> temp;
                if(i > 0) temp += arr[i-1][j];
                if(j > 0) temp += arr[i][j-1];
                if(j > 0 && i > 0) temp -= arr[i-1][j-1];
                arr[i][j] = temp;
            }
        int anx = -1270000;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                for(int a = i ; a < n ; a++)
                    for(int b = j ; b < n ; b++)
                    {
                        int p = arr[a][b];
                        if(i > 0) p -= arr[i-1][b];
                        if(j > 0) p -= arr[a][j-1];
                        if(i > 0 && j > 0) p += arr[i-1][j-1];
                        anx = max(anx,p);
                    }
        cout << anx << endl;
    }
}