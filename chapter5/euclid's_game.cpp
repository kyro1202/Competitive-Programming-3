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

int backtrack(int id,ll l,ll s)
{
    if(s == 0)
        return 1-id;
    int ret = 1-id;
    ll q = l/s;
    int win = backtrack(1-id,s,l%s);
    if(win == id)
        ret = id;
    if(q!=1 && backtrack(1-id,s+l%s,s) == id)
        ret = id;
    return ret;
}
int main()
{
    SYNC
    ll a,b;
    while(cin >> a >> b)
    {
        if(!(a+b))
            break;
        if(a > b) swap(a,b);
        int res = backtrack(0,b,a);
        if(res == 1)
            cout << "Ollie wins" << endl;
        else
            cout << "Stan wins" << endl;
    }
}