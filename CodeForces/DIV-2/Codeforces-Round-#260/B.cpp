#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int rest2[4] = {1,2,4,3}, rest3[4] = {1,3,4,2}, rest4[2] = {1,4};
    
    cin>>s;
    int res=0;
    int n;
    if(s.length()==1)
    {
        n = s[0] - '0';
    }
    else
    {
        n = (s[s.length()-2] - '0')*10 + (s[s.length()-1] - '0');
    }
    res = (1 + rest2[n%4]+rest3[n%4]+rest4[n%2])%5;
    cout<<res<<endl;
    return 0;
}
