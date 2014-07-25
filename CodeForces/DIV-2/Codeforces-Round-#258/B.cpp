#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

bool sorted(vector<int> &a)
{
    for(int i=1;i<a.size();i++)
    {
        if(a[i-1]>a[i]) return false;
    }
    return true;
}

void f(vector<int> &a, int l, int r)
{
    while(l<r)
    {
        int tmp = a[l];
        a[l]=a[r];
        a[r]=tmp;
        l++;
        r--;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    if(sorted(a))
    {
        cout<<"yes\n1 1\n";
        return 0;
    }

    int pos=0;
    while(pos<n-1)
    {
        if(a[pos]>a[pos+1])
        {
            int st = pos;
            while(pos<n-1 && a[pos]>a[pos+1])
            {
                pos++;
            }
            f(a,st,pos);
            if(sorted(a))
            {
                cout<<"yes\n"<<st+1<<' '<<pos+1<<endl;
            }
            else
            {
                cout<<"no\n";
                return 0;
            }
        }
        pos++;
    }
	return 0;
}





