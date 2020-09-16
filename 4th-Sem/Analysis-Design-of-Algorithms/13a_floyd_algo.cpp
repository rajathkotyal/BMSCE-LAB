#include<iostream>
#define inf 9999
using namespace std;
int a[10][10],d[10][10][10];

void floyds(int n){
    int k=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            d[k][i][j]=a[i][j];
    for(k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[k][i][j]=min(d[k-1][i][j],(d[k-1][i][k]+d[k-1][k][j]));
}

int main(){
    int n;
    cout<<"Enter no of vertices: ";
    cin>>n;
    cout<<"Enter Weight matrix(-1 if there is no edge): ";
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]==-1)
                a[i][j]=inf;
        }
    floyds(n);
    cout<<"Distance matrix: "<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(d[n][i][j]>=inf)
                cout<<(-1)<<" ";
            else                
                cout<<d[n][i][j]<<" ";
        }
        cout<<endl;
    }
}     