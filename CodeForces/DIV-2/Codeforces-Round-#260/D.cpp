#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node
{
    int child[26]; //numbers of child nodes
    char val;

    node()
    {
        for(int i=0;i<26;i++)
            child[i]=-1;
    }
};

vector<node> bor;

void add(string &s)
{
    int cur = 0;
    for(int i=0;i<s.size();i++)
    {
        int next = bor[cur].child[s[i]-'a'];
        if(next != -1)
        {
            cur=next;
        }
        else
        {
            node New;
            bor.push_back(New);
            next = bor.size()-1;
            bor[cur].child[s[i]-'a'] = next;
            cur = next;
        }
    }
}

bool canWin(int cur)
{
    bool hasC = false;
    for(int i=0;i<26;i++)
    {
        if(bor[cur].child[i]!=-1)
        {
            hasC = true;
            break;
        }
    }
    if(!hasC) return false;

    int chCount = 0;
    int enemyWin = 0;
    for(int i=0;i<26;i++)
    {
        if(bor[cur].child[i]!=-1)
        {
            chCount++;
            if(canWin(bor[cur].child[i])) enemyWin++;
        }
    }
    if(chCount>enemyWin) return true;
    return false;
}

bool canLoose(int cur)
{
    bool hasC = false;
    for(int i=0;i<26;i++)
    {
        if(bor[cur].child[i]!=-1)
        {
            hasC = true;
            break;
        }
    }
    if(!hasC) return true;

    int chCount = 0;
    int enemyLose = 0;
    for(int i=0;i<26;i++)
    {
        if(bor[cur].child[i]!=-1)
        {
            chCount++;
            if(canLoose(bor[cur].child[i])) enemyLose++;
        }
    }
    if(chCount>enemyLose) return true;
    return false;
}

int main()
{
    int n, k;
    cin>>n>>k;
    string s;
    node start;
    bor.push_back(start);
    for(int i=0;i<n;i++)
    {
        cin>>s;
        add(s);
    }

    bool win = canWin(0), lose = canLoose(0);


    string res;
    if(win && lose)
    {
        res = "First";
    }
    else if(win)
    {
        if(k%2 == 1)
        {
            res="First";
        }
        else
        {
            res="Second";
        }
    }
    else
    {
        res = "Second";
    }


    cout<<res<<endl;
    return 0;
}