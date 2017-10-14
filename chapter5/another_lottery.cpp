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
long long int gcd(long long int a,long long int b)
{
    if(b == 0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    SYNC
    int n,m;
    long long int arr[10005];
    long long int sum,temp;
    while(cin >> n >> m)
    {
        if(!(m+n))
            break;
        sum = 0;
        FOR0(i,n)
            FOR0(j,m)
            {
                if(j != m-1)
                    cin >> temp;
                else
                {
                    cin >> arr[i];
                    sum += arr[i];
                }
            }
        FOR0(i,n)
        {
            long long int g;
            if(arr[i] == 0)
                cout << "0 / 1" << endl;
            else
            {
                g = gcd(sum,arr[i]);
                cout << arr[i]/g << " / " << sum/g << endl;
            }
        }
    }
}