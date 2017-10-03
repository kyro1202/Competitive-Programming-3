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
int r,c,m,n;
bool visited[105][105];
char field[105][105];
int count1[105][105];
int even,odd;
int main()
{
    //simple bfs
    int test,w,a,b;
    cin >> test;
    FOR(I,1,test+1)
    {
        even = 0; odd = 0;
        memset(visited,false,sizeof(visited));
        memset(field,'.',sizeof(field));
        memset(count1,0,sizeof(count1));
        cin >> r >> c >> m >> n;
        cin >> w;
        int dx[] = {-m, -m, m, m, -n, n, -n, n};
        int dy[] = {n, -n, n, -n, m, m, -m, -m};
        FOR0(i,w)
        {
            cin >> a >> b;
            field[a][b] = 'w';
        }
        priority_queue<pair<int,int> > q;
        q.push(mp(0,0));
        visited[0][0] = true;
        while(!q.empty())
        {
            pair<int,int> temp = q.top(); q.pop();
            set<pair<int,int> > tocheck;
            FOR0(i,8)
            {
                int x = temp.ff + dx[i];
                int y = temp.ss + dy[i];
                tocheck.insert(mp(x,y));
            }
            set<pair<int,int> >::iterator it = tocheck.begin();
            for( ; it != tocheck.end() ; it++)
            {
                temp = *it;
                int x = temp.ff;
                int y = temp.ss;
                if(x < 0 || x >= r || y < 0 || y >= c || field[x][y] == 'w')
                    continue;
                count1[x][y]++;
                if(!visited[x][y])
                {
                    visited[x][y] = true;
                    q.push(mp(x,y));
                } 
            }
        }
        FOR0(i,r)
        {
            FOR0(j,c)
            {
                if(count1[i][j] != 0 || (i==0 && j==0))
                {
                    if(count1[i][j]%2)
                        odd++;
                    else
                        even++;
                }
            }
        }
        cout << "Case " << I << ": " << even << " " << odd << endl;
    }
}