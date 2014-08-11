#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solver
{
public:
    void solve()
    {
        readData();
        cout<<findAnswer()<<endl;
    }
private:
    static const int T = 100;
    static const int MOD = 1000000007;
    int n;
    vector<vector<int> > A;
    vector<int> C;
    vector<int> fdp;
    vector<vector<int> > gdp, hdp;

    void readData()
    {
        string s;
        stringstream ss;
        getline(cin, s);
        ss.str(s);
        ss>>n;
        A.resize(n, vector<int>(T));
        C.resize(n);
        for(int i=0;i<n;i++)
        {
            getline(cin, s);
            stringstream ss;
            ss.str(s);
            int val;
            ss>>val;
            val--;
            A[i][val]=1;
            C[i]++;
            while(!ss.eof())
            {
                ss>>val;
                val--;
                A[i][val]=1;
                C[i]++;
            }
        }
    }

    int findAnswer()
    {
        if(n==1) return C[0];

        fillFDP();
        fillGDP();
        fillHDP();

        return f((1<<n)-1);
    }

    void fillFDP()
    {
        fdp.resize(1<<n, -1);
        for(int i=0;i<n;i++)
        {
            fdp[1<<i] = C[i];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    int common=0;
                    for(int k=0;k<T;k++)
                    {
                        if(A[i][k] && A[j][k]) common++;
                    }
                    fdp[(1<<i)|(1<<j)] = C[i]*C[j] - common;
                }
            }
        }
    }

    void fillGDP()
    {
        gdp.resize(1<<n,vector<int>(T, -1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<T;j++)
            {
                gdp[1<<i][j] = (A[i][j])?(C[i]-1):(C[i]);
            }
        }
    }

    void fillHDP()
    {
        hdp.resize(1<<n,vector<int>(T, -1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<T;j++)
            {
                hdp[1<<i][j] = A[i][j];
            }
        }
    }

    int f(int mask)
    {
        if(fdp[mask]!=-1) return fdp[mask];

        int res = 0;

        for(int i=0;i<n;i++)
        {
            if(mask & (1<<i))
            {
                for(int j=0;j<T;j++)
                {
                    if(A[i][j])
                    {
                        res += g(mask^(1<<i), j);
                        res %= MOD;
                    }
                }
                break;
            }
        }
        fdp[mask] = res;
        return res;
    }

    int g(int mask, int x)
    {
        if(gdp[mask][x]!=-1) return gdp[mask][x];

        int res = (MOD - h(mask, x) + f(mask)) % MOD;
        gdp[mask][x] = res;
        return res;
    }

    int h(int mask, int x)
    {
        if(hdp[mask][x]!=-1) return hdp[mask][x];

        int res = 0;
        for(int i=0;i<n;i++)
        {
            if(mask & (1<<i))
            {
                if(A[i][x])
                {
                    res += g(mask ^ (1<<i), x);
                    res %= MOD;
                }
            }
        }

        hdp[mask][x] = res;
        return res;
    }
};

int main()
{
    string s;
    stringstream ss;
    getline(cin, s);
    ss.str(s);

    int t;
    ss>>t;

    for(int i=0;i<t;i++)
    {
        Solver S;
        S.solve();
    }

    return 0;
}
