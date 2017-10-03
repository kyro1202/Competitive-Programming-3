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
int n,m;
int adjmat[55][55];
int main()
{
    string s,t; int counter = 0;
    while(cin >> n >> m)
    {
        if(!(n+m))
            break;
        counter++;
        FOR0(i,n)
        {    
            FOR0(j,n)
                adjmat[i][j] = INF;
            adjmat[i][i] = 0;
        }
        map<string,int> ind;
        
        int num = 0;
        FOR0(i,m)
        {
            cin >> s >> t;
            if(!ind.count(s))
            {    ind[s] = num;    num++;      }
            if(!ind.count(t))
            {    ind[t] = num;    num++;      }
            adjmat[ind[s]][ind[t]] = 1;
            adjmat[ind[t]][ind[s]] = 1;
        }
        FOR0(i,n)
            FOR0(j,n)
                FOR0(k,n)
                    adjmat[j][k] = min(adjmat[j][k],adjmat[j][i]+adjmat[i][k]);
        int ans = -1;
        bool dis = false;    
        FOR0(i,n)
        {
            if(dis)
                break;
            FOR0(j,n)
            {
                if(adjmat[i][j] != INF)
                    ans = max(ans,adjmat[i][j]);
                else
                {
                    dis = true;
                    break;
                }
            }
        }
        cout << "Network " << counter << ": ";
        if(dis)
            cout << "DISCONNECTED" << endl;
        else
            cout << ans << endl;
        cout << endl;
    }
}