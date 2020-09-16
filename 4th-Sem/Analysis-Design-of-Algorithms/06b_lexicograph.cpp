#include<iostream>
using namespace std;
int a[10][10],visited[10],vertex;
int s[10],st[10],top=0,top1;

void dfs(int v,int n){
    visited[v]=1;
    for(int i=0;i<n;i++){
        if(a[v][i]){
            st[top1++]=i;
            if(!visited[i])
                dfs(i,n);
        }
    }
}

void isCycle(){
    for(int i=0;i<top1;i++)
        if(vertex==st[i]){
            cout<<(-1);
            exit(0);
        }
    return;
}

int min_degree(int indegree[],int n){
    int min_vertex,min;
    for(int i=0;i<n;i++){
        if(indegree[i]!=-1){
            min=indegree[i];
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(indegree[i]!=-1 && indegree[i]<min)
            min=indegree[i];
    }
    for(int i=0;i<n;i++){
        if(indegree[i]==min){
            min_vertex=i;
            break;
        }
    }
    return min_vertex;
}

int main(){
    int n;
    cout<<"Enter no of vertices: ";
    cin>>n;
    int indegree[n]={0};
    cout<<"Enter adjacency matrix: ";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(a[i][j]==1)
                indegree[j]++;
        }
    
    cout<<"Lexicographically smallest topological sorting:";
    for(int i=0;i<n;i++){
        top=0;
        vertex=i;
        dfs(i,n);
        for(int i=0;i<n;i++)
            visited[i]=0;
        isCycle();
    }
    for(int i=0;i<n;i++){
        int min_vertex=min_degree(indegree,n);
        s[top++]=min_vertex;
        for(int j=0;j<n;j++){
            if(a[min_vertex][j]==1)
                indegree[j]--;
        }
        indegree[min_vertex]--;
    }
    for(int i=0;i<top;i++)
        cout<<" v"<<(s[i]+1);
}