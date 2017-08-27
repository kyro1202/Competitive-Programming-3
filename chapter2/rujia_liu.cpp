#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    while( true )
    {
        if( scanf("%d", &n) != 1 )
        break;
        scanf("%d", &m);
        vector< vector<pair<int,int> > > list;
        vector< vector<pair<int,int> > >::iterator it;
        pair<int,int> tp; int t1,t2; 
        for(int j = 0 ; j < n ; j++)
        {
            cin >> t1;
            tp = make_pair(t1,j);
            int size = list.size(),i;
            for(i = 0 ; i < size ; i++)
            {
                if( list[i][0].first == t1 )
                break;
            }
            if(i == size)
            {
                vector<pair<int,int> > tv;
                tv.push_back(tp);
                list.push_back(tv);
            }
            else
            {
                list[i].push_back(tp);
            }
        }
        while(m--)
        {
            cin >> t1 >> t2;
            bool found = false;
            int i = 0;
            int size = list.size();
            for(i = 0 ; i < size ; i++)
            {
                if(list[i][0].first == t2)
                {
                    int j = 0;
                    int size2 = list[i].size();
                    if(t1 > size2)
                    break;
                    else
                    {
                        found = true;
                        cout << list[i][--t1].second + 1 << endl;
                    }
                }
            }
            if(!found)
            cout << 0 << endl;
        }
    }
}