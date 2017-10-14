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

ll gcd(int a,int b)
{
    return b == 0 ? a : gcd(b,a%b) ;
}

int main()
{
    SYNC
    int test; cin >> test;
    string s; stringstream ss;
    int temp; vi a; int n;
    getline(cin,s);
    while(test--)
    {
        getline(cin,s);
        ss.clear();
        ss << s;
        n = 0;
        a.clear();
        while(ss >> temp)
            a.pb(temp);
        n = a.size();
        ll ans = 0;
        FOR0(i,n)
        {
            FOR(j,i+1,n)
            {
                ans = max(ans,gcd(a[i],a[j]));
            }
        }
        cout << ans << endl;
    }
}