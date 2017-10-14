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
ull mmm[21];
void pre()
{
    mmm[0] = mmm[1] = 1;
    FOR(i,2,21)
        mmm[i] = mmm[i-1]*i;
}
ull fact(int a)
{
    return mmm[a];
}
int main()
{
    SYNC
    int test; cin >> test;
    string s;
    pre();
    int count[26]; int counter = 1;
    while(test--)
    {
        cin >> s;
        FOR0(i,26)
            count[i] = 0;
        FOR0(i,s.length())
        {
            count[s[i]-'A']++;
        }
        ull d = 1;
        FOR0(i,26)
        {
            if(count[i] > 1)
                d = d*fact(count[i]);
        }
        ull ans = (fact(s.length()))/d;
        cout << "Data set " << counter << ": " << ans << endl;
        counter++;
    }
}