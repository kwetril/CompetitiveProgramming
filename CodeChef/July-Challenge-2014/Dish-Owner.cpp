#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

struct Chef
{
    int best;
    int dishes;
};

int findParent(int dish, vector<int > &dishes)
{
    if(dishes[dish] == dish)
        return dish;
    vector<int> tmp;
    while(dishes[dish] != dish)
    {
        tmp.push_back(dish);
        dish = dishes[dish];
    }
    for(int i=0;i<tmp.size();i++)
    {
        dishes[tmp[i]]=dish;
    }
    return dish;
}

int unite(int dish1, int dish2, vector<int > &dishes)
{
    dish1 = findParent(dish1, dishes);
    dish2 = findParent(dish2, dishes);
    if(rand()&1)
    {
        dishes[dish1] = dish2;
        return dish2;
    }
    else
    {
        dishes[dish2] = dish1;
        return dish1;
    }
}

void solve()
{
    int N,Q;
    scanf("%d",&N);
    vector<Chef> C(N);
    vector<int> owner(N);
    vector<int> dishes(N); //<parent>
    for(int i=0;i<N;i++)
    {
        scanf("%d",&(C[i].best));
        dishes[i] = i;
        owner[i] = i;
        C[i].dishes = i;
    }
    scanf("%d",&Q);
    int type;
    for(int i=0;i<Q;i++)
    {
        scanf("%d",&type);
        if(type==1)
        {
            int dish;
            scanf("%d",&dish);
            dish--;
            dish = findParent(dish, dishes);
            int own = owner[dish];
            printf("%d\n",own+1);
        }
        else
        {
            int dish1, dish2;
            scanf("%d%d",&dish1,&dish2);
            dish1--,dish2--;
            dish1 = findParent(dish1, dishes);
            dish2 = findParent(dish2, dishes);
            if(dish1 == dish2)
            {
                printf("Invalid query!\n");
            }
            else
            {
                int ch1 = owner[dish1];
                int ch2 = owner[dish2];

                int win, un;
                if(C[ch1].best > C[ch2].best)
                {
                    win = ch1;
                    un = unite(dish1, dish2, dishes);
                    C[win].dishes = un;
                    owner[un] = win;
                }
                else if(C[ch1].best < C[ch2].best)
                {
                    win=ch2;
                    un = unite(dish1, dish2, dishes);
                    C[win].dishes = un;
                    owner[un] = win;
                }

            }
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        solve();
    }
    return 0;
}
