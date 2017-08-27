#include <bits/stdc++.h>
using namespace std;
vector<int> neighbour[26];
bool visited[26];
int counter;
void dfs(int i)
{
    if(!visited[i])
    {
        visited[i] = true;
        counter++;
        for(int j = 0 ; j < neighbour[i].size() ; j++)
        {
            dfs(neighbour[i][j]);
        }
    }
}
int main()
{
    int test; cin >> test;
    string s;
    while(test--)
    {
        memset(visited,0,26);
        for(int i = 0 ; i < 26 ; i++)
            neighbour[i].clear();
        while(true)
        {
            cin >> s;
            if(s[0] == '*')
                break;
            neighbour[s[1]-'A'].push_back(s[3]-'A');
            neighbour[s[3]-'A'].push_back(s[1]-'A');
        }
        int acorns = 0,trees = 0;
        cin >> s;
        for(int i = 0 ; i < s.length() ; i+=2)
        {
            if(!visited[s[i]-'A'])
            {
                counter = 0;
                dfs(s[i]-'A');
                if(counter == 1)
                acorns++;
                else
                trees++;
            }
        }
        printf("There are %d tree(s) and %d acorn(s).\n",trees,acorns);
    }
}