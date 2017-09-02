#include <bits/stdc++.h>
using namespace std;
int gmax;int n,tot;vector<int> ans;
void backtrack(vector<int> comb,int ind,int ar[],int sum)
{
    comb.push_back(ar[ind]); sum += ar[ind];
    if(sum > gmax || (sum == gmax && comb.size() > ans.size()))
    {
        gmax = sum;
        ans = comb;
    }
    for(int i = ind + 1 ; i < tot ; i++)
    {
        if(sum + ar[i] <= n)
        {
            backtrack(comb,i,ar,sum);
        }
    }
}
int main()
{
    while(scanf("%d", &n) == 1)
    {
        int p,index; cin >> tot;
        int cd[tot];
        for(int i = 0 ; i < tot ; i++)
            cin >> cd[i];
        gmax = 0; ans.clear();
        for(int i = 0 ; i < tot ; i++)
        {    
            vector<int> comb;
            backtrack(comb,i,cd,0);
        }
        for(int i = 0 ; i < ans.size() ; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "sum" << ":" << gmax << endl; 
    }
}