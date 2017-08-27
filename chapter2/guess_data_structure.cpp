#include <bits/stdc++.h>
using namespace std;
int count(bool a[])
{
    int b = 0;
    for(int i = 0 ; i < 3 ; i++)
    {
        if(a[i])
        b++;
    }
    return b;
}
int main()
{
    int test;
    while(cin >> test, test != EOF)
    {
        stack<int> ms; queue<int> mq; priority_queue<int> mpq;
        bool check[3];
        memset(check,true,3);
        if(!test)
            break;
        int type,value;
        while(test--)
        {
            cin >> type >> value;
            if(type == 1)
            {
                if(check[0]) ms.push(value);
                if(check[1]) mq.push(value);
                if(check[2]) mpq.push(value);
            }
            else
            {
                if(ms.empty())
                    check[0] = false;
                if(mq.empty())
                    check[1] = false;
                if(mpq.empty())
                    check[2] = false;
                if(check[0])
                {
                    if(value == ms.top())
                        ms.pop();
                    else
                        check[0] = false;
                }
                if(check[1])
                {
                    if(value == mq.front())
                        mq.pop();
                    else
                        check[1] = false;
                }
                if(check[2])
                {
                    if(value == mpq.top())
                        mpq.pop();
                    else
                        check[2] = false;
                }
            }
        }
        int res = count(check);
        if(res > 1)
        {
            cout << "not sure" << endl;
            continue;
        }
        if(!res)
        {
            cout << "impossible" << endl;
            continue;
        }
        if(check[0])
        {
            cout << "stack" << endl;
            continue;
        }if(check[1])
        {
            cout << "queue" << endl;
            continue;
        }if(check[2])
        {
            cout << "priority queue" << endl;
            continue;
        }
    }
}