#include <bits/stdc++.h>
using namespace std;
int len,max_ind = 0,gmax = 1; vector<int> arr;
int parent[1000000] = {};
int main()
{
    ios::sync_with_stdio(false);
    int temp;
    while(cin >> temp)
    {
        arr.push_back(temp);
    }
    vector<int> endind; vector<int> active; parent[0] = -1;
    active.push_back(0); endind.push_back(arr[0]);
    len = arr.size();
    for(int i = 1 ; i < len ; i++)
    {
        int lower = lower_bound(endind.begin(),endind.end(),arr[i]) - endind.begin();
        if(lower == endind.size())
        {
            parent[i] = active[active.size()-1];
            endind.push_back(arr[i]);
            active.push_back(i);
        }
        else
        {
            if(lower == 0)
            {
                parent[i] = -1;
            }
            else
            {
                parent[i] = active[lower-1];
            }
            endind[lower] = arr[i];
            active[lower] = i;
        }
    }
    cout << endind.size() << endl << "-" << endl;
    stack<int> ans;
    int index = active[active.size()-1];
    while(index != -1)
    {
        ans.push(index);
        index = parent[index];
    }
    while(!ans.empty())
    {
        cout << arr[ans.top()] << endl;
        ans.pop();
    }
}