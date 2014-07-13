#include <iostream>
#include <vector>

using namespace std;

vector<vector<double> > C;
void fillC(vector<vector<double> > &C, int size)
{
    C.push_back(vector<double>(1,1));
    for(int i=1;i<=size;i++)
    {
        C.push_back(vector<double>(i+1));
        C[i][0] = C[i-1][0]*0.5;
        for(int j=1;j<i;j++)
        {
            C[i][j] = (C[i-1][j-1]+C[i-1][j])*0.5;
        }
        C[i][i] = C[i-1][i-1]*0.5;
    }
}

void solve()
{
    int n,c,k;
    cin>>n>>c>>k;

    vector<int> A(n,0);
    for(int i=0;i<k;i++)
    {
        int left, right;
        cin>>left>>right;
        left--,right--;
        for(int pos=left;pos<=right;pos++)
        {
            A[pos]++;
        }
    }

    vector<vector<double> > P(k+1, vector<double>(c));
    P[0][1] = 1;
    double c1 = 1.0/c;
    for(int i=1;i<=k;i++)
    {
        for(int cs=0;cs<c;cs++)
        {
            for(int cc=0;cc<c;cc++)
            {
                int ce = (cs*cc)%c;
                P[i][ce] += P[i-1][cs] * c1;
            }
        }
    }

//    for(int i=0;i<P.size();i++)
//    {
//        for(int j=0;j<P[i].size();j++)
//        {
//            cout<<P[i][j]<<' ';
//        }
//        cout<<endl;
//    }

    double res = 0;
    for(int i=0;i<n;i++)
    {
        double curRes = 0;
        for(int j=0;j<=A[i];j++)
        {
            for(int q=0;q<c;q++)
            {
                curRes +=q*P[j][q]*C[A[i]][j];
            }
        }
        res+=curRes;
        //cout<<curRes<<endl;
    }

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(8);
    cout<<res<<endl;
}

int main()
{
    fillC(C,50);
    int t;
    cin>>t;
    for(int test=0;test<t;test++)
    {
        solve();
    }
    return 0;
}
