#include <bits/stdc++.h>
using namespace std;
long long int rock[110]; bool small[110],taken[110];
long long int min_dis(int n)
{
    long long int ans = rock[0];
    for(int i = 0 ; i < n ; i++)
    {
        taken[i] = true;
        if(!small[i+1])
        {
            ans = max(ans,rock[i+1]-rock[i]);
        }
        else
        {
            ans = max(ans,rock[i+2]-rock[i]);
            i++;
        }
    }
    for(int i = n ; i > 0 ; i--)
    {
        if(!taken[i-1] || !small[i-1])
        {
            ans = max(ans,rock[i]-rock[i-1]);
        }
        else
        {
            ans = max(ans,rock[i]-rock[i-2]);
            i--;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    int test; cin >> test;
    for(int ti = 1 ; ti <= test ; ti++)
    {
        int n; long long int d;
        cin >> n >> d;
        for(int i = 0 ; i < n ; i++)
        {
            char type,temp;
            cin >> type >> temp >> rock[i];
            small[i] = ( type == 'S');
            taken[i] = false;
        }
        rock[n] = d;
        taken[n] = false;
        small[n] = false;
        cout << "Case " << ti << ": " << min_dis(n) << endl;        
    }
}

