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
vi adj;
int n;
vi mark;
bool visited[50005] = {};
int dfs(int ind)
{
    visited[ind] = true;
    int tot = 0;
    if(adj[ind] != -1 && visited[adj[ind]] == false)
        tot += 1 + dfs(adj[ind]);
    visited[ind] = false;
    return mark[ind] = tot;
}
int main()
{
    SYNC
    int test; cin >> test;
    for(int ti = 1 ; ti <= test ; ti++)
    {
        int u,v;
        adj.clear();
        cin >> n;
        adj.assign(n,-1);
        mark.assign(n,-1);
        memset(visited,false,sizeof(visited));
        FOR0(i,n)
        {
            cin >> u >> v;
            u--; v--;
            adj[u] = v;
        }
        int max = -1,ans;
        FOR0(i,n)
        {
            if(mark[i] == -1)
            dfs(i);
            if(mark[i] > max)
            {
                max = mark[i];
                ans = i+1;
            }
        }
        cout << "Case " << ti << ": " << ans << endl;
    }
}