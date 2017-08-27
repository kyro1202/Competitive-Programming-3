#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int array[10001];
    int count = 0;
    long long int temp;
    while(cin >> temp)
    {
        array[count] = temp;
        count++;
        sort(array,array + count);
        if(count%2)
        {
            cout << array[count/2] << endl;
        }
        else
        {
            cout << (array[count/2 - 1] + array[count/2]) / 2 << endl;
        }
    }
}