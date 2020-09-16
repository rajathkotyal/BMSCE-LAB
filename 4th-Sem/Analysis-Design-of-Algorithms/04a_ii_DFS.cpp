//DFS
#include<iostream>
using namespace std;
int s[10],top=0;
int visited[10],a[10][10];

void dfs(int v,int n){
    s[top++]=v;
    visited[v]=1;
    for(int i=0;i<n;i++){
        if(a[v][i] && !visited[i])
            dfs(i,n);
    }
}

int main(){
    int n,k;
    cout<<"Enter no of vertices: ";
    cin>>n;
    cout<<"Enter adjacency matrix:";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    cout<<"Enter starting vertex:";
    cin>>k;
    for(int i=0;i<n;i++)
        visited[i]=0;
    visited[k-1]=1;
    dfs(k-1,n);
    cout<<"Vertices from v"<<k<<":";
    for(int i=1;i<top;i++)
        cout<<" v"<<(s[i]+1);
    cout<<endl;
    for(int i=0;i<n;i++)
        if(!visited[i]){
            cout<<"Graph is not connected"<<endl;
            return 0;
        }
    cout<<"Graph is connected"<<endl;
}