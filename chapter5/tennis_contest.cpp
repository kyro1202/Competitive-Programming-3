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
int main()
{
    SYNC
    int n;
    double p; int test; cin >> test;
    double prob[30][30];
    while(test--)
    {
        cin >> n >> p;
        FOR0(i,n+1)
            FOR0(j,n+1)
                prob[i][j] = 0;
        prob[0][0] = 1.0;
        FOR0(i,n)
            FOR0(j,n)
            {
                prob[i+1][j] += prob[i][j]*p;
                prob[i][j+1] += prob[i][j]*(1.0-p); 
            }
        double ans = 0;
        FOR0(i,n)
            ans += prob[n][i];
        cout << setprecision(2) << fixed << ans << endl;
    }
}