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
int n;
vvi adj;
int main()
{
    cin >> n;
    int temp,f;
    adj.resize(n,vi()); adj.clear();
    FOR0(i,n)
    {
        cin >> temp;
        FOR0(j,temp)
        {
            cin >> f;
            adj[i].pb(f);
        }
    }
    int q,s;
    cin >> q;
    FOR0(i,q)
    {
        int ansa = -1,ansb;
        queue<int> bfs;
        int level[2505],count[2505];
        FOR0(j,2505)
        {    level[j] = INF;
             count[j] = 0;  }
        cin >> s;
        bfs.push(s);
        level[s] = 1;
        count[1] = 1;
        while(!bfs.empty())
        {
            int u = bfs.front(); bfs.pop();
            FOR0(j,SZ(adj[u]))
            {
                if(level[adj[u][j]] == INF)
                {
                    level[adj[u][j]] = level[u] + 1;
                    bfs.push(adj[u][j]);
                    count[level[adj[u][j]]]++;
                }
            }
        }
        FOR0(j,2505)
        {
            if(count[j] > ansa)
            {
                ansa = count[j];
                ansb = j-1;
            }
        }
        if(count[2] == 0)
            cout << 0 << endl;
        else if(ansa == 1)
            cout << ansa << " " << 1 << endl;
        else
            cout << ansa << " " << ansb << endl;
    }
}