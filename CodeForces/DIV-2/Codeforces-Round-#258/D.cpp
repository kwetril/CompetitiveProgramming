#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n = s.size();
    vector<long long> a1(n+1),b1(n+1),a2(n+1),b2(n+1);

    for(int i=0;i<n;i++)
    {
        if(i%2)
        {
            if(s[i]=='a')
            {
                a1[i+1]++;
            }
            else
            {
                b1[i+1]++;
            }
        }
        else
        {
            if(s[i]=='a')
            {
                a2[i+1]++;
            }
            else
            {
                b2[i+1]++;
            }
        }
        a1[i+1]+=a1[i];
        b1[i+1]+=b1[i];
        a2[i+1]+=a2[i];
        b2[i+1]+=b2[i];
    }

    long long res1 = 0, res2 = 0;
    for(int i=0;i<n;i++)
    {
        if(i%2)
        {
            if(s[i]=='a')
            {
                res1 += a1[n]-a1[i];
                res2 += a2[n]-a2[i];
            }
            else
            {
                res1 += b1[n]-b1[i];
                res2 += b2[n]-b2[i];
            }
        }
        else
        {
            if(s[i]=='a')
            {
                res1 += a2[n]-a2[i];
                res2 += a1[n]-a1[i];
            }
            else
            {
                res1 += b2[n]-b2[i];
                res2 += b1[n]-b1[i];
            }
        }
    }

    cout<<res2<<' '<<res1<<endl;
    return 0;
}
