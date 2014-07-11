#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class HappyLetterDiv1
{
public:
    string getHappyLetters(string s)
    {
        vector<int> let(26);
        for(int i=0;i<s.size();i++)
            let[s[i]-'a']++;

        vector<char> res;
        for(int i=0;i<26;i++)
        {
            if(let[i]!=0 && canWin(i, let))
            {
                res.push_back('a'+i);
            }
        }

        string result = "";
        sort(res.begin(), res.end());
        for(int i=0;i<res.size();i++)
            result+=res[i];
        return result;
    }

private:
    bool canWin(int pos, vector<int> let)
    {
        int x=let[pos];
        let[pos] = 0;
        while(1)
        {
            sort(let.begin(), let.end(), greater<int>());
            if(let[1]==0)
            {
                if(let[0]==0) return true;
                return x>let[0];
            }
            let[0]--;
            let[1]--;
        }
    }
};

int main()
{
	HappyLetterDiv1 x;
	string input = "rdokcogscosn";
    cout<< x.getHappyLetters(input);
    return 0;
}
