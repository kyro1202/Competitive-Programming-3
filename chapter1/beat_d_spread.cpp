#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test; cin >> test;
    while(test--)
    {
        int sum,diff; cin >> sum >> diff;
        if(sum >= diff && (sum + diff)%2 == 0)
        {
            cout << (sum + diff) / 2 << " " << (sum - diff) / 2 << endl;
        }
        else
        {
            cout << "impossible" << endl;
        }
    }
}