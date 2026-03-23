#include<bits/stdc++.h>
using namespace std;
vector<int> parent(1e3,0);
vector<int> Size(1e3,0);
void nodeInit(int n)
{
    parent[n]=n;
}
int find(int u)
{
    if(parent[u]==u)
    return u;
    return parent[u]=find(parent[u]);
}
void Union(int u,int v)
{
    int p1=find(u);
    int p2=find(v);
    if(p1!=p2)
    {
        if(Size[p1]<Size[p2])
        {
            swap(p1,p2);
            parent[p2]=p1;
            Size[p1]+=Size[p2];
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    nodeInit(n);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    int ans=0;
    for(int i=1;i<m;i++)
    {
        if(parent[i]!=i) ans++;
    }
    cout<<"Total number of components : "<<ans<<endl;
    return 0;
}