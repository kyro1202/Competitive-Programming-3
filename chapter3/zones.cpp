#include <bits/stdc++.h>
using namespace std;
vector<pair<vector<int>,int> > common;
vector<vector<int> > comb; int n,k;

void make_combinations(vector<int> &combv,int s)
{
    if(combv.size() == k)
    {
        comb.push_back(combv);
        return;
    }
    for(int i = s ; i < n ; i++)
    {
        combv.push_back(i); make_combinations(combv,i+1); combv.erase(find(combv.begin(),combv.end(),i));
    }
}
int main()
{
    int m,u,max_coverage,max_index,count = 0;
    while(true)
    {
        count++;
        cin >> n >> k;
        if(!n)
            break;
        max_coverage = 0;
        common.clear(); comb.clear(); max_index = 0;
        int pop[n];
        for(int i = 0 ; i < n ; i++)
            cin >> pop[i];
        cin >> m; vector<int> combv;
        make_combinations(combv,0);
        for(int i = 0 ; i < m ; i++)
        {
            cin >> u;
            vector<int> temp; int temppop;
            while(u--)
            {
                cin >> temppop; temp.push_back(temppop - 1);
            }
            cin >> temppop;
            common.push_back(make_pair(temp,temppop));
        }
        for(int i = 0 ; i < comb.size() ; i++)
        {
            int coverage = 0;
            for(int j = 0 ; j < comb[i].size() ; j++)
            {
                coverage += pop[comb[i][j]];
            }
            for(int j = 0 ; j < common.size() ; j++)
            {
                int tower_count = 0;
                for(int k = 0 ; k < common[j].first.size() ; k++)
                {
                    if(find(comb[i].begin(),comb[i].end(),common[j].first[k]) != comb[i].end())
                        tower_count++;
                }
                if(tower_count > 1)
                    coverage -= (tower_count-1)*common[j].second;
            }
            if(coverage > max_coverage)
            {
                max_coverage = coverage;
                max_index = i;
            }
        }
        cout << "Case Number  " << count << endl;
        cout << "Number of Customers: " << max_coverage << endl;
        cout << "Locations recommended: " << comb[max_index][0] + 1;
        for(int i = 1 ; i < k ; i++)
        {
            cout << " " << comb[max_index][i] + 1;
        }
        cout << endl << endl;
    }
}