#include <bits/stdc++.h>
using namespace std;
class compare
{
    public:
        bool operator()(pair<int,int> n1,pair<int,int> n2) {
        if(n1.second != n2.second)
            return n1.second>n2.second;
        else
            return n1.first>n2.first;
    }
};

int main()
{
    stringstream ss;
    string s,temp;
    int id,sec;
    vector< pair<int,int> > index;
    priority_queue< pair<int,int> , vector<pair<int,int> > , compare > q;
    while(true)
    {
        getline(cin,s);
        if(s[0] == '#')
            break;
        ss << s;
        ss >> temp >> id >> sec;
        ss.clear();
        index.push_back(make_pair(id,sec));
    }
    int k; cin >> k;
    vector< pair<int,int> >::iterator it;
    it = index.begin(); 
    while(it != index.end())
    {
        for(int i = 0 ; i < k ; i++)
        {
            q.push(make_pair((*it).first,((*it).second)*(i+1)));
        }
        it++;
    }
    while(k--)
    {
        pair<int,int> temp = q.top(); q.pop();
        cout << temp.first << endl;    
    }
}