#include<iostream>
using namespace std;
int s[10],top=0;
int visited[10],a[10][10];

void topo(int v,int n){
    visited[v]=1;
    for(int i=0;i<n;i++){
        if(a[v][i] && !visited[i])
            topo(i,n);
    }
    s[top++]=v;
}

int main(){
    int n;
    cout<<"Enter no of vertices: ";
    cin>>n;
    cout<<"Enter adjacency matrix:";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    topo(0,n);
    for(int i=0;i<n;i++)
        if(!visited[i])
            topo(i,n);
    cout<<"Topological sorting:";
    for(int i=top-1;i>=0;i--)
        cout<<" v"<<(s[i]+1);
}