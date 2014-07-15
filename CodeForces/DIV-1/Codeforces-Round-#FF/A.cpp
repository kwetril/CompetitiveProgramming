#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    vector<pair<int,int> > O;
    O.push_back(make_pair(0,0));
    for(int i=1;i<n;i++)
    {
        if(A[i]<=A[i-1])
        {
            O.back().second = i-1;
            O.push_back(make_pair(i,i));
        }
    }
    O.back().second = n-1;

    int res=0;
    for(int i=0;i<O.size();i++)
    {
        if(O[i].second - O[i].first + 1 > res)
            res = O[i].second - O[i].first + 1;
    }
    if(res<n) res++;

//    cout<<res<<endl;
//    for(int i=0;i<O.size();i++)
//    {
//        cout<<O[i].first<<' '<<O[i].second<<endl;
//    }

    for(int i=1;i<O.size();i++)
    {
        if(O[i].second!=O[i].first && A[O[i].first+1]>A[O[i-1].second]+1)
        {
            int len = O[i-1].second - O[i-1].first + O[i].second-O[i].first+2;
            if(res< len)
                res = len;
            //cout<<'!'<<i<<' '<<res<<endl;
        }
        else if(O[i-1].second!=O[i-1].first && A[O[i].first]>A[O[i-1].second-1]+1)
        {
            int len = O[i-1].second - O[i-1].first + O[i].second-O[i].first+2;
            if(res< len)
                res = len;
        }
        else if(O[i-1].second==O[i-1].first && i-2>=0 && A[O[i-2].second]+1<A[O[i].first])
        {
            int len = O[i-2].second - O[i-2].first + O[i].second-O[i].first+3;
            if(res< len)
                res = len;
        }
    }

    cout<<res;
    return 0;
}
