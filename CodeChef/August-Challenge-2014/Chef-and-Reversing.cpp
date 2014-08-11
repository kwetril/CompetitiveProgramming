#include <cstdio>
#include <vector>
#include <queue>
 
using namespace std;
 
int main()
{
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    vector<vector<int> > G(n), RG(n);
 
 
    for(int i=0;i<m;i++)
    {
        scanf("%d%d", &x, &y);
        if(x!=y)
        {
            x--, y--;
            G[x].push_back(y);
            RG[y].push_back(x);
        }
    }
 
    vector<int> used(n);
    queue<int> Q, q;
 
    Q.push(0);
    int steps = -1;
    bool found = false;
    while(Q.size()!=0  && !found)
    {
        steps++;
        int qlen = Q.size();
        for(int i=0;i<qlen && !found;i++)
        {
            int cur = Q.front();
            Q.pop();
            if(cur==n-1)
            {
                found=true;
                break;
            }
            if(used[cur]) continue;
 
            q.push(cur);
            used[cur]=true;
        }
 
        while(q.size()!=0 && !found)
        {
            int v = q.front();
            q.pop();
            for(int j=0;j<G[v].size();j++)
            {
                if(used[G[v][j]]) continue;
                q.push(G[v][j]);
                used[G[v][j]]=true;
                if(G[v][j]==n-1)
                {
                    found=true;
                    break;
                }
            }
            for(int j=0;j<RG[v].size() && !found;j++)
            {
                if(used[RG[v][j]]) continue;
                Q.push(RG[v][j]);
            }
        }
    }
 
    if(found)
    {
        printf("%d\n", steps);
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}