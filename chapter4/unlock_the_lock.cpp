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
int l,c,r;
vi adj;
int level[10003];
int main()
{
    int temp; int counter = 0;
    while(cin >> l >> c >> r)
    {
        counter++;
        if(!(l+r+c))
            break;
        adj.clear();
        FOR0(i,10003)
            level[i] = -1;
        FOR0(i,r)
        {
            cin >> temp;
            adj.pb(temp);
        }
        queue<int> bfs;
        level[l] = 0;
        bfs.push(l);
        while(!bfs.empty())
        {
            int t = bfs.front(); bfs.pop();
            FOR0(i,r)
            {
                int n = t + adj[i];
                if(n > 9999)
                {
                    n -= 10000;
                }
                if(level[n] == -1)
                {
                    level[n] = level[t] + 1;
                    bfs.push(n);
                }
            }
        }
        cout << "Case " << counter << ": ";
        if(level[c] == -1)
            cout << "Permanently Locked" << endl;
        else
            cout << level[c] << endl;
    }
}