#include <iostream>

using namespace std;

int min(int a,int b)
{
    return (a<b)?a:b;
}

int max(int a,int b)
{
    return (a<b)?b:a;
}

int abs(int a)
{
    return (a<0)?-a:a;
}

void solve()
{
    int x,y;
    cin>>x>>y;
    x=abs(x);
    y=abs(y);
    int Min = min(x, y);
    int Max = max(x, y);

    int res=2*Min;
    int rest = Max - Min;

    if(Max==x && Max!=y)
    {
        rest--;
        res+=3;
        res+=rest/2 * 4 + rest%2;
    }
    else
    {
        res+=rest/2 * 4 + rest%2;
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
