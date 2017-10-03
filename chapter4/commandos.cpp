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
int adjmat[105][105];
int main()
{
    int test,n,m,a,b,counter = 0; cin >> test;
    while(test--)
    {
        counter++;
        cin >> n;
        cin >> m;
        FOR0(i,n)
        {
            FOR0(j,n)
            {
                adjmat[i][j] = INF;
            }
            adjmat[i][i] = 0;
        }
        FOR0(i,m)
        {
            cin >> a >> b;
            adjmat[a][b] = adjmat[b][a] = 1;
        }
        cin >> a >> b;
        FOR0(i,n)
            FOR0(j,n)
                FOR0(k,n)
                {
                    adjmat[j][k] = min(adjmat[j][k],adjmat[j][i]+adjmat[i][k]);
                }
        int ans = -1;
        FOR0(i,n)
        {
            ans = max(ans,adjmat[a][i]+adjmat[i][b]);
        }
        cout << "Case " << counter << ": " << ans << endl;
    }
}