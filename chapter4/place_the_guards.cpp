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
int main()
{
    int test; cin >> test;
    while(test--)
    {
        cin >> n >> m;
        int a,b;
        vi color(n,INF);
        vvi adj(n,vi());
        adj.clear();
        FOR0(i,m)
        {
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        int ans = 0;
        bool bipar;
        FOR0(i,n)
        {
            bipar = true;
            if(color[i] != INF)
                continue;
            queue<int> q;
            q.push(i);
            color[i] = 0;
            int count[2] = { 0 , 0 };
            count[0]++;
            while(!q.empty() && bipar)
            {
                int p = q.front(); q.pop();
                FOR0(j,SZ(adj[p]))
                {
                    if(color[adj[p][j]] == INF)
                    {
                        color[adj[p][j]] = 1 - color[p];
                        count[color[adj[p][j]]]++;
                        q.push(adj[p][j]);
                    }
                    else if(color[adj[p][j]] == color[p])
                    {
                        bipar = false; break;
                    }
                }
            }
            if(!bipar)
            {
                ans = -1;
                break;
            }
            else
            {
                ans += (count[0] > 0 && count[1] > 0 ) ? min(count[0],count[1]) : max(count[0],count[1]);
            }
        }
        cout << ans << endl;
    }
}