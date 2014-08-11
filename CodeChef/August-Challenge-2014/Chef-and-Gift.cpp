#include <iostream>
 
using namespace std;
 
void solve()
{
    int n,k,x,c=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x%2==0)
        {
            c++;
        }
    }
 
    if((k==0 && c==n) || k>c)
        cout<<"NO\n";
    else
        cout<<"YES\n";
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