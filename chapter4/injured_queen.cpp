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
int row[20];
long long int memo[20][20];
long long int put(int c,int r)
{
    if(c == n)
        return 1;
    if(memo[r][c] != -1)
        return memo[r][c];
    long long int ret = 0;
    if(row[c+1] == 0)
    {
        FOR(i,1,n+1)
        {
            if(i != r && i != r+1 && i != r-1)
                ret += put(c+1,i);
        }
    }
    else
    {
        if(row[c+1] != r+1 && row[c+1] != r && row[c+1] != r-1)
            ret += put(c+1,row[c+1]);    
    }
    return memo[r][c] = ret;
}
int main()
{
    string stat;
    while(cin >> stat)
    {
        memset(memo,-1,sizeof(memo));
        n = stat.length();
        FOR0(i,n)
        {
            if(stat[i] == '?')
                row[i+1] = 0;
            else if(stat[i] >= '0' && stat[i] <= '9')
                row[i+1] = stat[i] - '0';
            else
                row[i+1] = stat[i] - 'A' + 10;
        }
        long long int ans = 0;
        if(row[1] == 0)
        {
            FOR(i,1,n+1)
            {
                ans += put(1,i);
            }
        }
        else
            ans += put(1,row[1]);
        cout << ans << endl;
    }
}