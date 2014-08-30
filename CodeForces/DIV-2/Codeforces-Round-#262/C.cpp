#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node
{
	int minVal;
	int minPos;
	int updVal;
};

void updateNode(vector<Node> &T, int v)
{
	int val1 = T[2*v+1].minVal + T[2*v+1].updVal;
	int val2 = T[2*v+2].minVal + T[2*v+2].updVal;

	if(val1<=val2)
	{
		T[v].minVal = val1;
		T[v].minPos = T[2*v+1].minPos;
	}
	else
	{
		T[v].minVal = val2;
		T[v].minPos = T[2*v+2].minPos;
	}
}

//[l..r)
void init(vector<Node> &T, vector<int> &a, int v, int l, int r)
{
	if(r<=l) return;
	if(r-l==1)
	{
		T[v].minVal = a[l];
		T[v].minPos = l;
		T[v].updVal = 0;
	}	
	else
	{
		int m = (l+r)/2;
		init(T,a,2*v+1,l,m);
		init(T,a,2*v+2,m,r);
		updateNode(T,v);
		T[v].updVal = 0;	
	}
}

void update(vector<Node> &T, int v, int l, int r, int ql, int qr)
{
	if(r-l==1)
	{
		T[v].minVal++;
	}
	else if(l==ql && r==qr)
	{
		T[v].updVal++;
	}
	else
	{
		T[2*v+1].updVal+=T[v].updVal;
		T[2*v+2].updVal+=T[v].updVal;
		T[v].updVal=0;

		int m = (l+r)/2;
		if(ql>=m)
		{
			update(T,2*v+2,m,r,ql,qr);
		}
		else if(qr<=m)
		{
			update(T,2*v+1,l,m,ql,qr);
		}
		else
		{
			update(T,2*v+1,l,m,ql,m);
			update(T,2*v+2,m,r,m,qr);
		}
		updateNode(T,v);
	}
}

int minPos(vector<Node> &T)
{
	return T[0].minPos;
}

int minVal(vector<Node> &T)
{
	return T[0].minVal + T[0].updVal;
}

int main()
{
	int n,m,w;
	cin>>n>>m>>w;
	vector<int> a(n);
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	
	vector<Node> T(4*n);
	init(T,a,0,0,n);

	for(int i=0;i<m;i++)
	{
		int mPos = minPos(T);
		int l = mPos;
		int r = mPos + w;
		if(r>n)
		{
			r=n;
			l=n-w;
		}
		update(T,0,0,n,l,r);
	}
	cout<<minVal(T)<<endl;
	return 0;
}

