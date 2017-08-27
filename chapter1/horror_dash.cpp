#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test; cin >> test;
    for(int i = 1 ; i <= test ; i++)
    {
        int num,temp,max; cin >> num >> max;
        for(int j = 1 ; j < num ; j++)
        {
            cin >> temp;
            if(temp > max)
            max = temp;
        }
        cout << "Case " << i << ": " << max << endl;
    }
}