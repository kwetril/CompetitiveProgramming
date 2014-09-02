#include <iostream>
#include <vector>

using namespace std;

void solve()
{
	long long n;
	cin>>n;
	int result = 0;
	for(long long i=1;i<=n;i++)
	{
		int tmp;
		cin>>tmp;
		int cnt = (((n+1) * n/2) - (i * (i-1) / 2) - ((n-i+1)*(n-i)/2)) % 2;
		if(cnt) result ^= tmp;
	}
	cout<<result<<endl;
}

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		solve();
	}
	return 0;
}
