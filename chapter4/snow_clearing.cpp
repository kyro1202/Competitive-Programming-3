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
    int test;
    stringstream ss;
    string s;
    getline(cin,s);
    ss << s;
    ss >> test;
    cin.ignore();
    FOR0(i,test)
    {
        double ans = 0;
        getline(cin,s);
        while(getline(cin,s) && s.length() != 0)
        {
            ss.clear(); ss << s;
            int temp,a[4],i = 0;
            while(ss >> temp)
            {
                a[i] = temp;
                i++;
            }
            ans += hypot(abs(a[0]-a[2]),abs(a[3]-a[1]))*2.0;
        }
        ans = ans*3.0;
        ans /= 1000.0;
        if(ans - (int)ans >= 0.5) ans++;
        int hour = (int)ans / 60;
        int min = (int)ans%60;
        cout << hour << ":";
        if(min < 10)
            cout << "0";
        cout << min << endl;
        if(i != test-1)
            cout << endl;
    } 
}