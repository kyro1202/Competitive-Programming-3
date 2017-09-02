#include <bits/stdc++.h>
using namespace std;
int t,n; bool flag = false;
int ar[14]; map<vector<int> , bool> s; vector<int> v;
void check(vector<int> v,int m,int sum,int ind)
{
    if(sum == t)
    {
        flag = true;
        if(s[v] == true) return;
        s[v] = true;
        for(int i = 0 ; i < ind ; i++)
        {
            if(i != ind - 1)
            cout << v[i] << "+";
            else
            cout << v[i];
        }
        cout << endl;
        return;
    }
    if(sum > t || m == n)
    return; 
    for(int i = m ; i < n ; i++)
    {
        v.push_back(ar[i]); check(v,i+1,sum+ar[i],ind+1); v.pop_back();
    }
}
int main()
{
    while(true)
    {
        flag = false; s.clear();
        cin >> t;
        if(!t)
            break;
        cin >> n;
        for(int i = 0 ; i < n ; i++)
            cin >> ar[i];
        cout << "Sums of " << t << ":" << endl;
        check(v,0,0,0);
        if(!flag)
        cout << "NONE" << endl;
    }
}