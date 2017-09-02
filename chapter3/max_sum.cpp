#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(true)
    {
        cin >> n;
        if(!n)
            break;
        int temp; vector<int> ar;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> temp;
            if(temp > 0)
            ar.push_back(temp);
        }
        if(ar.size() == 0)
            cout << "0\n";
        else
        {
            for(int i = 0 ; i < ar.size() ; i++)
            {
                if(i == 0)
                cout << ar[i];
                else
                cout << " " << ar[i];
            }
            cout << endl;
        }
    }
}