#include <iostream>
 
using namespace std;
 
int Abs(int a)
{
    return (a<0)?-a:a;
}
 
bool f(int x, int y)
{
    if(x<0)
    {
        if(Abs(x)>=Abs(y))
            return Abs(x)%2==0;
        else
            return Abs(y)%2==0;
    }
 
    if(x==0) return Abs(y)%2==0;
 
    if(x==1) return (y==1) || (Abs(y)%2==0);
 
    y--;
    if(Abs(x)>=Abs(y))
        return Abs(x)%2==1;
    else
        return Abs(y)%2==1;
}
 
void solve()
{
    int x,y;
    cin>>x>>y;
    if(f(x,y))
        cout<<"YES\n";
    else
        cout<<"NO\n";
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