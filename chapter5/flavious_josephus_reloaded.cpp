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
ull n,a,b;
ull f(ull t)
{
    return (((a*t)%n*t)%n+b)%n; 
}
int main()
{
    SYNC
    while(cin >> n)
    {
        if(!n) 
            break;
        cin >> a >> b;
        ull hv = 0,tv = 0; ull m = 0;
        do
        {
            tv = f(tv);
            hv = f(hv);
            hv = f(hv);
            m++;
        }while(hv != tv);
        ull u = 0; hv = 0;
        while(hv != tv)
        {
            tv = f(tv);
            hv = f(hv);
            u++;
        }
        ull l = 1; hv = f(hv);
        while(hv != tv)
        {
            l++;
            hv = f(hv);
        }
        cout << n-l << endl;
    }
}