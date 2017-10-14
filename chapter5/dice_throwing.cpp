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
int n,x;
unsigned long long int memo[25][150];
unsigned long long int get(int left,int score)
{
    if(left == 0)
    {
        if(score >= x)
            return 1;
        return 0;
    }
    if(memo[left][score] != -1)
        return memo[left][score];
    long long int ret = 0;
    FOR(i,1,7)
    {
        ret += get(left-1,score+i);
    }
    return memo[left][score] = ret;
}
unsigned long long int gcd(unsigned long long int a,unsigned long long int b)
{
    return (b == 0) ? a : gcd(b,a%b);
}
int main()
{
    SYNC
    while(cin >> n >> x)
    {
        if(!(n+x))
            break;
        memset(memo,-1,sizeof(memo));
        unsigned long long int ways = get(n,0);
        unsigned long long int ss = pow(6,n);
        if(ways == 0)
            cout << 0 << endl;
        else if(ways%ss == 0)
            cout << ways/ss << endl;
        else
        {
            cout << ways/gcd(ss,ways) << "/" << ss/gcd(ss,ways) << endl;
        }        
    }
}