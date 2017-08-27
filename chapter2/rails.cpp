#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(true)
    {
        cin >> n;
        int temp;
        bool block = false;
        if(!n)
            break;
        vector<int> trainb;
        while(true)
        {
            trainb.clear();
            for(int i = 0 ; i < n ; i++)
            {
                cin >> temp;
                if(!temp)
                {
                    block = true;
                    break;
                }
                else
                {
                    trainb.push_back(temp);
                }
            }
            if(block)
            {
                cout << endl; break;
            }
            stack<int> station;
            int curr = 1;int mark = 0;
            while(curr <= n)
            {
                station.push(curr);
                
                
                while(!station.empty() && station.top() == trainb[mark])
                {
                    station.pop();
                    mark++;
                    if(mark >= n)
                        break;    
                }

                curr++;
            }
            if(station.empty())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;    
        }
    }
}