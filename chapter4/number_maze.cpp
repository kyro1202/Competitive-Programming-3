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
int m,n;
int cost[1001][1001];
int dist[1001][1001];
int x[4] = {0,0,1,-1};
int y[4] = {1,-1,0,0};
bool check(int a,int b)
{
    if(a < 0 || a >= m || b < 0 || b >= n)
        return true;
    return false;
}
int main()
{
    int test; cin >> test;
    while(test--)
    {
        cin >> m >> n;
        FOR0(i,m)
            FOR0(j,n)
            {    cin >> cost[i][j]; dist[i][j] = INF;   }
        priority_queue< pair<int,ii> , vector<pair<int,ii> > , greater<pair<int,ii> > > dij;
        dij.push(mp(0,mp(0,0)));
        dist[0][0] = cost[0][0];
        while(!dij.empty())
        {
            pair<int,ii> u = dij.top(); dij.pop();
            if(u.ff > dist[u.ss.ff][u.ss.ss])
                continue;
            FOR0(i,4)
            {
                if(check(u.ss.ff,u.ss.ss))
                    continue;
                if(dist[u.ss.ff+x[i]][u.ss.ss+y[i]] > (dist[u.ss.ff][u.ss.ss] + cost[u.ss.ff+x[i]][u.ss.ss+y[i]]))
                {
                    dist[u.ss.ff+x[i]][u.ss.ss+y[i]] = dist[u.ss.ff][u.ss.ss] + cost[u.ss.ff+x[i]][u.ss.ss+y[i]];
                    dij.push(mp(dist[u.ss.ff+x[i]][u.ss.ss+y[i]],mp(u.ss.ff+x[i],u.ss.ss+y[i])));
                }
            }
        }
        cout << dist[m-1][n-1] << endl;
    }
}