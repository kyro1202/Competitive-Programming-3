#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,cases = 0;
    while(cin >> n, n)
    {
        int arr[n]; cases++;
        for(int i = 0 ; i < n ; i++)
            cin >> arr[i];
        cin >> m; int q;
        vector<int> sum;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1 ; j < n ; j++)
            {
                int temp = arr[i] + arr[j];
                sum.push_back(temp);
            }
        }
        int size = sum.size();
        sort(sum.begin(),sum.end());
        int diff; int index;
        cout << "Case " << cases << ":" << endl;
        for(int i = 0 ; i < m ; i++)
        {
            cin >> q; index = 0;
            diff = abs(q - sum[0]);
            for(int j = 1 ; j < size ; j++)
            {
                if(abs(sum[j] - q) > diff)
                    break;
                index = j;
                diff = abs(sum[j] - q);
            }
            cout << "Closest sum to " << q << " is " << sum[index] << "." << endl;
        }
    }
}