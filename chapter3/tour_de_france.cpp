#include <bits/stdc++.h>
using namespace std;
int main()
{
    int f,r;
    while(cin >> f , f)
    {
        cin >> r;
        double front[f],rear[r];
        for(int i = 0 ; i < f ; i++)
            cin >> front[i];
        for(int i = 0 ; i < r ; i++)
            cin >> rear[i];
        vector<double> dr;
        for(int i = 0 ; i < f ; i++)
        {
            for(int j = 0 ; j < r ; j++)
            {
                dr.push_back(rear[j]/front[i]);
            }
        }
        sort(dr.begin(),dr.end());
        double spread = 0;
        for(int i = 0 ; i < dr.size() - 1 ; i++)
        {
            if( (dr[i+1]/dr[i]) > spread )
            spread = dr[i+1]/dr[i];
        }
        printf("%.2f\n", spread);
    }
}