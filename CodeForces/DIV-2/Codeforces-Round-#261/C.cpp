#include <iostream>
#include <vector>

using namespace std;

void next(vector<int> &a, int k)
{
    int pos = a.size()-1;
    if(a[pos]!=k-1) 
    {
        a[pos]++;
        return;
    }

    while(a[pos]==k-1 && pos>=0)
    {
        a[pos]=0;
        pos--;
    }
    if(pos>=0)
        a[pos]++;
}   

int main()
{
    int n,d,k;

    cin>>n>>k>>d;

    if(k>=n)
    {
        for(int i=0; i<d;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<j+1<<' ';
            }
            cout<<endl;
        }
    }
    else if(n==1)
    {
        for(int i=0; i<d; i++)      
        {
            cout<<1<<endl;
        }
    }
    else if(d==1 || k==1)
    {
        cout<<-1<<endl;
    }
    else
    {
        int c=1;
        bool gr= false;
        for(int i=0; i<d;i++)
        {
            c*=k;
            if(c>=n)
            {
                gr = true;
                break;
            }
        }

        if(!gr)
        {
            cout<<-1<<endl;
        }
        else
        {
            vector<int> a(d);
            vector<vector<int> > res(d, vector<int> (n));
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<d;j++)
                {
                    res[j][i] = a[j];
                }
                next(a,k);
            }
            for(int i=0;i<d;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<res[i][j]+1<<' ';
                }
                cout<<endl;
            }
        }
    }

    return 0;
}