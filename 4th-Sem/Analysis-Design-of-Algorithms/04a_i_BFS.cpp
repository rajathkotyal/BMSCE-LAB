//BFS
#include<iostream>
using namespace std;
int q[10],r=0,f=0;
int a[10][10],visited[10];

void bfs(int v,int n){
    for(int i=0;i<n;i++)
        if(a[v][i] && !visited[i]){
            q[r++]=i;
            visited[i]=1;
        }
    if(f<=r)
        bfs(q[f++],n);
}

int main(){
    int n,k;
    cout<<"Enter no of vertices:";
    cin>>n;
    cout<<"Enter adjacency matrix:";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    cout<<"Enter starting vertex:";
    cin>>k;
    visited[k-1]=1;
    for(int i=0;i<n;i++)
        visited[i]=0;
    cout<<"Nodes visited from v"<<k<<":";
    bfs(k-1,n);
    for(int i=0;i<r;i++)
        cout<<" v"<<(q[i]+1);
}