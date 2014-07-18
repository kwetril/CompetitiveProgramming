//#include <iostream>
//#include <vector>
//#include <string>
//#include <queue>
//#include <set>
//#include <map>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//
//bool checkAuto(string &a, string &b)
//{
//	int poss=0, post=0;
//	int al,bl;
//	al=a.size();
//	bl=b.size();
//	for(poss=0; poss<al; poss++)
//	{
//		while(post<bl && b[post]!=a[poss])
//		{
//			post++;
//		}
//		if(post==bl) return false;
//	}
//	return true;
//}
//
//bool checkArray(string &a, string &b)
//{
//	vector<int> leta(26);
//	vector<int> letb(26);
//
//	if(a.size()!=b.size()) return false;
//	for(int i=0; i<a.size(); i++)
//	{
//		leta[a[i]-'a']++;
//	}
//
//	for(int i=0; i<b.size(); i++)
//	{
//		letb[b[i]-'a']++;
//	}
//
//	for(int i=0; i<26; i++)
//	{
//		if(leta[i]!=letb[i]) return false;
//	}
//	return true;
//}
//
//int checkBoth(string &a, string &b)
//{
//	vector<int> leta(26);
//	vector<int> letb(26);
//
//	for(int i=0; i<a.size(); i++)
//	{
//		leta[a[i]-'a']++;
//	}
//
//	for(int i=0; i<b.size(); i++)
//	{
//		letb[b[i]-'a']++;
//	}
//
//	for(int i=0; i<26; i++)
//	{
//		if(leta[i]<letb[i]) return false;
//	}
//	return true;
//}
//
//int main()
//{
//	string s,t;
//
//	cin>>s>>t;
//	if(checkAuto(t,s)) cout<<"automaton";
//	else if(checkArray(s,t)) cout<<"array";
//	else if(checkBoth(s,t)) cout<<"both";
//	else cout<<"need tree";
//
//	cout<<endl;
//	return 0;
//}
//
//
//
//
//
