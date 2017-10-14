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
long long int memo[15];
long long int dp[15];
long long int fact(long long int a)
{
    if(a == 1)
        return 1;
    if(memo[a] != -1.0)
        return memo[a];
    return memo[a] = a*fact(a-1);
}
long long int da(long long int a)
{
    if(dp[a] != -1.0)
        return dp[a];
    return dp[a] = (a-1)*(da(a-1)+da(a-2));
}
int main()
{
    SYNC
    long long int num;
    FOR0(i,15)
    {
        memo[i] = -1.0;
        dp[i] = -1.0;
    }
    dp[1] = 0; dp[2] = 1;
    int test; cin >> test;
    while(test--)
    {
        cin >> num;
        long long int n,d;
        d = fact(num);
        n = da(num);
        cout << n << "/" << d << endl;
    }
}