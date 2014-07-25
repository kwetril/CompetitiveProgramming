#include <iostream>
#include <vector>

using namespace std;

bool check(long long n, long long k, long long w1, long long w2, long long w3)
{
    if(w1+w2+w3!=k) return false;
    if(w1<0 || w2<0 || w3<0 || w1>n/3 || w2>n/3 || w3>n/3) return false;

    long long rest = n-k;
    if (rest == 0)
    {
        if(w1==w2 && w1==w3) return true;
        return false;
    }

    rest -= n/3-w1;
    w1=n/3;
    if(rest<0) return false;
    if (rest == 0)
    {
        if(w1==w2 && w1==w3) return true;
        return false;
    }

    rest -= n/3-w2;
    w2=n/3;
    if(rest<0) return false;
    if (rest == 0)
    {
        if(w1==w2 && w1==w3) return true;
        return false;
    }

    rest -= n/3-w3;
    w3=n/3;
    if(rest<0) return false;
    if (rest == 0)
    {
        if(w1==w2 && w1==w3) return true;
        return false;
    }

    return false;
}

void solve()
{
    long long n, k, d1, d2;
    cin>>n>>k>>d1>>d2;
    long long x;

    x = k+d2-d1;
    if(x%3==0)
    {
        x/=3;
        if(check(n,k,d1+x,x,-d2+x))
        {
                cout<<"yes"<<endl;
                return;
        }
    }

    x = k-d2-d1;
    if(x%3==0)
    {
        x/=3;
        if(check(n,k,d1+x,x,d2+x))
        {
                cout<<"yes"<<endl;
                return;
        }
    }

    x = k+d1+d2;
    if(x%3==0)
    {
        x/=3;
        if(check(n,k,-d1+x,x,-d2+x))
        {
                cout<<"yes"<<endl;
                return;
        }
    }

    x = k+d1-d2;
    if(x%3==0)
    {
        x/=3;
        if(check(n,k,-d1+x,x,d2+x))
        {
                cout<<"yes"<<endl;
                return;
        }
    }

    cout<<"no"<<endl;
}

int main()
{
    int t;
    cin>>t;
    for(int test = 1; test<=t; test++)
        solve();
}


