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
string s;
int sum;
bool check()
{
    FOR0(i,SZ(s))
    {
        if( (sum-(s[i]-'0') )%3 == 0)
            return true;
    }
    return false;
}
int main()
{
    SYNC
    int test; cin >> test;
    FOR(ti,1,test+1)
    {
        cin >> s;
        sum = 0;
        int c = 0;
        FOR0(i,SZ(s))
        {
            sum += s[i] - '0';
            if((s[i] - '0')%3 == 0)
                c++;
        }
        int len = s.length();
        cout << "Case " << ti << ": ";
        if(len == 1)
        {
            cout << "S" << endl;
            continue;
        }  
        if(sum%3 == 0)
        {
            if(c%2)
                cout << "S";
            else
                cout << "T";
        }
        else if(check())
        {
            if(c%2)
                cout << "T";
            else
                cout << "S";
        }
        else
            cout << "T";
        cout << endl;        
    }
}