#include <iostream>

using namespace std;
void dij(int n,int v,int cost[10][10],int dist[])
{
    int i,u,c,w,flag[10],m;
    for(i=1;i<=n;i++)
        flag[i]=0,dist[i]=cost[v][i];
    c=2;
    while(c<=n)
    {
        m=999;
        for(w=1;w<=n;w++)
            if(dist[w]<m&& !flag[w])
            m=dist[w],u=w;
        flag[u]=1;
        c++;
        for(w=1;w<=n;w++)
            if((dist[u]+cost[u][w]<dist[w])&& !flag[w])
             dist[w]=dist[u]+cost[u][w];
    }
}

int main()
{
    int n,v,i,j,cost[10][10],dist[10];

    cout << "enter no of nodes" << endl;
    cin>>n;
    //cout<<"entr cost"<<endl;
   /* for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
       cin>>cost[i][j];
       if(cost[i][j]==0)
            cost[i][j]=999;
    }*/

     cost[3][3] = { {999, 2,4}, {2,999,1}, {4,1,999} };
    cout<<"enter ur location";
    cin>>v;
    dij(n,v,cost,dist);
    cout<<"shortest path";
    for(i=1;i<=n;i++)
        if(i!=v)
        cout<<v<<"->"<<i<<"cost"<<dist[i]<<endl;
    return 0;
}
