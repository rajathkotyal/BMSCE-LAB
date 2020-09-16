#include<iostream>
#include<vector>
using namespace std;
int a[10][10];

int knapsack(int n,int w[],int p[],int c){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=c;j++){
            if(j==0 || i==0)
                a[i][j]=0;
            else if(w[i]>j)
                a[i][j]=a[i-1][j];
            else
                a[i][j]=max(a[i-1][j],a[i-1][j-w[i]]+p[i]);  
        }
    }
    return a[n][c];
}

void opt_items(int n,int c,int w[]){
    int i=n,j=c;
    while(i!=0 && j!=0){
        if(a[i][j] != a[i-1][j]){
            cout<<i<<" ";
            j=j-w[i];
        }
        i--;
    }
}

int main(){
    int n,capacity;
    cout<<"Enter no of items: ";
    cin>>n;
    int weight[n],profit[n];
    cout<<"Enter weight and profit of "<<n<<" items: "<<endl;
    for(int i=1;i<=n;i++)
        cin>>weight[i]>>profit[i];
    cout<<"Enter capacity: ";
    cin>>capacity;
    cout<<"Optimal profit= "<<knapsack(n,weight,profit,capacity)<<endl;
    cout<<"Optimal items= ";
    opt_items(n,capacity,weight);
}