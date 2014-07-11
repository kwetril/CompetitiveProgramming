#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,k,p;
    vector<pair<int,int> > a;

    cin>>n>>k>>p;
    a.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    vector<int> S(n);
    int lastPos = a[0].first;
    int curS = 0;
    S[a[0].second] = curS;
    for(int i=1;i<n;i++)
    {
        if((a[i].first - lastPos)>k)
            curS++;
        S[a[i].second] = curS;
        lastPos = a[i].first;
    }
    int x,y;
    for(int i=0; i<p;i++)
    {
        cin>>x>>y;
        x--,y--;
        if(S[x]!=S[y]) cout<<"No\n";
        else cout<<"Yes\n";
    }
    return 0;
}
