#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int A[4][4] = {
	{0,1,2,3},
	{1,0,3,2},
	{2,3,0,1},
	{3,2,1,0}
};

char next(char a, char b)
{
	return 'A' + A[a-'A'][b-'A'];
}

int max2(int n)
{
	int res = -1;
	while(n>0)
	{
		n/=2;
		res++;
	}
	return res;
}

string mix(string s, int n)
{
	if(n==0) return s;

	int len = s.size();
	string tmp=s;
	int x = (1<<max2(n));
	for(int i=0;i<len;i++)
	{
		tmp[i] = next(s[i], s[(i+x)%len]);
	}
	return mix(tmp, n-x);
}

int main()
{
	string s;
	int n,l;
	cin>>l>>n;
	cin>>s;
	cout<<mix(s,n)<<endl;
	return 0;
}
