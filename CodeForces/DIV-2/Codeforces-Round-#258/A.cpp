#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int Min(int a,int b)
{

    return (a<b)?a:b;
}

int main()
{
    int n,m;
    cin>>n>>m;
    if(Min(n,m)%2==0)
    {
        cout<<"Malvika"<<endl;
    }
    else
    {
        cout<<"Akshat"<<endl;
    }

	return 0;
}
