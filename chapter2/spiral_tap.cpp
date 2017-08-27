#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int sz,p;
    while(true)
    {
        int column,line;
        cin >> sz >> p;
        if( sz + p == 0)
            break;
        int root = sqrt(p);
        float ori = sqrt(p);
        int midx = sz/2 + 1,midy = sz/2 + 1;
        if(root%2 && floor(ori) == ori )
        {
            line = midx + root/2;
            column = line;
        }
        else
        {
            if(root%2)
                root++;
            int fill[4*root]; int index = 0;
            int filled = (root-1)*(root-1);
            for(int i = 0 ; i < 4*root ; i++)
            {
                fill[i] = filled + i + 1;
                if(fill[i] == p)
                {
                    index = i;
                    break;
                }
            }
            if(index < root)
            {
                line = midx + root/2; column = midy + root/2 - 1 - index;
            }
            else if(index < 2*root)
            {
                column = midy - root/2; line = midx + root/2 - 1 - index%root;
            }
            else if(index < 3*root)
            {
                line = midx - root/2; column = midy - root/2 + 1 + index%root;
            }
            else
            {
                column = midy + root/2; line = midx - root/2 + 1 + index%root;
            }
        }
        cout << "Line = " << line << ", column = " << column << "." << endl;
    }
}