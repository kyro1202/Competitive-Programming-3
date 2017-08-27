#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s,b;
    while(cin >> s >> b)
    {
        if(s + b == 0)
            break;
        int left[100005],right[100005],l,r;
        for(int i = 1 ; i <= s ; i++)
        {
            left[i] = i-1;
            right[i] = i+1;
        }    
        left[1] = -1;
        right[s] = -1;
        while(b--)
        {
            cin >> l >> r;

            left[right[r]] = left[l];
            if(left[l] == -1)
            {
                cout << "* ";
            }
            else
            {
                cout << left[l] << " ";
            }

            right[left[l]] = right[r];
            if(right[r] == -1)
            {
                cout << "*";
            }
            else
            {
                cout << right[r];
            }
            cout << endl;
        }
        cout << "-" << endl;
    }
}