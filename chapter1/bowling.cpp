#include <bits/stdc++.h>
using namespace std;
string inp;
int place(int loc)
{
    char a = inp[loc];
    if(a == '/')
    {
        return 10 + place(loc-2);
    }
    else if(a == 'X')
    {
        return 10 + place(loc-2) + place(loc-4);
    }
    else
    {
        return a - '0';
    }
}
int main()
{ 
    while(getline(cin,inp),inp != "Game Over")
    {
        int score = 0,mark = inp.length()-1; char c;
        while(mark >= 0)
        {
            score += place(mark);
            mark -= 2;
        }
        cout << score << endl;
    }
}