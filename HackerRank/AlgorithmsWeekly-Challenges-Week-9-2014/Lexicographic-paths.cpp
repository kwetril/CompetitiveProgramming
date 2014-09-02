#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve()
{
	int n, m;
	long long k;
	cin>>m>>n>>k;
	n++, m++;
	vector<vector<long long> > a(n, vector<long long>(m));

	for(int i=0;i<n;i++)
	{
		a[i][m-1] = 1;
	}
	for(int i=0;i<m;i++)
	{
		a[n-1][i] = 1;
	}
	for(int i=n-2; i>=0; i--)
		for(int j=m-2; j>=0; j--)
			a[i][j] = a[i+1][j] + a[i][j+1];

	int ci,cj;
	ci=cj=0;
	string res = "";
	while(!((ci==n-1) && (cj==m-1)))
	{
		if(ci==n-1)
		{
			res+='H';
			cj++;
		}
		else if(cj==m-1)
		{
			res+='V';
			ci++;
		}
		else
		{
			if(k > a[ci][cj+1] - 1)
			{
				k -= a[ci][cj+1];
				res += 'V';
				ci++;
			}
			else
			{
				res += 'H';
				cj++;
			}
		}
	}
	cout<<res<<endl;
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		solve();
	}
	return 0;
}
