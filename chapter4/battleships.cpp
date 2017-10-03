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
char sea[105][105];
bool visited[105][105];
int dx[] = { 0 , 0 , 1 , -1 };
int dy[] = { 1 , -1 , 0 , 0 };
void dfs(int x,int y)
{
    if(x < 0 ||x >= n || y < 0 || y >= n || sea[x][y] == '.')
        return;
    sea[x][y] = '.';
    FOR0(i,4)
    {
        dfs(x+dx[i],y+dy[i]);
    }
    return;
}
int main()
{
    int test;
    cin >> test;
    string temp;
    FOR(ti,1,test+1)
    {
        cin >> n;
        memset(visited,false,sizeof(visited));
        FOR0(i,n)
        {
            cin >> temp;
            FOR0(j,n)
            {
                sea[i][j] = temp[j];
            }
        }
        int ans = 0;
        FOR0(i,n)
        {
            FOR0(j,n)
            {
                if(sea[i][j] == 'x')
                {
                    ans++; dfs(i,j);
                }
            }
        }
        cout << "Case " << ti << ": " << ans << endl;
    }
}