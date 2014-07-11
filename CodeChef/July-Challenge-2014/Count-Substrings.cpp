#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve()
{
	string s;
	int n;
	cin>>n;
	cin>>s;
	int k=0;
	for(int i=0; i<n; i++)
	{
		if(s[i]=='1')
		{
			k++;	
		}
	}
	long long res = ((long long)k)*(k+1)/2;
	cout<<res<<endl;
}

int main()
{
	int t;
	cin>>t;
	for(int test=1; test<=t; test++)
	{
		solve();
	}

	return 0;
}



