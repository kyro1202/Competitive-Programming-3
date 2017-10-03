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
int r,c;
int sx,sy,dx,dy;
bool safe[1005][1005];
int level[1005][1005];
int x[4] = { 0 , 0 , 1 , -1 };
int y[4] = { 1 , -1 , 0 , 0 };
int main()
{
    int br,bc,btr,temp;
    while(cin >> r >> c)
    {
        if(!(r+c))
            break;
        cin >> btr;
        FOR0(i,1005)
            FOR0(j,1005)
                level[i][j] = INF;
        memset(safe,true,sizeof(safe));
        FOR0(i,btr)
        {
            cin >> br >> bc;
                FOR0(j,bc)
                {
                    cin >> temp;
                    safe[br][temp] = false;
                }
        }
        cin >> sx >> sy;
        cin >> dx >> dy;
        queue<ii> bfs;
        bfs.push(mp(sx,sy));
        level[sx][sy] = 0;
        while(!bfs.empty())
        {
            ii n = bfs.front(); bfs.pop();
            FOR0(i,4)
            {
                if(n.ff+x[i] < 0 || n.ff+x[i] >= r || n.ss+y[i] < 0 || n.ss+y[i] >= c)
                    continue;
                if(level[n.ff+x[i]][n.ss+y[i]] == INF && safe[n.ff+x[i]][n.ss+y[i]])
                {
                    level[n.ff+x[i]][n.ss+y[i]] = level[n.ff][n.ss] + 1;
                    bfs.push(mp(n.ff+x[i],n.ss+y[i]));
                }
            }
        }
        cout << level[dx][dy] << endl;
    }
}