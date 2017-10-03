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
vector<string> V;
bool visited[105];
int main()
{
    string temp,temp2; int ti = 0;
    while(cin >> n)
    {
        ti++;
        memset(visited,false,sizeof(visited));
        map<int,int> indegree;
        map<string,int> index;
        V.clear(); queue<int> q;
        FOR0(i,n)
        {
            cin >> temp;
            index[temp] = i;
            indegree[i] = 0;
            V.pb(temp);
        }
        cin >> m;
        vvi adj;
        adj.resize(n,vi());
        adj.clear();
        FOR0(i,m)
        {
            cin >> temp >> temp2;
            adj[index[temp]].pb(index[temp2]);
            indegree[index[temp2]] += 1;
        }
        FOR0(i,n)
        {
            sort(adj[i].begin(),adj[i].end());
        }
        FOR0(i,n)
        {
            if(indegree[i] == 0)
            {    q.push(i); break;  }    
        }
        vector<string> ans;
        while(!q.empty())
        {
            string t = V[q.front()]; 
            visited[q.front()] = true;
            q.pop();
            ans.pb(t);
            FOR0(i,SZ(adj[index[t]]))
            {
                indegree[adj[index[t]][i]]--;
            }
            adj[index[t]].clear();
            if(q.empty())
            {
                FOR0(i,n)
                {
                    if(indegree[i] == 0 && !visited[i])
                    {
                        q.push(i);
                        break;
                    }
                }
            }
        }
        cout << "Case #" << ti << ": Dilbert should drink beverages in this order:";
        FOR0(i,SZ(ans))
        {
            cout << " " << ans[i];
        }
        cout << "." << endl << endl;   
    }
}