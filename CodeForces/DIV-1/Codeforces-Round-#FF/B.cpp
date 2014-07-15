#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstdlib>

using namespace std;

int main()
{
    long long n,m,p,k;
    cin>>n>>m>>k>>p;
    vector<int> N(n),M(m);

    long long tmp;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin>>tmp;
            N[i]+=tmp;
            M[j]+=tmp;
        }

    priority_queue<long long> qN,qM;
    for(int i=0;i<n;i++)
        qN.push(N[i]);
    for(int i=0;i<m;i++)
        qM.push(M[i]);

    vector<long long> vN(k+1), vM(k+1);

    for(int i=1;i<=k;i++)
    {
        tmp = qN.top();
        qN.pop();
        vN[i] = vN[i-1] + tmp;
        tmp -= p*m;
        qN.push(tmp);

        tmp = qM.top();
        qM.pop();
        vM[i] = vM[i-1] + tmp;
        tmp -= p*n;
        qM.push(tmp);
    }

    long long res=-1e18;
    for(int i=0;i<=k;i++)
    {
        tmp = vN[i] + vM[k-i] - ((long long)i)*(k-i)*p;
        if(tmp>res){
            res = tmp;
        }
    }

    cout<<res<<endl;
    return 0;
}
