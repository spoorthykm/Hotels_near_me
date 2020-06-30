#include <iostream>
#define inf 999
using namespace std;
void dij(int n,int v,float cost[8][8],float dist[])
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
     for(i=0;i<420;i++)
    cout << "*";

    cout<<"\n\n\t\t\t\t\tFIND HOTELS NEAR ME  "<<endl;
    cout<<endl<<"\t\t\t\t\t0)SAPTHAGIRI EXT\n\t\t\t\t\t1)JAYANAGAR\n\t\t\t\t\t2)SS PURAM\n\t\t\t\t\t3)SIT\n\t\t\t\t\t4)HANUMATHAPURA\n\t\t\t\t\t5)ASHOKA NAGARA\n\t\t\t\t\t6)MG ROAD\n\t\t\t\t\t7)GUBBI ROAD"<<endl;
    float cost[8][8] = {999,1,2,2.5,4,4.5,3.8,7,
                        1,999,2.3,3.3,4.5,5.5,4,7.5,
                        2,2.3,999,1.2,3.2,3.4,3.1,6,
                        2.5,3.3,1.2,999,2.5,4.2,3.7,7.2,
                        4,4.5,3.2,2.5,999,3.3,2.7,5.2,
                        4.5,5.5,3.4,4.2,3.3,999,0.5,1.5,
                        3.8,4,3.1,3.7,2.7,0.5,999,2,
                        7,7.5,6,7.2,5.2,1.5,2,999};



    cout<<endl<<"Please enter your location";
    cin>>v;
  system("cls");
    dij(n,v,cost,dist);

    cout<<"shortest path for hotels from your location"<<endl;
    if(v==2)
        cout<<"Sunitha hotel is in your location"<<endl;
    if(v==3)
        cout<<"DOMINOSS is in your location"<<endl;
    if(v==5)
        cout<<"ASHOKA HOTEL is in your location"<<endl;
char p[8][50] = {"SAPTHAGIRI EXT","JAYANAGAR","SS PURAM","SIT","HANUMATHAPURA","ASHOKA NAGARA","MG ROAD","GUBBI ROAD"};
char a[8][50] = {"no", "no", "SUNTHA HOTEL","DOMINOSS","NO","ASHOKA HOTEL","no"};
    for(i=0;i<n;i++)
        if(i!=v&&(i==2||i==3||i==5))
        cout<<endl<<p[v]<<"->"<<a[i]<<" has "<<dist[i]<<"km"<<endl;
    return 0;
}
