#include <iostream>
#include <vector>

using namespace std;

vector<int> a;

long long f(int l, int r, int h)
{
    long long res0 = r-l, res;

    int mina = a[l];
    for(int i=l;i<r;i++)
        if(mina>a[i]) mina=a[i];

    res = mina-h;
    bool started=false;
    int startedi;
    for(int i=l;i<r;i++)
    {
        if(!started && a[i]>mina)
        {
            started = true;
            startedi=i;
        }

        if(started && a[i]==mina)
        {
            res+=f(startedi,i,mina);
            started = false;
        }
    }
    if(started)
    {
        res+=f(startedi,r,mina);
    }
    return (res<res0)?res:res0;
}

int main()
{
    int n;
    cin>>n;
    a.assign(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    long long res = f(0,n,0);
    cout<<res<<endl;
    return 0;
}
