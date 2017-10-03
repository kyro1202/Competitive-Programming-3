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
vvi adj;
vi low,num;
stack<int> scc;
bool visited[30];
map<string,int> ind;
map<int,string> ret;
int n,m;
int counter;
void tarjanscc(int u)
{
    num[u] = low[u] = counter++;
    scc.push(u);
    visited[u] = true;
    FOR0(i,SZ(adj[u]))
    {
        if(num[adj[u][i]] == INF)
        {
            tarjanscc(adj[u][i]);
        }
        if(visited[adj[u][i]] == true)
        {
            low[u] = min(low[u],low[adj[u][i]]);
        }
    }
    if(low[u] == num[u])
    {
        int i = 1;
        while(i)
        {
            if(i == 1)
                cout << ret[scc.top()], visited[scc.top()] = false;
            else
                cout << ", " <<ret[scc.top()], visited[scc.top()] = false;
            if(scc.top() == u)
            {
                scc.pop();
                break;
            }
            scc.pop();
            i++;
        }
        cout << endl;
    }
}
int main()
{
    SYNC
    string temp1,temp2;
    int cases = 0;
    while(cin >> n >> m)
    {
        cases++;
        memset(visited,false,n);
        adj.resize(n,vi()); adj.clear(); num.assign(n,INF); low.assign(n,0); ind.clear(); ret.clear();
        counter = 0;
        while(!scc.empty())
            scc.pop();
        if(!(n+m))
            break;
        int flag = 0;
        FOR0(i,m)
        {
            cin >> temp1 >> temp2;
            if(ind.find(temp1) == ind.end())
                ind[temp1] = flag, ret[flag] = temp1, flag++;
            if(ind.find(temp2) == ind.end())
                ind[temp2] = flag, ret[flag] = temp2, flag++;
            adj[ind[temp1]].pb(ind[temp2]); 
        }
        cout << "Calling circles for data set " << cases << ":" << endl;
        if(m == 0)
        {    cout << endl; continue;    }
        FOR0(i,n)
        {
            if(num[i] == INF)
            {
                tarjanscc(i);
            }
        }
        cout << endl;
    }
}