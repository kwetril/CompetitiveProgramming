#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]--;
    }
    vector<int> used(n);
    vector<int> cicles;
    for(int i=0;i<n;i++)
    {
        if(!used[i])
        {
            int cur=i;
            int cnt=0;
            while(!used[cur])
            {
                used[cur]=true;
                cur = a[cur];
                cnt++;
            }
            cicles.push_back(cnt);
        }
    }

    vector<int> pw(100001);
    for(int i=0;i<cicles.size();i++)
    {
        if(cicles[i]>=2)
        {
            int limit = sqrt(cicles[i]);
            for(int j=2;j<=limit;j++)
            {
                int cur=0;
                while(cicles[i]%j==0)
                {
                    cicles[i]/=j;
                    cur++;
                }
                if(pw[j]<cur) pw[j] = cur;
            }
            if(cicles[i]!=1)
            {
                if(pw[cicles[i]]<1) pw[cicles[i]] = 1;
            }
        }
    }

    long long res = 1;
    for(int i=0;i<pw.size();i++)
    {
        for(int j=0;j<pw[i];j++)
        {
            res*=i;
            res%=1000000007;
        }
    }
    cout<<res<<endl;
}

int main()
{
    int t;
    cin>>t;
    for(int test=1;test<=t;test++)
    {
        solve();
    }
    return 0;
}
