#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define SZ(a) ((int)((a).size()))
#define pb push_back
#define mp make_pair
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
int n,m;
vvi adj;
bool visited[105];
stack<int> top;
void dfs(int ind)
{
    visited[ind] = true;
    FOR0(i,SZ(adj[ind]))
    {
        if(visited[adj[ind][i]] == false)
        {
            visited[adj[ind][i]] = true;
            dfs(adj[ind][i]);
        }
    }
    top.push(ind);
}
int main()
{
    while(cin >> n >> m)
    {
        if(!(n+m))
            break;
        adj.resize(n,vi());
        adj.clear();
        while(!top.empty()) top.pop(); 
        memset(visited,false,sizeof(visited));
        int a,b;
        FOR0(i,m)
        {
            cin >> a >> b;
            a--; b--;
            adj[a].pb(b);
        }
        FOR0(i,n)
        {
            if(visited[i] == false)
                dfs(i);
        }
        FOR0(i,SZ(top))
        {
            cout << top.top()+1 << " ";
            top.pop();
        }
        cout << endl;
    }
}