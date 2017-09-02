#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int m,f; int counter = 0;
    while(true)
    {
        counter++;
        cin >> m >> f;
        if(!(m+f))
            break;
        int male[m],female[f];
        cout << "Case " << counter << ": ";
        for(int i = 0 ; i < m ; i++)
            cin >> male[i];
        for(int i = 0 ; i < f ; i++)
            cin >> female[i];
        if(m == f)
        {
            cout << "0" << endl; continue;
        }
        sort(male,male+m); sort(female,female+f);
        int a = m-1,b = f - 1,mark;
        while(a > -1)
        {
            while(abs(male[a] - female[b]) > abs(male[a] - female[b-1]) && b > -1) b--;
            if(b == -1) break;
            if(a == m-1)
            mark = b;
            a--; b--;
        }
        
            int left = f - mark - 1;
            a -= left;
            if(a >= 0)
            cout << a+1 << " " << male[0] << endl;
            else
            cout << "0" << endl;
    }
}