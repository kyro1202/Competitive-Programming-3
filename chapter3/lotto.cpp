#include <bits/stdc++.h>
using namespace std;
int s[15],ans[6],n;
void dfs(int ind,int i)
{
    if(ind == 6)
    {
        cout << ans[0];
        for(int j = 1 ; j < 6 ; j++)
        {
            cout << " " << ans[j];
        }
        cout << endl;
        return;
    }
    for( ; i < n ; i++)
    {
        ans[ind] = s[i];
        dfs(ind+1,i+1);
    }
}
int main()
{
    bool first = true;
    while(cin >> n , n)
    {
        if(!first)
        cout << endl;
        first = false;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> s[i];
        }
        dfs(0,0);
    }
}