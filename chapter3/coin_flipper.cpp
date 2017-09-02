#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int test; cin >> test;
    while(test--)
    {
        int n; cin >> n;
        int coins[n];
        for(int i = 0 ; i < n ; i++)
            cin >> coins[i];
        int curr = coins[0]; int tot = 1;
        for(int i = 1 ; i < n-1 ; i++)
        {
            if(curr + coins[i] < coins[i+1])
            {
                curr += coins[i];
                tot++;
            }
        }
        cout << ++tot << endl;
    }
}