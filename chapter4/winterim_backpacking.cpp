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
int n,k;
int memo[605][305];
vi a,dist;
int dp(int left,int used)
{
    if(left == 0)
        return dist[n+1] - dist[used];
    if(memo[used][left] != -1)
        return memo[used][left];
    int temp,ans = 2*INF;
    FOR(i,used+1,n+1)
    {
        temp = max(dist[i]-dist[used],dp(left-1,i));
        ans = min(temp,ans);
    }
    return memo[used][left] = ans;
}
int main()
{
    while(cin >> n >> k)
    {
        dist.clear(); dist.assign(n+2,INF);
        a.clear(); a.assign(n+2,0);
        memset(memo,-1,sizeof(memo));
        int temp;
        FOR(i,1,n+2)
        {
            cin >> temp;
            a[i] = temp;
        }
        dist[0] = 0;
        FOR0(i,n+2)
        {
            dist[i] = dist[i-1] + a[i];
        }
        cout << dp(k,0) << endl;
    }
}