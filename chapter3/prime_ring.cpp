#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > table; int n;
int prime[] = {2,3,5,7,11,13,17,19,23,29,31};
bool find(int a)
{
    int low = 0,high = 10;
    while(high >= low)
    {
        int mid = (high + low) / 2;
        if(prime[mid] == a)
        return true;
        else if(prime[mid] > a)
        high = mid - 1;
        else
        low = mid + 1;
    }
    return false;
}
void backtrack(vector<int> comb,bool visited[],int next)
{
    if(next == (n - 1))
    {
        if(find(comb[next]+1))
        table.push_back(comb);
        return;
    }
    for(int i = 2 ; i <= n ; i++)
    {
        if(!visited[i-1])
        {
            if(find(i+comb[next]))
            {
                visited[i-1] = true;
                comb.push_back(i);
                backtrack(comb,visited,next+1);
                comb.erase(find(comb.begin(),comb.end(),i));
                visited[i-1] = false;
            }
        }
    }
}
int main()
{
    int count = 0; bool first = true;
    while(scanf("%d", &n) == 1)
    {
        if(!first)
        cout << endl;
        first = false;
        table.clear(); count++;
        vector<int> comb; comb.push_back(1);
        bool visited[n]; memset(visited,false,n);
        backtrack(comb,visited,0);
        cout << "Case " << count << ":" << endl;
        for(int i = 0 ; i < table.size() ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(j!=n-1)
                cout << table[i][j] << " ";
                else
                cout << table[i][j];
            }
            cout << endl;
        }
    }
}