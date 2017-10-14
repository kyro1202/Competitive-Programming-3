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
    int z,m,l,i,counter = 0;
    while(cin >> z >> i >> m >> l)
    {
        if(!(z+i+m+l))
            break;
        counter++;
        int hv,tv,h,t;
        hv = tv = l;
        int n = 0;
        do
        {
            tv = (tv*z+i)%m;
            hv = (hv*z+i)%m;
            hv = (hv*z+i)%m;
            n++;
        }while(hv != tv);
        int u = 0;
        hv = l;
        while(hv != tv)
        {
            hv = (hv*z+i)%m;
            tv = (tv*z+i)%m;
            u++;
        }
        int lamba = 1;
        hv = (hv*z+i)%m;
        while(tv != hv)
        {
            hv = (hv*z+i)%m;
            lamba++;
        }
        cout << "Case " << counter << ": ";
        cout << u+lamba << endl;
    }
}