#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
void solve()
{
    int n, m;
    cin>>n>>m;
    vector<int> t(n,-1), meals(m), cnt(401,0);
    vector<vector<int> > pos(401, vector<int>());
 
    for(int i=0;i<m;i++)
    {
        cin>>meals[i];
        pos[meals[i]].push_back(i);
    }
 
    int res=0;
    for(int i=0;i<m;i++)
    {
        bool served = false;
        for(int j=0;j<n;j++)
        {
            if(t[j]==meals[i])
            {
                cnt[meals[i]]++;
                served = true;
                break;
            }
        }
        if(served) continue;
        for(int j=0;j<n;j++)
        {
            if(t[j]==-1)
            {
                t[j] = meals[i];
                cnt[meals[i]]++;
                res++;
                served = true;
                break;
            }
        }
        if(served) continue;
        int mini = 0;
        for(int j=1;j<n;j++)
        {
            if(cnt[t[j]] >= pos[t[j]].size() || (cnt[t[mini]] < pos[t[mini]].size() && pos[t[mini]][cnt[t[mini]]]<pos[t[j]][cnt[t[j]]]))
            {
                mini = j;
            }
        }
        t[mini] = meals[i];
        cnt[meals[i]]++;
        res++;
    }
 
    cout<<res<<endl;
}
 
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
    return 0;
}