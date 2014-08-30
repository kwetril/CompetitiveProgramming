#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

int ItoD1(int i, int j, int n)
{
	int d1 = n - i + j - 1;
	return d1;
}

int ItoD2(int i, int j, int n)
{
	int d2 = j + i;
	return d2;
}

pair<int,int> DtoI(int d1, int d2, int n)
{
	pair<int, int> res;
	res.second = (d1+d2+1-n)/2;
	res.first = d2 - res.second;
	return res;
}

struct POS
{
	int d1;
	int d2;
	long long val;
};

long long modd(vector<long long> &a)
{
	long long mi, mval;
	mval = mi = -1;

	for(int i=1;i<a.size();i+=2)
	{
		if(a[i]>mval)
		{
			mval = a[i];
			mi = i;
		}
	}
	return mi;
}


long long meven(vector<long long> &a)
{
	long long mi, mval;
	mi = mval = -1;

	for(int i=0;i<a.size();i+=2)
	{
		if(a[i]>mval)
		{
			mval = a[i];
			mi = i;
		}
	}
	return mi;
}

vector<int> getListForD1(int d1, int n)
{
	vector<int> res;
	int i=0;
	int j;
	while(i<n)
	{	
		j = d1 - n + i + 1;
		if(j<0 || j>=n) 
		{
			i++;
			continue;
		}
		res.push_back(ItoD2(i,j,n));
		i++;
	}
	return res;
}

vector<int> getListForD2(int d2, int n)
{
	vector<int> res;
	int i=0;
	int j;
	while(i<n)
	{	
		j = d2 - i;
		if(j<0 || j>=n)
		{
			i++;
			continue;
		}	
		res.push_back(ItoD1(i,j,n));
		i++;
	}
	return res;
}

pair<POS, POS> solve1(vector<long long> &d1, vector<long long> &d2, vector<vector<int> > &a, int n)
{
	POS p1;
	p1.d1 = modd(d1);
	vector<int> tmp = getListForD1(p1.d1, n);
	p1.d2 = tmp[0];
	pair<int,int> cr = DtoI(p1.d1, p1.d2, n);
	p1.val = d1[p1.d1] + d2[p1.d2] - a[cr.first][cr.second];
	for(int i=1;i<tmp.size();i++)
	{
		cr = DtoI(p1.d1, tmp[i], n);
		if(p1.val < d1[p1.d1] + d2[tmp[i]] - a[cr.first][cr.second])
		{
			p1.d2 = tmp[i];
			p1.val = d1[p1.d1] + d2[tmp[i]] - a[cr.first][cr.second];
		}
	}

	POS p2;
	p2.d1 = meven(d1);
	tmp = getListForD1(p2.d1, n);
	p2.d2 = tmp[0];
	cr = DtoI(p2.d1, p2.d2, n);
	p2.val = d1[p2.d1] + d2[p2.d2] - a[cr.first][cr.second];
	for(int i=1;i<tmp.size();i++)
	{
		cr = DtoI(p2.d1, tmp[i], n);
		if(p2.val < d1[p2.d1] + d2[tmp[i]] - a[cr.first][cr.second])
		{
			p2.d2 = tmp[i];
			p2.val = d1[p2.d1] + d2[tmp[i]] - a[cr.first][cr.second];
		}
	}

	return make_pair(p1, p2);
}

pair<POS, POS> solve2(vector<long long> &d1, vector<long long> &d2, vector<vector<int> > &a, int n)
{
	POS p1;
	p1.d2 = modd(d2);
	vector<int> tmp = getListForD2(p1.d2, n);
	p1.d1 = tmp[0];
	pair<int,int> cr = DtoI(p1.d1, p1.d2, n);
	p1.val = d1[p1.d1] + d2[p1.d2] - a[cr.first][cr.second];
	for(int i=1;i<tmp.size();i++)
	{
		cr = DtoI( tmp[i], p1.d2 , n);
		if(p1.val < d1[tmp[i]] + d2[p1.d2] - a[cr.first][cr.second])
		{
			p1.d1 = tmp[i];
			p1.val = d1[tmp[i]] + d2[p1.d2] - a[cr.first][cr.second];
		}
	}

	POS p2;
	p2.d2 = meven(d2);
	tmp = getListForD2(p2.d2, n);
	p2.d1 = tmp[0];
	cr = DtoI(p2.d1, p2.d2, n);
	p2.val = d1[p2.d1] + d2[p2.d2] - a[cr.first][cr.second];
	for(int i=1;i<tmp.size();i++)
	{
		cr = DtoI(tmp[i], p2.d2, n);
		if(p2.val < d1[tmp[i]] + d2[p2.d2] - a[cr.first][cr.second])
		{
			p2.d1 = tmp[i];
			p2.val = d1[tmp[i]] + d2[p2.d2] - a[cr.first][cr.second];
		}
	}

	return make_pair(p1, p2);
}

int main()
{
	int n;
	scanf("%d",&n);
	vector<vector<int> > a(n, vector<int>(n));
	vector<long long> d1(2*n-1), d2(2*n-1);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			scanf("%d", &a[i][j]);
			d1[ItoD1(i,j,n)]+=a[i][j];
			d2[ItoD2(i,j,n)]+=a[i][j];
		}

	pair<POS, POS> res1 = solve1(d1,d2,a,n);
	pair<POS, POS> res2 = solve2(d1,d2,a,n);
	pair<int, int> p;
	if(res1.first.val + res1.second.val > res2.first.val + res2.second.val)
	{
		cout<<res1.first.val + res1.second.val<<endl;
		p = DtoI(res1.first.d1, res1.first.d2, n);
		cout<<p.first+1<<' '<<p.second+1<<' ';
		p = DtoI(res1.second.d1, res1.second.d2, n);
		cout<<p.first+1<<' '<<p.second+1<<endl;
	}
	else
	{
		cout<<res2.first.val + res2.second.val<<endl;
		p = DtoI(res2.first.d1, res2.first.d2, n);
		cout<<p.first+1<<' '<<p.second+1<<' ';
		p = DtoI(res2.second.d1, res2.second.d2, n);
		cout<<p.first+1<<' '<<p.second+1<<endl;
	}
	return 0;
}
