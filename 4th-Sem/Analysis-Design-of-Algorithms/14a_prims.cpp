#include<iostream>
using namespace std;
int g[10][10],parent[10];

int min_key(int visited[],int n,int parent[]){
    int min=INT8_MAX,k,j;
    for(int i=0;i<n;i++){
        if(visited[i]){
            for(int l=0;l<n;l++){
                if(!visited[l] && g[i][l] && min>g[i][l]){
                    min=g[i][l];
                    k=i;
                    j=l;
                }
            }
        }
    }
    parent[j]=k;
    visited[j]=1;
    return min;
}

void prims(int n){
    int parent[n],visited[n];
    for(int i=0;i<n;i++)
        visited[i]=0;
    visited[0]=1;
    int distance=0,flag=1;
    while(flag){
        distance+=min_key(visited,n,parent);
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                flag=1;
                break;
            }
            else
                flag=0;
        }
    }
    cout<<"Edges in spanning tree: "<<endl;
    for(int i=1;i<n;i++){
        cout<<parent[i]+1<<"-"<<i;
        cout<<endl;
    }
    cout<<endl<<"Total distance: "<<distance;
}

int main(){
    int n;
    cout<<"Enter no of vertices: ";
    cin>>n;
    cout<<"Enter Weight matrix: ";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>g[i][j];
        }
    prims(n);
}