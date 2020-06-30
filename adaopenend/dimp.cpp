#include <iostream>
#define inf 999
using namespace std;
void dij(int n,int v,float cost[7][7],float dist[])
{
    int i,u,c,w,flag[10],m;
    for(i=0;i<n;i++)
        flag[i]=0,dist[i]=cost[v][i];
    c=1;
    while(c<n)
    {
        m=999;
        for(w=0;w<n;w++)
            if(dist[w]<m&& !flag[w])
            m=dist[w],u=w;
        flag[u]=1;
        c++;
        for(w=0;w<n;w++)
            if((dist[u]+cost[u][w]<dist[w])&& !flag[w])
             dist[w]=dist[u]+cost[u][w];
    }
}

int main()
{
    int n,v,i,j;
    float dist[10];
     n=7;
    //cout << "enter no of nodes" << endl;
    //cin>>n;
    cout<<"0)sapthagiri\n1)JAYANAGAR\n 2)SS PURAM\n 3)SIT\n4)HANUMATHAPURA\n5)ASHOKA NAGARA\n6)GUBBI ROAD"<<endl;
    float cost[7][7] = {999,1,2,3,4,5,6,
                       1,999,2,3,4,5,6,
                       2,2,999,1,10,3.1,10,
                       3,3,1,999,3,4,6,
                       4,4,10,3,999,3,5,
                       5,5,3.1,4,3,999,2.3,
                       6,6,10,6,5,2.3,999};
    for(i=0;i<n;i++)
    {for(j=0;j<n;j++)

       cout<<cost[i][j];
       //if(cost[i][j]==0)
        //  cost[i][j]=999;
        cout<<endl;
    }


    cout<<"enter ur location";
    cin>>v;

    dij(n,v,cost,dist);

    cout<<"shortest path"<<endl;
    if(v==2)
        cout<<"sunitha hotel in your location"<<endl;
    if(v==3)
        cout<<"DOMINOSS in your location"<<endl;
    if(v==5)
        cout<<"ASHOKA HOTEL in ur location"<<endl;
char p[7][50] = {"sapthgiri", "Mg ", "ss puram"};
       char a[7][50] = {"no", "no", "SUNTHA HOTEL","DOMINOSS","NO","ASHOKA HOTEL","no"};
    for(i=0;i<n;i++)
        if(i!=v&&(i==2||i==3||i==5))
        cout<<endl<<p[v]<<"->"<<a[i]<<"cost"<<dist[i]<<endl;
    return 0;
}
