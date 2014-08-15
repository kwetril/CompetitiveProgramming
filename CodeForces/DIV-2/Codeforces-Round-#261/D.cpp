#include <iostream>
#include <vector>
#include <map>

using namespace std;

void update(vector<int> &T, int v, int l, int r, int pos)
{
    T[v]++;
    if(l==r) return;
    int mid = (l+r)/2;
    if(pos>mid)
        update(T,2*v+2,mid+1,r,pos);
    else
        update(T,2*v+1,l,mid,pos);
}

int sum(vector<int> &T, int v, int l, int r, int ql, int qr)
{
    if(l==ql && r==qr)
        return T[v];

    int mid = (l+r)/2;
    if(ql>mid)
        return sum(T,2*v+2,mid+1,r,ql,qr);
    else if(qr<=mid)
        return sum(T,2*v+1,l,mid,ql,qr);
    else
        return sum(T,2*v+1,l,mid,ql,mid)+sum(T,2*v+2,mid+1,r,mid+1,qr);
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> f1(n),f2(n);

    for(int i=0; i<n; i++)
        cin>>a[i];

    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }

    map<int,int> m;
    for(int i=0; i<n; i++)
    {
        map<int,int>::iterator it = m.find(a[i]);
        if(it==m.end())
        {
            it = m.insert(make_pair(a[i],1)).first;
        }
        else
        {
            (*it).second++;
        }
        f1[i] = (*it).second;
    }

    m.clear();
    for(int i=n-1; i>=0; i--)
    {
        map<int,int>::iterator it = m.find(a[i]);
        if(it==m.end())
        {
            it = m.insert(make_pair(a[i],1)).first;
        }
        else
        {
            (*it).second++;
        }
        f2[i] = (*it).second;
    }

    vector<int> T(4*n+4);
    long long res = 0;
    for(int i=n-2;i>=0;i--)
    {
        update(T,0,0,n,f2[i+1]);
        res+=sum(T,0,0,n,0,f1[i]-1);
    }
    cout<<res<<endl;
    return 0;
}
