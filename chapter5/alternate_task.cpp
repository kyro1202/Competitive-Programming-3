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
bool prime[10010];
vi p;
vector<ll> factors;
vvi ans;
void pre()
{
    memset(prime,true,sizeof(prime));
    prime[0] = prime[1] = false;
    for(ll i = 2 ; i < 10010 ; i++)
    {
        if(!prime[i])
            continue;
        for(ll j = i*i ; j < 10010 ; j += i)
            prime[j] = false;
        p.pb(i);
    }
}
int pf(int a)
{
    factors.clear();
    int index = 0; int d = p[0];
    ll ret = 1;
    while(d*d <= a)
    {
        ll count = 0;
        while(a%d == 0)
        {
            count++;
            a = a/d;
        }
        ret *= ((ll)pow((double)d,count+1.0)-1)/(d-1);
        if(index == p.size()-1)
            break;
        d = p[++index];
    }
    if(a != 1)  ret *= ((ll)pow((double)a,2.0)-1)/(a-1);
    return ret;
}
void pre2()
{
    FOR(i,1,10010)
    {
        int sum = pf(i);
        if(sum < 1001)
            ans[sum].pb(i);
    }
}
int main()
{
    SYNC
    p.clear();
    ans.resize(1001,vi());
    pre(); pre2();
    int n; int counter = 0;
    while(cin >> n)
    {
        if(!n)
            break;
        counter++;
        cout << "Case " << counter << ": ";
        if(ans[n].size())
            cout << ans[n][ans[n].size()-1] << endl;
        else
            cout << -1 << endl;
    }
}