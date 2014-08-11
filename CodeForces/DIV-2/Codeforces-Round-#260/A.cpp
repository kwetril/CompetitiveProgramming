#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<int, int> > a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }

    sort(a.begin(), a.end(), greater<pair<int, int> >());

    int maxB = a[0].second; 
    for(int i=1;i<n;i++)
    {
        if(a[i].first<a[i-1].first && a[i].second>a[i-1].second)
        {
            cout<<"Happy Alex\n";
            return 0;
        }
    }

    cout<<"Poor Alex\n";
    return 0;
}