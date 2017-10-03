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
double adjmat[22][22][22];
int par[22][22][22];
stack<int> s;
int main()
{
    while(cin >> n)
    {   
        memset(adjmat,0,sizeof(adjmat));
        FOR0(i,n)
        {
            FOR0(j,n)
            {
                par[i][j][0] = i;
                if(i == j)
                    continue;
                cin >> adjmat[i][j][0];
            }
            adjmat[i][i][0] = 1.0;
        }
        double curr;
        FOR(l,1,n)
            FOR0(i,n)
                FOR0(j,n)
                    FOR0(k,n)
                    {
                        curr = adjmat[j][i][l-1]*adjmat[i][k][0];
                        if(adjmat[j][k][l] < curr)
                        {
                            adjmat[j][k][l] = curr;
                            par[j][k][l] = i;
                        }
                    }
        bool found = false;
        int temp;
        FOR(l,1,n)
        {
            if(found)
                break;
            FOR0(i,n)
            {
                if(found)
                    break;
                if(adjmat[i][i][l] > 1.01)
                {
                    s.push(par[i][i][l]);
                    for(int j=l-1;j>-1;j--) s.push(par[i][s.top()][j]);
                    temp = s.top();
                    while(!s.empty()){
                        cout << s.top()+1 << ' ';
                        s.pop();
                    }
                    cout << temp+1;
                    found = true;
                    break;
                }
            }
        }
        if(!found)
            cout << "no arbitrage sequence exists";
        cout << endl;
    }
}