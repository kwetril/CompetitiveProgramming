#include <iostream>
#include <vector>

using namespace std;

long long n,m,k;

long long Min(long long a, long long b)
{
    return (a<b)?a:b;
}

long long f(long long x)
{
    long long cnt=0;
    for(int i=1;i<=n;i++)
    {
        cnt+=Min(m, (x-1)/i);
    }
    return cnt;
}

int main()
{
    cin>>n>>m>>k;

    long long left = 1;
    long long right = n*m+1;

    while(right - left > 1)
    {
        long long mid = (left + right) / 2;
        long long cnt = f(mid);
        if(cnt>=k)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }

    cout<<left<<endl;
    return 0;
}
