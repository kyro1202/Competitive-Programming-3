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
int main()
{
    SYNC
    int test; int h,check; double p;
    cin >> test;
    FOR(ti,1,test+1)
    { 
        cin >> n;
        double tot = 0,temp = 0;
        p = 0;
        check = 0;
        FOR0(i,n)
        {
            cin >> h >> temp;
            if(h > 0)
            {
                tot += h*temp; p += temp;
            }
            else
                tot -= h*temp;
        }
        cout << "Case " << ti << ": ";
        if(p <= 0)
            cout << "God! Save me" << endl;
        else
            cout << setprecision(2) << fixed << tot/p << endl;
    }
}