#include <iostream>
#include <vector>

#pragma comment(linker, "/STACK:100000000")

using namespace std;

int n;
vector<long long> X(100001,0);
vector<long long> dp(100001, -1);


long long f(int pos)
{
    if(pos>100000) return 0;
    if(dp[pos]!=-1) return dp[pos];

    long long res1 = f(pos+2) + X[pos]*pos;
    long long res2 = f(pos+1);

    dp[pos] = (res1>res2)?res1:res2;
    return dp[pos];
}

int main()
{
    cin>>n;
    int val;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        X[val]++;
    }

    long long res = f(0);

    cout<<res<<endl;
    return 0;
}