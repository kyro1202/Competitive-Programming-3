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
    double b,s; int counter = 0;
    while(cin >> b >> s)
    {
        double f,l;
        if(!(b+s))
            break;
        counter++;
        cout << "Case " << counter << ": ";
        if(b == 1)
        {
            cout << ":-\\" << endl;
            continue;
        }
        f = min(s/b,1.0);
        s = min((s-1)/(b-1),1.0);
        if(f > s)
            cout << ":-(" << endl;
        else if(f < s)
            cout << ":-)" << endl;
        else 
            cout << ":-|" << endl;
    }
}