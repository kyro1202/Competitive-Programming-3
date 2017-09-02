#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int temp; vector<long long int> arr;
    while(scanf("%lld", &temp) == 1)
    {
        arr.clear();
        arr.push_back(temp);
        while(true)
        {
            cin >> temp;
            if(temp == -999999)
                break;
            arr.push_back(temp);
        }
        long long int ans = -999999;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            long long int temp = 1;
            for(int j = i ; j < arr.size() ; j++)
            {
                temp = temp*arr[j];
            }
            ans = max(ans,temp);
        }
        cout << ans << endl;
    }   
}