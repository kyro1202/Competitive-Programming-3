#include <bits/stdc++.h>
using namespace std;
int n,m,first,last;
vector<pair<int,int> > pieces; bool flag = false; bool used[15];
void place(int ind,int curr,int next)
{
    if(ind == n)
    {
        if(next == last)
        {
            flag = true;
        }
        return;
    }
    for(int i = 0 ; i < m ; i++)
    {
        if(!used[i])
        {
            if(next == pieces[i].first)
            {
                used[i] = true;
                place(ind+1,next,pieces[i].second);
                used[i] = false;
            }
            else if(next == pieces[i].second)
            {
                used[i] = true;
                place(ind+1,next,pieces[i].first);
                used[i] = false;
            }
        }
    }
}
int main()
{
    while(true)
    {
        cin >> n;
        if(!n)
            break;
        flag = false; pieces.clear(); 
        memset(used,false,15);
        cin >> m;
        int temp,temp2;
        cin >> temp >> first; cin >> last >> temp;
        for(int i = 0 ; i < m ; i++)
        {
            cin >> temp >> temp2;
            pieces.push_back(make_pair(temp,temp2));
        }
        place(0,0,first);
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}